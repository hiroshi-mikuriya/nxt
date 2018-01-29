/*
 * MoveTail.h
 *
 *  Created on: 2012/05/12
 *      Author: HIROSHI MIKURIYA
 */

#ifndef MOVETAIL_H_
#define MOVETAIL_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * 尻尾角度変更命令
		 */
		class MoveTail: public instruction::impl::InstructionAbstract {
			int m_angle;
		public:
			/**
			 * 尻尾角度を変更する
			 * @param[in] angle 尻尾角度
			 * @param[in] unuse 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int angle, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* MOVETAIL_H_ */
