/*
 * UserInstruction.cpp
 *
 *  Created on: 2012/06/05
 *      Author: HIROSHI MIKURIYA
 */

#include "UserInstruction.h"

namespace instruction {
	namespace impl {

		int UserInstruction::DoInstruction(int userInstruction, int unuse)
		{
			return reinterpret_cast<userInstructionT>(userInstruction)();
		}

	} /* namespace impl */
} /* namespace instruction */
