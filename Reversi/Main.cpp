﻿// メモリリーク検出用
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include <iostream>
#include <string>
#include "reversi/test/code/TestDevelop.h"
#include "reversi/util/IOutputConsole.h"
#include "reversi/util/OutputConsole.h"
#include "reversi/game/ReversiGameLoop.h"

// エントリーポイント;
int main(int argc, const char* argv[]) {
	// メモリリーク検出用
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	reversi::IOutputConsole* console = new reversi::OutputConsole();
	console->PrintLine("--- main start -------------------");

	bool isTest = true;
	if (isTest) {
		// 実装テスト
		reversi::TestDevelop* testDevelop = new reversi::TestDevelop(console);
		bool testResult = testDevelop->Execute();
		if (testDevelop) {
			delete testDevelop;
			testDevelop = NULL;
		}
		if (!testResult) {
			console->PrintLine("test failure abort!");
			if (console) {
				delete console;
				console = NULL;
			}
			return 1;
		}
	}

	// リバーシゲーム
	{
		reversi::ReversiGameLoop gameLoop;
		gameLoop.Initialize();
		gameLoop.Task();
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
	console->PrintLine("--- main end -------------------");
	if (console) {
		delete console;
		console = NULL;
	}
	return 0;
}
