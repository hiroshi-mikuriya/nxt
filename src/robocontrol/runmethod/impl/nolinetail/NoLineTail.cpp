/*
 * NoLineTail.cpp
 *
 *  Created on: 2012/07/03
 *      Author: SATOSHI HANAMURA
 */

#include "NoLineTail.h"
#include "hardware/io/Io.h"
#include "hardware/body/Body.h"
#include "instruction/creater/InstructionCreater.h"
extern "C" {
}

namespace runmethod {
	namespace impl {

		NoLineTail::NoLineTail(NOLINETAIL_RUN_TYPE Run_Type, S16 Pw)
				: m_pw(Pw), m_run_type(Run_Type), m_motor_count_diff(0), m_is_initialized(false)
		{
		}

		void NoLineTail::Control(F32 gyroOffset, int color)
		{
			hardware::Io & io = hardware::Io::GetInstance();
			S8 leftPw;
			S8 rightPw;
			GetPw(&leftPw, &rightPw);
			io.SetPwm(leftPw, rightPw);

		}
		void NoLineTail::GetPw(S8* leftPw, S8* rightPw)
		{
			static bool m_straight_flag;
			hardware::Io & io = hardware::Io::GetInstance();

			/*
			 * 初期化
			 */
			if (m_is_initialized == false) {
				Initialization(&m_straight_flag);
			}
			if (m_run_type == RUN_MODE) {
				/*
				 * 直進補正のフラグを有効にする。
				 */
				if (m_straight_flag == false) {
					m_motor_count_diff = io.GetLeftMotorCount() - io.GetRightMotorCount();
					m_straight_flag = true;
				}
				*leftPw = m_pw;
				*rightPw = m_pw;
				Straight_Correction(leftPw, rightPw, io.GetLeftMotorCount() - io.GetRightMotorCount());

			}
			else {
				*leftPw = m_pw;
				*rightPw = (-1) * m_pw;
				m_straight_flag = false;
			}
		}
		void NoLineTail::Straight_Correction(S8* leftPw, S8* rightPw, S32 motor_count_diff)
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
		void NoLineTail::Initialization(bool* is_straight_run)
		{
			*is_straight_run = false;
			m_is_initialized = true;
		}
	} /* namespace impl */
} /* namespace runmethod */

