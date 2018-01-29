/*
 * BluetoothControl.h
 *
 *  Created on: 2012/05/19
 *      Author: HIROSHI MIKURIYA
 */

#ifndef BLUETOOTHCONTROL_H_
#define BLUETOOTHCONTROL_H_

#include "ecrobot_interface.h"

namespace controller {

	/**
	 * Bluetooth制御
	 */
	class BluetoothControl {

		bool m_connect; //!< 接続有無
		bool m_sendEnable; //!< 送信許可
		bool m_receiveEnable; //!< 受信許可
		U8 m_lastReceivedData; //!< 最後に受信したデータ
		U32 m_lastReceivedTime; //!< 最後に受信した時間

		BluetoothControl();
	public:

		static BluetoothControl & GetInstatnce();
		/**
		 * 初期化
		 */
		bool Initialize();
		/**
		 * 送信
		 * @param 送信データ
		 * @return 成功・失敗
		 */
		bool Send(U8 const * data, U32 size);
		/**
		 * 引数で指定した値をデバッグ形式で送信
		 */
		void Send(S8 (&dataS08)[2], U16 dataU16, S16 (&dataS16)[4], S32 (&dataS32)[4]);
		/**
		 * 引数で指定した値をデバッグ形式で送信(IOはGamePadの並び)
		 */
		void Send(S8 (&dataS08)[2], S32 dataS32);
		/**
		 * 受信制御
		 * @note 定期的に呼び出すこと
		 */
		void ReceiveControl();
		/**
		 * 送信許可設定
		 * @param 送信許可
		 */
		void SetSendEnable(bool enabled);
		/**
		 * 受信許可設定
		 * @param 受信許可
		 */
		void SetReceiveEnable(bool enabled);
		/**
		 * 最後に受信したデータを取得
		 * @return 最後に受信したデータ
		 * @note 最後の受信から１秒以上経過している場合は０を返す
		 */
		U8 GetLastReceiveData() const;
	};

} /* namespace controller */
#endif /* BLUETOOTHCONTROL_H_ */
