/*
 * GyroOffset.h
 *
 *  Created on: 2012/05/26
 *      Author: HIROSHI MIKURIYA
 */

#ifndef GYROOFFSET_H_
#define GYROOFFSET_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * ジャイロオフセットを初期化する命令
		 */
		class GyroOffset: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * ジャイロオフセットを初期化する
			 * @param unuse1 未使用
			 * @param unuse2 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int unuse1, int unuse2);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* GYROOFFSET_H_ */
