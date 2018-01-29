/*
 * Falldown.h
 *
 *  Created on: 2012/08/05
 *      Author: YUKI SHIMIZU
 */

#ifndef FALLDOWN_H_
#define FALLDOWN_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		/**
		 * 衝突検知
		 */
		class Falldown: public event::impl::EventAbstract {

		public:

			/**
			 * 検知するしきい値を指定
			 * @param[in] unuse1 未使用
			 * @param[in] unuse2 未使用
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

#endif /* FALLDOWN_H_ */
