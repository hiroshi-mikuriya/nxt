/*
 * parts::InstructionCreater.cpp
 *
 *  Created on: 2012/06/05
 *      Author: HIROSHI MIKURIYA
 */

#include "InstructionCreater.h"
#include "instruction/impl/balance/Balance.h"
#include "instruction/impl/movetail/MoveTail.h"
#include "instruction/impl/saveangle/SaveAngle.h"
#include "instruction/impl/saveposition/SavePosition.h"
#include "instruction/impl/savetime/SaveTime.h"
#include "instruction/impl/sound/Sound.h"
#include "instruction/impl/display/Display.h"
#include "instruction/impl/gyrooffset/GyroOffset.h"
#include "instruction/impl/setcolor/SetColor.h"
#include "instruction/impl/bluetooth/Bluetooth.h"
#include "instruction/impl/ioenabler/IoEnabler.h"
#include "instruction/impl/userinstruction/UserInstruction.h"
#include "instruction/impl/waitevent/WaitEvent.h"
#include "instruction/impl/setrun/SetRun.h"
#include "instruction/impl/goto/Goto.h"
#include "instruction/impl/selectcolorpackage/SelectColorPackage.h"
#include "instruction/impl/label/Label.h"
#include "instruction/impl/tailtobalance/TailToBalance.h"
#include "instruction/impl/balancetotail/BalanceToTail.h"
#include "instruction/impl/changegyrooffset/ChangeGyroOffset.h"
#include "instruction/impl/interruptenable/InterruptEnable.h"

namespace instruction {
	namespace creater {

		namespace {
			impl::Balance s_balance;
			impl::MoveTail s_moveTail;
			impl::SaveAngle s_saveAngle;
			impl::SavePosition s_savePosition;
			impl::SaveTime s_saveTime;
			impl::Sound s_sound;
			impl::Display s_display;
			impl::GyroOffset s_gyroOffset;
			impl::SetColor s_setColor;
			impl::Bluetooth s_bluetooth;
			impl::IoEnabler s_ioEnabler;
			impl::UserInstruction s_userInstruction;
			impl::WaitEvent s_waitEvent;
			impl::SetRun s_setRun;
			impl::Goto s_goto;
			impl::SelectColorPackage s_selectColorPackage;
			impl::Label s_label;
			impl::TaiToBalance s_tailToBalance;
			impl::BalanceToTail s_balanceToTail;
			impl::ChangeGyroOffset s_changeGyroOffset;
			impl::InterruptEnable s_interruptEnable;

		}

		Balance::operator parts::Instruction() const
		{
			return parts::Instruction(s_balance, 0, 0);
		}

		parts::Instruction MoveTail::operator()(int angle) const
		{
			return parts::Instruction(s_moveTail, angle, 0);
		}

		parts::Instruction SaveAngle::operator()(int index) const
		{
			return parts::Instruction(s_saveAngle, index, 0);
		}

		parts::Instruction SavePosition::operator()(int index) const
		{
			return parts::Instruction(s_savePosition, index, 0);
		}

		parts::Instruction SaveTime::operator()(int index) const
		{
			return parts::Instruction(s_saveTime, index, 0);
		}

		parts::Instruction Sound::operator()(int action, int param) const
		{
			return parts::Instruction(s_sound, action, param);
		}

		parts::Instruction Display::operator()(char const * text) const
		{
			return parts::Instruction(s_display, static_cast<int>(TEXT), reinterpret_cast<int>(text));
		}
		parts::Instruction Display::operator()(DISPLAY_ACTION action, int param) const
		{
			return parts::Instruction(s_display, static_cast<int>(action), param);
		}
		parts::Instruction Display::operator()(DISPLAY_ACTION action) const
		{
			return parts::Instruction(s_display, static_cast<int>(action), 0);
		}

		GyroOffset::operator parts::Instruction() const
		{
			return parts::Instruction(s_gyroOffset, 0, 0);
		}

		parts::Instruction SetColor::operator()(CALIBRATION_COLOR color, int index) const
		{
			return parts::Instruction(s_setColor, static_cast<int>(color), index);
		}

		parts::Instruction Bluetooth::operator()(BLUETOOTH_ACTION action) const
		{
			return parts::Instruction(s_bluetooth, static_cast<int>(action), 0);
		}

		parts::Instruction IoEnabler::operator()(int pattern, bool enabled) const
		{
			return parts::Instruction(s_ioEnabler, pattern, enabled);
		}

		parts::Instruction UserInstruction::operator ()(userInstructionT userInstruction) const
		{
			return parts::Instruction(s_userInstruction, reinterpret_cast<int>(userInstruction), 0);
		}

		parts::Instruction WaitEvent::operator()(event::parts::EventWithIndex const & event)
		{
			event::parts::EventWithIndex * copy = new event::parts::EventWithIndex(event);
			return parts::Instruction(s_waitEvent, reinterpret_cast<int>(copy), 0);
		}

		parts::Instruction WaitEvent::operator()(event::parts::Event const & event)
		{
			event::parts::EventWithIndex * copy = new event::parts::EventWithIndex(event, 1);
			return parts::Instruction(s_waitEvent, reinterpret_cast<int>(copy), 0);
		}

		parts::Instruction WaitEvent::operator()(event::parts::EventWithIndex const & event1, event::parts::EventWithIndex const & event2)
		{
			event::parts::EventWithIndex * copy1 = new event::parts::EventWithIndex(event1);
			event::parts::EventWithIndex * copy2 = new event::parts::EventWithIndex(event2);
			return parts::Instruction(s_waitEvent, reinterpret_cast<int>(copy1), reinterpret_cast<int>(copy2));
		}

		parts::Instruction SetRun::operator()(runmethod::impl::RunAbstract * run)
		{
			return parts::Instruction(s_setRun, reinterpret_cast<int>(run), 0);
		}

		parts::Instruction Goto::operator()(S16 index)
		{
			return parts::Instruction(s_goto, index, false);
		}

		parts::Instruction Goto::operator()(LABEL label)
		{
			return parts::Instruction(s_goto, static_cast<int>(label), true);
		}

		parts::Instruction SelectColorPackage::operator()(S16 index)
		{
			return parts::Instruction(s_selectColorPackage, index, 0);
		}

		parts::Instruction Label::operator()(LABEL label)
		{
			return parts::Instruction(s_label, static_cast<int>(label), 0);
		}

		TailToBalance::operator parts::Instruction() const
		{
			return parts::Instruction(s_tailToBalance, 0, 0);
		}

		parts::Instruction BalanceToTail::operator()(int targetAngle)
		{
			return parts::Instruction(s_balanceToTail, targetAngle, 0);
		}

		parts::Instruction ChangeGyroOffset::operator()(int gyro)
		{
			return parts::Instruction(s_changeGyroOffset, gyro, 0);
		}

		parts::Instruction InterruptEnable::operator()(bool enable)
		{
			return parts::Instruction(s_interruptEnable, enable, 0);
		}
	} /* namespace creater */
} /* namespace instruction */

