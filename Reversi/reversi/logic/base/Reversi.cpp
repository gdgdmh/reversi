#include "Reversi.h"
#include "../../util/Assert.h"
#include "../player/PlayerMan.h"
#include "../player/PlayerCpu.h"

/**
 * コンストラクタ
 */
reversi::Reversi::Reversi() : turn(reversi::ReversiConstant::TURN::TURN_BLACK), scene(reversi::Reversi::SCENE::INITIALIZE) {
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
	SetScene(reversi::Reversi::SCENE::INITIALIZE);
	// 暫定として人間vs人間としておく
	for (int i = 0; i < PLAYER_COUNT; ++i) {
		player[i] = new PlayerMan();
	}
}

/**
 * ゲーム開始のための初期化
 */
void reversi::Reversi::InitializeGame() {
	board.InitializeGame();
	turn = reversi::ReversiConstant::TURN::TURN_BLACK;
	SetScene(reversi::Reversi::SCENE::MOVE_START);
}

/**
 * 更新処理
 */
void reversi::Reversi::Task() {
	if (scene == reversi::Reversi::SCENE::INITIALIZE) {
	} else if (scene == reversi::Reversi::SCENE::MOVE_START) {
		board.Render();
		SetScene(reversi::Reversi::SCENE::MOVE_SELECT);
	} else if (scene == reversi::Reversi::SCENE::MOVE_SELECT) {
		if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
			reversi::MoveInfo move;
            bool isDecide = false;
            isDecide = player[PLAYER_BLACK]->SelectMove(board, move, turn);
		} else {
            reversi::MoveInfo move;
            bool isDecide = false;
            isDecide = player[PLAYER_WHITE]->SelectMove(board, move, turn);
        }
	} else if (scene == reversi::Reversi::SCENE::END) {
	}
}

/**
 * プレイヤーをリセットする(NULLクリア)
 */
void reversi::Reversi::ResetPlayer() {
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        player[i] = NULL;
    }
}

/**
 * プレイヤーを削除する(DELETE)
 */
void reversi::Reversi::ReleasePlayer() {
    for (int i = 0; i < PLAYER_COUNT; ++i) {
        if (player[i] != NULL) {
            delete player[i];
            player[i] = NULL;
        }
    }
}

/**
 * シーンをセットする
 * @param nextScene 次のシーン
 */
void reversi::Reversi::SetScene(reversi::Reversi::SCENE nextScene) {
    scene = nextScene;
}

