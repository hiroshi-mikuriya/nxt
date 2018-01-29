/*
 * SelectColorPackage.h
 *
 *  Created on: 2012/05/28
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SELECTCOLORPACKAGE_H_
#define SELECTCOLORPACKAGE_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * 使用するカラーパッケージを選択する
		 */
		class SelectColorPackage: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * カラーパッケージを選択する
			 * @param[in] index 指定するインデックス
			 * @param[in] unuse 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int index, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* SELECTCOLORPACKAGE_H_ */
