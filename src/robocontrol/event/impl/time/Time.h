/*
 * Time.h
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#ifndef TIME_H_
#define TIME_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		/**
		 * 時間検出イベント
		 */
		class Time: public event::impl::EventAbstract {
			int m_time_ms;
			int m_startTime;
		public:
			/**
			 * 検知時間と基準時間のインデックスを指定
			 * @param[in] time_ms 検知時間
			 * @param[in] index 基準時間を保持するインデックスを指定
			 */
			virtual void Initialize(int time_ms, int index);
			/**
			 * 検知有無
			 * @return 検知有無
			 */
			virtual bool Notify() const;
		};

	} /* namespace impl */
} /* namespace event */
#endif /* TIME_H_ */
