/*
 * TailToBalance.h
 *
 *  Created on: 2012/07/18
 *      Author: NOBUHITO ONODA & HIROHITO OTAKE
 */

#ifndef TAILTOBALANCE_ACTION_H_
#define TAILTOBALANCE_ACTION_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "controller/sound/SoundControl.h"
#include "Parameter.h"

namespace instruction {
	namespace impl {

		/**
		 * 尻尾走行から倒立振子走行へ切り替える
		 */
		class TaiToBalance: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 尻尾走行から倒立振子走行へ切り替える
			 * @param[in] unuse1 未使用
			 * @param[in] unuse2 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int unuse1, int unuse2);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* TAILTOBALANCE_ACTION_H_ */
