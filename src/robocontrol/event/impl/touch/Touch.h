/*
 * Touch.h
 *
 *  Created on: 2012/05/19
 *      Author: HIROSHI MIKURIYA
 */

#ifndef TOUCH_H_
#define TOUCH_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		class Touch: public event::impl::EventAbstract {
		public:
			/**
			 * 初期化
			 * @param[in] unuse1 未使用
			 * @param[in] unuse2 未使用
			 * @note 何もしない
			 */
			virtual void Initialize(int unuse1, int unuse2);
			/**
			 * 検知有無
			 * @return 検知有無
			 */
			virtual bool Notify() const;
		};

	} /* namespace impl */
} /* namespace event */
#endif /* TOUCH_H_ */
