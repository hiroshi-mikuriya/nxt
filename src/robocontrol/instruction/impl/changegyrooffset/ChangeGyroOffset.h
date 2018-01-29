/*
 * ChangeGyroOffset.h
 *
 *  Created on: 2012/07/19
 *      Author: NOBUHITO ONODA & HIROHITO OTAKE
 */

#ifndef CHANGEGYROOFFSET_ACTION_H_
#define CHANGEGYROOFFSET_ACTION_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "controller/sound/SoundControl.h"
#include "Parameter.h"

namespace instruction {
	namespace impl {

		/**
		 * ジャイロオフセット値を変更する
		 */
		class ChangeGyroOffset: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * ジャイロオフセット値を変更する
			 * @param[in] gyro ジャイロオフセット値にプラス(マイナス)する値
			 * @param[in] unuse 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int gyro, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* CHANGEGYROOFFSET_ACTION_H_ */
