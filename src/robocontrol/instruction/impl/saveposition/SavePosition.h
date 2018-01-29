/*
 * SavePosition.h
 *
 *  Created on: 2012/05/12
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SAVEPOSITION_H_
#define SAVEPOSITION_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * 座標を保存
		 */
		class SavePosition: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 座標を保存する
			 * @param[in] index 保存するインデックス
			 * @param[in] 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int index, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* SAVEPOSITION_H_ */
