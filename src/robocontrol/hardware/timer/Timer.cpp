/*
 * Timer.cpp
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 */

#include "Timer.h"
#include <Clock.h>

namespace hardware {
	namespace {
		ecrobot::Clock s_clock;
	}
	Timer::Timer()
	{
	}

	Timer & Timer::GetInstance()
	{
		static Timer timer;
		return timer;
	}

	U32 Timer::GetTime() const
	{
		return s_clock.now();
	}

	void Timer::Wait(U32 time_mm)
	{
		s_clock.wait(time_mm);
	}

	void Timer::Sleep(U32 time_mm)
	{
		s_clock.sleep(time_mm);
	}

} /* namespace hardware */
