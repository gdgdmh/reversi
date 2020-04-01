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
	// 方向
	enum DIRECTION {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		UP_LEFT,
		UP_RIGHT,
		DOWN_LEFT,
		DOWN_RIGHT
	};
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

public:

	/**
	 * その場所に打つことができるか
	 * @param  board    盤データ
	 * @param  position 打とうとする盤の位置
	 * @param  turn     手番(黒,白)
	 * @return          trueならその位置に打つことができる
	 */
	bool CheckEnableMove(const reversi::Board& board, int position, reversi::ReversiConstant::TURN turn);

	/**
	 * その位置の指定方向に打つことができるか
	 * @param  board    盤データ
	 * @param  position 打とうとする盤の位置
	 * @param  direction 打とうとする方向
	 * @param  turn     手番(黒,白)
	 * @return          trueならその方向に打つことができる
	 */
	bool CheckEnableMoveDirection(const reversi::Board& board, int position, DIRECTION direction, reversi::ReversiConstant::TURN turn);


	//void CheckValidBoardEmptyArea(const reversi::Board& board, int position, );

};

}

#endif  // REVERSI_LOGIC_RENDER_RENDERBOARDCONSOLE_H_
