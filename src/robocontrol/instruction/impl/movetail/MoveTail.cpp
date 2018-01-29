/*
 * MoveTail.cpp
 *
 *  Created on: 2012/05/12
 *      Author: HIROSHI MIKURIYA
 */

#include "MoveTail.h"
#include "controller/tail/TailControl.h"

namespace instruction {
	namespace impl {

		int MoveTail::DoInstruction(int angle, int unuse)
		{
			controller::TailControl::GetInstance().SetAngle(angle);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
