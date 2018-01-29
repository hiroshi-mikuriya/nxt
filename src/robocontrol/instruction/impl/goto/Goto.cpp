/*
 * Goto.cpp
 *
 *  Created on: 2012/06/10
 *      Author: HIROSHI
 */

#include "Goto.h"
#include "controller/script/Script.h"

namespace instruction {
	namespace impl {

		int Goto::DoInstruction(int index, int isLabel)
		{
			controller::Script & script = controller::Script::GetInstance();
			return isLabel ? script.GetInstructionPointer(static_cast<LABEL>(index)) - script.GetInstructionPointer() : index;
		}

	} /* namespace impl */
} /* namespace instruction */
