/*
 * Bluetooth.h
 *
 *  Created on: 2012/05/27
 *      Author: HIROSHI MIKURIYA
 */

#ifndef BLUETOOTHCONNECT_H_
#define BLUETOOTHCONNECT_H_

#include "instruction/impl/abstract/InstructionAbstract.h"
#include "Parameter.h"

namespace instruction {
	namespace impl {

		/**
		 * Bluetooth関連の命令
		 */
		class Bluetooth: public instruction::impl::InstructionAbstract {
		public:
			/**
			 * Bluetooth命令（接続・通信許可）を実行する
			 * @param[in] 命令内容(BLUETOOTH_ACTION)
			 * @param[in] unuse 未使用
			 * @return NO_INDEXを返す
			 */
			int DoInstruction(int instruction, int unuse);
		};

	} /* namespace impl */
} /* namespace instruction */
#endif /* BLUETOOTHCONNECT_H_ */
