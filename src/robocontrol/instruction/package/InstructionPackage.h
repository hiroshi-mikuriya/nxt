/*
 * InstructionPackage.h
 *
 *  Created on: 2012/06/09
 *      Author: HIROSHI MIKURIYA
 */

#ifndef INSTRUCTION_PACKAGE_H_
#define INSTRUCTION_PACKAGE_H_

#include "instruction/creater/InstructionCreater.h"

namespace instruction {
	namespace package {

		namespace {
			creater::Balance Balance; //!< バランス初期化
			creater::MoveTail MoveTail; //!< 尻尾角度変更
			creater::SaveAngle SaveAngle; //!< 角度保存
			creater::SavePosition SavePosition; //!< 座標保存
			creater::SaveTime SaveTime; //!< 時間保存
			creater::Sound Sound; //!< サウンド
			creater::Display Display; //!< LCD
			creater::GyroOffset GyroOffset; //!< ジャイロオフセットを登録
			creater::SetColor SetColor; //!< 色の基準値を設定
			creater::Bluetooth Bluetooth; //!< Bluetoothを接続・通信許可
			creater::IoEnabler IoEnable; //!< IOの使用許可設定
			creater::UserInstruction UserInstruction; //!< ユーザー命令
			creater::WaitEvent WaitEvent; //!< イベント待ち
			creater::SetRun SetRun; //!< 走法を設定
			creater::Goto Goto; //!< 指定インデックスへ移動
			creater::SelectColorPackage SelectColorPackage; //!< 走行で使用するカラーパッケージを選択
			creater::Label Label; //!< ラベル
			creater::TailToBalance TailToBalance; //!< 尻尾走行から倒立振子走行へ切り替え
			creater::BalanceToTail BalanceToTail; //!< 倒立振子走行から尻尾走行へ切り替え
			creater::ChangeGyroOffset ChangeGyroOffset; //!< ジャイロオフセット値を変更
			creater::InterruptEnable InterruptEnable; //!< 割り込み許可・禁止
		}
	} /* namespace package */
} /* namespace instruction */

#endif // INSTRUCTION_PACKAGE_H_
