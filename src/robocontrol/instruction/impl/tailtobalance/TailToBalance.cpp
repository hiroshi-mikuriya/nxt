/*
 * TailToBalance.cpp
 *
 *  Created on: 2012/07/18
 *      Author: NOBUHITO ONODA & HIROHITO OTAKE
 *      date: 2012/08/03 HIROSHI MIKURIYA
 */

#include "TailToBalance.h"
#include "controller/run/RunControl.h"
#include "hardware/timer/Timer.h"
#include "controller/tail/TailControl.h"
#include "runmethod/impl/nolinetail/NoLineTail.h"

namespace instruction {
	namespace impl {

		int TaiToBalance::DoInstruction(int unuse1, int unuse2)
		{
			hardware::Timer & timer = hardware::Timer::GetInstance();
			controller::TailControl & tail = controller::TailControl::GetInstance();
			controller::RunControl & run = controller::RunControl::GetInstance();
			runmethod::impl::NoLineTail noLineTail(RUN_MODE, -20);
			run.SetRunMethod(&noLineTail); // 少しバックすることで、ロボが立ち上がり易くなる
			tail.SetAngle(105);
			while (tail.GetTailAngle() < 102) // 目標角より微妙に少ない値にすることで転倒防止になる
			{
				timer.Sleep(10); // Scriptタスクが処理を握らないようにするため適度にスリープしている
			}
			run.StopRunControl(); // 命令内部でSetRunしたので、abort防止のためこのAPIを呼び出す
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
