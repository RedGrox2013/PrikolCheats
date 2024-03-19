#pragma once
#include "stdafx.h"

inline cCombatantPtr GetAvatarCombatant()
{
	switch (GameNounManager.GetCurrentGameMode())
	{
	case GameModeIDs::kGameCreature:
	case GameModeIDs::kScenarioMode:
		return GameNounManager.GetAvatar();
	case GameModeIDs::kGameSpace:
		return Simulator::GetPlayerUFO();
	default:
		return nullptr;
	}
}

inline bool TryParseInt32(const char* str, int& result, const ArgScript::FormatParser* parser)
{
	try {
		result = parser->ParseInt(str);
	}
	catch (...) {
		return false;
	}
	return true;
}

inline uint32_t ParseID(const char* str, const ArgScript::FormatParser* parser)
{
	uint32_t res;
	try {
		res = parser->ParseUInt(str);
	}
	catch (...) {
		res = id(str);
	}

	return res;
}