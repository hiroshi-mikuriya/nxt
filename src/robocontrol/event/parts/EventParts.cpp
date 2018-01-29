/*
 * Event.cpp
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#include "EventParts.h"

namespace event {
	namespace parts {

		Event & Event::operator=(Event const & that)
		{
			this->m_event = that.m_event;
			this->m_param1 = that.m_param1;
			this->m_param2 = that.m_param2;
			return *this;
		}

		Event::Event()
				: m_event(0), m_param1(0), m_param2(0)
		{
		}

		Event::Event(event::impl::EventAbstract & event, S16 param1, S16 param2)
				: m_event(&event), m_param1(param1), m_param2(param2)
		{
		}

		void Event::Initialize()
		{
			if (m_event)
				m_event->Initialize(m_param1, m_param2);
		}

		bool Event::Notify() const
		{
			return m_event ? m_event->Notify() : false;
		}

		EventWithIndex & EventWithIndex::operator=(EventWithIndex const & that)
		{
			this->m_event = that.m_event;
			this->m_index = that.m_index;
			return *this;
		}

		EventWithIndex::EventWithIndex(Event const & event, S16 index)
				: m_event(event), m_index(index)
		{
		}

		Event & EventWithIndex::GetEvent()
		{
			return m_event;
		}
		S16 EventWithIndex::GetIndex() const
		{
			return m_index;
		}

		EventWithIndex operator>>(Event const & event, S16 index)
		{
			return EventWithIndex(event, index);
		}

	}
}
