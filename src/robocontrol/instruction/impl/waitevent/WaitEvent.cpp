/*
 * WaitEvent.cpp
 *
 *  Created on: 2012/06/09
 *      Author: HIROSHI
 */

#include "WaitEvent.h"
#include "event/impl/abstract/EventAbstract.h"
#include "event/parts/EventParts.h"
#include "hardware/timer/Timer.h"

namespace instruction {
	namespace impl {

		int WaitEvent::DoInstruction(int event1, int event2)
		{
			event::parts::EventWithIndex * e1 = 0;
			event::parts::EventWithIndex * e2 = 0;
			if (event1) {
				e1 = reinterpret_cast<event::parts::EventWithIndex*>(event1);
				e1->GetEvent().Initialize();
			}
			if (event2) {
				e2 = reinterpret_cast<event::parts::EventWithIndex*>(event2);
				e2->GetEvent().Initialize();
			}
			for (;;) {
				if (e1 && e1->GetEvent().Notify()) {
					return e1->GetIndex();
				}
				if (e2 && e2->GetEvent().Notify()) {
					return e2->GetIndex();
				}
				hardware::Timer::GetInstance().Sleep(20); // CPU負荷軽減のため
			}
			return 1; // eclipseの警告を消すため記述する
		}

	} /* namespace impl */
} /* namespace instruction */
