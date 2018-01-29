/*
 * Label.cpp
 *
 *  Created on: 2012/07/19
 *      Author: HIROSHI MIKURIYA
 */

#include "Label.h"
#include "Parameter.h"
#include "controller/script/Script.h"

namespace instruction {
	namespace impl {

		void Label::Initialize(int label, int unuse, void * p)
		{
			controller::Script::GetInstance().SetLabel(static_cast<parts::Instruction*>(p), static_cast<LABEL>(label));

		}

		int Label::DoInstruction(int unuse1, int unuse2)
		{
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
