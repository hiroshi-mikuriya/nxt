/*
 * Angle.cpp
 *
 *  Created on: 2012/05/24
 *      Author: HIROSHI MIKURIYA
 */

#include "Angle.h"
#include "controller/save/SaveData.h"

namespace event {
	namespace impl {
		template<typename AnyType>
		AnyType abs(AnyType const & a)
		{
			return a < 0 ? -a : a;
		}

		void Angle::Initialize(int angle, int index)
		{
			m_angle = abs(angle);
			m_startAngle = index < 0 ? controller::Position::GetInstance().GetAngle() : controller::SaveData::GetInstance().GetAngle(index);
		}

		bool Angle::Notify() const
		{
			return m_angle <= abs(m_startAngle - controller::Position::GetInstance().GetAngle());
		}

	} /* namespace impl */
} /* namespace event */
