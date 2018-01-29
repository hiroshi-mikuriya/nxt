/*
 * Gray.cpp
 *
 *  Created on: 2012/08/01
 *      Author: HIROSHI MIKURIYA
 */

#include "Gray.h"
#include "controller/log/Logger.h"

namespace event {
	namespace impl {
		template<typename AnyType>
		AnyType abs(AnyType const & a)
		{
			return a < 0 ? -a : a;
		}

		void Gray::Initialize(int unuse1, int unuse2)
		{
			// do nothing
		}

		bool Gray::Notify() const
		{
			controller::Logger::colorsLogT const & log = controller::Logger::GetInstance().GetColorLog();
			int sum = 0;
			for (int i = 0; i < log.GetSize(); ++i) {
				sum += abs(log[i] - 280); // 灰200, 白400との仮定のもと成立する式
			}
			return sum < 2000; // この閾値を大きくすると感度が上がり、小さくすると感度が下がる
		}

	} /* namespace impl */
} /* namespace event */
