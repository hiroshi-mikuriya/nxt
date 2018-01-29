/*
 * SetColor.h
 *
 *  Created on: 2012/05/26
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SETCOLOR_H_
#define SETCOLOR_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "Parameter.h"

namespace instruction {
	namespace impl {

		/**
		 * カラーパッケージに色を保存
		 */
		class SetColor: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * カラーパッケージに色を保存
			 * @param[in] color 保存する色
			 * @param[in] index 保存するインデックス
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int color, int index);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* SETCOLOR_H_ */
