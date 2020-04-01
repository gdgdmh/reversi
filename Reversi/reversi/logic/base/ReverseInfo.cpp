#include "ReverseInfo.h"
#include "../../util/Assert.h"

//const int reversi::ReverseInfo::MAX_DIRECTION = 8;

/**
 * コンストラクタ
 * @param position 打つ位置
 * @param turn     手番
 */
reversi::ReverseInfo::ReverseInfo(reversi::ReversiConstant::POSITION position, reversi::ReversiConstant::TURN turn) {
	info.position = position;
	for (int i = 0; i < reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT; ++i) {
		info.reversePositions[i] = reversi::ReversiConstant::POSITION::A1;
	}
	info.reversePositionCount = 0;
	info.turn = turn;
}

/**
 * デストラクタ
 */
reversi::ReverseInfo::~ReverseInfo() {
}

/**
 * 裏返る位置を追加登録する
 * @param reversePosition 登録するデータ
 */
void reversi::ReverseInfo::AddReversePosition(reversi::ReversiConstant::POSITION reversePosition) {
	if (info.reversePositionCount < reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT) {
		return;
	}
	reversi::Assert::AssertArrayRange(info.reversePositionCount, reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT, "ReverseInfo::AddReversePosition index over");
	info.reversePositions[info.reversePositionCount] = reversePosition;
	++info.reversePositionCount;
}

/**
 * 裏返る位置の取得
 * @param  index 取得するindex
 * @return 裏返る位置
 */
reversi::ReversiConstant::POSITION reversi::ReverseInfo::GetReversePosition(int index) const {
	reversi::Assert::AssertArrayRange(info.reversePositionCount, reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT, "ReverseInfo::GetReversePosition index over");
	return info.reversePositions[index];
}
