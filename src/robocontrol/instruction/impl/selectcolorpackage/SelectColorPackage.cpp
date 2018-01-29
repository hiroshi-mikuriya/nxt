/*
 * SelectColorPackage.cpp
 *
 *  Created on: 2012/05/28
 *      Author: HIROSHI MIKURIYA
 */

#include "SelectColorPackage.h"
#include "controller/run/RunControl.h"

namespace instruction {
	namespace impl {

		int SelectColorPackage::DoInstruction(int index, int unuse)
		{
			controller::RunControl::GetInstance().SelectPackage(index);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
