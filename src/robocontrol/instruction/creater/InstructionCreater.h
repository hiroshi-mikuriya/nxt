/*
 * InstructionCreater.h
 *
 *  Created on: 2012/06/05
 *      Author: HIROSHI MIKURIYA
 */

#ifndef INSTRUCTION_CREATER_H_
#define INSTRUCTION_CREATER_H_

#include "runmethod/impl/abstract/RunAbstract.h"
#include "instruction/parts/InstructionParts.h"
#include "event/parts/EventParts.h"
#include "Typedef.h"
#include "Parameter.h"

namespace instruction {
	namespace creater {

		struct Balance {
			/**
			 * バランス初期化を行う
			 * @return 命令のインスタンス
			 */
			operator parts::Instruction() const;
		};
		struct MoveTail {
			/**
			 * 尻尾の角度を設定する
			 * @param[in] angle 尻尾の角度
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(int angle) const;
		};
		struct SaveAngle {
			/**
			 * タイヤの回転から求めた現在の角度を保存する
			 * @param[in] index 保存するインデックス
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(int index) const;
		};
		struct SavePosition {
			/**
			 * タイヤの回転から求めた現在の座標を保存する
			 * @param[in] index 保存するインデックス
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(int index) const;
		};
		struct SaveTime {
			/**
			 * 現在の時間を保存する
			 * @param[in] index 保存するインデックス
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(int index) const;
		};
		struct Sound {
			/**
			 * 音量設定・音のリクエストを行う
			 * @param[in] action 音量設定(VOLUME)・音のリクエスト(PLAY)どちらを行うか
			 * @param[in] param 音量または、リクエストする音の種類
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(int action, int param) const;
		};
		struct Display {
			/**
			 * 引数で指定したテキストをLCDに表示する
			 * @param[in] text 表示するテキスト
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(char const * text) const;
			/**
			 * 引数で指定した表示命令を行う（パラメータあり版）
			 * @param[in] action 表示命令（2012/6/12現在はCOLORのみ）
			 * @param[in] param 表示命令に対応したパラメータ
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(DISPLAY_ACTION action, int param) const;
			/**
			 * 引数で指定した表示命令を行う（パラメータなし版）
			 * @param[in] action 表示命令（2012/6/14現在はPF_VERSIONのみ）
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(DISPLAY_ACTION action) const;
		};
		struct GyroOffset {
			/**
			 * ジャイロオフセットを設定
			 * @return 命令のインスタンス
			 */
			operator parts::Instruction() const;
		};
		struct SetColor {
			/**
			 * キャリブレーションした色値を設定
			 * @param[in] color 設定する色
			 * @param[in] index 設定するカラーパッケージのインデックス
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(CALIBRATION_COLOR color, int index) const;
		};
		struct Bluetooth {
			/**
			 * Bluetoothの操作を行う
			 * @param[in] action 操作の種類（接続・通信許可のいずれか）
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(BLUETOOTH_ACTION action) const;
		};
		struct IoEnabler {
			/**
			 * IOの使用許可設定を行う
			 * @param[in] pattern 設定するIOの種類（orで複数指定可能）
			 * @param[in] enabled 許可・禁止
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(int pattern, bool enabled) const;
		};
		struct UserInstruction {
			/**
			 * ユーザが独自に作成した命令を行う
			 * @param[in] userInstruction ユーザ操作を行う関数へのポインタ
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(userInstructionT userInstruction) const;
		};
		struct WaitEvent {
			/**
			 * １つのイベント待つ
			 * @param[in] event 待つイベントを指定する
			 * @return 命令のインスタンス
			 * @note イベントが発生したら指定された数だけインデックスを進める
			 */
			parts::Instruction operator()(event::parts::EventWithIndex const & event);
			/**
			 * １つのイベント待つ
			 * @param[in] event 待つイベントを指定する
			 * @return 命令のインスタンス
			 * @note イベントが発生したら１つだけインデックスを進める
			 */
			parts::Instruction operator()(event::parts::Event const & event);
			/**
			 * ２つのイベントを待つ
			 * @param[in] event1 待つイベント１
			 * @param[in] event2 待つイベント２
			 * @return 命令のインスタンス
			 * @note 発生したイベントごとに指定された数だけインデックスを進める
			 */
			parts::Instruction operator()(event::parts::EventWithIndex const & event1, event::parts::EventWithIndex const & event2);
		};
		struct SetRun {
			/**
			 * 走法を設定する
			 * @param[in] run 走法（runmethod::createrを指定すること）
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(runmethod::impl::RunAbstract * run);
		};
		struct Goto {
			/**
			 * 指定したインデックスだけ進める
			 * @param[in] index 進めるインデックスの数
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(S16 index);
			/**
			 * 指定したラベルへ進める
			 * @param[in] label 進めるラベル
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(LABEL label);
		};
		struct SelectColorPackage {
			/**
			 * カラーパッケージを指定する（走行中に切り替えるため）
			 * @param index 指定するカラーパッケージのインデックス
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(S16 index);
		};

		struct Label {
			parts::Instruction operator()(LABEL label);
		};

		struct TailToBalance {
			/**
			 * 尻尾走行から倒立振子走行へ切り替える
			 * @return 命令のインスタンス
			 */
			operator parts::Instruction() const;
		};

		struct BalanceToTail {
			/**
			 * 倒立振子走行から尻尾走行へ切り替える
			 * @param targetAngle 目標の尻尾角度
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(int targetAngle);
		};

		struct ChangeGyroOffset {
			/**
			 * ジャイロオフセット値を変更する
			 * @param[in] gyro ジャイロオフセット値にプラス(マイナス)する値
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(int gyro);
		};

		struct InterruptEnable {
			/**
			 * 割り込み許可・不許可する
			 * @param[in] enable 許可・不許可
			 * @return 命令のインスタンス
			 */
			parts::Instruction operator()(bool enable);
		};

	} /* namespace creater */
} /* namespace instruction */
#endif /* INSTRUCTION_CREATER_H_ */
