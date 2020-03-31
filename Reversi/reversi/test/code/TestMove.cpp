#include "TestMove.h"
// test
#include "../../logic/base/Move.h"
#include "../../logic/base/Board.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::TestMove::TestMove(reversi::IOutputConsole* outputConsole) : UnitTestBase(outputConsole) {
}

/**
 * デストラクタ
 */
reversi::TestMove::~TestMove() {
}

/**
 * 実行
 * @return trueなら成功 falseなら失敗
 */
bool reversi::TestMove::Execute() {
	reversi::Board board;
	board.InitializeGame();

	// 初期化した盤に対して空の位置を取得する(初期位置の石には置けない)
    reversi::Move move;
	reversi::EMPTY_POSITION emptyPosition;
    move.FindEmptyPosition(board, emptyPosition);

	size_t size = emptyPosition.position.size();
	for (int i = 0; i < size; ++i) {
		reversi::ReversiConstant::BOARD_INFO position = (reversi::ReversiConstant::BOARD_INFO)emptyPosition.position[i];
		// 初期位置の石のpositionは含まれていないことを確認
		reversi::Assert::AssertEquals((position != reversi::ReversiConstant::D4) && (position != reversi::ReversiConstant::E5) && (position != reversi::ReversiConstant::E4) && (position != reversi::ReversiConstant::D5), "TestMove::Execute invalid findEmptyPosition");
	}
	return true;
}

