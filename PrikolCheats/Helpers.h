#pragma once

cCombatantPtr GetAvatarCombatant();

bool TryParseInt32(const char* str, int& result, const ArgScript::FormatParser* parser);

uint32_t ParseID(const char* str, const ArgScript::FormatParser* parser);