/*
 * SetRun.h
 *
 *  Created on: 2012/06/09
 *      Author: HIROSHI
 */

#ifndef SETRUN_H_
#define SETRUN_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		class SetRun: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 走法を設定する
			 * @return NO_INDEXを返す
			 */
			virtual int DoInstruction(int runmethod, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* SETRUN_H_ */
