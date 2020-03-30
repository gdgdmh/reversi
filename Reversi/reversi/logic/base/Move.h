#ifndef REVERSI_LOGIC_BASE_MOVE_H_
#define REVERSI_LOGIC_BASE_MOVE_H_

#include <vector>
#include "ReversiConstant.h"

namespace reversi {
class Board;
}

namespace reversi {

// 石が置かれていない場所データ
typedef struct {
	std::vector<reversi::ReversiConstant::POSITION> position;
} EMPTY_POSITION;

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
	void FindEmptyPosition(const reversi::Board& board, EMPTY_POSITION& emptyPosition);

	/**
	 * 打てる場所を探す
	 * @param board          盤データ
	 * @param emptyPositions 石の置かれてない場所が入ったデータ
	 * @param turn           手番(黒,白)
	 */
	void FindPutEnablePosition(const reversi::Board& board, const EMPTY_POSITION& emptyPosition, reversi::ReversiConstant::TURN turn);

private:

	//void CheckValidBoardEmptyArea(const reversi::Board& board, int position, );

};

}

#endif  // REVERSI_LOGIC_RENDER_RENDERBOARDCONSOLE_H_
