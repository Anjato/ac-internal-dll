#pragma once

#include "pch.h"

namespace cons
{

	void printTableDividers(bool between = true, int dividerLen = 1, int topBotLen = 2);
	void printTableValues(std::string description, std::string address, std::string offset, std::string value, bool format = false, int formatLen = 2);

	int SetConsoleVirtualTerminalSequence();
}