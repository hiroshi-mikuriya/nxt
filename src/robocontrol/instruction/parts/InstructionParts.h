/*
 * Instruction.h
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#ifndef INSTRUCTION_PARTS_H_
#define INSTRUCTION_PARTS_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "ecrobot_interface.h"

namespace instruction {
	namespace parts {

		class Instruction {
			instruction::impl::InstructionAbstract & m_instruction;
			int m_param1;
			int m_param2;
		public:
			Instruction & operator=(Instruction const & that);

			Instruction(instruction::impl::InstructionAbstract & a, int param1, int param2);

			void Initialize();
			/**
			 * 命令実行
			 */
			int DoInstruction();
		};

	} /* namespace programparts */
}
#endif /* INSTRUCTION_PARTS_H_ */
