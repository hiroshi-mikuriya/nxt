/*
 * Next.h
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 */

#ifndef NEXT_H_
#define NEXT_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		class Next: public event::impl::EventAbstract {
		public:

			/**
			 * 初期化
			 * @note 何も行わない
			 */
			virtual void Initialize(int unuse1, int unuse2);
			/**
			 * 検知有無
			 * @return 検知有無
			 * @note 必ずtrueを返す
			 */
			virtual bool Notify() const;
		};

	} /* namespace impl */
} /* namespace event */
#endif /* NEXT_H_ */
