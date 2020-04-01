#include "TestBoard.h"
// test
#include "../../logic/base/Board.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::TestBoard::TestBoard(reversi::IOutputConsole* outputConsole) : UnitTestBase(outputConsole) {
}

/**
 * デストラクタ
 */
reversi::TestBoard::~TestBoard() {
}

/**
 * 実行
 * @return trueなら成功 falseなら失敗
 */
bool reversi::TestBoard::Execute() {
	reversi::Board board;
	board.InitializeGame();

	// 盤が初期位置になっているかチェック
	int size = reversi::ReversiConstant::POSITION_SIZE;
	const reversi::BOARD boardData = board.GetRawData();
	for (int i = 0; i < size; ++i) {
		reversi::Assert::AssertArrayRange(i, size, "TestBoard::Execute() position index over");
		
		reversi::ReversiConstant::POSITION position = (reversi::ReversiConstant::POSITION)reversi::ReversiConstant::POSITIONS[i];

		reversi::Assert::AssertArrayRange((int)position, reversi::ReversiConstant::BOARD_SIZE, "TestBoard::Execute() board index over");

		reversi::ReversiConstant::BOARD_INFO info = (reversi::ReversiConstant::BOARD_INFO)boardData.boardData[(int)position];

		if ((position == reversi::ReversiConstant::POSITION::D4) || (position == reversi::ReversiConstant::POSITION::E5)) {
			// 白の初期位置
			if (!AssertEqual(info == reversi::ReversiConstant::WHITE, "TestBoard::Execute() NOT WHITE")) {
				return false;
			}
		} else if ((position == reversi::ReversiConstant::POSITION::E4) || (position == reversi::ReversiConstant::POSITION::D5)) {
			// 黒の初期位置
			if (!AssertEqual(info == reversi::ReversiConstant::BLACK, "TestBoard::Execute() NOT BLACK")) {
				return false;
			}
		} else {
			// 空白
			if (!AssertEqual(info == reversi::ReversiConstant::NONE, "TestBoard::Execute() NOT NONE")) {
				return false;
			}
		}
	}
	return true;
}

