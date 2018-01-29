/*
 * Sound.h
 *
 *  Created on: 2012/05/21
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SOUND_ACTION_H_
#define SOUND_ACTION_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "controller/sound/SoundControl.h"
#include "Parameter.h"

namespace instruction {
	namespace impl {

		/**
		 * 音を鳴らす
		 */
		class Sound: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 音を鳴らす
			 * @param[in] instructionType 命令内容
			 * @param[in] param 命令に応じたパラメータ
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int instructionType, int param);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* SOUND_ACTION_H_ */
