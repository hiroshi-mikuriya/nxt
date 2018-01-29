/*
 * InterruptEnable.h
 *
 *  Created on: 2012/07/31
 *      Author: HIROSHI
 */

#ifndef INTERRUPTENABLE_H_
#define INTERRUPTENABLE_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		class InterruptEnable: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 割り込みを許可・不許可する
			 * @param enable 許可・不許可
			 * @param unuse 未使用
			 * @return 次に進むインデックス数
			 */
			virtual int DoInstruction(int enable, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* INTERRUPTENABLE_H_ */
