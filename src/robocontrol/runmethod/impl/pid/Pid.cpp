/*
 * Pid.cpp
 *
 *  Created on: 2012/06/04
 *      Author: HIROHITO OTAKE
 */

#include "Pid.h"
#include "hardware/io/Io.h"
#include "Common.h"
#include "hardware/body/Body.h"

extern "C" {
#include "balancer.h"
}

namespace runmethod {
	namespace impl {

		namespace {
			const S16 TURN_MAX = 100;
			const S16 TURN_MIN = -100;
			const S8 PWM_MAX = 100;
			const S8 PWM_MIN = -100;
		}

		Pid::Pid(S16 forward, LINETRACE_EDGE edge, utils::PidCalculation<S16>::Parameter const & parameter)
				: m_forward(forward), m_edge(edge), m_pid(parameter)
		{
		}

		void Pid::Control(F32 gyroOffset, int color)
		{
			S8 leftPwm;
			S8 rightPwm;
			S8 turn = GetTurn(color);
			if (m_edge == EDGE_RIGHT) {
				turn = -turn;
			}
			hardware::Io & io = hardware::Io::GetInstance();
			balance_control(m_forward, turn/*GetTurn(color)*/, io.GetGyro(), gyroOffset, io.GetLeftMotorCount(), io.GetRightMotorCount(), hardware::Body::GetInstance().GetBattMv(), &leftPwm, &rightPwm);
			io.SetPwm(leftPwm, rightPwm);
		}

		S8 Pid::GetTurn(int color)
		{
			return compress_cast<S16, TURN_MIN, TURN_MAX>(m_pid.Calculate(color));
		}

		void Pid::SetPwm(S8 turn, S8* biggerPwm, S8* smallerPwm)
		{
			*biggerPwm = m_forward + turn / 2;
			*smallerPwm = m_forward - turn / 2;
			if ((*biggerPwm) > PWM_MAX) {
				*biggerPwm = PWM_MAX;
				*smallerPwm -= (*biggerPwm) - PWM_MAX;
			}
			else if ((*smallerPwm) < PWM_MIN) {
				*smallerPwm = PWM_MIN;
				*biggerPwm += (*smallerPwm) - PWM_MIN;
			}
		}

	} /* namespace impl */
} /* namespace runmethod */
