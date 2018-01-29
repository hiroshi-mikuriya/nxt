/*
 * Pid.h
 *
 *  Created on: 2012/06/04
 *      Author: HIROHITO OTAKE
 */

#ifndef PID_H_
#define PID_H_

#include "runmethod/impl/abstract/RunAbstract.h"
#include "utils/PidCalculation.hpp"
#include "Parameter.h"

namespace runmethod {
	namespace impl {

		class Pid: public runmethod::impl::RunAbstract {
		private:
			S16 m_forward;
			LINETRACE_EDGE m_edge;
			utils::PidCalculation<S16> m_pid;

		public:
			/**
			 * 走行パラメータを設定
			 * @param[in] forward
			 * @param[in] edge
			 */
			Pid(S16 forward, LINETRACE_EDGE edge, utils::PidCalculation<S16>::Parameter const & parameter);

			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] 色値
			 */
		private:
			/**
			 * 旋回度を返す
			 * @param[in] color 色値
			 * @return 旋回度
			 */
			S8 GetTurn(int color);

			/**
			 *  スピード・旋回度より、出力するPWM値をセットする
			 * @param[in] turn 旋回度
			 * @param[out] biggerPwm PWM値(大)
			 * @param[out] smallerPwm PWM値(小)
			 */
			void SetPwm(S8 turn, S8* biggerPwm, S8* smallerPwm);

			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] color 色値
			 */
			virtual void Control(F32 gyroOffset, int color);

		};

	} /* namespace impl */
} /* namespace runmethod */
#endif /* PID_H_ */
