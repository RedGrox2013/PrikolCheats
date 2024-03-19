#include "stdafx.h"
#include "PrikolTestCheat.h"

void PrikolTestCheat::ParseLine(const ArgScript::Line& line)
{
	App::ConsolePrintF("Test cheat");
	if (!Simulator::IsSpaceGame())
		return;

	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	/*Simulator::cSpaceInventoryItem* item;
	inventory->GetFreeCargoSlot(item);
	if (!item)
		return;*/

	cAnimalCargoInfoPtr animalCargo;
	AnimalSpeciesManager.CreateAnimalItem(animalCargo, { 0x06577404, TypeIDs::crt, 0x40626200 });
	inventory->AddItem(animalCargo.get());
}

const char* PrikolTestCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	return nullptr;
}
