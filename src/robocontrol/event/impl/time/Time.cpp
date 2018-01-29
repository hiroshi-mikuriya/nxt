/*
 * Time.cpp
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#include "Time.h"
#include "controller/save/SaveData.h"
#include <Clock.h>

namespace event {
	namespace impl {

		namespace {
			ecrobot::Clock s_clock;
		}

		/**
		 * タイムイベントの初期化
		 * @param[in] time_ms イベント検知時間(ms)
		 */
		void Time::Initialize(int time_ms, int index)
		{
			m_time_ms = time_ms;
			m_startTime = index < 0 ? s_clock.now() : controller::SaveData::GetInstance().GetTime(index);
		}

		/**
		 * タイムイベント検知有無
		 * @return イベント発生有無
		 */
		bool Time::Notify() const
		{
			return m_time_ms < static_cast<int>(s_clock.now() - m_startTime);
		}

	} /* namespace impl */
} /* namespace event */
