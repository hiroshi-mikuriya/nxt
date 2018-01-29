/*
 * PidTail.h
 *
 *  Created on: 2012/06/16
 *      Author: KOUICHIRO HONDA
 */

#ifndef PIDTAIL_H_
#define PIDTAIL_H_

#include "runmethod/impl/abstract/RunAbstract.h"
#include "utils/PidCalculation.hpp"
#include "Parameter.h"

namespace runmethod {
	namespace impl {

		class PidTail: public ::runmethod::impl::RunAbstract {
		private:
			S16 m_forward;
			LINETRACE_EDGE m_edge;
			utils::PidCalculation<S16> m_pid;

		public:
			/**
			 * 走行パラメータを設定
			 * @param[in] forward スピード
			 * @param[in] edge ライントレースのエッジ
			 * @param[in] parameter 使用するPID制御のパラメータ
			 */
			PidTail(S16 forward, LINETRACE_EDGE edge, utils::PidCalculation<S16>::Parameter const & parameter);

			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] color 色値
			 */
			virtual void Control(F32 gyroOffset, int color);

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
			 * @param[out] blackSidePwm PWM値(黒側)
			 * @param[out] smallerPwm PWM値(白側)
			 */
			void SetPwm(S8 turn, S16* blackSidePwm, S16* whiteSidePwm);

			/**
			 * @param[in,out] biggerPwm PWM値(大)
			 * @param[in,out] smallerPwm PWM値(小)
			 */
			void ValidatePwm(S16* biggerPwm, S16* smallerPwm);
		};

	} /* namespace impl */
} /* namespace runmethod */

#endif /* PIDTAIL_H_ */
