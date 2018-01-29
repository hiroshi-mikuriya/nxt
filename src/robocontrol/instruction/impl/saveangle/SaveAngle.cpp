/*
 * SaveAngle.cpp
 *
 *  Created on: 2012/05/12
 *      Author: HIROSHI MIKURIYA
 */

#include "SaveAngle.h"
#include "controller/save/SaveData.h"

namespace instruction {
	namespace impl {

		int SaveAngle::DoInstruction(int index, int unuse)
		{
			controller::SaveData::GetInstance().SaveAngle(index);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
