/*
 * Display.cpp
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 */

#include "Display.h"
#include "controller/display/DisplayControl.h"

namespace instruction {
	namespace impl {

		int Display::DoInstruction(int instruction, int param)
		{
			switch (static_cast<DISPLAY_ACTION>(instruction)) {
			default:
				break;
			case TEXT:
				controller::DisplayControl::GetInstance().DisplayText(reinterpret_cast<char const*>(param));
				break;
			case COLOR:
				controller::DisplayControl::GetInstance().DisplayColor(param);
				break;
			case PF_VERSION:
				controller::DisplayControl::GetInstance().DisplayPfVersion();
				break;
			}
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
