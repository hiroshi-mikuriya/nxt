/*
 * InterruptEnable.cpp
 *
 *  Created on: 2012/07/31
 *      Author: HIROSHI
 */

#include "InterruptEnable.h"
#include "controller/interrupt/Interrupt.h"

namespace instruction {
	namespace impl {

		int InterruptEnable::DoInstruction(int enable, int unuse)
		{
			controller::Interrupt::GetInstance().Enable(!!enable);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
