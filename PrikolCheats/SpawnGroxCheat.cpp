#include "stdafx.h"
#include "SpawnGroxCheat.h"

SpawnGroxCheat::SpawnGroxCheat()
{
}


SpawnGroxCheat::~SpawnGroxCheat()
{
}


void SpawnGroxCheat::ParseLine(const ArgScript::Line& line)
{
	if (!Simulator::IsSpaceGame())
		return;

	cStarRecordPtr starRecord = Simulator::GetActiveStarRecord();
	auto grobID = StarManager.GetGrobEmpireID();
	if (starRecord->mEmpireID == -1)
		App::ConsolePrintF("This star system is not occupied. Use the cheat only on occupied systems.");
	else if (starRecord->mEmpireID != grobID)
		Simulator::cEmpire::CaptureSystem(starRecord.get(), grobID);
}

const char* SpawnGroxCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat will spawn Grox.";
	}
	else {
		return "spawnGrox: this cheat will spawn Grox.";
	}
}
