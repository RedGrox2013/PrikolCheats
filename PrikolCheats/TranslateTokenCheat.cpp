#include "stdafx.h"
#include "TranslateTokenCheat.h"

TranslateTokenCheat::TranslateTokenCheat()
{
}


TranslateTokenCheat::~TranslateTokenCheat()
{
}


void TranslateTokenCheat::ParseLine(const ArgScript::Line& line)
{
	if (line.GetArgumentsCount() < 2) {
		App::ConsolePrintF("Error. Token not entered.");
		return;
	}

	auto detokenizer = LocaleManager.GetStringDetokenizer();
	for (size_t i = 1; i < line.GetArgumentsCount(); i++) {
		const char* token = line.GetArgumentAt(i);
		char16_t* str16Token = nullptr;
		try {
			string16 result;
			auto len = strlen(token) + 1;
			str16Token = new char16_t[len];
			for (size_t j = 0; j < len; j++)
				str16Token[j] = (char16_t)token[j];
			detokenizer->FindTokenTranslation(str16Token, result);
			App::ConsolePrintF("~%s~ -> %ls", token, result.c_str());
		}
		catch (...) {
			App::ConsolePrintF("Error! Failed to translate token ~%s~", token);
		}
		if (str16Token)
			delete[] str16Token;
	}
}

const char* TranslateTokenCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat translates the token using cStringDetokenizer.";
	}
	else {
		return "This cheat translates the token using cStringDetokenizer.\n"
			"In locale files, tokens are surrounded with ~ characters.\n"
			"Usage example: translateToken player_creature_name.\n"
			"You can also translate multiple tokens at the same time.\n"
			"For example: translateToken player_creature_name ep1_captain_full_name";
	}
}
