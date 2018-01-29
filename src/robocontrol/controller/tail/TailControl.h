/*
 * TailControl.h
 *
 *  Created on: 2012/05/17
 *      Author: HIROSHI MIKURIYA
 */

#ifndef TAILCONTROL_H_
#define TAILCONTROL_H_

#include "ecrobot_interface.h"

namespace controller {

	/**
	 * 尻尾制御
	 */
	class TailControl {
		S32 m_tailAngle; //!< 尻尾目標角度
		F32 m_pgain; //!< PGAIN値
		bool m_pcontrol; //!< P制御するかどうか
		S8 m_pwm; //!< P制御しないときのPWM値
		TailControl();
	public:
		static TailControl & GetInstance();
		/**
		 * 尻尾をコントロールする
		 */
		void Control() const;
		/**
		 * 尻尾モータの角度を設定
		 * @param 角度
		 */
		void SetAngle(S32 angle);
		/**
		 * PGAIN値を変更する
		 * @param pgain
		 */
		void SetPgain(F32 pgain);
		/**
		 * PGAIN値を元に戻す
		 */
		void SetPgainDefault();
		/**
		 * 尻尾角度を取得する
		 * @return
		 */
		S32 GetTailAngle() const;
		/**
		 * P制御を有効にする（PWM制御が無効となる）
		 */
		void SetPControl();
		/**
		 * PWM制御を有効にする（P制御が無効となる）
		 * @param pwm PWM値
		 */
		void SetPwmControl(S8 pwm);
	};

} /* namespace controller */
#endif /* TAILCONTROL_H_ */
