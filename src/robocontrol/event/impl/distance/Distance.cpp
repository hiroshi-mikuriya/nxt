/*
 * Distance.cpp
 *
 *  Created on: 2012/05/22
 *      Author: HIROSHI MIKURIYA
 */

#include "Distance.h"
#include "utils/Point.hpp"
#include "controller/save/SaveData.h"

namespace event {
	namespace impl {

		namespace {
			int CalcLength(utils::RealPoint const & p1, utils::RealPoint const & p2)
			{
				utils::RealPoint const pos = p1 - p2;
				return static_cast<int>(pos * pos);
			}
		}

		void Distance::Initialize(int length_mm, int index)
		{
			m_length_mm2 = length_mm * length_mm;
			m_startPoint = index < 0 ? controller::Position::GetInstance().GetPosition() : controller::SaveData::GetInstance().GetPosition(index);
		}

		bool Distance::Notify() const
		{
			// 平方根を求める処理を行うと、バイナリサイズが大きくなるため（約1kByte）、
			// 距離の２乗で評価する
			return m_length_mm2 < CalcLength(m_startPoint, controller::Position::GetInstance().GetPosition());
		}

	} /* namespace impl */
} /* namespace event */
