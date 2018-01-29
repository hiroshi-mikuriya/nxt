/*
 * SaveData.cpp
 *
 *  Created on: 2012/05/13
 *      Author: HIROSHI MIKURIYA
 */

#include "SaveData.h"
#include "controller/position/Position.h"
#include "hardware/body/Body.h"
#include "hardware/timer/Timer.h"

namespace controller {

	namespace {
		utils::RealPoint s_position[SaveData::POSITION_COUNT];
		int s_angle[SaveData::ANGLE_COUNT];
		U32 s_time[SaveData::TIME_COUNT];
	}

	SaveData::SaveData()
	{
	}

	SaveData & SaveData::GetInstance()
	{
		static SaveData saveData;
		return saveData;
	}

	void SaveData::SavePosition(int index)
	{
		s_position[index % POSITION_COUNT] = controller::Position::GetInstance().GetPosition();
	}

	void SaveData::SaveAngle(int index)
	{
		s_angle[index % ANGLE_COUNT] = controller::Position::GetInstance().GetAngle();
	}

	void SaveData::SaveTime(int index)
	{
		s_time[index % ANGLE_COUNT] = hardware::Timer::GetInstance().GetTime();
	}

	utils::RealPoint SaveData::GetPosition(int index) const
	{
		return s_position[index % POSITION_COUNT];
	}
	int SaveData::GetAngle(int index) const
	{
		return s_angle[index % ANGLE_COUNT];
	}
	int SaveData::GetTime(int index) const
	{
		return s_time[index % TIME_COUNT];
	}

} /* namespace controller */
