/*
 * NoLine.cpp
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 *      Date: 2012/7/11 SATOSHI HANAMURA
 */

#include "NoLine.h"
#include "hardware/io/Io.h"
#include "hardware/body/Body.h"

extern "C" {
#include "balancer.h"
}

namespace runmethod {
	namespace impl {

		NoLine::NoLine(S16 forward, S16 turn)
				: m_forward(forward), m_turn(turn), m_motor_count_diff(0), m_is_initialized(false)
		{
			hardware::Io & io = hardware::Io::GetInstance();
			m_motor_count_diff = io.GetLeftMotorCount() - io.GetRightMotorCount();
		}

		void NoLine::Control(F32 gyroOffset, int color)
		{
			hardware::Io & io = hardware::Io::GetInstance();
			static bool m_straight_flag;
			S8 leftPw;
			S8 rightPw;
			balance_control(m_forward, m_turn, io.GetGyro(), gyroOffset, io.GetLeftMotorCount(), io.GetRightMotorCount(), hardware::Body::GetInstance().GetBattMv(), &leftPw, &rightPw);
			/*
			 * 初期化
			 */
			if (m_is_initialized == false) {
				Initialization(&m_straight_flag);
			}
			/*
			 * turnが0だったときは直進補正をかける
			 */
			if (m_turn == 0) {
				/*
				 * 直進補正のフラグを有効にする。
				 */
				if (m_straight_flag == false) {
					m_motor_count_diff = io.GetLeftMotorCount() - io.GetRightMotorCount();
					m_straight_flag = true;
				}

				Straight_Correction(&leftPw, &rightPw, io.GetLeftMotorCount() - io.GetRightMotorCount());
			}
			/*
			 * 直進補正のフラグを無効にする。
			 */
			else {
				m_straight_flag = false;
			}
			io.SetPwm(leftPw, rightPw); //"gray : ", run.GetGray(index), 3,
		}
		void NoLine::Straight_Correction(S8* leftPw, S8* rightPw, S32 motor_count_diff)
		{
			/*
			 * 直進を始めたときの両輪のカウントの差と現在の差を比較して補正をかける。
			 * 補正値 5 は適当に決めたので変更する可能性あり。
			 */
			if (m_motor_count_diff > motor_count_diff) {
				*leftPw += 5;
			}
			else if (motor_count_diff > m_motor_count_diff) {
				*rightPw += 5;
			}
			else {
				/*
				 Nothing
				 */
			}
		}
		void NoLine::Initialization(bool* is_straight_run)
		{
			*is_straight_run = false;
			m_is_initialized = true;
		}
	} /* namespace impl */
} /* namespace runmethod */
