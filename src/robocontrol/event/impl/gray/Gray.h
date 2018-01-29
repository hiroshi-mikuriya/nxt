/*
 * Gray.h
 *
 *  Created on: 2012/08/01
 *      Author: HIROSHI MIKURIYA
 */

#ifndef GRAY_H_
#define GRAY_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		class Gray: public event::impl::EventAbstract {
		public:
			/**
			 * 初期化
			 * @param unuse1 未使用
			 * @param unuse2 未使用
			 */
			virtual void Initialize(int unuse1, int unuse2);
			/**
			 * 灰色マーカー検知有無
			 * @return 検知有無
			 */
			virtual bool Notify() const;
		};

	} /* namespace impl */
} /* namespace event */
#endif /* GRAY_H_ */
