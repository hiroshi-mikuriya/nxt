/*
 * SaveData.h
 *
 *  Created on: 2012/05/13
 *      Author: HIROSHI MIKURIYA
 */

#ifndef SAVEDATA_H_
#define SAVEDATA_H_

#include "utils/Point.hpp"
#include "ecrobot_interface.h"

namespace controller {

	/**
	 * データを記憶する
	 */
	class SaveData {
	public:
		enum {
			POSITION_COUNT = 4, //!< 座標を記憶可能な数
			ANGLE_COUNT = 4, //!< 角度を記憶可能な数
			TIME_COUNT = 4, //!< 時間を記憶可能な数
		};
	private:

		SaveData();
	public:
		static SaveData & GetInstance();

		/**
		 * 座標を記憶する
		 * @param 記憶するインデックス
		 */
		void SavePosition(int index);
		/**
		 * 記憶した座標を取得
		 * @param 記憶したインデックス
		 * @return 記憶した座標
		 */
		utils::RealPoint GetPosition(int index) const;
		/**
		 * 角度を記憶する
		 * @param 記憶するインデックス
		 */
		void SaveAngle(int index);
		/**
		 * 記憶した角度を取得
		 * @param 記憶したインデックス
		 * @return 記憶した角度
		 */
		int GetAngle(int index) const;
		/**
		 * 時間を記憶する
		 * @param 記憶するインデックス
		 */
		void SaveTime(int index);
		/**
		 * 記憶した時間を取得
		 * @param 記憶したインデックス
		 * @return 記憶した時間
		 */
		int GetTime(int index) const;

	};

} /* namespace controller */
#endif /* SAVEDATA_H_ */
