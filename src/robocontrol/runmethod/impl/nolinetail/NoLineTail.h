/*
 * NoLineTail.h
 *
 *  Created on: 2012/07/03
 *      Author: SATOSHI HANAMURA
 */

#ifndef NOLINETAIL_H_
#define NOLINETAIL_H_

#include "runmethod/impl/abstract/RunAbstract.h"
#include "Parameter.h"

namespace runmethod {
	namespace impl {

		class NoLineTail: public runmethod::impl::RunAbstract {
			int m_pw;
			NOLINETAIL_RUN_TYPE m_run_type;
			S32 m_motor_count_diff;
			bool m_is_initialized;
		public:
			/**
			 * 走行パラメータを設定
			 * @param[in] forward スピード
			 * @param[in] turn ターン
			 */
			NoLineTail(NOLINETAIL_RUN_TYPE Run_Type, S16 Pw);

			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] 色値
			 */
			void Control(F32 gyroOffset, int color);
			/**
			 * モーターに与える値の制御
			 * @param[in] leftPw 左モーターに与える値
			 * @param[in] rightPw 右モーターに与える値
			 */
			void GetPw(S8* leftPw, S8* rightPw);
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
#endif /* NOLINETAIL_H_ */
