#ifndef REVERSI_LOGIC_BASE_MOVE_H_
#define REVERSI_LOGIC_BASE_MOVE_H_

#include "ReversiConstant.h"

namespace reversi {
class Board;
}

namespace reversi {

// 石が置かれていない場所データ
typedef struct {
	reversi::ReversiConstant::POSITION* positions;
	int count;
} EMPTY_POSITIONS;

// 着手クラス
class Move {
public:
	/**
	 * コンストラクタ
	 */
	Move();

	/**
	 * デストラクタ
	 */
	virtual ~Move();

	/**
	 * 石の置かれていない場所を探す
	 * @param board          盤データ
	 * @param emptyPositions 結果をいれるための参照渡しオブジェクト
	 */
	void FindEmptyPosition(const reversi::Board& board, EMPTY_POSITIONS& emptyPositions);

	/**
	 * 打てる場所を探す
	 * @param board          盤データ
	 * @param emptyPositions 石の置かれてない場所が入ったデータ
	 * @param turn           手番(黒,白)
	 */
	void FindPutEnablePosition(const reversi::Board& board, const EMPTY_POSITIONS& emptyPositions, reversi::ReversiConstant::TURN turn);

private:

};

}

#endif  // REVERSI_LOGIC_RENDER_RENDERBOARDCONSOLE_H_
