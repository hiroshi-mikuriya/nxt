/*
 * Black.cpp
 *
 *  Created on: 2012/06/20
 *      Author: YUKI SHIMIZU
 */

#include "Black.h"
#include "controller/log/Logger.h"
#include "Parameter.h"

namespace event {
	namespace impl {
		namespace {
			const int B_THRETHOLD = static_cast<int>((COLOR_GRAY + COLOR_BLACK) / 2);
		}

		void Black::Initialize(int unuse1, int unuse2)
		{
		}

		bool Black::Notify() const
		{
			int b_count = 0;
			int color_log_size = controller::Logger::GetInstance().GetColorLog().GetSize();

			// 色ログを見ていって、境界値を下回っていたらカウント
			for (int i = 0; i < color_log_size; ++i) {
				if (controller::Logger::GetInstance().GetColorLog()[i] < B_THRETHOLD) {
					b_count++;
				}
			}

			// 境界値を下回っている数が色ログ全体の90％より多くを占めていれば検知
			return static_cast<int>(color_log_size * 0.9) < b_count;
		}

	} /* namespace impl */
} /* namespace event */

