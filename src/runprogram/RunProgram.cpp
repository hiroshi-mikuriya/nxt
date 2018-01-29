/*
 * RunProgram.cpp
 *
 *  Created on: 2012/05/18
 *      Author: xxx xxx
 */

#include "controller/script/Script.h"
#include "instruction/package/InstructionPackage.h"
#include "runmethod/package/RunmethodPackage.h"
#include "event/package/EventPackage.h"
#include "Common.h"
#include "Parameter.h"
#include "UserInstruction.h"

using namespace instruction::package;
using namespace instruction::parts;
using namespace runmethod::package;
using namespace event::package;

typedef utils::PidCalculation<S16>::Parameter PidParameter;
namespace
{
//PidTail
const int PIDTAIL_SPEED = 30;
const PidParameter s_pid(2.0f, 0.0f, 0.03f, COLOR_GRAY);
//Pid
const int PID_SPEED_10 = 10;
const PidParameter s_pid_10(1.75f, 0.0f, 0.00f, COLOR_GRAY);

const int PID_SPEED_30 = 30;
const PidParameter s_pid_30(2.0f, 0.0f, 0.04f, COLOR_GRAY);

const int PID_SPEED_40 = 40;
const PidParameter s_pid_40(1.65f, 0.0f, 0.065f, COLOR_GRAY);

const int PID_SPEED_50 = 50;
const PidParameter s_pid_50(1.65f, 0.0f, 0.09f, COLOR_GRAY);

const int PID_SPEED_60 = 60;
const PidParameter s_pid_60(1.4f, 0.0f, 0.085f, COLOR_GRAY);

const int PID_SPEED_70 = 70;
const PidParameter s_pid_70(0.8f, 0.0f, 0.05f, COLOR_GRAY);

const int PID_SPEED_80 = 80;
const PidParameter s_pid_80(0.7f, 0.0f, 0.065f, COLOR_GRAY);

const int PID_SPEED_100 = 100;
const PidParameter s_pid_100(0.6f, 0.0f, 0.075f, COLOR_GRAY);

const int PID_SPEED_120 = 120;
const PidParameter s_pid_120(0.6f, 0.0f, 0.09f, COLOR_GRAY);

const int PID_SPEED_140 = 140;
const PidParameter s_pid_140(0.65f, 0.0f, 0.095f, COLOR_GRAY);
}



/**
 * 走行プログラムメイン
 */
void RunProgramMain()
{
	static Instruction RunProgram[] = {
		// ボリューム設定
		Sound(VOLUME, 50),

		// Bluetoothの接続
		Bluetooth(BLUETOOTH_CONNECT),
		Sound(PLAY, SOUND_CLICK),

		// 尻尾を有効に
		IoEnable(TAIL_MOTOR_BIT, true),
		// 直立する角度に尻尾を調整
		MoveTail(100),

		// プラットフォームバージョンを表示
		Display(PF_VERSION),
		WaitEvent(evTouch),
		Sound(PLAY, SOUND_CLICK),
		WaitEvent(evTime(500)),

		// ジャイロオフセットのキャリブレーション
		Display("calibrate gyro\n\nset machine\nand touch button."),
		WaitEvent(evTouch),
		Sound(PLAY, SOUND_CLICK),
		IoEnable(GYRO_BIT, true),
		WaitEvent(evTime(1500)),
		GyroOffset,
		Sound(PLAY, SOUND_CLICK),
		IoEnable(GYRO_BIT, false),

	#if 0
		// 光センサを有効に
		IoEnable(LIGHT_BIT, true),
		// 白キャリブレーション
		Display("calibrate white\n\nset machine\nand touch button."),
		WaitEvent(evTouch),
		Sound(PLAY, SOUND_CLICK),
		WaitEvent(evTime(1500)),
		SetColor(CALIB_WHITE, 0),
		Sound(PLAY, SOUND_CLICK),
		// 灰色キャリブレーション
		Display("calibrate gray\n\nset machine\nand touch button."),
		WaitEvent(evTouch),
		Sound(PLAY, SOUND_CLICK),
		WaitEvent(evTime(1500)),
		SetColor(CALIB_GRAY, 0),
		Sound(PLAY, SOUND_CLICK),
		// 黒キャリブレーション
		Display("calibrate black\n\nset machine\nand touch button."),
		WaitEvent(evTouch),
		Sound(PLAY, SOUND_CLICK),
		WaitEvent(evTime(1500)),
		SetColor(CALIB_BLACK, 0),
		Sound(PLAY, SOUND_CLICK),
		// キャリブレーション結果を表示
		Display(COLOR, 0),
		WaitEvent(evTouch),
		WaitEvent(evTime(1000)),
		// 光センサを無効に
		IoEnable(LIGHT_BIT, false),
	#endif // 光キャリブレーション


		// Bluetooth受信許可
		Bluetooth(BLUETOOTH_RECEIVE_ENABLE),
		// スタンバイ画面を出す
		Sound(PLAY, SOUND_CLICK),
		Display("ready\n\ntouch start\nor\nbluetooth start."),
		WaitEvent(evTouch>>1, evBluetooth(BLUETOOTH_START)>>1),
		Sound(PLAY, SOUND_CLICK),
		// タイヤモータ、ジャイロセンサ、光センサを有効に
		IoEnable(RIGHT_MOTOR_BIT | LEFT_MOTOR_BIT | GYRO_BIT | LIGHT_BIT, true),
		// カラーパッケージを選択
		SelectColorPackage(0),
		// Bluetooth送信許可
		Bluetooth(BLUETOOTH_SEND_ENABLE),
		// 割り込みタスクを有効にする
		InterruptEnable( true ),


	#if 1
		/* 三角走行 */
		Balance,
		Label( TRIANGLE_START ),
		SetRun(runNoLine(100,0)),
		WaitEvent(evDistance(200)),
		SetRun(runNoLine(0,100)),
		WaitEvent(evAngle(120)),
		Goto(TRIANGLE_START),
	#elif 0
		/* 倒立・尻尾切り替えサンプルプログラム */
		Balance,
		MoveTail(10),
		Label( BALANCE_TAIL ) ,
		SetRun( runNoLine( 40, 0 )),
		WaitEvent( evTime( 2000 )),
		BalanceToTail( 70 ),
		SetRun( runNoLineTail( RUN_MODE, 40 )),
		WaitEvent( evTime( 2000 )),
		TailToBalance,
		Balance,	// TailToBalanceの後に必ず呼ぶこと
		MoveTail(10), // TailToBalanceの後に必ず呼ぶこと（地面に尻尾が接地しない角度で）
		Goto( BALANCE_TAIL ),
	#elif 0
		/* サンプルコースを走らせ、灰色マーカー上で音を鳴らすサンプル */
		Balance,
		MoveTail( 10 ),
		SetRun( runLineTrace( 30, 90, EDGE_LEFT )),
		WaitEvent( evTime(1000)),
		Label( GRAY_TEST ),
		WaitEvent( evGray ),
		Sound( PLAY, SOUND_CLICK ),
		Goto( GRAY_TEST ),
	#else
		/* 普通のライントレースでサンプルコースを走行する */
		Balance,
		MoveTail( 10 ),
		SetRun( runLineTrace( 30, 50, EDGE_LEFT )),
		Goto( 0 ),

	#endif
	};
	controller::Script::GetInstance().Set(beginof(RunProgram), endof(RunProgram));
}
