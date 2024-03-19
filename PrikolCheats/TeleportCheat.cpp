#include "stdafx.h"
#include "TeleportCheat.h"
#include "Helpers.h"

using namespace Simulator;

void TeleportCheat::ParseLine(const ArgScript::Line& line)
{
	auto avatar = object_cast<cCreatureAnimal>(GetAvatarCombatant());
	if (!avatar) {
#ifdef _DEBUG
		App::ConsolePrintF("avatar == nullptr");
#endif // _DEBUG
		return;
	}

	avatar->Teleport(GameViewManager.GetWorldMousePosition(), avatar->GetOrientation());
}

const char* TeleportCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Teleports a creature at the cursor coordinates.";
	}
	else {
		return "teleport: teleports a creature at the cursor coordinates.";
	}
}
