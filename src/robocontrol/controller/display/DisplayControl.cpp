/*
 * DisplayControl.cpp
 *
 *  Created on: 2012/05/25
 *      Author: HIROSHI MIKURIYA
 */

#include "DisplayControl.h"
#include "hardware/body/Body.h"
#include "controller/run/RunControl.h"
#include "config/Version.h"

/**
 * @brief マクロの数値を文字列にするためのマクロ
 */
/*@{*/
#define STRINGIZE_IN(x)		#x
#define STRINGIZE(x)		STRINGIZE_IN(x)
/*@}*/

/// プラットフォームバージョンを表すテキスト
#define PF_VERSION_TEXT	\
	STRINGIZE(PF_MAJOR_VERSION) "." \
	STRINGIZE(PF_MINOR_VERSION) "." \
	STRINGIZE(PF_REVISION_VERSION)

namespace controller {

	DisplayControl::DisplayControl()
	{
	}

	DisplayControl & DisplayControl::GetInstance()
	{
		static DisplayControl display;
		return display;
	}

	void DisplayControl::DisplayText(char const * text)
	{
		ecrobot::Lcd & lcd = hardware::Body::GetInstance().RefLcd();
		lcd.clear();
		lcd.putf("s", text);
		lcd.disp();
	}

	void DisplayControl::DisplayColor(int index)
	{
		ecrobot::Lcd & lcd = hardware::Body::GetInstance().RefLcd();
		controller::RunControl & run = controller::RunControl::GetInstance();
		lcd.clear();
		lcd.putf("sdnsdnsdnsd", "index : ", index, 3, "white : ", run.GetWhite(index), 3, "gray : ", run.GetGray(index), 3, "black : ", run.GetBlack(index), 3);
		lcd.disp();
	}

	void DisplayControl::DisplayPfVersion()
	{
		DisplayText("PF ver. " PF_VERSION_TEXT);
	}

} /* namespace controller */
