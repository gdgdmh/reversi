#include <iostream>
#include "MoveThinkingCpu3.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"
#include "../../util/IRandomInt.h"
#include "../../util/StdRandomInt.h"

// 定数定義
// 静的評価位置
const int reversi::MoveThinkingCpu3::STATIC_EVALUATION_POSITIONS[reversi::ReversiConstant::POSITION_SIZE] = {
	 60,  -30,  20,   5,   5,  20, -30,  60,
	-30,  -40,  -5,  -5,  -5,  -5, -40, -30,
	 20,   -5,  20,   3,   3,  20,  -5,  20,
	  5,   -5,   3,   3,   3,   3,  -5,   5,
	  5,   -5,   3,   3,   3,   3,  -5,   5,
	 20,   -5,  20,   3,   3,  20,  -5,  20,
	-30,  -40,  -5,  -5,  -5,  -5, -40, -30,
	 60,  -30,  20,   5,  20,  20, -30,  60,
};
// 参考元
const int reversi::MoveThinkingCpu3::DEFAULT_STATIC_EVALUATION_POSITIONS[reversi::ReversiConstant::POSITION_SIZE] = {
	120,  -20,  20,   5,   5,  20, -20, 120,
	-20,  -40,  -5,  -5,  -5,  -5, -40, -20,
	 20,   -5,  15,   3,   3,  15,  -5,  20,
	  5,   -5,   3,   3,   3,   3,  -5,   5,
	  5,   -5,   3,   3,   3,   3,  -5,   5,
	 20,   -5,  15,   3,   3,  15,  -5,  20,
	-20,  -40,  -5,  -5,  -5,  -5, -40, -20,
	120,  -20,  20,   5,  20,  20, -20, 120,
};

/**
 * コンストラクタ
 */
reversi::MoveThinkingCpu3::MoveThinkingCpu3() {
}

/**
 * デストラクタ
 */
reversi::MoveThinkingCpu3::~MoveThinkingCpu3() {
}

/**
 * 思考初期化
 * 手番が来たときに一度だけ呼ばれる
 * @param  board    盤情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
void reversi::MoveThinkingCpu3::InitializeMoveThinking(const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	// 空の位置を探す
	reversi::ReversiConstant::EMPTY_POSITION emptyPosition;
	reversiMove.FindEmptyPosition(board, emptyPosition);
	// 打てる位置を探す
	reversiMove.FindPutEnablePosition(board, emptyPosition, turn);
}

/**
 * 思考
 * @param  board    盤情報
 * @param  move     着手情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
bool reversi::MoveThinkingCpu3::MoveThinking(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {
	return false;
}

reversi::ReversiConstant::BOARD_INFO reversi::MoveThinkingCpu3::GetTurnToStone(reversi::ReversiConstant::TURN turn) {
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	} else {
		return reversi::ReversiConstant::BOARD_INFO::WHITE;
	}
}
