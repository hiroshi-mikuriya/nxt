/*
 * SavePosition.cpp
 *
 *  Created on: 2012/05/12
 *      Author: HIROSHI MIKURIYA
 */

#include "SavePosition.h"
#include "controller/save/SaveData.h"

namespace instruction {
	namespace impl {

		int SavePosition::DoInstruction(int index, int unuse)
		{
			controller::SaveData::GetInstance().SavePosition(index);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
