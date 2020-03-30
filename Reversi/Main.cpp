﻿// Main.cpp

#include <iostream>
#include <string>
#include "reversi/ReversiGame.h"
#include "reversi/test/code/TestDevelop.h"

// エントリーポイント;
int main(int argc, const char* argv[]) {

	bool isTest = true;
	if (isTest) {
		// 実装テスト
		reversi::TestDevelop* testDevelop = new reversi::TestDevelop();
		testDevelop->Execute();
		if (testDevelop) {
			delete testDevelop;
			testDevelop = NULL;
		}
	} else {
		// リバーシゲーム
		reversi::ReversiGame* reversiGame = new reversi::ReversiGame();
		reversiGame->Task();
		if (reversiGame) {
			delete reversiGame;
			reversiGame = NULL;
		}
	}

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
