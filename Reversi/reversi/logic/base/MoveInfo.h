#ifndef REVERSI_LOGIC_BASE_MOVEINFO_H_
#define REVERSI_LOGIC_BASE_MOVEINFO_H_

#include "ReversiConstant.h"
#include "ReverseInfo.h"

namespace reversi {

// 着手情報クラス
class MoveInfo {
public:

	// 着手情報
	typedef struct {
		reversi::ReversiConstant::POSITION position;    // 位置
		reversi::ReversiConstant::BOARD_INFO info;  // 着手する石
		reversi::ReversiConstant::TURN turn;            // 手番
		reversi::ReverseInfo::REVERSE_INFO reverseInfo; // 裏返し情報
	} MOVE_INFO;

public:

	/**
	 * コンストラクタ
	 * @param info 着手情報
	 */
	MoveInfo(MOVE_INFO info);

	/**
	 * デストラクタ
	 */
	virtual ~MoveInfo();

	/**
	 * 着手情報取得
	 * @return 着手情報
	 */
	MOVE_INFO Get() {
		return moveInfo;
	};

private:
	MOVE_INFO moveInfo;
};

}

#endif  // REVERSI_LOGIC_BASE_MOVEINFO_H_
