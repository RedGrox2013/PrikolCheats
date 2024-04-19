#pragma once

#include <Spore\BasicIncludes.h>

class GetAnimalCheat 
	: public ArgScript::ICommand
	, public Sporepedia::IShopperListener
{
private:
	bool _isFirstCreature;
	Sporepedia::ShopperRequest _shopperRequest;

	void AddAnimal(const ResourceKey& key, int count, bool isSentient) const;
public:
	GetAnimalCheat();
	~GetAnimalCheat();

	// Called when the cheat is invoked
	void ParseLine(const ArgScript::Line& line) override;
	
	// Returns a string containing the description. If mode != DescriptionMode::Basic, return a more elaborated description
	const char* GetDescription(ArgScript::DescriptionMode mode) const override;

	void OnShopperAccept(const ResourceKey& selection) override;
};

