/*
 * Collision.cpp
 *
 *  Created on: 2012/06/20
 *      Author: YUKI SHIMIZU
 */

#include "Collision.h"
#include "controller/log/Logger.h"

namespace event {
	namespace impl {
		namespace {
			// 衝突した時の分散値
			const S16 COL_VARIANCE = 5000;
		}

		void Collision::Initialize(int unuse1, int unuse2)
		{
		}

		bool Collision::Notify() const
		{
			return COL_VARIANCE < static_cast<S16>(controller::Logger::GetInstance().GetGyroLog().GetVariance());
		}

	} /* namespace impl */
} /* namespace event */

