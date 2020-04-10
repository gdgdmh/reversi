﻿#include <iostream>
#include "MoveThinkingCpu3.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"
#include "../../util/IRandomInt.h"
#include "../../util/StdRandomInt.h"

// 定数定義
// 静的評価位置
const int reversi::MoveThinkingCpu3::STATIC_EVALUATION_POINTS[reversi::ReversiConstant::POSITION_SIZE] = {
	 60,  -30,  20,   5,   5,  20, -30,  60,
	-30,  -40,  -5,  -5,  -5,  -5, -40, -30,
	 20,   -5,  20,   3,   3,  20,  -5,  20,
	  5,   -5,   3,   3,   3,   3,  -5,   5,
	  5,   -5,   3,   3,   3,   3,  -5,   5,
	 20,   -5,  20,   3,   3,  20,  -5,  20,
	-30,  -40,  -5,  -5,  -5,  -5, -40, -30,
	 60,  -30,  20,   5,  20,  20, -30,  60,
};
// 参考元
const int reversi::MoveThinkingCpu3::DEFAULT_STATIC_EVALUATION_POINTS[reversi::ReversiConstant::POSITION_SIZE] = {
	120,  -20,  20,   5,   5,  20, -20, 120,
	-20,  -40,  -5,  -5,  -5,  -5, -40, -20,
	 20,   -5,  15,   3,   3,  15,  -5,  20,
	  5,   -5,   3,   3,   3,   3,  -5,   5,
	  5,   -5,   3,   3,   3,   3,  -5,   5,
	 20,   -5,  15,   3,   3,  15,  -5,  20,
	-20,  -40,  -5,  -5,  -5,  -5, -40, -20,
	120,  -20,  20,   5,  20,  20, -20, 120,
};

/**
 * コンストラクタ
 */
reversi::MoveThinkingCpu3::MoveThinkingCpu3() {
}

/**
 * デストラクタ
 */
reversi::MoveThinkingCpu3::~MoveThinkingCpu3() {
}

/**
 * 思考初期化
 * 手番が来たときに一度だけ呼ばれる
 * @param  board    盤情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
void reversi::MoveThinkingCpu3::InitializeMoveThinking(const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	// 空の位置を探す
	reversi::ReversiConstant::EMPTY_POSITION emptyPosition;
	reversiMove.FindEmptyPosition(board, emptyPosition);
	// 打てる位置を探す
	reversiMove.FindPutEnablePosition(board, emptyPosition, turn);
}

/**
 * 思考
 * @param  board    盤情報
 * @param  move     着手情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
bool reversi::MoveThinkingCpu3::MoveThinking(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {

	reversi::ReversiConstant::POSITION maxPosition = reversi::ReversiConstant::POSITION::A1; // 仮
	int currentPoint = DEFAULT_POINTS; // 現在の最高評価値
	int reverseInfoIndex = 0;
	bool isUpdate = false; // 更新したか(バグチェック用)

	int size = reversiMove.GetReverseInfoSize();
	for (int i = 0; i < size; ++i) {
		const reversi::ReverseInfo& reverseInfo = reversiMove.GetReverseInfoByIndex(i);
		reversi::Assert::AssertArrayRange(i, size, "MoveThinkingCpu3::MoveThinking index over reverseInfo");
		reversi::ReversiConstant::POSITION position = reverseInfo.GetPosition();
		if (!reversiMove.CheckEnableMoveByCache(position)) {
			// うてないならスキップ
			continue;
		}

		int positionIndex = reversi::ReversiConstant::GetPositionToIndex(position);
		reversi::Assert::AssertArrayRange(positionIndex, reversi::ReversiConstant::POSITION_SIZE, "MoveThinkingCpu3::MoveThinking index over position index");
		if (currentPoint < STATIC_EVALUATION_POINTS[positionIndex]) {
			// 現在の評価値より高いなら更新
			maxPosition = position;
			reverseInfoIndex = i;
			currentPoint = STATIC_EVALUATION_POINTS[positionIndex];
			isUpdate = true;
		}
	}
	// 最低でも1度は更新されるはず
	reversi::Assert::AssertEquals(isUpdate, "MoveThinkingCpu3::MoveThinking not update");

	// 着手情報を作成
	const reversi::ReverseInfo& reverseInfo = reversiMove.GetReverseInfoByIndex(reverseInfoIndex);
	reversi::MoveInfo::MOVE_INFO moveInfoData;
	moveInfoData.position = reverseInfo.GetPosition();
	moveInfoData.info = GetTurnToStone(turn);
	moveInfoData.turn = turn;
	reversi::MoveInfo moveInfo(moveInfoData, reverseInfo);
	// 着手情報を入力
	move.Copy(moveInfo);
	return true;
}

reversi::ReversiConstant::BOARD_INFO reversi::MoveThinkingCpu3::GetTurnToStone(reversi::ReversiConstant::TURN turn) {
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	} else {
		return reversi::ReversiConstant::BOARD_INFO::WHITE;
	}
}
