/*
 * LineTrace.h
 *
 *  Created on: 2012/05/23
 *      Author: HIROSHI MIKURIYA
 */

#ifndef LINETRACE_H_
#define LINETRACE_H_

#include "runmethod/impl/abstract/RunAbstract.h"
#include "Parameter.h"

namespace runmethod {
	namespace impl {

		class LineTrace: public runmethod::impl::RunAbstract {
			S16 m_forward;
			S16 m_turn;
			LINETRACE_EDGE m_edge;
		public:
			/**
			 * 走行パラメータを設定
			 * @param[in] forward スピード
			 * @param[in] turn ターン
			 * @param[in] edge エッジ
			 */
			LineTrace(S16 forward, S16 turn, LINETRACE_EDGE edge);

			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] 色値
			 */
			virtual void Control(F32 gyroOffset, int color);
		};

	} /* namespace impl */
} /* namespace runmethod */
#endif /* LINETRACE_H_ */
