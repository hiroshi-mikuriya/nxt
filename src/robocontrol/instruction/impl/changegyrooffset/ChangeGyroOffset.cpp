/*
 * ChangeGyroOffset.cpp
 *
 *  Created on: 2012/07/19
 *      Author: NOBUHITO ONODA & HIROHITO OTAKE
 */

#include "ChangeGyroOffset.h"
#include "controller/run/RunControl.h"

namespace instruction {
	namespace impl {

		int ChangeGyroOffset::DoInstruction(int gyro, int unuse)
		{
			controller::RunControl::GetInstance().ChangeGyroOffset(gyro);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
