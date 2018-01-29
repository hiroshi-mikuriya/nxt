/*
 * Distance.h
 *
 *  Created on: 2012/05/22
 *      Author: HIROSHI MIKURIYA
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_

#include "event/impl/abstract/EventAbstract.h"
#include "controller/position/Position.h"

namespace event {
	namespace impl {

		class Distance: public event::impl::EventAbstract {
			int m_length_mm2;
			utils::RealPoint m_startPoint;
		public:

			/**
			 * 距離と基準座標のインデックスを指定
			 * @param[in] length_mm 指定距離
			 * @param[in] index 基準座標のインデックス
			 */
			virtual void Initialize(int length_mm, int index);
			/**
			 * 検知有無
			 * @return 検知有無
			 */
			virtual bool Notify() const;
		};

	} /* namespace impl */
} /* namespace event */
#endif /* DISTANCE_H_ */
