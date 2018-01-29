/*
 * DisplayControl.h
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 */

#ifndef DISPLAYCONTROL_H_
#define DISPLAYCONTROL_H_

namespace controller {

	/**
	 * ディスプレイ制御
	 */
	class DisplayControl {
		DisplayControl();
	public:
		static DisplayControl & GetInstance();

		/**
		 * LCD表示更新
		 * @param 表示内容
		 */
		void DisplayText(char const* text);
		/**
		 * LCDに色パッケージの値を表示
		 * @param 色パッケージのインデックス
		 */
		void DisplayColor(int index);
		/**
		 * LCDにプラットフォームバージョンを表示
		 */
		void DisplayPfVersion();
	};

} /* namespace controller */
#endif /* DISPLAYCONTROL_H_ */
