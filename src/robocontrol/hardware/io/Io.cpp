/*
 * Input.cpp
 *
 *  Created on: 2012/05/14
 *      Author: HIROSHI MIKURIYA
 */

#include "Io.h"

#include <Motor.h>
#include <LightSensor.h>
#include <GyroSensor.h>
#include <SonarSensor.h>
#include <TouchSensor.h>

namespace hardware {
	namespace {
		ecrobot::GyroSensor s_gyro(PORT_1);
		ecrobot::SonarSensor s_sonar(PORT_2);
		ecrobot::LightSensor s_light(PORT_3);
		ecrobot::TouchSensor s_touch(PORT_4);
		ecrobot::Motor s_tailMotor(PORT_A);
		ecrobot::Motor s_rightMotor(PORT_B);
		ecrobot::Motor s_leftMotor(PORT_C);
	}

	Io::Io()
			: m_rightMotorEnabled(false), m_leftMotorEnabled(false), m_tailMotorEnabled(false), m_gyroEnabled(false), m_lightEnabled(false), m_sonarEnabled(false), m_touchEnabled(false)

	{
	}

	Io & Io::GetInstance()
	{
		static hardware::Io io;
		return io;
	}

	void Io::Update()
	{
		if (m_rightMotorEnabled)
			m_rightMotorCount = s_rightMotor.getCount();
		if (m_leftMotorEnabled)
			m_leftMotorCount = s_leftMotor.getCount();
		if (m_gyroEnabled)
			m_gyro = s_gyro.get();
		if (m_lightEnabled)
			m_light = s_light.getBrightness();
	}

	void Io::UpdateSonar()
	{
		if (m_sonarEnabled)
			m_sonar = s_sonar.getDistance();
	}

	void Io::UpdateTouch()
	{
		if (m_touchEnabled)
			m_touch = s_touch.isPressed();
	}

	void Io::UpdateTail()
	{
		if (m_tailMotorEnabled)
			m_tailMotorCount = s_tailMotor.getCount();
	}

	void Io::SetPwm(S8 leftPwm, S8 rightPwm)
	{
		if (m_leftMotorEnabled)
			s_leftMotor.setPWM(leftPwm);
		if (m_rightMotorEnabled)
			s_rightMotor.setPWM(rightPwm);
	}

	void Io::SetTailPwm(S8 tailPwm)
	{
		if (m_tailMotorEnabled)
			s_tailMotor.setPWM(tailPwm);
	}

	S32 Io::GetRightMotorCount() const
	{
		return m_rightMotorCount;
	}

	S32 Io::GetLeftMotorCount() const
	{
		return m_leftMotorCount;
	}

	S32 Io::GetTailMotorCount() const
	{
		return m_tailMotorCount;
	}

	S16 Io::GetGyro() const
	{
		return m_gyro;
	}

	S16 Io::GetLight() const
	{
		return m_light;
	}

	S16 Io::GetSonar() const
	{
		return m_sonar;
	}

	bool Io::GetTouch() const
	{
		return m_touch;
	}

	void Io::SetRightMotorEnabled(bool enabled)
	{
		m_rightMotorEnabled = enabled;
	}

	void Io::SetLeftMotorEnabled(bool enabled)
	{
		m_leftMotorEnabled = enabled;
	}

	void Io::SetTailMotorEnabled(bool enabled)
	{
		m_tailMotorEnabled = enabled;
	}

	void Io::SetGyroEnabled(bool enabled)
	{
		m_gyroEnabled = enabled;
	}

	void Io::SetLightEnabled(bool enabled)
	{
		m_lightEnabled = enabled;
	}

	void Io::SetSonarEnabled(bool enabled)
	{
		m_sonarEnabled = enabled;
	}

	void Io::SetTouchEnabled(bool enabled)
	{
		m_touchEnabled = enabled;
	}

	void Io::InitTireMotorCount()
	{
		s_rightMotor.setCount(0);
		s_leftMotor.setCount(0);
	}

} /* namespace hardware */
