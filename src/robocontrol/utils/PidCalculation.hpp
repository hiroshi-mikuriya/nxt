/*
 * PidCalculation.hpp
 *
 *  Created on: 2012/06/16
 *      Author: KOUICHIRO HONDA
 */

#ifndef PIDCALCULATION_HPP_
#define PIDCALCULATION_HPP_

#include "hardware/timer/Timer.h"
#include "ecrobot_interface.h"

namespace utils {

	template<typename AnyType>
	class PidCalculation {
	public:
		/**
		 * PID制御に使用するパラメータ
		 */
		struct Parameter {
			F32 pGain; /**< 比例ゲイン */
			F32 iGain; /**< 積分ゲイン */
			F32 dGain; /**< 微分ゲイン */
			AnyType target; /**< 目標値 */
			/**
			 * PID制御に使用するパラメータを設定
			 * @param[in] p 比例ゲイン
			 * @param[in] i 積分ゲイン
			 * @param[in] d 微分ゲイン
			 * @param[in] t 目標値
			 */
			Parameter(F32 p, F32 i, F32 d, AnyType t)
					: pGain(p), iGain(i), dGain(d), target(t)
			{
			}
		};
	private:
		Parameter const & m_parameter;
		AnyType m_previousDiff;
		U32 m_previousTimeInMS;
		F32 m_integral;

	public:
		/**
		 * PIDパラメータとPID制御の目標値を設定
		 * @param[in] parameter PIDパラメータ
		 * @param[in] target 目標値
		 */
		PidCalculation(Parameter const & parameter)
				: m_parameter(parameter), m_previousDiff(), m_previousTimeInMS(::hardware::Timer::GetInstance().GetTime()), m_integral()
		{
		}

		/**
		 * PID制御により出力値を計算する
		 * @param[in] input 入力値
		 * @return 出力値
		 */
		AnyType Calculate(AnyType input)
		{
			AnyType diffValue = input - m_parameter.target;
			F32 intervalInSec = UpdateTime();
			F32 ret = Proportional(diffValue) + Integral(diffValue, intervalInSec) + Derivative(diffValue, intervalInSec);
			m_previousDiff = diffValue;
			return static_cast<AnyType>(ret);
		}

	private:
		/**
		 * PID制御に使用する時間の更新を行う
		 * @return 前回制御から今回制御まで間隔 [sec]
		 */
		F32 UpdateTime()
		{
			S32 currentTimeInMS = ::hardware::Timer::GetInstance().GetTime();
			F32 intervalInSec = (currentTimeInMS - m_previousTimeInMS) / 1000.0f;
			m_previousTimeInMS = currentTimeInMS;
			return intervalInSec;
		}

		/**
		 * P制御による操作量を計算する
		 * @param[in] diffValue 入力値と目標値との差
		 * @return P制御による操作量
		 */
		F32 Proportional(AnyType diffValue)
		{
			return m_parameter.pGain * diffValue;
		}

		/**
		 * I制御による操作量を計算する
		 * @param[in] diffValue 入力値と目標値との差
		 * @param[in] intervalInSec 前回の制御と今回の制御との間隔 [sec]
		 * @return I制御による操作量
		 */
		F32 Integral(AnyType diffValue, F32 intervalInSec)
		{
			m_integral += (m_previousDiff + diffValue) / 2.0f * intervalInSec;
			return m_parameter.iGain * m_integral;
		}

		/**
		 * D制御による操作量を計算する
		 * @param[in] diffValue 入力値と目標値との差
		 * @param[in] intervalInSec 前回の制御と今回の制御との間隔 [sec]
		 * @return D制御による操作量
		 */
		F32 Derivative(AnyType diffValue, F32 intervalInSec)
		{
			return m_parameter.dGain * (diffValue - m_previousDiff) / intervalInSec;
		}

	};

} /* namespace utils */

#endif /* PIDCALCULATION_HPP_ */
