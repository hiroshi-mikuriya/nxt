/*
 * Goto.h
 *
 *  Created on: 2012/06/10
 *      Author: HIROSHI
 */

#ifndef GOTO_H_
#define GOTO_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "instruction/parts/InstructionParts.h"

namespace instruction {
	namespace impl {

		class Goto: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 命令を実行する
			 * @param[in] index 次に進むインデックスor ラベル
			 * @param[in] isLabel ラベルかインデックスか
			 * @return 次に進むインデックス数
			 */
			virtual int DoInstruction(int index, int isLabel);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* GOTO_H_ */
