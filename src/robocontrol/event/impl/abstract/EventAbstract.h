/*
 * EventAbstract.h
 *
 *  Created on: 2012/05/11
 *      Author: HIROSHI MIKURIYA
 */

#ifndef EVENTABSTRACT_H_
#define EVENTABSTRACT_H_

namespace event {
	namespace impl {
		/**
		 * イベントの基底クラス
		 */
		class EventAbstract {
		public:
			virtual ~EventAbstract();

			/**
			 * 初期化
			 */
			virtual void Initialize(int param1, int param2)=0;
			/**
			 * 検知有無
			 * @return 検知有無
			 */
			virtual bool Notify() const=0;
		};

	} /* namespace impl */
} /* namespace event */

#endif /* EVENTABSTRACT_H_ */
