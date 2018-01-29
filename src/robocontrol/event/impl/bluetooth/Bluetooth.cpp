/*
 * Bluetooth.cpp
 *
 *  Created on: 2012/07/22
 *      Author: YUKI SHIMIZU
 */

#include "Bluetooth.h"
#include "Parameter.h"
#include "controller/bluetooth/BluetoothControl.h"

namespace event {
	namespace impl {
		namespace {
			const char COMMAND_START = 'a';
			const char COMMAND_STOP = 'z';
		}

		void Bluetooth::Initialize(int type, int unuse)
		{
			m_type = type;
		}

		bool Bluetooth::Notify() const
		{
			controller::BluetoothControl &bt = controller::BluetoothControl::GetInstatnce();
			if (static_cast<RECIEVE_TYPE>(m_type) == BLUETOOTH_START) {
				return static_cast<char>(bt.GetLastReceiveData()) == COMMAND_START;
			}
			else if (static_cast<RECIEVE_TYPE>(m_type) == BLUETOOTH_STOP) {
				return static_cast<char>(bt.GetLastReceiveData()) == COMMAND_STOP;
			}

			return false;
		}

	} /* namespace impl */
} /* namespace event */
