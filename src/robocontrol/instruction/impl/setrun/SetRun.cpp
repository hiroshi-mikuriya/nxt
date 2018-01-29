/*
 * SetRun.cpp
 *
 *  Created on: 2012/06/09
 *      Author: HIROSHI
 */

#include "SetRun.h"
#include "controller/run/RunControl.h"

namespace instruction {
	namespace impl {

		int SetRun::DoInstruction(int runmethod, int unuse)
		{
			runmethod::impl::RunAbstract * run = reinterpret_cast<runmethod::impl::RunAbstract *>(runmethod);
			run->Initialize();
			controller::RunControl::GetInstance().SetRunMethod(run);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
