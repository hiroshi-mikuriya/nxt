/*
 * PidTail.cpp
 *
 *  Created on: 2012/06/16
 *      Author: KOUICHIRO HONDA
 */

#include "PidTail.h"
#include "hardware/io/Io.h"
#include "Common.h"

namespace runmethod {
	namespace impl {

		namespace {
			const S16 TURN_MAX = 100;
			const S16 TURN_MIN = -100;
			const S16 PWM_MAX = 100;
			const S16 PWM_MIN = -100;
		}

		PidTail::PidTail(S16 forward, LINETRACE_EDGE edge, utils::PidCalculation<S16>::Parameter const & parameter)
				: m_forward(forward), m_edge(edge), m_pid(parameter)
		{
		}

		void PidTail::Control(F32 gyroOffset, int color)
		{
			S16 leftPwm;
			S16 rightPwm;
			if (m_edge == EDGE_LEFT) {
				SetPwm(GetTurn(color), &leftPwm, &rightPwm);
			}
			else {
				SetPwm(GetTurn(color), &rightPwm, &leftPwm);
			}
			rightPwm = compress_cast<S16, PWM_MIN, PWM_MAX>(rightPwm);
			leftPwm = compress_cast<S16, PWM_MIN, PWM_MAX>(leftPwm);
			::hardware::Io::GetInstance().SetPwm(static_cast<S8>(leftPwm), static_cast<S8>(rightPwm));
		}

		S8 PidTail::GetTurn(int color)
		{
			return static_cast<S8>(compress_cast<S16, TURN_MIN, TURN_MAX>(m_pid.Calculate(color)));
		}

		void PidTail::SetPwm(S8 turn, S16* blackSidePwm, S16* whiteSidePwm)
		{
			*blackSidePwm = m_forward + turn / 2;
			*whiteSidePwm = m_forward - turn / 2;
			if (*blackSidePwm > *whiteSidePwm) {
				ValidatePwm(blackSidePwm, whiteSidePwm);
			}
			else {
				ValidatePwm(whiteSidePwm, blackSidePwm);
			}
		}

		void PidTail::ValidatePwm(S16* biggerPwm, S16* smallerPwm)
		{
			if ((*biggerPwm) > PWM_MAX) {
				*smallerPwm -= (*biggerPwm) - PWM_MAX;
				*biggerPwm = PWM_MAX;
			}
			else if ((*smallerPwm) < PWM_MIN) {
				*biggerPwm -= (*smallerPwm) - PWM_MIN;
				*smallerPwm = PWM_MIN;
			}
		}

	} /* namespace impl */
} /* namespace runmethod */
