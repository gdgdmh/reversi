#include <iostream>
#include "MoveThinkingCpu1.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::MoveThinkingCpu1::MoveThinkingCpu1() {
}

/**
 * デストラクタ
 */
reversi::MoveThinkingCpu1::~MoveThinkingCpu1() {
}

/**
 * 思考初期化
 * 手番が来たときに一度だけ呼ばれる
 * @param  board    盤情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
void reversi::MoveThinkingCpu1::InitializeMoveThinking(const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	// 空の位置を探す
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
bool reversi::MoveThinkingCpu1::MoveThinking(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {

	reversi::ReversiConstant::POSITION minPosition = reversi::ReversiConstant::POSITION::A1; // 仮
	int minCount = MIN_COUNT_DEFAULT;
	int minIndex = 0;
	int size = reversiMove.GetReverseInfoSize();
	bool isUpdate = false;
	for (int i = 0; i < size; ++i) {
		const reversi::ReverseInfo& reverseInfo = reversiMove.GetReverseInfoByIndex(i);
		int total = reverseInfo.GetReversePositionCountTotal();
		// 取れる数が少ない + 打てる
		if ((total < minCount) && (reversiMove.CheckEnableMoveByCache(reverseInfo.GetPosition()))) {
			minPosition = reverseInfo.GetPosition();
			minCount = total;
			minIndex = i;
			isUpdate = true;
		}
	}
	// 1つでも打てる箇所があれば引っかかるはず
	reversi::Assert::AssertEquals(isUpdate, "MoveThinkingCpu1::MoveThinking ReverseInfo not hit");

	// 着手情報を確定
	reversi::MoveInfo::MOVE_INFO moveInfoData;
	moveInfoData.position = minPosition;
	moveInfoData.info = GetTurnToStone(turn);
	moveInfoData.turn = turn;
	reversi::MoveInfo moveInfo(moveInfoData, reversiMove.GetReverseInfoByIndex(minIndex));
	// 着手情報を入力
	move.Copy(moveInfo);
	return true;
}

reversi::ReversiConstant::BOARD_INFO reversi::MoveThinkingCpu1::GetTurnToStone(reversi::ReversiConstant::TURN turn) {
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	} else {
		return reversi::ReversiConstant::BOARD_INFO::WHITE;
	}
}