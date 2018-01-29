/*
 * Timer.h
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "ecrobot_interface.h"

namespace hardware {

	class Timer {
		Timer();
	public:
		static Timer & GetInstance();

		/**
		 * 時間取得[mm]
		 * @return 時間
		 */
		U32 GetTime() const;
		/**
		 * ウェイト[mm]
		 * @param ウェイト時間
		 */
		void Wait(U32 time_mm);
		/**
		 * スリープ[mm]
		 * @param スリープ時間
		 */
		void Sleep(U32 time_mm);
	};

} /* namespace hardware */
#endif /* TIMER_H_ */
