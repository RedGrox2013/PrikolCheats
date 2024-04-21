#include "stdafx.h"
#include "SetCreatureCheat.h"

SetCreatureCheat::SetCreatureCheat()
{
}


SetCreatureCheat::~SetCreatureCheat()
{
}


void SetCreatureCheat::ParseLine(const ArgScript::Line& line)
{
	Sporepedia::ShopperRequest request(this);
	request.shopperID = id("CreatureShopper");
	Sporepedia::ShopperRequest::Show(request);
}

const char* SetCreatureCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "SetCreatureCheat: Elaborate description of what this cheat does.";
	}
}

void SetCreatureCheat::OnShopperAccept(const ResourceKey& selection)
{
	auto playerEmpire = Simulator::GetPlayerEmpire();
	if (!playerEmpire)
		return;

	auto species = SpeciesManager.GetSpeciesProfile(selection);
	playerEmpire->SetSpeciesProfile(species);
	if (Simulator::IsCreatureGame()) {
		auto avatar = GameNounManager.GetAvatar();
		avatar->mpSpeciesProfile = species;
		avatar->mSpeciesKey = selection;
	}
}