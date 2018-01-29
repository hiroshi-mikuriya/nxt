/*
 * EventPackage.h
 *
 *  Created on: 2012/06/09
 *      Author: HIROSHI MIKURIYA
 */

#ifndef EVENT_PACKAGE_H_
#define EVENT_PACKAGE_H_

#include "event/creater/EventCreater.h"

namespace event {
	namespace package {
		/**
		 * イベント定義
		 */
		namespace {
			creater::EventNone evNone; //!< イベントなし
			creater::Time evTime; //!< 時間経過
			creater::Distance evDistance; //!< 距離検知
			creater::Touch evTouch; //!< タッチセンサ
			creater::Angle evAngle; //!< 角度検知
			creater::Next evNext; //!< 次のプログラムへ遷移
			creater::Sonar evSonar; //!< 物体検知
			creater::Collision evCollision; //!< 衝突検知
			creater::Falldown evFalldown; //!< 転倒検知
			creater::Black evBlack; //!< 黒検知
			creater::White evWhite; //!< 白検知
			creater::Gray evGray; //!< 灰検知
			creater::Bluetooth evBluetooth; //!< Bluetooth受信検知
		}
	} /* namespace package */
} /* namespace event */

#endif // EVENT_PACKAGE_H_
