/*
 * Black.h
 *
 *  Created on: 2012/06/20
 *      Author: YUKI SHIMIZU
 */

#ifndef BLACK_H_
#define BLACK_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		/**
		 * 黒検知
		 */
		class Black: public event::impl::EventAbstract {

		public:

			/**
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

#endif /* BLACK_H_ */
