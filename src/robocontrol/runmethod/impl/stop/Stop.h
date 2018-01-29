/*
 * Stop.h
 *
 *  Created on: 2012/05/24
 *      Author: HIROSHI MIKURIYA
 */

#ifndef RUN_STOP_H_
#define RUN_STOP_H_

#include "runmethod/impl/abstract/RunAbstract.h"

namespace runmethod {
	namespace impl {

		class Stop: public runmethod::impl::RunAbstract {
		public:
			/**
			 * 走行制御
			 * @param[in] gyroOffset ジャイロオフセット値
			 * @param[in] 色値
			 */
			virtual void Control(F32 gyroOffset, int color);
		};

	} /* namespace impl */
} /* namespace runmethod */
#endif /* RUN_STOP_H_ */
