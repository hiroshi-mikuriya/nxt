/*
 * IoEnabler.cpp
 *
 *  Created on: 2012/05/31
 *      Author: HIROSHI MIKURIYA
 */

#include "IoEnabler.h"
#include "Parameter.h"
#include "hardware/io/Io.h"

namespace instruction {
	namespace impl {

		int IoEnabler::DoInstruction(int enablePattern, int enabled)
		{
			hardware::Io & io = hardware::Io::GetInstance();
			if (enablePattern & LEFT_MOTOR_BIT)
				io.SetLeftMotorEnabled(!!enabled);
			if (enablePattern & RIGHT_MOTOR_BIT)
				io.SetRightMotorEnabled(!!enabled);
			if (enablePattern & TAIL_MOTOR_BIT)
				io.SetTailMotorEnabled(!!enabled);
			if (enablePattern & GYRO_BIT)
				io.SetGyroEnabled(!!enabled);
			if (enablePattern & LIGHT_BIT)
				io.SetLightEnabled(!!enabled);
			if (enablePattern & SONAR_BIT)
				io.SetSonarEnabled(!!enabled);
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
