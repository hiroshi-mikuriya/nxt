/*
 * RunProgram.cpp
 *
 *  Created on: 2012/07/30
 *      Author: xxx xxx
 */

#include "controller/bluetooth/BluetoothControl.h"
#include "controller/display/DisplayControl.h"
#include "controller/log/Logger.h"
#include "controller/position/Position.h"
#include "controller/run/RunControl.h"
#include "controller/save/SaveData.h"
#include "controller/script/Script.h"
#include "controller/sound/SoundControl.h"
#include "controller/tail/TailControl.h"
#include "controller/interrupt/Interrupt.h"
#include "hardware/io/Io.h"
#include "hardware/timer/Timer.h"
#include "hardware/body/Body.h"
#include "event/package/EventPackage.h"
#include "Parameter.h"

using namespace event::package;

/**
 * リタイアしたらタイヤを止める
 */
void FailSafeProc()
{
	controller::RunControl::GetInstance().StopRunControl();
	controller::DisplayControl::GetInstance().DisplayText("fail safe");
	for (;;)
	{
		// do nothing
	}
}

/**
 * 割り込みプログラムメイン
 */
void InterruptProgramMain()
{
	static controller::Interrupt::EventProcT InterruptProgram[] =
	{
	{ evFalldown, FailSafeProc },
	// TODO
	//{ evBluetooth(BLUETOOTH_STOP), FailSafeProc },
			};
	controller::Interrupt::GetInstance().Set(beginof(InterruptProgram),
			endof(InterruptProgram));
}
