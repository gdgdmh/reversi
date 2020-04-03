#include "PLayerMan.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::PlayerMan::PlayerMan() {
}

/**
 * デストラクタ
 */
reversi::PlayerMan::~PlayerMan() {
}

/**
 * 自分のターンが来たときに1度だけ呼ばれる
 */
void reversi::PlayerMan::EventTurnStart() {
}

/**
 * 着手処理
 * @param  board 盤情報
 * @param  move  着手情報
 * @param  turn  手番
 * @return       trueなら着手済み(moveに情報が入っている)
 */
bool reversi::PlayerMan::SelectMove(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {
}

/**
 * 着手後に呼ばれる
 */
void reversi::PlayerMan::EventMoveAfter() {
}
