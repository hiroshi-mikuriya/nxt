/*
 * RunAbstract.h
 *
 *  Created on: 2012/05/23
 *      Author: HIROSHI MIKURIYA
 */

#ifndef RUNABSTRACT_H_
#define RUNABSTRACT_H_

#include "ecrobot_interface.h"

namespace runmethod {
	namespace impl {

		class RunAbstract {
		public:
			virtual ~RunAbstract();

			/**
			 *  初期化する
			 */
			virtual void Initialize();
			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] 色値
			 */
			virtual void Control(F32 gyroOffset, int color)=0;
		};

	} /* namespace impl */
} /* namespace runmethod */
#endif /* RUNABSTRACT_H_ */
