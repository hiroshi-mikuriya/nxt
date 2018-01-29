/*
 * Sonar.cpp
 *
 *  Created on: 2012/05/28
 *      Author: HIROSHI MIKURIYA
 */

#include "Sonar.h"
#include "controller/log/Logger.h"

namespace event {
	namespace impl {

		void Sonar::Initialize(int distance, int unuse)
		{
			m_distance = distance;
		}

		bool Sonar::Notify() const
		{
			S16 distance = controller::Logger::GetInstance().GetSonarLog().GetAverage();
			return 0 < distance && distance < m_distance;
		}

	} /* namespace impl */
} /* namespace event */
