#include "PLayerCpu.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::PlayerCpu::PlayerCpu() {
}

/**
 * デストラクタ
 */
reversi::PlayerCpu::~PlayerCpu() {
}

/**
 * 自分のターンが来たときに1度だけ呼ばれる
 */
void reversi::PlayerCpu::EventTurnStart() {
}

/**
 * 着手処理
 * @param  board 盤情報
 * @param  move  着手情報
 * @param  turn  手番
 * @return       trueなら着手済み(moveに情報が入っている)
 */
bool reversi::PlayerCpu::SelectMove(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {
    return false;
}

/**
 * 着手後に呼ばれる
 */
void reversi::PlayerCpu::EventMoveAfter() {
}
