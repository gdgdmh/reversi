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

	{
		size_t size = emptyPosition.position.size();
		for (int i = 0; i < size; ++i) {
			reversi::ReversiConstant::POSITION position = emptyPosition.position[i];
			// 初期位置の石のpositionは含まれていないことを確認
			if (!AssertEqual((position != reversi::ReversiConstant::POSITION::D4) && (position != reversi::ReversiConstant::POSITION::E5) && (position != reversi::ReversiConstant::POSITION::E4) && (position != reversi::ReversiConstant::POSITION::D5), "TestMove::Execute invalid findEmptyPosition")) {
				return false;
			}
		}
	}
	// 打つことができるか(黒) CheckEnableMove
	// D3, C4, F5, E6
	{
		// 空いている盤座標
		size_t size = emptyPosition.position.size();
		for (int i = 0; i < size; ++i) {
			reversi::ReversiConstant::POSITION position = emptyPosition.position[i];
			switch (position) {
				// 黒はこの座標に打つことができる
			case reversi::ReversiConstant::POSITION::D3:
			case reversi::ReversiConstant::POSITION::C4:
			case reversi::ReversiConstant::POSITION::F5:
			case reversi::ReversiConstant::POSITION::E6:
				AssertEqual(move.CheckEnableMove(board, (int)position,  reversi::ReversiConstant::TURN_BLACK), "TestMove::Execute invalid CheckEnableMove black enable");
				break;
			default:
				// 打てない
				AssertEqual(!move.CheckEnableMove(board, (int)position,  reversi::ReversiConstant::TURN_BLACK), "TestMove::Execute invalid CheckEnableMove black disable");
				break;
			}
		}
	}
	// 打つことができるか(白)
	{
		// 空いている盤座標
		size_t size = emptyPosition.position.size();
		for (int i = 0; i < size; ++i) {
			reversi::ReversiConstant::POSITION position = emptyPosition.position[i];
			switch (position) {
				// 白はこの座標に打つことができる
			case reversi::ReversiConstant::POSITION::E3:
			case reversi::ReversiConstant::POSITION::F4:
			case reversi::ReversiConstant::POSITION::C5:
			case reversi::ReversiConstant::POSITION::D6:
				AssertEqual(move.CheckEnableMove(board, (int)position,  reversi::ReversiConstant::TURN_WHITE), "TestMove::Execute invalid CheckEnableMove white enable");
				break;
			default:
				// 打てない
				AssertEqual(!move.CheckEnableMove(board, (int)position,  reversi::ReversiConstant::TURN_WHITE), "TestMove::Execute invalid CheckEnableMove white disable");
				break;
			}
		}
	}
	return true;
}

