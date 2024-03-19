#include "stdafx.h"
#include "AddCargoSlotCheat.h"
#include "Helpers.h"

AddCargoSlotCheat::AddCargoSlotCheat()
{
}


AddCargoSlotCheat::~AddCargoSlotCheat()
{
}


void AddCargoSlotCheat::ParseLine(const ArgScript::Line& line)
{
	if (!Simulator::IsSpaceGame())
		return;

	int count;
	if (line.GetArgumentsCount() < 2 || !TryParseInt32(line.GetArgumentAt(1), count, mpFormatParser))
		count = 1;
	SimulatorSpaceGame.GetPlayerInventory()->AddCargoSlots(count);
}

const char* AddCargoSlotCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat adds new slots to the ship's cargo compartment.";
	}
	else {
		return "addCargoSlot: this cheat adds new slots to the ship's cargo compartment.";
	}
}
