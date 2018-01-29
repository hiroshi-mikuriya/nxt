/*
 * Bluetooth.cpp
 *
 *  Created on: 2012/05/27
 *      Author: HIROSHI MIKURIYA
 */

#include "Bluetooth.h"
#include "controller/bluetooth/BluetoothControl.h"

namespace instruction {
	namespace impl {

		int Bluetooth::DoInstruction(int instruction, int unuse)
		{
			switch (static_cast<BLUETOOTH_ACTION>(instruction)) {
			case BLUETOOTH_CONNECT:
				controller::BluetoothControl::GetInstatnce().Initialize();
				break;
			case BLUETOOTH_SEND_ENABLE:
				controller::BluetoothControl::GetInstatnce().SetSendEnable(true);
				break;
			case BLUETOOTH_RECEIVE_ENABLE:
				controller::BluetoothControl::GetInstatnce().SetReceiveEnable(true);
				break;
			}
			return NO_INDEX;
		}

	} /* namespace impl */
} /* namespace instruction */
