/*
 * RingBuffer.h
 *
 *  Created on: 2012/05/13
 *      Author: HIROSHI MIKURIYA
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include "Common.h"
#include "ecrobot_interface.h"

namespace utils {

	template<typename AnyType, int Size>
	class RingBuffer {
	public:
		typedef AnyType ElemT;
	private:
		ElemT m[Size];
		int m_latest_index;
		F32 m_sum;
		/// std::fillよりバイナリサイズを縮められると思って作成。あまり変わらない結論…。
		void fill(ElemT value)
		{
			for (ElemT *it = m; it != (m + Size); ++it)
				*it = value;
		}
	public:
		RingBuffer()
				: m_sum(0)
		{
			fill(0);
		}
		RingBuffer(ElemT const & initParam)
		{
			fill(initParam);
			m_sum = initParam * Size;
		}
		/**
		 * バッファサイズを取得
		 * @return バッファサイズ
		 */
		int GetSize() const
		{
			return countof(m);
		}
		/**
		 * 新データをバッファに格納する（古いものは消される）
		 */
		void SetNewData(ElemT const & d)
		{
			m_latest_index = (m_latest_index + 1) % GetSize();
			m_sum -= m[m_latest_index];
			m[m_latest_index] = d;
			m_sum += d;
		}
		/**
		 * 最新のデータを取得
		 */
		ElemT GetLatestData() const
		{
			return m[m_latest_index];
		}
		/**
		 * データの平均値を取得
		 * @return 平均値
		 */
		ElemT GetAverage() const
		{
			return static_cast<ElemT>(m_sum / GetSize());
		}
		/**
		 * データの分散を取得
		 * @return 標準偏差
		 */
		F32 GetVariance() const
		{
			ElemT const ave = GetAverage();
			F32 v = 0;
			for (int i = 0; i < GetSize(); ++i) {
				F32 diff = (m[i] - ave);
				v += diff * diff;
			}

			v /= GetSize() - 1;
			return v;
		}
		/**
		 * []オペレータで要素を取得
		 * 0が最古の要素
		 * Size-1が最新の要素
		 */
		ElemT & operator[](int index)
		{
			return m[(m_latest_index + index + 1) % GetSize()];
		}
		ElemT const & operator[](int index) const
		{
			return m[(m_latest_index + index + 1) % GetSize()];
		}
	};

} /* namespace utils */
#endif /* RINGBUFFER_H_ */
