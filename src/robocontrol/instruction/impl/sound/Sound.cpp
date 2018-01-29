/*
 * Sound.cpp
 *
 *  Created on: 2012/05/21
 *      Author: HIROSHI MIKURIYA
 */

#include "Sound.h"

namespace instruction {
	namespace impl {

		int Sound::DoInstruction(int instructionType, int param)
		{
			switch (static_cast<SOUND_ACTION>(instructionType)) {
			default:
				break;
			case PLAY:
				controller::SoundControl::GetInstance().Request(param);
				break;
			case VOLUME:
				controller::SoundControl::GetInstance().SetVolume(param);
				break;
			}
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
