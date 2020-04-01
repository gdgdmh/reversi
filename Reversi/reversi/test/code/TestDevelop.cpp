#include "TestDevelop.h"
// test include(テストするものはここに追加する)
#include "../../util/IOutputConsole.h"
#include "../../util/OutputConsole.h"
#include "../../util/OutputVisualStudioConsole.h"
#include "../../test/base/UnitTest.h"
#include "../../logic/base/Board.h"
#include "../../logic/base/Move.h"

#include "../code/TestBoard.h"
#include "../code/TestMove.h"
#include "../code/TestReverseInfo.h"


/**
 * コンストラクタ
 */
reversi::TestDevelop::TestDevelop(reversi::IOutputConsole* outputConsole) : UnitTestBase(outputConsole), console(NULL) {
	console = new OutputConsole();
}

/**
 * デストラクタ
 */
reversi::TestDevelop::~TestDevelop() {
	if (console) {
		delete console;
		console = NULL;
	}
}

/**
 * 実行
 * @return trueなら成功 falseなら失敗
 */
bool reversi::TestDevelop::Execute() {
	console->PrintLine("--- TestDevelop start -------------------");

	// UnitTest
	{
		IOutputConsole* console = new OutputConsole();
		// TestBoard
		{
			reversi::TestBoard t(console);
			t.Execute();
		}
		// TestMove
		{
			reversi::TestMove m(console);
			m.Execute();
		}
		// TestReverseInfo
		{
			reversi::TestReverseInfo info(console);
			info.Execute();
		}
	}

	Board board;
	board.InitializeGame();

	// 出力
	board.Render();

	{
		IOutputConsole* console = new OutputConsole();

		Move move;
		reversi::EMPTY_POSITION emptyPosition;
		// 空いているマスを確認
		move.FindEmptyPosition(board, emptyPosition);

		// その方向に打てるか
		bool result = move.CheckEnableMoveDirection(board, (int)reversi::ReversiConstant::POSITION::D3, reversi::Move::DIRECTION::DOWN, reversi::ReversiConstant::TURN::TURN_BLACK);

		// そのマスに打てるか
		result = move.CheckEnableMove(board, (int)reversi::ReversiConstant::POSITION::F4, reversi::ReversiConstant::TURN::TURN_WHITE);
		if (result) {
			console->PrintLine("put enable");
		} else {
			console->PrintLine("put disable");
		}
	}

	console->PrintLine("--- TestDevelop end -------------------");
	return true;
}
