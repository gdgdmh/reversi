﻿#include "PLayerCpu.h"
#include "MoveThinkingCpu1.h"
#include "MoveThinkingCpu2.h"
#include "MoveThinkingCpu3.h"
#include "MoveThinkingCpu4.h"
#include "MoveThinkingCpu5.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::PlayerCpu::PlayerCpu(reversi::PlayerCpu::LEVEL level) : moveThinking(NULL) {
	// 思考レベル指定に応じて思考クラスを生成
	switch (level) {
	case reversi::PlayerCpu::LEVEL::LEVEL1:
		moveThinking = new MoveThinkingCpu1();
		break;
	case reversi::PlayerCpu::LEVEL::LEVEL2:
		moveThinking = new MoveThinkingCpu2();
		break;
	case reversi::PlayerCpu::LEVEL::LEVEL3:
		moveThinking = new MoveThinkingCpu3();
		break;
	case reversi::PlayerCpu::LEVEL::LEVEL4:
		moveThinking = new MoveThinkingCpu4();
		break;
	case reversi::PlayerCpu::LEVEL::LEVEL5:
		moveThinking = new MoveThinkingCpu5();
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
 * 自分の手番が来たときに一度だけ呼ばれる
 * @param reversi   リバーシクラス
 * @param moveCache 着手キャッシュ
 * @param board     盤情報
 * @param turn      手番
 */
void reversi::PlayerCpu::EventTurnStart(const reversi::Reversi& reversi, const reversi::Move& moveCache, const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	moveThinking->InitializeMoveThinking(reversi, moveCache, board, turn);
}

/**
 * 着手処理
 * @param  reversi   リバーシクラス
 * @param  moveCache 着手キャッシュ
 * @param  board     盤情報
 * @param  move      着手情報
 * @param  turn      手番
 * @return           trueなら思考が完了
 */
bool reversi::PlayerCpu::SelectMove(const reversi::Reversi& reversi, const reversi::Move& moveCache, const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {
	return moveThinking->MoveThinking(reversi, moveCache, board, move, turn);
}

/**
 * 着手後に呼ばれる
 */
void reversi::PlayerCpu::EventMoveAfter() {
}
