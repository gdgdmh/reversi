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
	enum class DIRECTION {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		UP_LEFT,
		UP_RIGHT,
		DOWN_LEFT,
		DOWN_RIGHT
	};
	// 挟まれチェックの状態
	enum SANDWICH_STATUS {
		SANDWICH_OK,        // 挟み状態になっている
		SANDWICH_CONTINUE,      // まだ挟み状態になっているかわからない
		SANDWICH_NG_INVALID,   // 無効マスで挟みにならない
		SANDWICH_NG_EMPTY,     // 空マスで挟みにならない
		SANDWICH_NG_SELF,      // 自分の石で挟みにならない
		SANDWICH_NG_UNKNOWN
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

	/**
	 * 位置から盤のオフセットを取得する
	 * @param  direction 方向
	 * @return           盤のオフセット
	 */
	int ToDirectionOffset(DIRECTION direction);

	/**
	 * 挟まれている情報の取得
	 * @param  isSandwichStarted 挟まれているか
	 * @param  sandwichCount     いくつ挟まれているか
	 * @param  turn              手番(黒,白)
	 * @param  info              盤の情報
	 * @return                   状態
	 */
	reversi::Move::SANDWICH_STATUS GetSandwichInfo(bool& isSandwichStarted, int& sandwichCount, reversi::ReversiConstant::TURN turn, reversi::ReversiConstant::BOARD_INFO info);

};

}

#endif  // REVERSI_LOGIC_RENDER_RENDERBOARDCONSOLE_H_
