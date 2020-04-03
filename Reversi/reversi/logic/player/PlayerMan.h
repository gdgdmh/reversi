#ifndef REVERSI_LOGIC_PLAYER_PLAYERMAN_H_
#define REVERSI_LOGIC_PLAYER_PLAYERMAN_H_

#include "../base/ReversiConstant.h"
#include "../base/MoveInfo.h"

// 前方宣言
namespace reversi {
class Board;
}

namespace reversi {

// プレイヤー(人間)クラス
class PlayerMan {
public:
	/**
	 * コンストラクタ
	 */
	PlayerMan();

	/**
	 * デストラクタ
	 */
	virtual ~PlayerMan();

	/**
	 * 自分のターンが来たときに1度だけ呼ばれる
	 */
	void EventTurnStart();

	/**
	 * 着手処理
	 * @param  board 盤情報
	 * @param  move  着手情報
	 * @param  turn  手番
	 * @return       trueなら着手済み(moveに情報が入っている)
	 */
	bool SelectMove(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn);

	/**
	 * 着手後に呼ばれる
	 */
	void EventMoveAfter();

};

}

#endif  // REVERSI_LOGIC_PLAYER_PLAYERMAN_H_
