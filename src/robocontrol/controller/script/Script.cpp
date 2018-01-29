/*
 * Script.cpp
 *
 *  Created on: 2012/05/19
 *      Author: HIROSHI MIKURIYA
 */

#include "Script.h"
#include "hardware/timer/Timer.h"

namespace controller {

	Script::Script()
			: m_begin(0), m_end(0), m_instructionPointer(0)
	{
	}

	Script & Script::GetInstance()
	{
		static Script programData;
		return programData;
	}

	void Script::Do()
	{
		hardware::Timer & timer = hardware::Timer::GetInstance();
		m_instructionPointer = m_begin;
		while (m_instructionPointer < m_end) {
			m_instructionPointer += m_instructionPointer->DoInstruction();
			timer.Sleep(20);
		}
	}

	bool Script::Set(instruction::parts::Instruction *begin, instruction::parts::Instruction * end)
	{
		if (end <= begin) {
			return false;
		}
		m_begin = begin;
		m_end = end;
		for (instruction::parts::Instruction* p = m_begin; p != m_end; ++p) {
			p->Initialize();
		}
		return true;
	}

	void Script::SetLabel(instruction::parts::Instruction * p, LABEL label)
	{
		m_labelTabel[label] = p;
	}

	instruction::parts::Instruction * Script::GetInstructionPointer(LABEL label) const
	{
		return m_labelTabel[label];
	}

	instruction::parts::Instruction * Script::GetInstructionPointer() const
	{
		return m_instructionPointer;
	}

} /* namespace controller */
