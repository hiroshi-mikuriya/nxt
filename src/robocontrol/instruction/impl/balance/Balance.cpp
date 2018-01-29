/*
 * BalanceInit.cpp
 *
 *  Created on: 2012/05/12
 *      Author: HIROSHI MIKURIYA
 */

#include "Balance.h"
#include "hardware/io/Io.h"
#include "controller/position/Position.h"

extern "C" {
#include "balancer.h"
}

namespace instruction {
	namespace impl {

		int Balance::DoInstruction(int unuse1, int unuse2)
		{
			balance_init();
			hardware::Io::GetInstance().InitTireMotorCount();
			controller::Position::GetInstance().ClearPrevMotorCount();
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
