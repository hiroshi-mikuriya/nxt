/*
 * RunControl.h
 *
 *  Created on: 2012/05/18
 *      Author: HIROSHI MIKURIYA
 */

#ifndef RUNCONTROLDATA_H_
#define RUNCONTROLDATA_H_

#include "ecrobot_interface.h"
#include "controller/color/ColorPackage.h"
#include "runmethod/impl/abstract/RunAbstract.h"

namespace controller {

	/**
	 * 走行制御
	 */
	class RunControl {
	public:
		enum {
			COLOR_PACKAGE_COUNT = 2, //!< カラーパッケージの数
		};
	private:
		S16 m_gyroOffset; //!< ジャイロオフセット値
		S16 m_modifiedGyroOffset; //!< 変更したジャイロオフセット値
		ColorPackage m_colorPackage[COLOR_PACKAGE_COUNT]; //!< カラーパッケージ
		int m_index; //!< 選択中のカラーパッケージ
		runmethod::impl::RunAbstract * m_run; //!< 走行方法

		/**
		 * ノイズ除去した色値を取得
		 * @return ノイズ除去した色値
		 */
		int GetNoiselessColor() const;

		RunControl();
	public:

		static RunControl & GetInstance();
		/**
		 * 走行制御をする
		 * @note 倒立制御を行うため4ms周期で呼び出すこと
		 */
		void Control();
		/**
		 * カラーパッケージを選択
		 * @param インデックス
		 */
		void SelectPackage(int index);
		/**
		 * ジャイロオフセット値を設定
		 * @param ジャイロオフセット値
		 */
		void SetGyroOffset(S16 gyroOffset);
		/**
		 * ジャイロオフセット値を変更
		 * @param gyro ジャイロオフセット値にプラス(マイナス)する値
		 */
		void ChangeGyroOffset(S16 gyro);
		/**
		 * 走法を設定
		 * @param 走法
		 */
		void SetRunMethod(runmethod::impl::RunAbstract * run);
		/**
		 * カラーパッケージに黒の基準値を設定
		 * @param 黒の基準値
		 * @param カラーパッケージのインデックス
		 */
		void SetBlack(S16 brightness, int index);
		/**
		 * カラーパッケージに灰色の基準値を設定
		 * @param 灰色の基準値
		 * @param カラーパッケージのインデックス
		 */
		void SetGray(S16 brightness, int index);
		/**
		 * カラーパッケージに白の基準値を設定
		 * @param 白の基準値
		 * @param カラーパッケージのインデックス
		 */
		void SetWhite(S16 brightness, int index);
		/**
		 * 指定したカラーパッケージの黒の値を取得
		 * @param カラーパッケージを指定するインデックス
		 * @return 黒の値
		 */
		S16 GetBlack(int index) const;
		/**
		 * 指定したカラーパッケージの灰色の値を取得
		 * @param カラーパッケージを指定するインデックス
		 * @return 灰色の値
		 */
		S16 GetGray(int index) const;
		/**
		 * 指定したカラーパッケージの白の値を取得
		 * @param カラーパッケージを指定するインデックス
		 * @return 白の値
		 */
		S16 GetWhite(int index) const;
		/**
		 * 光センサを色値へ変換した値を取得
		 * @return 色値
		 */
		int GetColor() const;
		/**
		 *  走行制御を止め、タイヤを停止させる
		 */
		void StopRunControl();
	}
	;

} /* namespace controller */
#endif /* RUNCONTROLDATA_H_ */
