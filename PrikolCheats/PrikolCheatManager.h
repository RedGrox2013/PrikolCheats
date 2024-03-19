#pragma once

class PrikolCheatManager
{
private:
	static vector<char*> _cheatKeyWords;
public:
	static void AddCheat(const char* keyWord, ArgScript::ICommand* cheat, bool bNotify = false);

	//static vector<ArgScript::ICommand*>* GetCheats();
	static vector<char*>* GetCheatsKeyWords();
};