/*
 * Position.h
 *
 *  Created on: 2012/05/18
 *      Author: HIROSHI MIKURIYA
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "utils/Point.hpp"
#include "ecrobot_interface.h"

namespace controller
{

/**
 * ロボの現在位置と角度を管理する
 */
class Position
{
	/// 現在位置の座標
	utils::RealPoint m_position;
	/// 現在の角度
	F32 m_angle;

	S32 m_leftCount;
	S32 m_rightCount;

	Position();
public:

	static Position & GetInstance();
	/**
	 * 座標と角度を更新
	 */
	void Update();
	/**
	 * 現在位置を取得
	 * @return 現在位置
	 */
	utils::RealPoint GetPosition() const;
	/**
	 * 現在角度を取得
	 * @return 現在角度
	 */
	int GetAngle() const;
	/**
	 * 前回のモーターカウント値を0にする
	 */
	void ClearPrevMotorCount();
};

} /* namespace controller */
#endif /* POSITION_H_ */
