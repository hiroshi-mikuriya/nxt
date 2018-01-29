/*
 * Balance.h
 *
 *  Created on: 2012/05/12
 *      Author: HIROSHI MIKURIYA
 */

#ifndef BALANCE_H_
#define BALANCE_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * バランス初期化
		 */
		class Balance: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * バランス初期化する(balance_initを呼ぶ)
			 * @param unuse1 未使用
			 * @param unuse2 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int unuse1, int unuse2);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* BALANCE_H_ */
