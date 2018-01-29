/*
 * BluetoothControl.cpp
 *
 *  Created on: 2012/05/19
 *      Author: HIROSHI MIKURIYA
 */

#include "BluetoothControl.h"
#include "hardware/body/Body.h"
#include "hardware/io/Io.h"
#include "hardware/timer/Timer.h"
#include "controller/log/Logger.h"
#include "controller/position/Position.h"

namespace controller {

	namespace {

		const CHAR *PASSKEY = "9999";
		const CHAR *DEVNAME = "NXT";
	}

	BluetoothControl::BluetoothControl()
			: m_connect(false), m_sendEnable(false), m_receiveEnable(false), m_lastReceivedData(0), m_lastReceivedTime(0)
	{
	}

	BluetoothControl & BluetoothControl::GetInstatnce()
	{
		static BluetoothControl bluetooth;
		return bluetooth;
	}

	bool BluetoothControl::Initialize()
	{
		m_connect = (1 == hardware::Body::GetInstance().BtConnect(PASSKEY, DEVNAME));
		return m_connect;
	}

	bool BluetoothControl::Send(U8 const * data, U32 size)
	{
		if (!(m_connect && m_sendEnable)) {
			return false;
		}
		return size == hardware::Body::GetInstance().BtSend(const_cast<U8*>(data), size);
	}

	void BluetoothControl::Send(S8 (&dataS08)[2], U16 dataU16, S16 (&dataS16)[4], S32 (&dataS32)[4])
	{
		if (m_connect && m_sendEnable) {
			hardware::Body::GetInstance().BtSend(dataS08, dataU16, dataS16, dataS32);
		}
	}
	void BluetoothControl::Send(S8 (&dataS08)[2], S32 dataS32)
	{
		if (m_connect && m_sendEnable) {
			hardware::Io & io = hardware::Io::GetInstance();
			U16 dataU16 = hardware::Body::GetInstance().GetBattMv();
			S16 dataS16[4] = { io.GetGyro(), io.GetSonar(), io.GetLight(), io.GetTouch() };
			S32 dataS32S[4] =
					{ static_cast<S32>(Position::GetInstance().GetPosition().x), static_cast<S32>(Position::GetInstance().GetPosition().y), static_cast<S32>(Position::GetInstance().GetAngle()), 0 };
			Send(dataS08, dataU16, dataS16, dataS32S);
		}
	}

	void BluetoothControl::ReceiveControl()
	{
		if (!(m_connect && m_receiveEnable)) {
			return;
		}

		U8 buf[BT_MAX_RX_BUF_SIZE] = { 0 };
		U32 size = hardware::Body::GetInstance().BtReceive(buf, sizeof(buf));

		if (0 < size) {
			m_lastReceivedTime = hardware::Timer::GetInstance().GetTime();
			m_lastReceivedData = buf[size - 1];
		}

		return;
	}

	void BluetoothControl::SetSendEnable(bool enabled)
	{
		m_sendEnable = enabled;
	}

	void BluetoothControl::SetReceiveEnable(bool enabled)
	{
		m_receiveEnable = enabled;
	}

	U8 BluetoothControl::GetLastReceiveData() const
	{
		U32 const timeRag = hardware::Timer::GetInstance().GetTime() - m_lastReceivedTime;
		if (1000 < timeRag) {
			return 0;
		}
		return m_lastReceivedData;
	}

} /* namespace controller */

