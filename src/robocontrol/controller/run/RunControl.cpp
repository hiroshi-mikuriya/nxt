/*
 * RunControl.cpp
 *
 *  Created on: 2012/05/18
 *      Author: HIROSHI MIKURIYA
 */

#include "RunControl.h"
#include "hardware/io/Io.h"
#include "hardware/body/Body.h"
#include "controller/log/Logger.h"

namespace controller {

	RunControl::RunControl()
			: m_gyroOffset(0), m_modifiedGyroOffset(0), m_index(0), m_run(0)
	{
	}

	RunControl & RunControl::GetInstance()
	{
		static RunControl runControl;
		return runControl;
	}

	void RunControl::Control()
	{
		if (m_run)
			m_run->Control(m_modifiedGyroOffset == 0 ? m_gyroOffset : m_modifiedGyroOffset, GetNoiselessColor());
	}

	void RunControl::SelectPackage(int index)
	{
		m_index = index;
	}

	void RunControl::SetGyroOffset(S16 gyroOffset)
	{
		m_gyroOffset = gyroOffset;
	}

	void RunControl::SetRunMethod(runmethod::impl::RunAbstract * run)
	{
		m_run = run;
	}

	void RunControl::ChangeGyroOffset(S16 gyro)
	{
		if (gyro == 0) {
			m_modifiedGyroOffset = 0;
			return;
		}
		m_modifiedGyroOffset = m_gyroOffset + gyro;
	}
	void RunControl::SetBlack(S16 brightness, int index)
	{
		m_colorPackage[index % COLOR_PACKAGE_COUNT].SetBlack(brightness);
	}
	void RunControl::SetGray(S16 brightness, int index)
	{
		m_colorPackage[index % COLOR_PACKAGE_COUNT].SetGray(brightness);
	}
	void RunControl::SetWhite(S16 brightness, int index)
	{
		m_colorPackage[index % COLOR_PACKAGE_COUNT].SetWhite(brightness);
	}
	S16 RunControl::GetBlack(int index) const
	{
		return m_colorPackage[index].GetBlack();
	}
	S16 RunControl::GetGray(int index) const
	{
		return m_colorPackage[index].GetGray();
	}
	S16 RunControl::GetWhite(int index) const
	{
		return m_colorPackage[index].GetWhite();
	}

	int RunControl::GetColor() const
	{
		return m_colorPackage[m_index].GetStdColor(hardware::Io::GetInstance().GetLight());
	}

	int RunControl::GetNoiselessColor() const
	{
		typedef controller::Logger LogType;
		LogType::colorsLogT const & log = LogType::GetInstance().GetColorLog();
		enum {
			samplelingCount = 10 // TODO
		};
		int sum = 0;
		for (int i = LogType::COLOR_LOG_COUNT - samplelingCount; i < LogType::COLOR_LOG_COUNT; ++i) {
			sum += log[i];
		}
		return sum / samplelingCount;
	}

	void RunControl::StopRunControl()
	{
		m_run = 0;
		hardware::Io::GetInstance().SetPwm(0, 0);
	}

} /* namespace controller */
