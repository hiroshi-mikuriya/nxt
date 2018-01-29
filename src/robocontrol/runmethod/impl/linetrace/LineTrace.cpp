/*
 * LineTrace.cpp
 *
 *  Created on: 2012/05/23
 *      Author: HIROSHI MIKURIYA
 */

#include "LineTrace.h"
#include "hardware/io/Io.h"
#include "hardware/body/Body.h"

extern "C" {
#include "balancer.h"
}

namespace runmethod {
	namespace impl {

		LineTrace::LineTrace(S16 forward, S16 turn, LINETRACE_EDGE edge)
				: m_forward(forward), m_turn(turn), m_edge(edge)
		{
		}

		void LineTrace::Control(F32 gyroOffset, int color)
		{
			hardware::Io & io = hardware::Io::GetInstance();
			S8 leftPwm;
			S8 rightPwm;
			F32 const thresh = (COLOR_GRAY + COLOR_WHITE) / 2;
			F32 turn = color < thresh ? m_turn : -m_turn;
			if (m_edge == EDGE_LEFT) {
				turn = -turn;
			}
			balance_control(m_forward, turn, io.GetGyro(), gyroOffset, io.GetLeftMotorCount(), io.GetRightMotorCount(), hardware::Body::GetInstance().GetBattMv(), &leftPwm, &rightPwm);
			io.SetPwm(leftPwm, rightPwm);
		}

	} /* namespace impl */
} /* namespace runmethod */
