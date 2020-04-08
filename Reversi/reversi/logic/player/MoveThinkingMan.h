#ifndef REVERSI_LOGIC_PLAYER_MOVETHINKINGMAN_H_
#define REVERSI_LOGIC_PLAYER_MOVETHINKINGMAN_H_

#include "IMoveThinking.h"
#include "IPlayerSelectPosition.h"
#include "../base/ReversiConstant.h"
#include "../base/MoveInfo.h"
#include "../base/Move.h"

// 前方宣言
namespace reversi {
class Board;
}

namespace reversi {

// プレイヤー(MAN)思考クラス
class MoveThinkingMan : public IMoveThinking {
public:
	/**
	 * コンストラクタ
	 */
	MoveThinkingMan();

	/**
	 * デストラクタ
	 */
	virtual ~MoveThinkingMan();

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
	 * 入力から位置を取得する
	 * @param  position 入力された位置
	 * @return          trueなら入力された
	 */
	bool GetPositionByInput(reversi::ReversiConstant::POSITION& position);

	/**
	 * 手番から対応した石情報を取得する
	 * @param  turn 手番
	 * @return      対応した石
	 */
	reversi::ReversiConstant::BOARD_INFO GetTurnToStone(reversi::ReversiConstant::TURN turn);

private:
	reversi::Move reversiMove;
	reversi::IPlayerSelectPosition* playerSelectPosition;

};

}

#endif  // REVERSI_LOGIC_PLAYER_MOVETHINKINGMAN_H_
