#pragma once


namespace Hack {

	// All variables! :)
	static const char* green     = "\f0";
    static const char* blue      = "\f1";
    static const char* gold      = "\f2";
    static const char* red       = "\f3";
    static const char* darkGray  = "\f4";
    static const char* lightGray = "\f5";
    static const char* brown     = "\f6";
    static const char* darkRed   = "\f7";
    static const char* pink      = "\f8";
    static const char* orange    = "\f9";

	// call chat game function
	std::string chatCall(const char* color, bool variable = false);
}