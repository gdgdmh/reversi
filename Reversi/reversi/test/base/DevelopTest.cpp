#include "DevelopTest.h"
// test include(テストするものはここに追加する)
#include "../../util/OutputConsole.h"
#include "../../util/OutputVisualStudioConsole.h"
#include "../../test/base/UnitTest.h"
#include "../../logic/base/Board.h"
#include "../../logic/base/Move.h"

#include "../code/TestBoard.h"


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

	// UnitTest
	{
		reversi::TestBoard t;
		t.Execute();
	}

	Board board;
	board.InitializeGame();

	// 出力
	board.Render();

	// 空いているマスを確認
	{
		Move move;
		reversi::EMPTY_POSITION emptyPosition;
		move.FindEmptyPosition(board, emptyPosition);
	}


	/*
	{
		Board board2;
		board2 = board.Clone();

	}
	*/

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
