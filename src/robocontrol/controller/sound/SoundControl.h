/*
 * Sound.h
 *
 *  Created on: 2012/05/15
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SOUND_CONTROL_H_
#define SOUND_CONTROL_H_

#include "ecrobot_interface.h"

namespace controller {

	/**
	 * 音制御
	 */
	class SoundControl {
		enum {
			REQUEST_COUNT = 5,
		};
		int m_requestContainer[REQUEST_COUNT];
		int m_volume;
		int m_index;
		int m_latestIndex;
		void Play(U32 freq, U32 duration);
		void Wait(U32 duration);

		SoundControl();
	public:
		static SoundControl & GetInstance();

		/**
		 * 音鳴動
		 */
		void Play();
		/**
		 * 音をリクエストする
		 * @param[in] pattrn リクエストする音
		 */
		void Request(int pattern);
		/**
		 * 音量を設定する
		 */
		void SetVolume(int volume);
	};

} /* namespace controller */
#endif /* SOUND_CONTROL_H_ */
