/*
 * Stop.cpp
 *
 *  Created on: 2012/05/24
 *      Author: HIROSHI MIKURIYA
 */

#include "Stop.h"
#include "hardware/io/Io.h"

namespace runmethod {
	namespace impl {

		void Stop::Control(F32 gyroOffset, int color)
		{
			hardware::Io::GetInstance().SetPwm(0, 0);
		}

	} /* namespace impl */
} /* namespace runmethod */
