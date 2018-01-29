/*
 * UserInstruction.h
 *
 *  Created on: 2012/06/05
 *      Author: HIROSHI MIKURIYA
 */

#ifndef USERACTION_H_
#define USERACTION_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "Typedef.h"

namespace instruction {
	namespace impl {

		/**
		 * ユーザー命令を行うクラス
		 */
		class UserInstruction: public instruction::impl::InstructionAbstract {
			userInstructionT m_userInstruction;
		public:
			/**
			 * ユーザー命令を実行する
			 * @param[in] userInstruction ユーザー命令
			 * @param[in] unuse 未使用
			 * @return 次に進むインデックス数
			 */
			int DoInstruction(int userInstruction, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* USERACTION_H_ */
