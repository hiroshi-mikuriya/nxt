/*
 * ColorPackage.h
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#ifndef COLORPACKAGE_H_
#define COLORPACKAGE_H_

#include "ecrobot_interface.h"

namespace controller {

	/**
	 * ライトセンサ値から色値に変換するための
	 * カラーパッケージ
	 */
	class ColorPackage {
		S16 m_white;
		S16 m_gray;
		S16 m_black;
	public:
		ColorPackage();

		/**
		 * 黒の基準値を設定
		 * @param 黒の基準値
		 */
		void SetBlack(S16 black);
		/**
		 * 灰色の基準値を設定
		 * @param 灰色の基準値
		 */
		void SetGray(S16 gray);
		/**
		 * 白の基準値を設定
		 * @param 白の基準値
		 */
		void SetWhite(S16 white);
		/**
		 * 色の基準値が正常に設定されたか判定する
		 * @return 判定結果
		 * @note 色値の大小関係が不正であったときにfalseを返す
		 */
		bool IsValidColors() const;
		/**
		 * センサ値を色値へ変換
		 * @param センサ値
		 * @return 色値
		 */
		int GetStdColor(S16 brightness) const;
		/**
		 * 黒の基準値を取得
		 * @return 黒の基準値
		 */
		S16 GetBlack() const;
		/**
		 * 灰色の基準値を取得
		 * @return 灰色の基準値
		 */
		S16 GetGray() const;
		/**
		 * 白の基準値を取得
		 * @return 白の基準値
		 */
		S16 GetWhite() const;

	};

} /* namespace controller */
#endif /* COLORPACKAGE_H_ */
