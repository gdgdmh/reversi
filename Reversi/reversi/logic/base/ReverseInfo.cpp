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
	for (int i = 0; i < reversi::ReverseInfo::MAX_DIRECTION; ++i) {
		for (int j = 0; j < reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT; ++j) {
			reversi::Assert::AssertArrayRange(i, reversi::ReverseInfo::MAX_DIRECTION, "ReverseInfo::ReverseInfo index over i");
			reversi::Assert::AssertArrayRange(j, reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT, "ReverseInfo::ReverseInfo index over j");
			info.reversePositions[i][j] = reversi::ReversiConstant::POSITION::A1;
		}

	}

	for (int i = 0; i < reversi::ReverseInfo::MAX_DIRECTION; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReverseInfo::MAX_DIRECTION, "ReverseInfo::ReverseInfo index over count i");
		info.reversePositionCount[i] = 0;
	}
	
	info.turn = turn;
}

/**
 * デストラクタ
 */
reversi::ReverseInfo::~ReverseInfo() {
}

/**
 * 裏返る位置を追加登録する
 * @param direction       方向
 * @param reversePosition 登録するデータ
 */
void reversi::ReverseInfo::AddReversePosition(reversi::ReverseInfo::DIRECTION direction, reversi::ReversiConstant::POSITION reversePosition) {
	reversi::Assert::AssertArrayRange((int)direction, reversi::ReverseInfo::MAX_DIRECTION, "ReverseInfo::AddReversePosition index over direction");
	const int directionInt = (int)direction;
	const int positionCount = info.reversePositionCount[directionInt];
	if (info.reversePositionCount[directionInt] >= reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT) {
		return;
	}
	reversi::Assert::AssertArrayRange(directionInt, reversi::ReverseInfo::MAX_DIRECTION, "ReverseInfo::AddReversePosition index over direction 2");
	reversi::Assert::AssertArrayRange(positionCount, reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT, "ReverseInfo::AddReversePosition index over count");
	info.reversePositions[directionInt][positionCount] = reversePosition;
	++info.reversePositionCount[directionInt];
}

/**
 * 裏返る位置をクリアする
 * @param direction 方向
 */
void reversi::ReverseInfo::ClearReversePosition(reversi::ReverseInfo::DIRECTION direction) {
	int directionInt = (int)direction;
	reversi::Assert::AssertArrayRange(directionInt, reversi::ReverseInfo::MAX_DIRECTION, "ReverseInfo::ClearReversePosition index over direction");


	for (int i = 0; i < reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT; ++i) {
		info.reversePositions[directionInt][i] = reversi::ReversiConstant::POSITION::A1;
	}
	info.reversePositionCount[directionInt] = 0;
}

/**
 * 裏返る位置の取得
 * @param  direction 方向
 * @param  index     取得するindex
 * @return           裏返る位置
 */
reversi::ReversiConstant::POSITION reversi::ReverseInfo::GetReversePosition(reversi::ReverseInfo::DIRECTION direction, int index) const {
	reversi::Assert::AssertArrayRange((int)direction, reversi::ReverseInfo::MAX_DIRECTION, "ReverseInfo::GetReversePosition index over direction");
	reversi::Assert::AssertArrayRange(info.reversePositionCount[(int)direction], reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT, "ReverseInfo::GetReversePosition index over");
	return info.reversePositions[(int)direction][index];
}

/**
 * 裏返る位置の数の取得
 * @param  direction 方向
 * @return           裏返る位置のデータの数
 */
int reversi::ReverseInfo::GetReversePositionCount(reversi::ReverseInfo::DIRECTION direction) const {
	reversi::Assert::AssertArrayRange((int)direction, reversi::ReverseInfo::MAX_DIRECTION, "ReverseInfo::GetReversePositionCount index over");
	return info.reversePositionCount[(int)direction];
}

/**
 * どこかの方向に打てば取ることができるか
 * @return trueなら打つことができる
 */
bool reversi::ReverseInfo::IsEnableMove() const {
	for (int i = 0; i < reversi::ReverseInfo::MAX_DIRECTION; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReverseInfo::MAX_DIRECTION, "ReverseInfo::IsEnableMove index over");
		if (info.reversePositionCount[i] > 0) {
			// 取れる方向がある
			return true;
		}
	}
	return false;
}
