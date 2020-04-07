﻿#ifndef REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU1_H_
#define REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU1_H_

#include "IMoveThinking.h"
#include "../base/ReversiConstant.h"
#include "../base/MoveInfo.h"
#include "../base/Move.h"

// 前方宣言
namespace reversi {
class Board;
}

namespace reversi {

// プレイヤー(CPU)思考クラス1
class MoveThinkingCpu1 : public IMoveThinking {
public:
	static const int MIN_COUNT_DEFAULT = 999; // 取れる石をチェックするときのデフォルト最小値(18以上にすれば安全)
public:
	/**
	 * コンストラクタ
	 */
	MoveThinkingCpu1();

	/**
	 * デストラクタ
	 */
	virtual ~MoveThinkingCpu1();

	/**
	 * 思考初期化
	 * 手番が来たときに一度だけ呼ばれる
	 * @param  board    盤情報
	 * @param  turn     手番
	 * @return          trueなら思考が完了
	 */
	virtual void InitializeMoveThinking(const reversi::Board& board, reversi::ReversiConstant::TURN turn);

	/**
	 * 思考
	 * @param  board    盤情報
	 * @param  move     着手情報
	 * @param  turn     手番
	 * @return          trueなら思考が完了
	 */
	bool MoveThinking(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn);

private:

	/**
	 * 手番から石を取得する
	 * @param  turn 手番
	 * @return      手番の石
	 */
	reversi::ReversiConstant::BOARD_INFO GetTurnToStone(reversi::ReversiConstant::TURN turn);

	/**
	 * 最小の着手をする
	 * @param  board 盤情報
	 * @param  move  着手情報
	 * @param  turn  手番
	 * @return       trueなら思考が完了
	 */
	bool MoveThinkingMin(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn);

	/**
	 * 最小の着手をする
	 * 複数最小値がある場合、ランダム性あり
	 * @param  board 盤情報
	 * @param  move  着手情報
	 * @param  turn  手番
	 * @return       trueなら思考が完了
	 */
	bool MoveThinkingMinRandom(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn);

private:
	reversi::Move reversiMove;
	reversi::ReversiConstant::EMPTY_POSITION emptyPosition;

};

}

#endif  // REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU1_H_
