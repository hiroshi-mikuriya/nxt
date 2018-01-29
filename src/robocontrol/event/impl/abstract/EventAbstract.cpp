/*
 * EventAbstract.cpp
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#include "EventAbstract.h"

namespace event {
	namespace impl {

		EventAbstract::~EventAbstract()
		{
		}

		/**
		 * イベント検知
		 * @return 検知有無
		 */
		bool EventAbstract::Notify() const
		{
			return false;
		}

	} /* impl */
} /* namespace event */
