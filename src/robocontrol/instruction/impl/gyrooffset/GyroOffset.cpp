/*
 * GyroOffset.cpp
 *
 *  Created on: 2012/05/26
 *      Author: HIROSHI MIKURIYA
 */

#include "GyroOffset.h"
#include "controller/log/Logger.h"
#include "controller/run/RunControl.h"

namespace instruction {
	namespace impl {

		int GyroOffset::DoInstruction(int unuse1, int unuse2)
		{
			controller::RunControl::GetInstance().SetGyroOffset(controller::Logger::GetInstance().GetGyroLog().GetAverage());
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
