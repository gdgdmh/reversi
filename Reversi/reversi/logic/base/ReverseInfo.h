#ifndef REVERSI_LOGIC_BASE_REVERSEINFO_H_
#define REVERSI_LOGIC_BASE_REVERSEINFO_H_

#include "ReversiConstant.h"

namespace reversi {

// 裏返し情報
class ReverseInfo {
public:

	// 方向
	enum class DIRECTION {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		UP_LEFT,
		UP_RIGHT,
		DOWN_LEFT,
		DOWN_RIGHT
	};
	static const int MAX_DIRECTION = 8;

	// [ReverseInfo::MAX_DIRECTION]
	// 裏返し情報
	typedef struct {
		reversi::ReversiConstant::POSITION position; // 打つ位置
		reversi::ReversiConstant::POSITION reversePositions[reversi::ReversiConstant::ONE_MOVE_MAX_REVERSE_COUNT]; // 打ったことで裏返る位置
		int reversePositionCount; // 裏返る位置の数
		reversi::ReversiConstant::TURN turn; // 手番情報
	} REVERSE_INFO;

public:

	/**
	 * コンストラクタ
	 * @param position 打つ位置
	 * @param turn     手番
	 */
	ReverseInfo(reversi::ReversiConstant::POSITION position, reversi::ReversiConstant::TURN turn);

	/**
	 * デストラクタ
	 */
	virtual ~ReverseInfo();

	/**
	 * 裏返る位置を追加登録する
	 * @param reversePosition 登録するデータ
	 */
	void AddReversePosition(reversi::ReversiConstant::POSITION reversePosition);

	/**
	 * 打つ位置の取得
	 * @return 打つ位置
	 */
	reversi::ReversiConstant::POSITION GetPosition() const {
		return info.position;
	}

	/**
	 * 裏返る位置の取得
	 * @param  index 取得するindex
	 * @return 裏返る位置
	 */
	reversi::ReversiConstant::POSITION GetReversePosition(int index) const;

	/**
	 * 裏返る位置の数の取得
	 * @return 裏返る位置のデータの数
	 */
	int GetReversePositionCount() const {
		return info.reversePositionCount;
	}

	/**
	 * 手番情報の取得
	 * @return 手番情報
	 */
	reversi::ReversiConstant::TURN GetTurn() const {
		return info.turn;
	}

private:
	REVERSE_INFO info;
};

}

#endif  // REVERSI_LOGIC_BASE_REVERSEINFO_H_
