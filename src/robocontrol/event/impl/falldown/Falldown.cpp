/*
 * Falldown.cpp
 *
 *  Created on: 2012/08/05
 *      Author: YUKI SHIMIZU
 */

#include "Falldown.h"
#include "controller/log/Logger.h"

namespace event {
	namespace impl {
		namespace {
			// 転倒した時の分散値
			const S16 FALL_VARIANCE = 15000;
		}

		void Falldown::Initialize(int unuse1, int unuse2)
		{
		}

		bool Falldown::Notify() const
		{
			// ジャイロの値だけで検知
			// TODO モータへの入力などを条件に入れて精度を上げると良い
			return FALL_VARIANCE < static_cast<S16>(controller::Logger::GetInstance().GetGyroLog().GetVariance());
		}

	} /* namespace impl */
} /* namespace event */

