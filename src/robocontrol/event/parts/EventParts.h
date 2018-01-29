/*
 * Event.h
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "event/impl/abstract/EventAbstract.h"
#include "ecrobot_interface.h"

namespace event {
	namespace parts {

		class Event {
			event::impl::EventAbstract * m_event;
			S16 m_param1;
			S16 m_param2;
		public:
			Event & operator=(Event const & that);
			Event();
			Event(event::impl::EventAbstract & event, S16 param1, S16 param2);

			void Initialize();
			bool Notify() const;
		};

		class EventWithIndex {
			Event m_event;
			S16 m_index;
		public:
			EventWithIndex & operator=(EventWithIndex const & that);
			EventWithIndex(Event const & event, S16 index);

			Event & GetEvent();
			S16 GetIndex() const;
		};

		EventWithIndex operator>>(Event const & event, S16 index);

	} /* namespace parts */
} /* namespace event */
#endif /* EVENT_H_ */
