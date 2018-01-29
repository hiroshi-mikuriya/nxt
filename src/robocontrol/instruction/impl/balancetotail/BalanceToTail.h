/*
 * BalanceToTail.h
 *
 *  Created on: 2012/07/18
 *      Author: NOBUHITO ONODA & HIROHITO OTAKE
 */

#ifndef BALANCETOTAIL_ACTION_H_
#define BALANCETOTAIL_ACTION_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "Parameter.h"

namespace instruction {
	namespace impl {

		/**
		 * 倒立振子走行から尻尾走行へ切り替える
		 */
		class BalanceToTail: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 倒立振子走行から尻尾走行へ切り替え
			 * @param[in] targetAngle 目標の尻尾角度
			 * @param[in] unuse 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int targetAngle, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* BALANCETOTAIL_ACTION_H_ */
