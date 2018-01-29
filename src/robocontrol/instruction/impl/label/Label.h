/*
 * Label.h
 *
 *  Created on: 2012/07/19
 *      Author: HIROSHI MIKURIYA
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		class Label: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * gotoラベルをセットする
			 * @param label ラベル番号
			 * @param unuse 未使用
			 * @param p 命令ポインタ
			 */
			void Initialize(int label, int unuse, void * p);
			/**
			 * することのない関数
			 * @param[in] unuse1 未使用
			 * @param[in] unuse2 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int unuse1, int unuse2);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* LABEL_H_ */
