#include "stdafx.h"
#include "PrikolCheatsHelp.h"
#include "PrikolCheatManager.h"

void PrikolCheatsHelp::ParseLine(const ArgScript::Line& line)
{
	auto cheats = PrikolCheatManager::GetCheatsKeyWords();
	for (eastl_size_t i = 0; i < cheats->size(); i++) {
		auto cheat = CheatManager.GetCheat(cheats->at(i));
		auto descr = cheat->GetDescription(ArgScript::DescriptionMode::Basic);
		App::ConsolePrintF("%s: %s", cheats->at(i), descr ? descr : "no description");
	}
}

const char* PrikolCheatsHelp::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Get help with PrikolCheats mod.";
	}
	else {
		return "prikolCheatsHelp: get help with PrikolCheats mod.";
	}
}
