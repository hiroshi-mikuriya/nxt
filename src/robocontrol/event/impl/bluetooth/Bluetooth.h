/*
 * Bluetooth.h
 *
 *  Created on: 2012/07/22
 *      Author: YUKI SHIMIZU
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "event/impl/abstract/EventAbstract.h"

namespace event {
	namespace impl {

		/**
		 * Bluetooth受信検知
		 */
		class Bluetooth: public event::impl::EventAbstract {
		private:
			int m_type;

		public:

			/**
			 * @param[in] type 受信するイベントの種類
			 * @param[in] unuse 未使用
			 */
			virtual void Initialize(int type, int unuse);
			/**
			 * 検知有無
			 * @return 検知有無
			 */
			virtual bool Notify() const;
		};

	} /* namespace impl */
} /* namespace event */

#endif /* BLUETOOTH_H_ */
