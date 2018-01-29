/*
 * Angle.h
 *
 *  Created on: 2012/05/24
 *      Author: HIROSHI MIKURIYA
 */

#ifndef ANGLE_H_
#define ANGLE_H_

#include "event/impl/abstract/EventAbstract.h"
#include "controller/position/Position.h"

namespace event {
	namespace impl {

		/**
		 * 角度検知
		 */
		class Angle: public event::impl::EventAbstract {
			int m_angle;
			int m_startAngle;
		public:

			/**
			 * 検知する角度を指定
			 * @param[in] angle 検知する角度
			 * @param[in] index 検知するための基準角度を保存しているインデックス
			 */
			virtual void Initialize(int angle, int index);
			/**
			 * 検知有無
			 * @return 検知有無
			 */
			virtual bool Notify() const;
		};

	} /* namespace impl */
} /* namespace event */
#endif /* ANGLE_H_ */
