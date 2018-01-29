/*
 * White.cpp
 *
 *  Created on: 2012/06/20
 *      Author: YUKI SHIMIZU
 */

#include "White.h"
#include "controller/log/Logger.h"
#include "Parameter.h"

namespace event {
	namespace impl {
		namespace {
			const int W_THRETHOLD = static_cast<int>((COLOR_GRAY + COLOR_WHITE) / 2);
		}

		void White::Initialize(int unuse1, int unuse2)
		{
		}

		bool White::Notify() const
		{

			int w_count = 0;
			int color_log_size = controller::Logger::GetInstance().GetColorLog().GetSize();

			// 色ログを見ていって、境界値を上回っていたらカウント
			for (int i = 0; i < color_log_size; ++i) {
				if (W_THRETHOLD < controller::Logger::GetInstance().GetColorLog()[i]) {
					w_count++;
				}
			}

			// 境界値を上回っている数が色ログ全体の90％より多くを占めていれば検知
			return static_cast<int>(color_log_size * 0.9) < w_count;
		}

	} /* namespace impl */
} /* namespace event */
