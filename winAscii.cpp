#include <iostream>
#include <windows.h>
std::string winAscii() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

	std::string win = R"(
|||||||||||||||||||||||||||||||||||||||||||||||||||||
-----------------------------------------------------
--------------------YOU WIN!!!-----------------------
-----------------------------------------------------
||||| CONGRATULATIONS YOU HIT THE RIGHT NUMBER ||||||
-----------------------------------------------------
||||||||||||||||||||||||||||||||||||||||||||||||||||| 
)";
	return win; 
}