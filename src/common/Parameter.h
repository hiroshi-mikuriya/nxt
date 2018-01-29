/*
 * Parameter.h
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 */

#ifndef PRAMETER_H
#define  PRAMETER_H

#include "ecrobot_interface.h"

/**
 * SoundControlが鳴らす音の種類
 */
enum {
	SOUND_NONE = -1, //!< 音なし
	SOUND_CLICK = 0, //!< クリック音
	SOUND_CAUTION = 1, //!< 警告音
	SOUND_OK = 2, //!< OK音
	SOUND_ERROR = 3, //!< エラー音
};

/**
 * SoundControlが実行する処理の種類
 */
enum SOUND_ACTION {
	PLAY = 0,	//!< 音を鳴らす
	VOLUME,	//!< ボリューム変更
};

/**
 * DisplayControlが実行する処理の種類
 */
enum DISPLAY_ACTION {
	TEXT = 0,	//!< テキストを表示
	COLOR,	//!< カラーパッケージを表示
	PF_VERSION,	//!< PFバージョンを表示
};

/**
 * 音のボリュームの範囲
 */
/*@{*/
const int MIN_VOLUME = 0;	//!< 最小音量
const int MAX_VOLUME = 100;	//!< 最大音量
/*@}*/

/**
 * LineTraceへ渡すライントレースするときのエッジの向き
 */
enum LINETRACE_EDGE {
	EDGE_RIGHT = 0,	//!< 右エッジ
	EDGE_LEFT,	//!< 左エッジ
};

/**
 *  SetColorへ渡すキャリブレーションする色
 */
enum CALIBRATION_COLOR {
	CALIB_WHITE = 0,	//!< 白
	CALIB_GRAY,	//!< 灰色
	CALIB_BLACK,	//!< 黒
};

/**
 * カラーパッケージから取得する色の値
 */
/*@{*/
const int COLOR_BLACK = 0;	//!< 黒のときの色値
const int COLOR_GRAY = 200;	//!< 灰色のときの色値
const int COLOR_WHITE = 400;	//!< 白のときの色値
/*@}*/

/**
 * BluetoothControlが実行する処理の種類
 */
enum BLUETOOTH_ACTION {
	BLUETOOTH_CONNECT = 0,	//!< Bluetooth接続
	BLUETOOTH_SEND_ENABLE,	//!< 送信許可
	BLUETOOTH_RECEIVE_ENABLE,	//!< 受信許可
};

/**
 *  Bluetooth受信イベントへ渡すコマンド
 */
enum RECIEVE_TYPE {
	BLUETOOTH_START = 0,	//!< スタート
	BLUETOOTH_STOP,	//!< ストップ
};

/**
 * IoEnablerへ渡すIO許可ビットパターン
 * @note タッチセンサの指定できないようにするため定義しない
 */
/*@{*/
const int LEFT_MOTOR_BIT = 1 << 0;	//!< 左モーターカウント取得を許可するビット
const int RIGHT_MOTOR_BIT = 1 << 1;	//!< 右モーターカウント取得を許可するビット
const int TAIL_MOTOR_BIT = 1 << 2;	//!< 尻尾モーターカウント取得を許可するビット
const int GYRO_BIT = 1 << 3;	//!< ジャイロセンサを許可するビット
const int LIGHT_BIT = 1 << 4;	//!< 光センサを許可するビット
const int SONAR_BIT = 1 << 5;	//!< ソナーセンサを許可するビット
/*@}*/

/**
 *
 */
const S16 NO_INDEX = 0xFFFF;

/**
 * NoLineTailの走行タイプ
 */
enum NOLINETAIL_RUN_TYPE {
	RUN_MODE = 0,	//!< 直進
	TURN_MODE,	//!< ターン
};

/**
 * Gotoのラベル定義
 * @note 先頭のラベルの値は０にすること
 * @note LABEL_COUNTは末尾に置くこと
 * @note 先頭以外のラベルの値は決めずに自動的に配置されるものを使用すること
 */
enum LABEL {
	TRIANGLE_START = 0, //!< 三角走法の開始位置
	BALANCE_TAIL,     //!< 倒立・尻尾切り替えサンプル開始位置
	GRAY_TEST,		//!<灰色検知サンプルプログラム開始位置
	LABEL_COUNT,		//!<ラベルの総数
};

#endif // PRAMETER_H