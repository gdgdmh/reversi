#include "Reversi.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::Reversi::Reversi() {
}

/**
 * デストラクタ
 */
reversi::Reversi::~Reversi() {
}

/**
 *  初期化
 */
void reversi::Reversi::Initialize() {
	board.InitializeGame();
	turn = reversi::ReversiConstant::TURN::TURN_BLACK;
}

/**
 * ゲーム開始のための初期化
 */
void reversi::Reversi::InitializeGame() {
	board.InitializeGame();
	turn = reversi::ReversiConstant::TURN::TURN_BLACK;
}

/**
 * 更新処理
 */
void reversi::Reversi::Task() {
}
