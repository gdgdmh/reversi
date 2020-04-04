﻿#ifndef REVERSI_LOGIC_PLAYER_IMOVETHINKING_H_
#define REVERSI_LOGIC_PLAYER_IMOVETHINKING_H_

#include "../base/ReversiConstant.h"
#include "../base/Board.h"
#include "../base/MoveInfo.h"

namespace reversi {

// 思考インターフェース
class IMoveThinking {
public:

	/**
	 * デストラクタ
	 */
	virtual ~IMoveThinking();

	/**
	 * 思考
	 * @param  board    盤情報
	 * @param  move     着手情報
	 * @param  turn     手番
	 * @return          trueなら思考が完了
	 */
	virtual bool MoveThinking(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) = 0;

};

}

#endif  // REVERSI_LOGIC_PLAYER_IMOVETHINKING_H_