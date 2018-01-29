/*
 * Instruction.cpp
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#include "InstructionParts.h"

namespace instruction {
	namespace parts {

		Instruction & Instruction::operator=(Instruction const & that)
		{
			this->m_instruction = that.m_instruction;
			this->m_param1 = that.m_param1;
			this->m_param2 = that.m_param2;
			return *this;
		}

		Instruction::Instruction(instruction::impl::InstructionAbstract & a, int param1, int param2)
				: m_instruction(a), m_param1(param1), m_param2(param2)
		{
		}

		void Instruction::Initialize()
		{
			m_instruction.Initialize(m_param1, m_param2, this);
		}

		int Instruction::DoInstruction()
		{
			S16 const index = m_instruction.DoInstruction(m_param1, m_param2);
			return NO_INDEX == index ? 1 : index;
		}

	}
}

