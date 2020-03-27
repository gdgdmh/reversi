// Main.cpp

#include <iostream>
#include <string>
#include "./reversi/ReversiGame.h"
#include "./reversi/util/OutputConsole.h"
#include "./reversi/test/UnitTest.h"

// エントリーポイント;
int main(int argc, const char* argv[]) {

	//reversi::ReversiGame* reversiGame = new reversi::ReversiGame();
	//reversiGame->Task();

	reversi::IOutputConsole* outputConsole = new reversi::OutputConsole();
	outputConsole->Print("aue");
	outputConsole->PrintLine("ライン");
	outputConsole->Print("123");

	reversi::UnitTest* unitTest = new reversi::UnitTest();
	unitTest->Execute();




	/*
	while (true)
	{
		std::cout << "　　　ａ　　　ｂ　　　ｃ　　　ｄ　　　ｅ　　　ｆ　　　ｇ　　　ｈ　　" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
		std::cout << "１｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
		std::cout << "２｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
		std::cout << "３｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
		std::cout << "４｜　　　｜　　　｜　　　｜　◯　｜　Ｘ　｜　　　｜　　　｜　　　｜" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
		std::cout << "５｜　　　｜　　　｜　　　｜　Ｘ　｜　◯　｜　　　｜　　　｜　　　｜" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
		std::cout << "６｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
		std::cout << "７｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
		std::cout << "８｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
		std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;

		std::string input;
		std::cout << "Your move: ";
		std::getline(std::cin, input);
		std::cout << "Opponent move: XX" << std::endl;
	}
	*/

	return 0;
}
