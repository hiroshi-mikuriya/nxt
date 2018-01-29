/*
 * Common.h
 *
 *  Created on: 2012/05/18
 *      Author: HIROSHI MIKURIYA
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stddef.h>

/**
 * 配列の先頭ポインタを返す
 * @param 配列
 * @return 先頭ポインタ
 */
template<typename AnyType, size_t n>
AnyType * beginof(AnyType (&a)[n])
{
	return a;
}

/**
 * 配列の末尾の次のポインタを返す
 * @param 配列
 * @return 末尾の次のポインタ
 */
template<typename AnyType, size_t n>
AnyType * endof(AnyType (&a)[n])
{
	return a + n;
}

/**
 * 配列の要素数を返す
 * @param 配列
 * @return 配列の要素数
 */
template<typename AnyType, size_t n>
size_t countof(AnyType (&a)[n])
{
	return n;
}

template<typename AnyType, AnyType Min, AnyType Max>
AnyType compress_cast(AnyType const & a)
{
	if (a < Min) {
		return Min;
	}
	if (Max < a) {
		return Max;
	}
	return a;
}

#endif /* COMMON_H_ */
