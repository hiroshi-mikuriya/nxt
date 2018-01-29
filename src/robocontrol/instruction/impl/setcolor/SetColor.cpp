/*
 * SetColor.cpp
 *
 *  Created on: 2012/05/26
 *      Author: HIROSHI MIKURIYA
 */

#include "SetColor.h"
#include "controller/run/RunControl.h"
#include "controller/log/Logger.h"

namespace instruction {
	namespace impl {

		int SetColor::DoInstruction(int color, int index)
		{
			controller::RunControl & run = controller::RunControl::GetInstance();
			S16 const light = controller::Logger::GetInstance().GetLightLog().GetAverage();
			switch (static_cast<CALIBRATION_COLOR>(color)) {
			default:
				break;
			case CALIB_WHITE:
				run.SetWhite(light, index);
				break;
			case CALIB_GRAY:
				run.SetGray(light, index);
				break;
			case CALIB_BLACK:
				run.SetBlack(light, index);
				break;
			}
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
