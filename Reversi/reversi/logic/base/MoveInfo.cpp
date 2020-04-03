#include "MoveInfo.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 * @param moveInfo    着手情報
 * @param reverseInfo 裏返し情報
 */
reversi::MoveInfo::MoveInfo(MOVE_INFO moveInfo, const reversi::ReverseInfo& reverseInfo) : moveInfo(moveInfo), reverseInfo(reverseInfo) {
}

/**
 * デストラクタ
 */
reversi::MoveInfo::~MoveInfo() {
}
