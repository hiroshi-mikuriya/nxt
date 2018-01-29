/*
 * Sonar.h
 *
 *  Created on: 2012/05/28
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SONAR_H_
#define SONAR_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		class Sonar: public event::impl::EventAbstract {
			int m_distance;
		public:
			/**
			 * 初期化
			 * @param[in] distance 物体との距離[cm]
			 * @param[in] unuse 未使用
			 */
			virtual void Initialize(int distance, int unuse);
			/**
			 * 検知有無
			 * @return 検知有無
			 */
			virtual bool Notify() const;
		};

	} /* namespace impl */
} /* namespace event */
#endif /* SONAR_H_ */
