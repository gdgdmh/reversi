#include "Reversi.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::Reversi::Reversi() : turn(reversi::ReversiConstant::TURN::TURN_BLACK) {
    ResetPlayer();
}

/**
 * デストラクタ
 */
reversi::Reversi::~Reversi() {
    ReleasePlayer();
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

void reversi::Reversi::ResetPlayer() {
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        player[i] = NULL;
    }
}

void reversi::Reversi::ReleasePlayer() {
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        if (player[i] != NULL) {
            delete player[i];
            player[i] = NULL;
        }
    }
}
