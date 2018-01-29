/*
 * Display.h
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "Parameter.h"

namespace instruction {
	namespace impl {

		/**
		 * 画面関連の命令
		 */
		class Display: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 画面表示を実行
			 * @param[in] instruction 命令内容
			 * @param[in] param 命令に応じたパラメータ
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int instruction, int param);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* DISPLAY_H_ */
