/*
 * SaveTime.h
 *
 *  Created on: 2012/05/19
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SAVETIME_H_
#define SAVETIME_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * 時間を保存する
		 */
		class SaveTime: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 時間を保存する
			 * @param[in] 保存するインデックス
			 * @param[in] 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int index, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* SAVETIME_H_ */
