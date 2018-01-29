/*
 * EventCreater.h
 *
 *  Created on: 2012/06/05
 *      Author: HIROSHI MIKURIYA
 */

#ifndef EVENTCREATER_H_
#define EVENTCREATER_H_

#include "event/parts/EventParts.h"
#include "Parameter.h"

namespace event {
	namespace creater {

		struct EventNone {
			/**
			 * 検知しないイベント
			 * @return イベントのインスタンス
			 */
			operator parts::Event();
			/**
			 * 検知しないイベント
			 * @return イベントのインスタンス
			 */
			operator parts::EventWithIndex();
		};
		struct Time {
			/**
			 * 時間待ちをするイベント
			 * @param[in] time_ms 待つ時間（ミリ秒）
			 * @return イベントのインスタンス
			 */
			parts::Event operator()(int time_ms);
			/**
			 * 指定した基準時間からの時間待ちをするイベント
			 * @param[in] time_ms 待つ時間（ミリ秒）
			 * @param[in] index 基準時間が保存されているインデックス
			 * @return イベントのインスタンス
			 */
			parts::Event operator()(int time_ms, int index);
		};
		struct Distance {
			/**
			 * 距離を検知するイベント
			 * @param[in] time_ms 検知する距離（ミリメートル）
			 * @return イベントのインスタンス
			 */
			parts::Event operator()(int length_mm);
			/**
			 * 指定した座標からの距離を検知するイベント
			 * @param[in] time_ms 検知する距離（ミリメートル）
			 * @param[in] index 基準とする座標が保存されているインデックス
			 * @return イベントのインスタンス
			 */
			parts::Event operator()(int length_mm, int index);
		};
		struct Touch {
			/**
			 * タッチイベント
			 * @return イベントのインスタンス
			 */
			operator parts::Event();
			/**
			 * タッチイベント＋イベント発生後に進めるインデックス
			 * @param[in] index イベント発生後に進めるインデックス
			 * @return イベントのインスタンス
			 */
			parts::EventWithIndex operator>>(S16 index);
		};
		struct Angle {
			/**
			 * 角度変化を検知するイベント
			 * @param[in] angle 検知する角度
			 * @return イベントのインスタンス
			 */
			parts::Event operator()(int angle);
			/**
			 * 基準角からの変化を検知するイベント
			 * @param[in] angle 検知する角度
			 * @param[in] index 基準角が保存されているインデックス
			 * @return イベントのインスタンス
			 */
			parts::Event operator()(int angle, int index);
		};
		struct Next {
			/**
			 * すぐに完了するイベント
			 * @return イベントのインスタンス
			 */
			operator parts::Event();
			/**
			 * すぐに完了するイベント
			 * @param[in] index イベント発生後に進めるインデックス数
			 * @return イベントのインスタンス
			 */
			parts::EventWithIndex operator>>(S16 index);
		};
		struct Sonar {
			/**
			 * ソナーセンサによる物体検知イベント
			 * @param[in] distance 検知する物体との距離（センチメートル）
			 * @return イベントのインスタンス
			 */
			parts::Event operator()(int distance);
		};

		struct Collision {
			/**
			 * ジャイロセンサによる衝突検知イベント
			 */
			operator parts::Event();

			/**
			 * ジャイロセンサによる衝突検知イベント
			 * @param[in] index イベント発生後に進めるインデックス
			 */
			parts::EventWithIndex operator>>(S16 index);
		};

		struct Falldown {
			/**
			 * ジャイロセンサによる転倒検知イベント
			 */
			operator parts::Event();

			/**
			 * ジャイロセンサによる転倒検知イベント
			 * @param[in] index イベント発生後に進めるインデックス
			 */
			parts::EventWithIndex operator>>(S16 index);
		};

		struct Black {
			/**
			 * 色値のログによる黒検知イベント
			 */
			operator parts::Event();

			/**
			 * 色値のログによる黒検知イベント
			 * @param[in] index イベント発生後に進めるインデックス
			 */
			parts::EventWithIndex operator>>(S16 index);
		};

		struct White {
			/**
			 * 色値のログによる白検知イベント
			 */
			operator parts::Event();

			/**
			 * 色値のログによる白検知イベント
			 * @param[in] index イベント発生後に進めるインデックス
			 */
			parts::EventWithIndex operator>>(S16 index);
		};

		struct Gray {
			/**
			 * 色値のログによる灰検知イベント
			 */
			operator parts::Event();

			/**
			 * 色値のログによる灰検知イベント
			 * @param[in] index イベント発生後に進めるインデックス
			 */
			parts::EventWithIndex operator>>(S16 index);
		};

		struct Bluetooth {
			/**
			 * Bluetoothによる受信検知イベント
			 * @param[in] command 受信するコマンドの種類
			 */
			parts::Event operator()(RECIEVE_TYPE type);
			/**
			 * Bluetooth受信検知イベント＋イベント発生後に進めるインデックス
			 * @param[in] index イベント発生後に進めるインデックス
			 * @return イベントのインスタンス
			 */
			parts::EventWithIndex operator>>(S16 index);
		};

	} /* namespace creater */
} /* namespace programparts */
#endif /* EVENTCREATER_H_ */
