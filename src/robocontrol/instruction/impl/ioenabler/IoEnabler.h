/*
 * IoEnabler.h
 *
 *  Created on: 2012/05/31
 *      Author: HIROSHI MIKURIYA
 */

#ifndef IOENABLER_H_
#define IOENABLER_H_

#include "instruction/impl/abstract/InstructionAbstract.h"

namespace instruction {
	namespace impl {

		/**
		 * センサの取得許可する命令
		 */
		class IoEnabler: public instruction::impl::InstructionAbstract {
			int m_enablePattern;
			bool m_enabled;

		public:
			/**
			 * センサの取得許可を設定する
			 * @param[in] enablePattern 許可パターン
			 * @param[in] enabled 許可・禁止
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int enablePattern, int enabled);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* IOENABLER_H_ */
