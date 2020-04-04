#include "MoveThinkingMan.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::MoveThinkingMan::MoveThinkingMan() {
}

/**
 * デストラクタ
 */
reversi::MoveThinkingMan::~MoveThinkingMan() {
}

/**
 * 思考
 * @param  board    盤情報
 * @param  move     着手情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
bool reversi::MoveThinkingMan::MoveThinking(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {
	return false;
}
