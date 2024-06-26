#include "stdafx.h"
#include "GetAnimalCheat.h"
#include "Helpers.h"

GetAnimalCheat::GetAnimalCheat() : _isFirstCreature(true), _shopperRequest(this)
{
	_shopperRequest.shopperID = id("CreatureShopper");
}


GetAnimalCheat::~GetAnimalCheat()
{
}


void GetAnimalCheat::ParseLine(const ArgScript::Line& line)
{
	if (!Simulator::IsSpaceGame())
		return;

	if (line.HasFlag("sporepedia")) {
		Sporepedia::ShopperRequest::Show(_shopperRequest);
		return;
	}

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

	AddAnimal(species, count, isSentient);
}

const char* GetAnimalCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat gives the creature to the cargo hold of the ship.";
	}
	else {
		return "getAnimal -prop <id> <count> <isSentient>: this cheat gives the creature to the cargo hold of the ship.\n"
			"To indicate diet, use the flags -carn or -herb.\n"
			"Use the -sporepedia flag to select a creature from the Sporepedia.\n";
	}
}

void GetAnimalCheat::OnShopperAccept(const ResourceKey& selection)
{
	AddAnimal(selection, 1, false);
}

void GetAnimalCheat::AddAnimal(const ResourceKey& key, int count, bool isSentient) const
{
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	cAnimalCargoInfoPtr animalCargo;
	AnimalSpeciesManager.CreateAnimalItem(animalCargo, key, count, isSentient);
	inventory->AddItem(animalCargo.get());
}