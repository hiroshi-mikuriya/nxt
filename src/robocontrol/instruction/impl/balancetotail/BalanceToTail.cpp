/*
 * BalanceToTail.cpp
 *
 *  Created on: 2012/07/18
 *      Author: NOBUHITO ONDA & HIROHITO OTAKE
 *      date: 2012/08/03 HIROSHI MIKURIYA
 */

#include "BalanceToTail.h"
#include "controller/tail/TailControl.h"
#include "hardware/timer/Timer.h"
#include "controller/run/RunControl.h"
#include "runmethod/impl/nolinetail/NoLineTail.h"

namespace instruction {
	namespace impl {

		int BalanceToTail::DoInstruction(int targetAngle, int unuse)
		{
			hardware::Timer & timer = hardware::Timer::GetInstance();
			controller::TailControl & tail = controller::TailControl::GetInstance();
			controller::RunControl & run = controller::RunControl::GetInstance();
			tail.SetAngle(targetAngle);
			runmethod::impl::NoLineTail noLineTail(RUN_MODE, 50);
			run.SetRunMethod(&noLineTail); // 少し前進させることで後転を防止している
			timer.Sleep(500); // 尻尾に寄りかかり安定するまでの時間
			run.StopRunControl(); // 命令内部でSetRunしたので、abort防止のためこのAPIを呼び出す
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
