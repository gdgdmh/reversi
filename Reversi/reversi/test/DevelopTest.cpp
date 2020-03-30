#include "DevelopTest.h"
// test include(テストするものはここに追加する)
#include "../util/OutputConsole.h"
#include "../util/OutputVisualStudioConsole.h"
#include "../test/UnitTest.h"
#include "../logic/base/Board.h"

/**
 * コンストラクタ
 */
reversi::DevelopTest::DevelopTest() {
}

/**
 * デストラクタ
 */
reversi::DevelopTest::~DevelopTest() {
}

/**
 * 実行
 */
void reversi::DevelopTest::Execute() {

	Board board;
	board.InitializeGame();

	// 両方で出力
	OutputConsole console;
	OutputVisualStudioConsole vsConsole;
	board.Render(&console);
	board.Render(&vsConsole);

	{
		Board board2;
		board2 = board.Clone();

	}

	/*
	// コンソールテスト
	reversi::IOutputConsole* outputConsole = new reversi::OutputConsole();
	outputConsole->Print("aue");
	outputConsole->PrintLine("ライン");
	outputConsole->Print("123");
	// ユニットテスト
	reversi::UnitTest* unitTest = new reversi::UnitTest();
	unitTest->Execute();
	*/


}
