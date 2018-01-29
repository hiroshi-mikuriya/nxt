/*
 * Point.h
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#ifndef UTILS_POINT_H_
#define UTILS_POINT_H_

#include "ecrobot_interface.h"

namespace utils {

	template<typename AnyType>
	struct PointT {
		typedef AnyType ElemT;
		ElemT x;
		ElemT y;

		friend PointT operator-(PointT const & point)
		{
			PointT const tmp = { -point.x, -point.y };
			return tmp;
		}
		friend PointT operator+(PointT const & lh, PointT const & rh)
		{
			PointT const tmp = { lh.x + rh.x, lh.y + rh.y };
			return tmp;
		}
		friend PointT operator-(PointT const & lh, PointT const & rh)
		{
			return lh + (-rh);
		}
		friend PointT & operator+=(PointT const & lh, PointT const & rh)
		{
			lh.x += rh.x;
			lh.y += rh.y;
			return lh;
		}
		friend PointT operator-=(PointT const & lh, PointT const & rh)
		{
			return lh += -rh;
		}
		friend bool operator==(PointT const & lh, PointT const & rh)
		{
			return lh.x == rh.x && lh.y == rh.y;
		}
		friend bool operator!=(PointT const & lh, PointT const & rh)
		{
			return !(lh == rh);
		}
		friend ElemT operator*(PointT const & lh, PointT const & rh)
		{
			return lh.x * rh.x + lh.y * rh.y;
		}
		template<typename NumberT>
		friend PointT operator*(PointT const & p, NumberT a)
		{
			PointT const pos = { p.x * a, p.y * a };
			return pos;
		}
	};

	typedef PointT<F32> RealPoint;
	typedef PointT<int> Point;

} /* namespace utils */
#endif /* UTILS_POINT_H_ */
