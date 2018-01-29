/*
 * Body.h
 *
 *  Created on: 2012/05/23
 *      Author: HIROSHI MIKURIYA
 */

#ifndef BODY_H_
#define BODY_H_

#include "ecrobot_interface.h"
#include <Lcd.h>

namespace hardware {

	class Body {
		Body();
	public:

		static Body & GetInstance();

		/**
		 * 音を鳴らす
		 * @param freq 周波数
		 * @param duration 長さ
		 * @param volume 音量
		 */
		void playTone(U32 freq, U32 duration, U32 volume);
		/**
		 * LCDを参照する
		 * @return LCDの参照
		 */
		ecrobot::Lcd & RefLcd();
		/**
		 * バッテリー値を取得する
		 * @return バッテリー値
		 */
		S16 GetBattMv(void) const;
		/**
		 * Bluetoothを接続する
		 * @param passkey パスキー
		 * @param deviceName デバイス名
		 * @return 1(connected)/0(canceled)/-1(failed)
		 */
		S32 BtConnect(const CHAR *passkey, const CHAR *devname = 0);
		/**
		 * Bluetoothデータ送信
		 * @param data データの先頭ポインタ
		 * @param length データ長
		 */
		U32 BtSend(U8 *data, U32 length);
		/**
		 * 引数で指定した値をデバッグ形式で送信
		 */
		void BtSend(S8 dataS08[2], U16 dataU16, S16 dataS16[4], S32 dataS32[4]);
		/**
		 * Bluetoothデータ受信
		 * @param data データの先頭ポインタ
		 * @param length データ長
		 */
		U32 BtReceive(U8 *data, U32 length) const;
	};

} /* namespace hardware */
#endif /* BODY_H_ */
