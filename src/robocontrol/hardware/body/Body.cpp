/*
 * Body.cpp
 *
 *  Created on: 2012/05/23
 *      Author: HIROSHI MIKURIYA
 */

#include "Body.h"

#include <Speaker.h>
#include <Nxt.h>
#include <Bluetooth.h>
#include <BTConnection.h>
#include <Daq.h>

namespace hardware {
	namespace {
		ecrobot::Speaker s_speaker;
		ecrobot::Nxt s_nxt;
		ecrobot::Lcd s_lcd;
		ecrobot::Bluetooth s_bluetooth;
		ecrobot::BTConnection s_btConnect(s_bluetooth, s_lcd, s_nxt);
		ecrobot::Daq s_daq(s_bluetooth);
	}

	Body::Body()
	{
	}

	Body & Body::GetInstance()
	{
		static Body body;
		return body;
	}

	void Body::playTone(U32 freq, U32 duration, U32 volume)
	{
		s_speaker.playTone(freq, duration, volume);
	}

	ecrobot::Lcd & Body::RefLcd()
	{
		return s_lcd;
	}

	S16 Body::GetBattMv(void) const
	{
		return s_nxt.getBattMv();
	}

	S32 Body::BtConnect(const CHAR *passkey, const CHAR *devname)
	{
		return s_btConnect.connect(passkey, devname);
	}

	U32 Body::BtSend(U8 *data, U32 length)
	{
		return s_bluetooth.send(data, length);
	}

	void Body::BtSend(S8 dataS08[2], U16 dataU16, S16 dataS16[4], S32 dataS32[4])
	{
		s_daq.send(dataS08, dataU16, dataS16, dataS32);
	}

	U32 Body::BtReceive(U8 *data, U32 length) const
	{
		// receiveのAPIは2つあるが、推奨されるAPIを使用しないと正しく受信できない。
		return s_bluetooth.receive(data, 0, length);
	}

} /* namespace hardware */
