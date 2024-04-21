// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "CheatsIncludes.h"

void Initialize()
{
	PrikolCheatManager::AddCheat("prikolHelp", new PrikolCheatsHelp());
	PrikolCheatManager::AddCheat("teleport", new TeleportCheat(), true);
	PrikolCheatManager::AddCheat("spawnGrox", new SpawnGroxCheat(), true);
	PrikolCheatManager::AddCheat("getTool", new GetToolCheat(), true);
	PrikolCheatManager::AddCheat("addCargoSlot", new AddCargoSlotCheat(), true);
	PrikolCheatManager::AddCheat("getAnimal", new GetAnimalCheat(), true);
	PrikolCheatManager::AddCheat("translateToken", new TranslateTokenCheat());
	PrikolCheatManager::AddCheat("setCreature", new SetCreatureCheat(), true);
}

void Dispose()
{
	// This method is called when the game is closing
}

void AttachDetours()
{
	// Call the attach() method on any detours you want to add
	// For example: cViewer_SetRenderType_detour::attach(GetAddress(cViewer, SetRenderType));
}


// Generally, you don't need to touch any code here
BOOL APIENTRY DllMain( HMODULE hModule,
					   DWORD  ul_reason_for_call,
					   LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ModAPI::AddPostInitFunction(Initialize);
		ModAPI::AddDisposeFunction(Dispose);

		PrepareDetours(hModule);
		AttachDetours();
		CommitDetours();
		break;

	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

