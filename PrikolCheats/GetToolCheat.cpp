#include "stdafx.h"
#include "GetToolCheat.h"
#include "Helpers.h"

GetToolCheat::GetToolCheat()
{
}


GetToolCheat::~GetToolCheat()
{
}


void GetToolCheat::ParseLine(const ArgScript::Line& line)
{
	if (!Simulator::IsSpaceGame())
		return;
	if (line.GetArgumentsCount() < 2) {
		App::ConsolePrintF("Enter the tool ID or name. Example: getTool PlanetBusterBomb");
		return;
	}

	cSpaceToolDataPtr tool;
	if (!ToolManager.LoadTool({ ParseID(line.GetArgumentAt(1), mpFormatParser), 0, 0 }, tool)) {
		App::ConsolePrintF("\"%s\" not found.", line.GetArgumentAt(1));
		return;
	}
	auto args = line.GetOption("count", 1);
	if (!args || !TryParseInt32(args[0], tool->mCurrentAmmoCount, mpFormatParser))
		tool->mCurrentAmmoCount = 1;
	SimulatorSpaceGame.GetPlayerInventory()->AddItem(tool.get());
}

const char* GetToolCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat will give the player a tool by ID or name.";
	}
	else {
		return "getTool <id> -count <count>: this cheat will give the player a tool by ID or name.";
	}
}
