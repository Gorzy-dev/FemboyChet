#pragma once
#include "include.h"

class USettings
{
public:
	bool EnableBhop = false;

	bool EnableTriggerbot = false;
	int TriggerbotDelay = 0;

	bool EnableRecoilControl = false;
	float RecoilControlAmount = 1.0f;
};