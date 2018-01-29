/*
 * Position.cpp
 *
 *  Created on: 2012/05/18
 *      Author: HIROSHI MIKURIYA
 */

#include "Position.h"
#include "hardware/io/Io.h"

namespace controller {

	namespace {
		const F32 axleLength = 231.15; //!< 車軸長(無次元)
		const F32 convertToMM = 0.683; //!< 無次元からミリメートルへ単位を換算する係数
		const F32 convertToDegree = 180 / 3.14; //!<ラジアンから度へ単位を換算する係数

		/**
		 sinの値を１度ごとに計算したテーブル
		 cmathの三角関数はバイナリサイズが大きくなるため使わない
		 精度は0.01度で幅0.005以内に収まっている
		 (これにより7kByteくらい削減できる)
		 */
		const float sin_table[] = { 0.0f, 0.0174436f, 0.0348818f, 0.0523094f, 0.0697212f, 0.0871117f, 0.104476f, 0.121808f, 0.139103f, 0.156356f, 0.173561f, 0.190713f, 0.207808f, 0.224839f, 0.241802f,
				0.258691f, 0.275501f, 0.292228f, 0.308866f, 0.325409f, 0.341854f, 0.358194f, 0.374426f, 0.390544f, 0.406543f, 0.422418f, 0.438164f, 0.453778f, 0.469253f, 0.484585f, 0.49977f, 0.514803f,
				0.529679f, 0.544394f, 0.558943f, 0.573323f, 0.587528f, 0.601554f, 0.615396f, 0.629052f, 0.642516f, 0.655785f, 0.668854f, 0.68172f, 0.694378f, 0.706825f, 0.719057f, 0.73107f, 0.742861f,
				0.754425f, 0.76576f, 0.776862f, 0.787727f, 0.798353f, 0.808736f, 0.818873f, 0.82876f, 0.838396f, 0.847776f, 0.856898f, 0.86576f, 0.874358f, 0.88269f, 0.890753f, 0.898546f, 0.906065f,
				0.913308f, 0.920273f, 0.926958f, 0.933361f, 0.939481f, 0.945314f, 0.950859f, 0.956116f, 0.961081f, 0.965754f, 0.970133f, 0.974217f, 0.978004f, 0.981494f, 0.984685f, 0.987576f, 0.990167f,
				0.992456f, 0.994444f, 0.996129f, 0.997511f, 0.998589f, 0.999363f, 0.999834f, 1.0f, };

		float sinN(int deg)
		{
			for (; deg < 0; deg += 360)
				;
			deg %= 360;
			if (deg <= 90) {
				return sin_table[deg];
			}
			if (deg <= 180) {
				return sin_table[180 - deg];
			}
			if (deg <= 270) {
				return -sin_table[deg - 180];
			}
			return -sin_table[360 - deg];
		}
		float sin(float deg)
		{
			int degN = static_cast<int>(deg);
			float diff = deg - degN;
			return (1 - diff) * sinN(degN) + diff * sinN(degN + 1);
		}
		float cos(float deg)
		{
			return sin(deg + 90.0f);
		}
	}

	Position::Position()
			: m_position(), m_angle(0), m_leftCount(0), m_rightCount(0)
	{
	}

	Position & Position::GetInstance()
	{
		static Position position;
		return position;
	}

	utils::RealPoint Position::GetPosition() const
	{
		return m_position;
	}
	int Position::GetAngle() const
	{
		return static_cast<int>(m_angle);
	}

	void Position::Update()
	{
		S32 const leftCount = hardware::Io::GetInstance().GetLeftMotorCount();
		S32 const rightCount = hardware::Io::GetInstance().GetRightMotorCount();
		S32 const diffLeft = leftCount - m_leftCount;
		S32 const diffRight = rightCount - m_rightCount;
		m_leftCount = leftCount;
		m_rightCount = rightCount;
		F32 const diffAngle = convertToDegree * (diffRight - diffLeft) / axleLength;
		F32 const move = convertToMM * (diffLeft + diffRight) / 2.0f;
		m_angle += diffAngle;
		m_position.x += move * cos(m_angle);
		m_position.y += move * sin(m_angle);
	}

	void Position::ClearPrevMotorCount()
	{
		m_leftCount = 0;
		m_rightCount = 0;
	}

} /* namespace controller */
