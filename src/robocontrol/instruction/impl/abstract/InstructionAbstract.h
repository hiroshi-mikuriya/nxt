/*
 * InstructionAbstract.h
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#ifndef INSTRUCTION_ABSTRACT_H_
#define INSTRUCTION_ABSTRACT_H_

#include "Parameter.h"

namespace instruction {
	namespace impl {

		/**
		 * 命令の基底クラス
		 */
		class InstructionAbstract {
		public:
			virtual ~InstructionAbstract();
			/**
			 * 命令の初期化をする
			 * @param param1
			 * @param param2
			 * @param p 命令へのポインタ
			 */
			virtual void Initialize(int param1, int param2, void * p);
			/**
			 * 命令を実行する
			 * @return 次に進むインデックス数
			 */
			virtual int DoInstruction(int param1, int param2)=0;
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* INSTRUCTION_ABSTRACT_H_ */
