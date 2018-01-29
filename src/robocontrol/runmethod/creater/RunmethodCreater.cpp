/*
 * RunCreater.cpp
 *
 *  Created on: 2012/06/05
 *      Author: HIROSHI MIKURIYA
 */

#include "RunmethodCreater.h"
#include "runmethod/impl/linetrace/LineTrace.h"
#include "runmethod/impl/pid/Pid.h"
#include "runmethod/impl/pidtail/PidTail.h"
#include "runmethod/impl/noline/NoLine.h"
#include "runmethod/impl/nolinetail/NoLineTail.h"
#include "runmethod/impl/stop/Stop.h"
#include "runmethod/impl/linetracetail/LineTraceTail.h"

namespace runmethod {
	namespace creater {

		runmethod::impl::RunAbstract * LineTrace::operator()(S16 speed, S16 turn_power, LINETRACE_EDGE edge) const
		{
			return new runmethod::impl::LineTrace(speed, turn_power, edge);
		}

		runmethod::impl::RunAbstract * LineTraceTail::operator()(S16 speed, S16 turn_power, LINETRACE_EDGE edge) const
		{
			return new runmethod::impl::LineTraceTail(speed, turn_power, edge);
		}

		runmethod::impl::RunAbstract * Pid::operator()(S16 speed, LINETRACE_EDGE edge, utils::PidCalculation<S16>::Parameter const & parameter) const
		{
			return new runmethod::impl::Pid(speed, edge, parameter);
		}

		runmethod::impl::RunAbstract * PidTail::operator()(S16 speed, LINETRACE_EDGE edge, utils::PidCalculation<S16>::Parameter const & parameter) const
		{
			return new runmethod::impl::PidTail(speed, edge, parameter);
		}

		runmethod::impl::RunAbstract * NoLine::operator()(S16 speed, S16 turn_power) const
		{
			return new runmethod::impl::NoLine(speed, turn_power);
		}

		runmethod::impl::RunAbstract * NoLineTail::operator()(NOLINETAIL_RUN_TYPE Run_Type, S16 power) const
		{
			return new runmethod::impl::NoLineTail(Run_Type, power);
		}

		Stop::operator runmethod::impl::RunAbstract *() const
		{
			return new runmethod::impl::Stop();
		}

	} /* namespace impl */
} /* namespace runmethod */

