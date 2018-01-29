/*
 * ColorPackage.cpp
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#include "ColorPackage.h"
#include "Parameter.h"

namespace controller {

	ColorPackage::ColorPackage()
	{
	}

	void ColorPackage::SetBlack(S16 black)
	{
		m_black = black;
	}
	void ColorPackage::SetGray(S16 gray)
	{
		m_gray = gray;
	}
	void ColorPackage::SetWhite(S16 white)
	{
		m_white = white;
	}

	bool ColorPackage::IsValidColors() const
	{
		return m_black < m_gray && m_gray && m_white;
	}
	int ColorPackage::GetStdColor(S16 brightness) const
	{
#if 0
		if (brightness <= m_black)
		{
			return COLOR_BLACK;
		}
		if (brightness <= m_gray)
		{
			return COLOR_BLACK
			+ (COLOR_GRAY - COLOR_BLACK) * (brightness - m_black)
			/ (m_gray - m_black);
		}
		if (brightness <= m_white)
		{
			return COLOR_GRAY
			+ (COLOR_WHITE - COLOR_GRAY) * (brightness - m_gray)
			/ (m_white - m_gray);
		}
		return COLOR_WHITE;
#else
		if (brightness <= m_gray) {
			int diff = m_gray - brightness;
			int range = m_gray - m_black;
			return COLOR_GRAY - (COLOR_GRAY - COLOR_BLACK) * diff / range;
		}
		else {
			int diff = brightness - m_gray;
			int range = m_white - m_gray;
			return COLOR_GRAY + (COLOR_WHITE - COLOR_GRAY) * diff / range;
		}

#endif
	}
	S16 ColorPackage::GetBlack() const
	{
		return m_black;
	}
	S16 ColorPackage::GetGray() const
	{
		return m_gray;
	}
	S16 ColorPackage::GetWhite() const
	{
		return m_white;
	}

} /* namespace controller */
