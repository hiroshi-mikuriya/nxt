/*
 * Interrupt.h
 *
 *  Created on: 2012/07/31
 *      Author: HIROSHI MIKURIYA
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "event/parts/EventParts.h"

namespace controller {

	class Interrupt {
	public:
		/**
		 * イベントとそれが発生したときに行う動作のペア
		 */
		struct EventProcT {
			event::parts::Event m_event;
			void (*m_proc)();
		};

	private:

		Interrupt();

		bool m_enable;

		EventProcT * m_begin;
		EventProcT * m_end;
	public:
		static Interrupt & GetInstance();

		void Do();

		void Set(EventProcT * begin, EventProcT * end);

		void Enable(bool enable);
	};

} /* namespace controller */
#endif /* INTERRUPT_H_ */
