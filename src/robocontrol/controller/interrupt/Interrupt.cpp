/*
 * Interrupt.cpp
 *
 *  Created on: 2012/07/31
 *      Author: HIROSHI MIKURIYA
 */

#include "Interrupt.h"
#include "hardware/timer/Timer.h"

namespace controller {

	Interrupt::Interrupt()
			: m_enable(false)
	{
	}

	Interrupt & Interrupt::GetInstance()
	{
		static Interrupt interrupt;
		return interrupt;
	}

	void Interrupt::Do()
	{
		hardware::Timer & timer = hardware::Timer::GetInstance();
		for (;;) {
			for (EventProcT * p = m_begin; m_enable && p != m_end; ++p) {
				timer.Sleep(20);
				if (p->m_event.Notify()) {
					p->m_proc();
				}
			}
			timer.Sleep(20);
		}

	}

	void Interrupt::Set(EventProcT * begin, EventProcT * end)
	{
		m_begin = begin;
		m_end = end;
		for (EventProcT * p = m_begin; p != m_end; ++p) {
			p->m_event.Initialize();
		}
	}

	void Interrupt::Enable(bool enable)
	{
		m_enable = enable;
	}
} /* namespace controller */
