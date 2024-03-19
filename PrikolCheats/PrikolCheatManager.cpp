#include "stdafx.h"
#include "PrikolCheatManager.h"

vector<char*> PrikolCheatManager::_cheatKeyWords;

void PrikolCheatManager::AddCheat(const char* keyWord, ArgScript::ICommand* cheat, bool bNotify)
{
	CheatManager.AddCheat(keyWord, cheat, bNotify);
	_cheatKeyWords.push_back((char*)keyWord);
}

//vector<ArgScript::ICommand*>* PrikolCheatManager::GetCheats()
//{
//	if (!_cheatKeyWords.get())
//		return nullptr;
//
//	intrusive_ptr<vector<ArgScript::ICommand*>> cheats = new vector<ArgScript::ICommand*>();
//	for (eastl_size_t i = 0; i < _cheatKeyWords->size(); i++)
//		cheats->push_back(CheatManager.GetCheat(_cheatKeyWords->at(i)));
//
//	return cheats.get();
//}

vector<char*>* PrikolCheatManager::GetCheatsKeyWords()
{
	return &_cheatKeyWords;
}