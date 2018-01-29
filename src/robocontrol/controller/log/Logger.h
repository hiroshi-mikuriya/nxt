/*
 * Logger.h
 *
 *  Created on: 2012/05/13
 *      Author: HIROSHI MIKURIYA
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "utils/RingBuffer.hpp"
#include "ecrobot_interface.h"

namespace controller {

	/**
	 * ログを管理する
	 */
	class Logger {
	public:
		enum {
			/// ジャイロログの数
			GYRO_LOG_COUNT = 100,
			/// ライトログの数
			LIGHT_LOG_COUNT = 30,
			/// 色ログの数
			COLOR_LOG_COUNT = 100,
			/// ソナーログの数
			SONAR_LOG_COUNT = 10,
		};

		typedef utils::RingBuffer<S16, GYRO_LOG_COUNT> gyroLogT;
		typedef utils::RingBuffer<S16, LIGHT_LOG_COUNT> lightLogT;
		typedef utils::RingBuffer<S16, COLOR_LOG_COUNT> colorsLogT;
		typedef utils::RingBuffer<S16, SONAR_LOG_COUNT> sonarLogT;

	private:

		Logger();
	public:
		static Logger & GetInstance();
		/**
		 * ソナー以外のログを更新
		 */
		void Update();
		/**
		 * ソナーログを更新
		 */
		void UpdateSonar();
		void UpdateTouch();

		gyroLogT const & GetGyroLog();
		lightLogT const & GetLightLog();
		colorsLogT const & GetColorLog();
		sonarLogT const & GetSonarLog();
	};

} /* namespace controllers */
#endif /* LOGGER_H_ */
