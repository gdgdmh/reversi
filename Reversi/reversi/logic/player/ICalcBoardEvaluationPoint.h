#ifndef REVERSI_LOGIC_PLAYER_ICALCBOARDEVALUATIONPOINT_H_
#define REVERSI_LOGIC_PLAYER_ICALCBOARDEVALUATIONPOINT_H_

#include "../base/ReversiConstant.h"
#include "../base/Board.h"

namespace reversi {

// 盤評価値計算インターフェース
class ICalcBoardEvaluationPoint {
public:
	/**
	 * デストラクタ
	 */
	virtual ~ICalcBoardEvaluationPoint() {
	}

	/**
	 * 盤評価値を計算する
	 * @param board 盤
	 * @param turn  どの手番を評価するか
	 */
	virtual void CalcBoardEvaluationPoint(const reversi::Board& board, reversi::ReversiConstant::TURN turn) = 0;
};

}

#endif  // REVERSI_LOGIC_PLAYER_ICALCBOARDEVALUATIONPOINT_H_
