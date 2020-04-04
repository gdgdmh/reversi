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
        player[i]->Initialize();
	}
}

/**
 * ゲーム開始のための初期化
 */
void reversi::Reversi::InitializeGame() {
	board.InitializeGame();
	turn = reversi::ReversiConstant::TURN::TURN_BLACK;
	SetScene(reversi::Reversi::SCENE::MOVE_SELECT_START);
}

/**
 * 更新処理
 */
void reversi::Reversi::Task() {
	if (scene == reversi::Reversi::SCENE::INITIALIZE) {
		TaskInitialize();
	} else if (scene == reversi::Reversi::SCENE::MOVE_SELECT_START) {
		TaskMoveSelectStart();
	} else if (scene == reversi::Reversi::SCENE::MOVE_SELECT) {
		TaskMoveSelect();
	} else if (scene == reversi::Reversi::SCENE::MOVE_AFTER) {
		TaskMoveAfter();
	} else if (scene == reversi::Reversi::SCENE::END) {
		TaskEnd();
	}
}

/**
 * 初期化
 */
void reversi::Reversi::TaskInitialize() {
}

/**
 * 着手選択開始
 */
void reversi::Reversi::TaskMoveSelectStart() {
	board.Render();
    int playerIndex = TurnToPlayerIndex(turn);
    player[playerIndex]->EventTurnStart(board, turn);
	SetScene(reversi::Reversi::SCENE::MOVE_SELECT);
}

/**
 * 着手選択
 */
void reversi::Reversi::TaskMoveSelect() {
	int playerIndex = TurnToPlayerIndex(turn);
	reversi::MoveInfo move;
	
	bool isDecide = player[playerIndex]->SelectMove(board, move, turn);
    if (isDecide) {
        moveInfo = move;
        bool isMove = board.Move(moveInfo);
        reversi::Assert::AssertEquals(isMove, "Reversi::TaskMoveSelect move invalid");
        SetScene(reversi::Reversi::SCENE::MOVE_AFTER);
    }
}

/**
 * 着手後処理
 */
void reversi::Reversi::TaskMoveAfter() {

    int playerIndex = TurnToPlayerIndex(turn);
    player[playerIndex]->EventMoveAfter();

    // ターン切り替え
    ChangeTurn(turn);

    SetScene(reversi::Reversi::SCENE::MOVE_SELECT_START);
    /*
std::string input;
std::cout << "Your move: ";
std::getline(std::cin, input);
std::cout << "Opponent move: XX" << std::endl;

    */
}

/**
 * 対局終了
 */
void reversi::Reversi::TaskEnd() {
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

/**
 * 手番からプレイヤーのindexを取得する
 * @param  turn 手番
 * @return      プレイヤーindex
 */
int reversi::Reversi::TurnToPlayerIndex(reversi::ReversiConstant::TURN turn) {
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return PLAYER_BLACK;
	} else {
		return PLAYER_WHITE;
	}
}

void reversi::Reversi::ChangeTurn(reversi::ReversiConstant::TURN& turn) {
    // 手番切り替え(黒->白, 白->黒)
    if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
        turn = reversi::ReversiConstant::TURN::TURN_WHITE;
    } else {
        turn = reversi::ReversiConstant::TURN::TURN_BLACK;
    }
}
