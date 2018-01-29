/*
 * TailControl.cpp
 *
 *  Created on: 2012/05/17
 *      Author: HIROSHI MIKURIYA
 */

#include "TailControl.h"
#include "hardware/io/Io.h"
#include "Common.h"

namespace controller {

	const S16 MAX_POWER = 100;
	const F32 P_GAIN_DEFAULT = 2.5F;

	TailControl::TailControl()
			: m_tailAngle(0), m_pgain(P_GAIN_DEFAULT), m_pcontrol(true)
	{
	}

	TailControl & TailControl::GetInstance()
	{
		static TailControl tailControl;
		return tailControl;
	}

	void TailControl::Control() const
	{
		S16 const power = static_cast<S16>(m_pgain * (m_tailAngle - hardware::Io::GetInstance().GetTailMotorCount()));
		S8 pwm;
		if (m_pcontrol) {
			S16 const compPower = compress_cast<S16, -MAX_POWER, MAX_POWER>(power);
			pwm = static_cast<S8>(compPower);
		}
		else {
			pwm = 0 <= power ? m_pwm : -m_pwm;
		}
		hardware::Io::GetInstance().SetTailPwm(pwm);
	}

	void TailControl::SetAngle(S32 angle)
	{
		m_tailAngle = angle;
	}

	void TailControl::SetPgain(F32 pgain)
	{
		m_pgain = pgain;
	}

	void TailControl::SetPgainDefault()
	{
		SetPgain(P_GAIN_DEFAULT);
	}

	S32 TailControl::GetTailAngle() const
	{
		return hardware::Io::GetInstance().GetTailMotorCount();
	}

	void TailControl::SetPControl()
	{
		m_pcontrol = true;
	}

	void TailControl::SetPwmControl(S8 pwm)
	{
		m_pcontrol = false;
		m_pwm = pwm;
	}

} /* namespace controller */
