#include "PLayerCpu.h"
#include "MoveThinkingCpu1.h"
#include "MoveThinkingCpu2.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::PlayerCpu::PlayerCpu(reversi::PlayerCpu::LEVEL level) : moveThinking(NULL) {
	switch (level) {
	case reversi::PlayerCpu::LEVEL::LEVEL1:
		moveThinking = new MoveThinkingCpu1();
		break;
    case reversi::PlayerCpu::LEVEL::LEVEL2:
        moveThinking = new MoveThinkingCpu2();
        break;
	default:
		break;
	}
}

/**
 * デストラクタ
 */
reversi::PlayerCpu::~PlayerCpu() {
	if (moveThinking) {
		delete moveThinking;
		moveThinking = NULL;
	}
}

/**
 * 初期化
 */
void reversi::PlayerCpu::Initialize() {
}

/**
 * 自分のターンが来たときに1度だけ呼ばれる
 * @param board 盤情報
 * @param turn  手番
 */
void reversi::PlayerCpu::EventTurnStart(const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	moveThinking->InitializeMoveThinking(board, turn);
}

/**
 * 着手処理
 * @param  board 盤情報
 * @param  move  着手情報
 * @param  turn  手番
 * @return       trueなら着手済み(moveに情報が入っている)
 */
bool reversi::PlayerCpu::SelectMove(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {
	return moveThinking->MoveThinking(board, move, turn);
}

/**
 * 着手後に呼ばれる
 */
void reversi::PlayerCpu::EventMoveAfter() {
}
