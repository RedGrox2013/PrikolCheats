#include "stdafx.h"
#include "GetAnimalCheat.h"
#include "Helpers.h"

GetAnimalCheat::GetAnimalCheat() : _isFirstCreature(true)
{
}


GetAnimalCheat::~GetAnimalCheat()
{
}


void GetAnimalCheat::ParseLine(const ArgScript::Line& line)
{
	if (!Simulator::IsSpaceGame())
		return;

	const int ARGS_COUNT = 3;
	auto args = line.GetOption("prop", ARGS_COUNT);
	ResourceKey species(id("ZelenoidsWife"), TypeIDs::crt, GroupIDs::CreatureModels);
	int count = 1;
	bool isSentient = false;
	if (args) {
		species.instanceID = ParseID(args[0], mpFormatParser);
		if (!TryParseInt32(args[1], count, mpFormatParser))
			count = 1;
		try {
			isSentient = mpFormatParser->ParseBool(args[2]);
		}
		catch (...) {
			isSentient = false;
		}
	}
	else if (line.HasFlag("carn") && !line.HasFlag("herb"))
		species.instanceID = id("PrikolBen");
	else if (!line.HasFlag("carn") && line.HasFlag("herb")) {
		species.instanceID = _isFirstCreature ? 0x0761F7B6 : id("PrikolHitler");
		_isFirstCreature = !_isFirstCreature;
	}

	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	cAnimalCargoInfoPtr animalCargo;
	AnimalSpeciesManager.CreateAnimalItem(animalCargo, species, count, isSentient);
	inventory->AddItem(animalCargo.get());
}

const char* GetAnimalCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat gives the creature to the cargo hold of the ship.";
	}
	else {
		return "getAnimal -prop <id> <count> <isSentient>: this cheat gives the creature to the cargo hold of the ship. To indicate diet, use the flags -carn or -herb.";
	}
}
