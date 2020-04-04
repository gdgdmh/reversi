#ifndef REVERSI_LOGIC_PLAYER_PLAYERCPU_H_
#define REVERSI_LOGIC_PLAYER_PLAYERCPU_H_

#include "IMoveThinking.h"
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

	bool GetPositionByInput(reversi::ReversiConstant::POSITION& position);

	reversi::ReversiConstant::BOARD_INFO GetTurnToStone(reversi::ReversiConstant::TURN turn);

private:
	reversi::Move reversiMove;

};

}

#endif  // REVERSI_LOGIC_PLAYER_PLAYERCPU_H_
