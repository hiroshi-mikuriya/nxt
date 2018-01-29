/*
 * White.h
 *
 *  Created on: 2012/06/20
 *      Author: YUKI SHIMIZU
 */

#ifndef WHITE_H_
#define WHITE_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		/**
		 * 白検知
		 */
		class White: public event::impl::EventAbstract {

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

#endif /* WHITE_H_ */
