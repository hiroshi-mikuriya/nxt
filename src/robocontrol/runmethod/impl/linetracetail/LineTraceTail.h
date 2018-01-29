/*
 * runLineTraceTail.h
 *
 *  Created on: 2012/07/04
 *      Author: NOBUHITO ONODA
 */

#ifndef LINETRACETAIL_H_
#define LINETRACETAIL_H_

#include "runmethod/impl/abstract/RunAbstract.h"
#include "Parameter.h"

namespace runmethod {
	namespace impl {

		class LineTraceTail: public runmethod::impl::RunAbstract {
			S16 m_forward;
			S16 m_turn;
			LINETRACE_EDGE m_edge;
		private:
			/**
			 * 左右モータのPwm値を設定
			 * @param color
			 * @param turn
			 * @param leftPwm
			 * @param rightPwm
			 */
			void SetPwm(int color, F32 turn, S8 & leftPwm, S8 & rightPwm);
		public:
			/**
			 * 走行パラメータを設定
			 * @param[in] forward スピード
			 * @param[in] turn ターン
			 * @param[in] angle 尻尾角度
			 * @param[in] edge エッジ
			 */
			LineTraceTail(S16 forward, S16 turn, LINETRACE_EDGE edge);

			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] color 色値
			 */
			virtual void Control(F32 gyroOffset, int color);
		};

	} /* namespace impl */
} /* namespace runmethod */
#endif /* LINETRACETAIL_H_ */
