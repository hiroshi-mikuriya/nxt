/*
 * RunmethodPackage.h
 *
 *  Created on: 2012/06/09
 *      Author: HIROSHI MIKURIYA
 */

#ifndef RUNMETHOD_PACKAGE_H_
#define RUNMETHOD_PACKAGE_H_

#include "runmethod/creater/RunmethodCreater.h"

namespace runmethod {
	namespace package {
		namespace {
			creater::LineTrace runLineTrace; //!< 倒立制御ありライントレース
			creater::LineTraceTail runLineTraceTail; //!< 倒立制御なしライントレース
			creater::Pid runPid; //!< 倒立制御ありPID
			creater::PidTail runPidTail; //!< 倒立制御なしPID
			creater::NoLine runNoLine; //!< 倒立制御ありライン無視
			creater::NoLineTail runNoLineTail; //!< 倒立制御なしライン無視
			creater::Stop runStop; //!< 完全停止
		}
	} /* namespace package */
} /* namespace runmethod */

#endif // RUNMETHOD_PACKAGE_H_
