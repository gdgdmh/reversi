﻿#include "Reversi.h"
#include "../../util/Assert.h"
#include "../../util/OutputConsole.h"
#include "../player/PlayerMan.h"
#include "../player/PlayerCpu.h"
#include "Move.h"

/**
 * コンストラクタ
 */
reversi::Reversi::Reversi() : turn(reversi::ReversiConstant::TURN::TURN_BLACK), scene(reversi::Reversi::SCENE::INITIALIZE), console(NULL), result(reversi::Reversi::RESULT::NONE), resultBlackCount(0), resultWhiteCount(0), resultNoneCount(0) {
	ResetPlayer();
	ResetPassCheck();
}

/**
 * デストラクタ
 */
reversi::Reversi::~Reversi() {
	ReleasePlayer();
	if (console) {
		delete console;
		console = NULL;
	}
}

/**
 *  初期化
 */
void reversi::Reversi::Initialize() {
	board.InitializeGame();
	turn = reversi::ReversiConstant::TURN::TURN_BLACK;
	SetScene(reversi::Reversi::SCENE::INITIALIZE);
	// プレイヤーの初期化
	player[0] = new PlayerMan();
	player[1] = new PlayerCpu(reversi::PlayerCpu::LEVEL::LEVEL1);
	for (int i = 0; i < PLAYER_COUNT; ++i) {
		//player[i] = new PlayerMan();
		player[i]->Initialize();
	}
	if (console == NULL) {
		console = new OutputConsole();
	}
	result = reversi::Reversi::RESULT::NONE;
	ResetPassCheck();
	resultBlackCount = 0;
	resultWhiteCount = 0;
	resultNoneCount = 0;
}

/**
 * ゲーム開始のための初期化
 */
void reversi::Reversi::InitializeGame() {
	board.InitializeGame();
	turn = reversi::ReversiConstant::TURN::TURN_BLACK;
	result = reversi::Reversi::RESULT::NONE;
	SetScene(reversi::Reversi::SCENE::MOVE_SELECT_START);
	ResetPassCheck();
	resultBlackCount = 0;
	resultWhiteCount = 0;
	resultNoneCount = 0;
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
	} else if (scene == reversi::Reversi::SCENE::PASS) {
		TaskPass();
	} else if (scene == reversi::Reversi::SCENE::MOVE_AFTER) {
		TaskMoveAfter();
	} else if (scene == reversi::Reversi::SCENE::RESULT) {
		TaskResult();
	} else if (scene == reversi::Reversi::SCENE::END) {
		TaskEnd();
	}
}

/**
 * 盤面をコピーする(デバッグ用途)
 * @param source コピー元
 */
void reversi::Reversi::CopyBoard(const reversi::Board& source) {
	board.Copy(source);
}

/**
 * 最終結果の石や空白の数を取得する
 * @param black 黒石
 * @param white 白石
 * @param none  空白
 */
void reversi::Reversi::GetResultStone(int& black, int& white, int& none) {
	black = resultBlackCount;
	white = resultWhiteCount;
	none = resultNoneCount;
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

	if (IsEveryonePass()) {
		// 両者パスしたので終局
		SetScene(reversi::Reversi::SCENE::RESULT);
		return;
	}

	if (CheckPass(turn)) {
		// 打つことができないのでパス
		SetPassCheck(turn);
		SetScene(reversi::Reversi::SCENE::PASS);
		return;
	}
	// パスフラグリセット
	ResetPassCheck();

	int playerIndex = TurnToPlayerIndex(turn);
	player[playerIndex]->EventTurnStart(board, turn);
	SetScene(reversi::Reversi::SCENE::MOVE_SELECT);
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		console->PrintLine("黒のターン");
	} else {
		console->PrintLine("白のターン");
	}

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
 * パス
 */
void reversi::Reversi::TaskPass() {
	// ターン切り替え
	ChangeTurn(turn);
	SetScene(reversi::Reversi::SCENE::MOVE_SELECT_START);
}

/**
 * 着手後処理
 */
void reversi::Reversi::TaskMoveAfter() {

	int playerIndex = TurnToPlayerIndex(turn);
	player[playerIndex]->EventMoveAfter();

	// ターン切り替え
	ChangeTurn(turn);

	if (IsEnded()) {
		// 結果
		SetScene(reversi::Reversi::SCENE::RESULT);
		return;
	}
	SetScene(reversi::Reversi::SCENE::MOVE_SELECT_START);
}

/**
 * 結果処理
 */
void reversi::Reversi::TaskResult() {

	// 石の数を取得
	int black, white, none;
	board.GetCount(black, white, none);

	// 結果
	if (black == white) {
		result = reversi::Reversi::RESULT::DRAW;
	} else if (black > white) {
		result = reversi::Reversi::RESULT::BLACK;
	} else if (black < white) {
		result = reversi::Reversi::RESULT::WHITE;
	}
	// 空白の数
	resultBlackCount = black;
	resultWhiteCount = white;
	resultNoneCount = none;
	// 公式ルールで空白は勝者の石になる
	SetResultStone(resultBlackCount, resultWhiteCount, resultNoneCount, result);

	// 終了
	SetScene(reversi::Reversi::SCENE::END);
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
 * @param  targetTurn 手番
 * @return            プレイヤーindex
 */
int reversi::Reversi::TurnToPlayerIndex(reversi::ReversiConstant::TURN targetTurn) {
	if (targetTurn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return PLAYER_BLACK;
	} else {
		return PLAYER_WHITE;
	}
}

/**
 * 手番の切り替え
 * @param targetTurn 現在の手番
 */
void reversi::Reversi::ChangeTurn(reversi::ReversiConstant::TURN& targetTurn) {
	// 手番切り替え(黒->白, 白->黒)
	if (targetTurn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		targetTurn = reversi::ReversiConstant::TURN::TURN_WHITE;
	} else {
		targetTurn = reversi::ReversiConstant::TURN::TURN_BLACK;
	}
}

/**
 * 終局したか
 * @return trueなら終局している
 */
bool reversi::Reversi::IsEnded() {
	if (board.IsFull()) {
		// 盤面が全て埋まっている
		return true;
	}
	return false;
}

/**
 * 打つ場所がなくてパスかどうかチェック
 * @param  targetTurn 現在の手番
 * @return            trueならパス(打つ場所がない)
 */
bool reversi::Reversi::CheckPass(reversi::ReversiConstant::TURN targetTurn) {

	reversi::Move move;
	reversi::EMPTY_POSITION emptyPosition;
	move.FindEmptyPosition(board, emptyPosition);

	// キャッシュを作成する
	move.FindPutEnablePosition(board, emptyPosition, targetTurn);

	return (!move.CheckSomewherePutEnableByCache());
}

/**
 * パスのチェックフラグをリセットする
 */
void reversi::Reversi::ResetPassCheck() {
	passCheck.passBlack = false;
	passCheck.passWhite = false;
}

/**
 * パスのチェックフラグをセットする
 * @param targetTurn 現在の手番
 */
void reversi::Reversi::SetPassCheck(reversi::ReversiConstant::TURN targetTurn) {
	if (targetTurn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		passCheck.passBlack = true;
	} else {
		passCheck.passWhite = true;
	}
}

/**
 * プレイヤー2人ともパスしているか
 * @return trueなら2人ともパスしている
 */
bool reversi::Reversi::IsEveryonePass() const {
	if ((passCheck.passBlack) && (passCheck.passWhite)) {
		return true;
	}
	return false;
}

/**
 * 結果の石をセットする(空白を勝者の石とする)
 * @param black  現在の黒石の数
 * @param white  現在の白石の数
 * @param none   現在の空白の数
 * @param result 勝敗結果
 */
void reversi::Reversi::SetResultStone(int& black, int& white, int& none, reversi::Reversi::RESULT result) {
	// 日本オセロ連盟競技ルール No.13
	// 終局（対局者双方が石を置けなくなった状態）時に盤面に空きマスが発生した場合、その空きマスは勝者の獲得石に加算される。
	if (result == reversi::Reversi::RESULT::BLACK) {
		black += none;
	} else if (result == reversi::Reversi::RESULT::WHITE) {
		white += none;
	}
}
