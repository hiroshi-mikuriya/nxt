/*
 * WaitEvent.h
 *
 *  Created on: 2012/06/09
 *      Author: HIROSHI
 */

#ifndef WAITEVENT_H_
#define WAITEVENT_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * イベントが発生するまで待つ
		 */
		class WaitEvent: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 命令を実行する
			 * @param[in] event1 待ちイベント1
			 * @param[in] event2 待ちイベント2
			 * @return 次に進むインデックス数
			 */
			virtual int DoInstruction(int event1, int event2);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* WAITEVENT_H_ */
