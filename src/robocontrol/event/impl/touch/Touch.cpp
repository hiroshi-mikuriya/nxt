/*
 * Touch.cpp
 *
 *  Created on: 2012/05/19
 *      Author: HIROSHI MIKURIYA
 */

#include "Touch.h"
#include "controller/log/Logger.h"
#include "hardware/Io/io.h"

namespace event {
	namespace impl {

		void Touch::Initialize(int unuse1, int unuse2)
		{
		}

		bool Touch::Notify() const
		{
			hardware::Io::GetInstance().SetTouchEnabled(true);
			hardware::Io::GetInstance().UpdateTouch();
			bool touch = hardware::Io::GetInstance().GetTouch();
			hardware::Io::GetInstance().SetTouchEnabled(false);
			return touch;
		}

	} /* namespace impl */
} /* namespace event */
