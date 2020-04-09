#ifndef REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU3_H_
#define REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU3_H_

#include "IMoveThinking.h"
#include "../base/ReversiConstant.h"
#include "../base/MoveInfo.h"
#include "../base/Move.h"

// 前方宣言
namespace reversi {
class Board;
}

namespace reversi {

// プレイヤー(CPU)思考クラス LEVEL3
// 静的評価関数を使用する
class MoveThinkingCpu3 : public IMoveThinking {
private:
	// 静的評価位置
	// 石が置いてある場所によって評価をつける(ここの位置はいい、悪いなど)
	static const int STATIC_EVALUATION_POINTS[reversi::ReversiConstant::POSITION_SIZE];
	// 参考元
	static const int DEFAULT_STATIC_EVALUATION_POINTS[reversi::ReversiConstant::POSITION_SIZE];
	static const int DEFAULT_POINTS = -99999;
public:
	/**
	 * コンストラクタ
	 */
	MoveThinkingCpu3();

	/**
	 * デストラクタ
	 */
	virtual ~MoveThinkingCpu3();

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

	reversi::ReversiConstant::BOARD_INFO GetTurnToStone(reversi::ReversiConstant::TURN turn);

private:
	reversi::Move reversiMove;

};

}

#endif  // REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU3_H_
