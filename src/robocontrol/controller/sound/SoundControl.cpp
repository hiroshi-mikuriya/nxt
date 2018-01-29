/*
 * Sound.cpp
 *
 *  Created on: 2012/05/15
 *      Author: HIROSHI MIKURIYA
 */

#include "SoundControl.h"
#include "hardware/body/Body.h"
#include "hardware/timer/Timer.h"
#include "Parameter.h"
#include "SoundDef.h"

namespace controller {

	SoundControl::SoundControl()
			: m_index(0), m_latestIndex(0)
	{
	}

	void SoundControl::Play(U32 freq, U32 duration)
	{
		hardware::Body::GetInstance().playTone(freq, duration, m_volume);
		Wait(duration);
	}

	void SoundControl::Wait(U32 duration)
	{
		hardware::Timer::GetInstance().Sleep(duration);
	}

	SoundControl & SoundControl::GetInstance()
	{
		static SoundControl sound;
		return sound;
	}

	void SoundControl::Play()
	{
		hardware::Timer & timer = hardware::Timer::GetInstance();
		for (;; timer.Sleep(100)) {
			if (m_index == m_latestIndex) {
				continue;
			}
			switch (m_requestContainer[m_index]) {
			default:
				break;
			case SOUND_CLICK:
				Play(B6, 100);
				break;
			case SOUND_CAUTION:
				Play(B6, 100);
				Wait(100);
				Play(B6, 500);
				break;
			case SOUND_OK:
				Play(E6, 100);
				Play(D6, 100);
				Play(E6, 100);
				Play(D6, 500);
				break;
			case SOUND_ERROR:
				Play(B6, 100);
				Wait(100);
				Play(B6, 100);
				Wait(100);
				Play(B6, 100);
				Wait(100);
				Play(B6, 100);
				Wait(100);
				Play(B6, 100);
				break;
			}
			m_requestContainer[m_index] = SOUND_NONE;
			m_index = (m_index + 1) % REQUEST_COUNT;
		}
	}

	void SoundControl::Request(int pattern)
	{
		m_latestIndex = (m_latestIndex + 1) % REQUEST_COUNT;
		m_requestContainer[m_latestIndex] = pattern;
	}

	void SoundControl::SetVolume(int volume)
	{
		m_volume = volume;
	}

} /* namespace controller */
