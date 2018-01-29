/*
 * NoLine.h
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 *      Date: 2012/7/11 SATOSHI HANAMURA
 */

#ifndef NOLINE_H_
#define NOLINE_H_

#include "runmethod/impl/abstract/RunAbstract.h"

namespace runmethod {
	namespace impl {

		class NoLine: public runmethod::impl::RunAbstract {
			int m_forward;
			int m_turn;
			S32 m_motor_count_diff;
			bool m_is_initialized;
		public:

			/**
			 * 走行パラメータを設定
			 * @param[in] forward スピード
			 * @param[in] turn ターン
			 */
			NoLine(S16 forward, S16 turn);

			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] 色値
			 */
			void Control(F32 gyroOffset, int color);
			/**
			 * 直進補正
			 * @param[in] leftPw 左モーターに与える値
			 * @param[in] rightPw 右モーターに与える値
			 */
			void Straight_Correction(S8* leftPw, S8* rightPw, S32 motor_count_diff);
			/**
			 * 初期化
			 * @param[in] is_straight_run 直線フラグのbool変数
			 */
			void Initialization(bool* is_straight_run);
		};

	} /* namespace impl */
} /* namespace runmethod */
#endif /* NOLINE_H_ */
