/*
 * Logger.cpp
 *
 *  Created on: 2012/05/13
 *      Author: HIROSHI MIKURIYA
 */

#include "Logger.h"
#include "hardware/io/Io.h"
#include "controller/run/RunControl.h"

namespace controller {

	namespace {
		Logger::gyroLogT s_gyroLog;
		Logger::lightLogT s_lightLog;
		Logger::colorsLogT s_colorsLog;
		Logger::sonarLogT s_sonarLog;
	}

	Logger::Logger()
	{
	}

	Logger & Logger::GetInstance()
	{
		static Logger logger;
		return logger;
	}

	void Logger::Update()
	{
		s_gyroLog.SetNewData(hardware::Io::GetInstance().GetGyro());
		s_lightLog.SetNewData(hardware::Io::GetInstance().GetLight());
		s_colorsLog.SetNewData(controller::RunControl::GetInstance().GetColor());
	}

	void Logger::UpdateSonar()
	{
		s_sonarLog.SetNewData(hardware::Io::GetInstance().GetSonar());
	}

	Logger::gyroLogT const & Logger::GetGyroLog()
	{
		return s_gyroLog;
	}
	Logger::lightLogT const & Logger::GetLightLog()
	{
		return s_lightLog;
	}
	Logger::colorsLogT const & Logger::GetColorLog()
	{
		return s_colorsLog;
	}
	Logger::sonarLogT const & Logger::GetSonarLog()
	{
		return s_sonarLog;
	}

} /* namespace controller */
