#include "pch.h"
#include "hack.h"


std::string Hack::chatCall(const char* color, bool variable) {

    // original: "%s:\f0 %s" = playerName:Color Message
    std::ostringstream stringFormat;
    stringFormat << "%s" << color << " %s";

    return stringFormat.str();
}
