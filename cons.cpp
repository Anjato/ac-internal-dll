#include "pch.h"
#include "cons.h"
#include <string>
#include <windows.h>
#include <algorithm>


void cons::printTableValues(std::string description, std::string address, std::string offset, std::string value, bool format, int formatLen)
{

    std::transform(address.begin(), address.end(), address.begin(), ::toupper);
    std::transform(offset.begin(), offset.end(), offset.begin(), ::toupper);

    if (format) {
        std::cout << std::left
            << std::setw(formatLen) << description
            << std::setw(formatLen) << address
            << std::setw(formatLen) << offset
            << std::setw(formatLen) << value
            << std::endl;
    }
    else {
        std::cout << std::left
            << std::setw(formatLen) << "|"
            << std::setw(14) << description
            << std::setw(formatLen) << "|"
            << std::setw(9) << address
            << std::setw(formatLen) << "|"
            << std::setw(7) << offset
            << std::setw(formatLen) << "|"
            << std::setw(6) << value
            << std::setw(formatLen) << "|"
            << std::endl;
    }


}


void cons::printTableDividers(bool between, int dividerLen, int topBotLen)
{


    if (between) {

        std::cout << std::left
            << std::setw(dividerLen) << "|"
            << std::setw(14) << "---------------"
            << std::setw(dividerLen) << "|"
            << std::setw(9) << "----------"
            << std::setw(dividerLen) << "|"
            << std::setw(7) << "--------"
            << std::setw(dividerLen) << "|"
            << std::setw(6) << "-------"
            << std::setw(dividerLen) << "|"
            << std::endl;

    }
    else {

        std::cout << std::left
            << std::setw(topBotLen) << "+---------------+"
            << std::setw(topBotLen) << "----------+"
            << std::setw(topBotLen) << "--------+"
            << std::setw(topBotLen) << "-------+"
            << std::endl;
    }
}



int cons::SetConsoleVirtualTerminalSequence()
{

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD dwMode = SetConsoleMode(hOut, 1);
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }

}
