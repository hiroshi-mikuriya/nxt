/*
 * Input.h
 *
 *  Created on: 2012/05/14
 *      Author: HIROSHI MIKURIYA
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

#include "mytypes.h"

namespace hardware {

	/**
	 * センサ、モーターの値を保持する
	 */
	class Io {

		S32 m_rightMotorCount;
		S32 m_leftMotorCount;
		S32 m_tailMotorCount;
		S16 m_gyro;
		S16 m_light;
		S16 m_sonar;
		bool m_touch;

		bool m_rightMotorEnabled;
		bool m_leftMotorEnabled;
		bool m_tailMotorEnabled;
		bool m_gyroEnabled;
		bool m_lightEnabled;
		bool m_sonarEnabled;
		bool m_touchEnabled;

		Io();
	public:
		static Io & GetInstance();

		/**
		 * IOを更新する（ソナー、タッチ以外）
		 */
		void Update();
		/**
		 * ソナーを更新
		 */
		void UpdateSonar();
		/**
		 * タッチセンサを更新
		 */
		void UpdateTouch();
		/**
		 * 尻尾モーターを更新
		 */
		void UpdateTail();
		/**
		 * 走行モーターのPWMを設定
		 * @param 左モーターPWM
		 * @param 右モーターPWM
		 */
		void SetPwm(S8 leftPwm, S8 rightPwm);
		/**
		 * 尻尾モーターのPWMを設定
		 * @param 尻尾モーターPWM
		 */
		void SetTailPwm(S8 tailPwm);
		/**
		 * 右モーターのカウントを取得
		 * @return 右モーターのカウント
		 */
		S32 GetRightMotorCount() const;
		/**
		 * 左モーターのカウントを取得
		 * @return 左モーターのカウント
		 */
		S32 GetLeftMotorCount() const;
		/**
		 * 尻尾モーターのカウントを取得
		 * @return 尻尾モーターのカウント
		 */
		S32 GetTailMotorCount() const;
		/**
		 * ジャイロセンサ値を取得
		 * @return ジャイロセンサ値
		 */
		S16 GetGyro() const;
		/**
		 * ライトセンサ値を取得
		 * @return ライトセンサ値
		 */
		S16 GetLight() const;
		/**
		 * ソナー値を取得
		 * @return ソナー値
		 */
		S16 GetSonar() const;
		/**
		 * タッチセンサ値を取得
		 * @return タッチセンサ値
		 */
		bool GetTouch() const;
		/**
		 * 右モーター使用許可を設定
		 * @param 許可
		 */
		void SetRightMotorEnabled(bool enabled);
		/**
		 * 左モーター使用許可を設定
		 * @param 許可
		 */
		void SetLeftMotorEnabled(bool enabled);
		/**
		 * 尻尾モーター使用許可を設定
		 * @param 許可
		 */
		void SetTailMotorEnabled(bool enabled);
		/**
		 * ジャイロセンサ取得許可を設定
		 * @param 許可
		 */
		void SetGyroEnabled(bool enabled);
		/**
		 * 光センサ取得許可を設定
		 * @param 許可
		 */
		void SetLightEnabled(bool enabled);
		/**
		 * ソナー取得許可を設定
		 * @param 許可
		 */
		void SetSonarEnabled(bool enabled);
		/**
		 * タッチセンサ取得許可を設定
		 * @param 許可
		 */
		void SetTouchEnabled(bool enabled);
		/**
		 * タイヤモーターカウントを初期化する
		 * @note balance_initするときに呼び出す想定
		 */
		void InitTireMotorCount();
	};

} /* namespace hardware */
#endif /* HARDWARE_H_ */
