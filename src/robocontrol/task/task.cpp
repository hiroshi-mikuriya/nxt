/*
 * RoboControlMain.cpp
 *
 *  Created on: 2012/05/18
 *      Author: HIROSHI MIKURIYA
 */

extern "C" {
#include "rtoscalls.h"
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
}

#include "hardware/io/Io.h"
#include "controller/sound/SoundControl.h"
#include "controller/tail/TailControl.h"
#include "controller/run/RunControl.h"
#include "controller/log/Logger.h"
#include "controller/position/Position.h"
#include "controller/script/Script.h"
#include "controller/bluetooth/BluetoothControl.h"
#include "controller/interrupt/Interrupt.h"

extern void RunProgramMain();

extern void InterruptProgramMain();

/**
 * TOPPERS/ATK declarations
 */
/*@{*/
DeclareCounter (SysTimerCnt);
/*@}*/

/**
 * デバイスの初期化
 *  @note nxtOSEK hooks
 */
void ecrobot_device_initialize(void)
{
}

/**
 * デバイスの終了処理
 *  @note nxtOSEK hooks
 */
void ecrobot_device_terminate(void)
{
}

/**
 * 1msec timer interrupt hook
 */
void user_1ms_isr_type2()
{
	StatusType ercd = SignalCounter(SysTimerCnt);
	if (ercd != E_OK) {
		ShutdownOS(ercd);
	}
	SleeperMonitor(); // Need for Nxt and I2C device classes
}

/**
 * 倒立制御タスク
 * @note 倒立制御をするため必ず4ms周期で処理を行う
 */
extern "C" TASK(TaskBalanceControl)
{
	controller::RunControl::GetInstance().Control();
	hardware::Io::GetInstance().Update();
	controller::Logger::GetInstance().Update();
	S8 dataS8s[2] =
	{	0};
	U16 dataU16 = 0;
	S16 dataS16s[4] =
	{	0};
	S32 dataS32s[4] =
	{	0};
	controller::BluetoothControl::GetInstatnce().Send(dataS8s, dataU16,
			dataS16s, dataS32s);
	TerminateTask();
}

/**
 * ポジション更新処理タスク
 */
extern "C" TASK(TaskPosition)
{
	controller::Position::GetInstance().Update();
	TerminateTask();
}

/**
 * ソナー更新タスク
 */
extern "C" TASK(TaskSonar)
{
	hardware::Io::GetInstance().UpdateSonar();
	controller::Logger::GetInstance().UpdateSonar();
	TerminateTask();
}

/**
 * Bluetooth受信処理タスク
 */
extern "C" TASK(TaskBluetooth)
{
	controller::BluetoothControl::GetInstatnce().ReceiveControl();
	TerminateTask();
}

/**
 * 尻尾制御タスク
 */
extern "C" TASK(TaskTail)
{
	hardware::Io::GetInstance().UpdateTail();
	controller::TailControl::GetInstance().Control();
	TerminateTask();
}

/**
 * 割り込みタスク
 * @note プログラムの実行は処理を握るため、このタスク内で他の処理はできない
 */
extern "C" TASK(TaskInterrupt)
{
	InterruptProgramMain();
	controller::Interrupt::GetInstance().Do();
	TerminateTask();
}

/**
 * 走行プログラム更新タスク
 * @note プログラムの実行は処理を握るため、このタスク内で他の処理はできない
 */
extern "C" TASK(TaskScript)
{
	RunProgramMain();
	controller::Script::GetInstance().Do();
	TerminateTask();
}

/**
 * 音声制御タスク
 * @note 音声鳴動は処理を握るため、このタスク内で他の処理はできない
 */
extern "C" TASK(TaskSound)
{
	controller::SoundControl::GetInstance().Play();
	TerminateTask();
}

