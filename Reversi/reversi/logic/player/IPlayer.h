#ifndef REVERSI_LOGIC_PLAYER_IPLAYER_H_
#define REVERSI_LOGIC_PLAYER_IPLAYER_H_

#include "../base/ReversiConstant.h"
#include "../base/MoveInfo.h"

// 前方宣言
namespace reversi {
class Board;
}

namespace reversi {

// プレイヤーベースクラス
class IPlayer {
public:
	/**
	 * デストラクタ
	 */
	virtual ~IPlayer() {
	}

	/**
	 * 初期化
	 */
	virtual void Initialize() = 0;

	/**
	 * 自分のターンが来たときに1度だけ呼ばれる
	 * @param board 盤情報
	 * @param turn  手番
	 */
	virtual void EventTurnStart(const reversi::Board& board, reversi::ReversiConstant::TURN turn) = 0;

	/**
	 * 着手処理
	 * @param  board 盤情報
	 * @param  move  着手情報
	 * @param  turn  手番
	 * @return       trueなら着手済み(moveに情報が入っている)
	 */
	virtual bool SelectMove(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) = 0;

	/**
	 * 着手後に呼ばれる
	 */
	virtual void EventMoveAfter() = 0;

};

}

#endif  // REVERSI_LOGIC_PLAYER_IPLAYER_H_
