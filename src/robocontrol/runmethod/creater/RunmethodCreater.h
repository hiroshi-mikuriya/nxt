/*
 * RunCreater.h
 *
 *  Created on: 2012/06/05
 *      Author: HIROSHI MIKURIYA
 */

#ifndef RUNCREATER_H_
#define RUNCREATER_H_

#include "runmethod/impl/abstract/RunAbstract.h"
#include "utils/PidCalculation.hpp"
#include "Parameter.h"

namespace runmethod {
	namespace creater {

		struct LineTrace {
			/**
			 * ライントレース
			 * @param[in] speed 速度
			 * @param[in] turn_power ターンの強さ
			 * @param[in] edge 左右のエッジ
			 * @return 走法のインスタンス
			 */
			runmethod::impl::RunAbstract * operator()(S16 speed, S16 turn_power, LINETRACE_EDGE edge) const;
		};
		struct LineTraceTail {
			// TODO
			/// 尻尾によりかかりながらライントレース
			runmethod::impl::RunAbstract * operator()(S16 speed, S16 turn_power, LINETRACE_EDGE edge) const;
		};

		struct Pid {
			/**
			 * 尻尾をあげたままライントレース
			 * @param[in] speed 速度
			 * @param[in] edge 左右のエッジ
			 * @param[in] parameter 使用するPID制御パラメータ
			 */
			runmethod::impl::RunAbstract * operator()(S16 speed, LINETRACE_EDGE edge, utils::PidCalculation<S16>::Parameter const & parameter) const;
		};

		struct PidTail {
			/**
			 * 尻尾によりかかりながらライントレース
			 * @param[in] speed 速度
			 * @param[in] edge 左右のエッジ
			 * @param[in] parameter 使用するPID制御パラメータ
			 * @return 走法のインスタンス
			 */
			runmethod::impl::RunAbstract * operator()(S16 speed, LINETRACE_EDGE edge, utils::PidCalculation<S16>::Parameter const & parameter) const;
		};
		struct NoLine {
			/**
			 * ライン無視走行
			 * @param[in] speed 速度
			 * @param[in] turn_power ターンの強さ
			 */
			runmethod::impl::RunAbstract * operator()(S16 speed, S16 turn_power) const;
		};
		struct NoLineTail {
			/// 尻尾によりかかりながらライントレース
			runmethod::impl::RunAbstract * operator()(NOLINETAIL_RUN_TYPE Run_Type, S16 power) const;
		};
		struct Stop {
			/**
			 * 完全停止
			 */
			operator runmethod::impl::RunAbstract *() const;
		};

	} /* namespace creater */
} /* namespace runmethod */
#endif /* RUNCREATER_H_ */
