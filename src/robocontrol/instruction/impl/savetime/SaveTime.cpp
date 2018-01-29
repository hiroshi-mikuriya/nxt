/*
 * SaveTime.cpp
 *
 *  Created on: 2012/05/19
 *      Author: HIROSHI MIKURIYA
 */

#include "SaveTime.h"
#include "controller/save/SaveData.h"

namespace instruction {
	namespace impl {

		int SaveTime::DoInstruction(int index, int unuse)
		{
			controller::SaveData::GetInstance().SaveTime(index);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
