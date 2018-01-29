/*
 * SaveAngle.h
 *
 *  Created on: 2012/05/12
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SAVEANGLE_H_
#define SAVEANGLE_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * 角度を保存
		 */
		class SaveAngle: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * 角度を保存する
			 * @param[in] index インデックス
			 * @param[in] 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int index, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* SAVEANGLE_H_ */
