/*
 * LineTrace.cpp
 *
 *  Created on: 2012/07/04
 *      Author: NOBUHITO ONODA
 */

#include "LineTraceTail.h"
#include "hardware/io/Io.h"

namespace runmethod {
	namespace impl {

		LineTraceTail::LineTraceTail(S16 forward, S16 turn, LINETRACE_EDGE edge)
				: m_forward(forward), m_turn(turn), m_edge(edge)
		{
		}

		void LineTraceTail::SetPwm(int color, F32 turn, S8 & leftPwm, S8 & rightPwm)
		{
			if (color < (COLOR_GRAY + COLOR_WHITE) / 2) {
				leftPwm = static_cast<S8>(m_edge == EDGE_LEFT ? m_forward - turn * 2 / 3 : m_forward + turn * 2 / 3);
				rightPwm = static_cast<S8>(m_edge == EDGE_LEFT ? m_forward + turn * 2 / 3 : m_forward - turn * 2 / 3);
			}
			else {
				leftPwm = static_cast<S8>(m_edge == EDGE_LEFT ? m_forward + m_turn * 2 / 3 : m_forward - m_turn * 2 / 3);
				rightPwm = static_cast<S8>(m_edge == EDGE_LEFT ? m_forward - m_turn * 2 / 3 : m_forward + m_turn * 2 / 3);
			}
		}

		void LineTraceTail::Control(F32 gyroOffset, int color)
		{
			F32 const thresh = (COLOR_GRAY + COLOR_WHITE) / 2;
			F32 turn = color < thresh ? m_turn : -m_turn;
			if (m_edge == EDGE_RIGHT) {
				turn = -turn;
			}
			S8 leftPwm;
			S8 rightPwm;
			SetPwm(color, turn, leftPwm, rightPwm);
			hardware::Io::GetInstance().SetPwm(leftPwm, rightPwm);
		}

	} /* namespace impl */
} /* namespace runmethod */
