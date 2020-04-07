﻿#include "PLayerMan.h"
#include "MoveThinkingMan.h"
#include "../../util/OutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::PlayerMan::PlayerMan() : moveThinking(NULL), console(NULL) {
}

/**
 * デストラクタ
 */
reversi::PlayerMan::~PlayerMan() {
	if (moveThinking) {
		delete moveThinking;
		moveThinking = NULL;
	}
    if (console) {
        delete console;
        console = NULL;
    }
}

/**
 * 初期化
 */
void reversi::PlayerMan::Initialize() {
	if (moveThinking == NULL) {
		moveThinking = new MoveThinkingMan();
	}
    if (console == NULL) {
        console = new OutputConsole();
    }
}

/**
 * 自分のターンが来たときに1度だけ呼ばれる
 * @param board 盤情報
 * @param turn  手番
 */
void reversi::PlayerMan::EventTurnStart(const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	moveThinking->InitializeMoveThinking(board, turn);
    console->PrintLine("石を打つ場所を入力してください");
}

/**
 * 着手処理
 * @param  board 盤情報
 * @param  move  着手情報
 * @param  turn  手番
 * @return       trueなら着手済み(moveに情報が入っている)
 */
bool reversi::PlayerMan::SelectMove(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {
    bool result = moveThinking->MoveThinking(board, move, turn);
    if (!result) {
        console->PrintLine("うまく場所を読み取れなかったのでもう一度入力してください");
    }
	return result;
}

/**
 * 着手後に呼ばれる
 */
void reversi::PlayerMan::EventMoveAfter() {
}
