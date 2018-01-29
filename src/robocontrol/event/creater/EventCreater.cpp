/*
 * EventCreater.cpp
 *
 *  Created on: 2012/06/05
 *      Author: HIROSHI MIKURIYA
 */

#include "EventCreater.h"
#include "event/impl/time/Time.h"
#include "event/impl/distance/Distance.h"
#include "event/impl/touch/Touch.h"
#include "event/impl/angle/Angle.h"
#include "event/impl/next/Next.h"
#include "event/impl/sonar/Sonar.h"
#include "event/impl/collision/Collision.h"
#include "event/impl/falldown/Falldown.h"
#include "event/impl/black/Black.h"
#include "event/impl/white/White.h"
#include "event/impl/gray/Gray.h"
#include "event/impl/bluetooth/Bluetooth.h"

namespace event {
	namespace creater {

		namespace {
			impl::Time s_time;
			impl::Distance s_distance;
			impl::Touch s_touch;
			impl::Angle s_angle;
			impl::Next s_next;
			impl::Sonar s_sonar;
			impl::Collision s_collision;
			impl::Falldown s_falldown;
			impl::Black s_black;
			impl::White s_white;
			impl::Gray s_gray;
			impl::Bluetooth s_bluetooth;
		}

		EventNone::operator parts::Event()
		{
			return parts::Event();
		}

		EventNone::operator parts::EventWithIndex()
		{
			return parts::EventWithIndex(*this, 0);
		}

		parts::Event Time::operator()(int time_ms, int index)
		{
			return parts::Event(s_time, time_ms, index);
		}

		parts::Event Time::operator()(int time_ms)
		{
			return (*this)(time_ms, -1);
		}

		parts::Event Distance::operator()(int length_mm, int index)
		{
			return parts::Event(s_distance, length_mm, index);
		}

		parts::Event Distance::operator()(int length_mm)
		{
			return (*this)(length_mm, -1);
		}

		Touch::operator parts::Event()
		{
			return parts::Event(s_touch, 0, 0);
		}
		parts::EventWithIndex Touch::operator>>(S16 index)
		{
			return parts::EventWithIndex(parts::Event(s_touch, 0, 0), index);
		}

		parts::Event Angle::operator()(int angle, int index)
		{
			return parts::Event(s_angle, angle, index);
		}

		parts::Event Angle::operator()(int angle)
		{
			return (*this)(angle, -1);
		}

		Next::operator parts::Event()
		{
			return parts::Event(s_next, 0, 0);
		}
		parts::EventWithIndex Next::operator>>(S16 index)
		{
			return parts::EventWithIndex(parts::Event(s_next, 0, 0), index);
		}

		parts::Event Sonar::operator()(int distance)
		{
			return parts::Event(s_sonar, distance, 0);
		}

		Collision::operator parts::Event()
		{
			return parts::Event(s_collision, 0, 0);
		}
		parts::EventWithIndex Collision::operator>>(S16 index)
		{
			return parts::EventWithIndex(parts::Event(s_collision, 0, 0), index);
		}

		Falldown::operator parts::Event()
		{
			return parts::Event(s_falldown, 0, 0);
		}
		parts::EventWithIndex Falldown::operator>>(S16 index)
		{
			return parts::EventWithIndex(parts::Event(s_falldown, 0, 0), index);
		}

		Black::operator parts::Event()
		{
			return parts::Event(s_black, 0, 0);
		}
		parts::EventWithIndex Black::operator>>(S16 index)
		{
			return parts::EventWithIndex(parts::Event(s_black, 0, 0), index);
		}

		White::operator parts::Event()
		{
			return parts::Event(s_white, 0, 0);
		}
		parts::EventWithIndex White::operator>>(S16 index)
		{
			return parts::EventWithIndex(parts::Event(s_white, 0, 0), index);
		}

		Gray::operator parts::Event()
		{
			return parts::Event(s_gray, 0, 0);
		}
		parts::EventWithIndex Gray::operator>>(S16 index)
		{
			return parts::EventWithIndex(parts::Event(s_gray, 0, 0), index);
		}

		parts::Event Bluetooth::operator()(RECIEVE_TYPE type)
		{
			return parts::Event(s_bluetooth, static_cast<int>(type), 0);
		}
		parts::EventWithIndex Bluetooth::operator>>(S16 index)
		{
			return parts::EventWithIndex(parts::Event(s_bluetooth, 0, 0), index);
		}

	} /* namespace impl */
} /* namespace event */

