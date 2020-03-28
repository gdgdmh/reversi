#ifndef REVERSI_LOGIC_BASE_BOARD_H_
#define REVERSI_LOGIC_BASE_BOARD_H_

#include "ReversiConstant.h"

namespace reversi {

//  8x8の盤だが斜め判定を考慮して全体を無効マスで囲う用にしている(Xが無効マス)
// XXXXXXXXXX
// X--------X
// X--------X
// X--------X
// X--------X
// X--------X
// X--------X
// X--------X
// X--------X
// XXXXXXXXXX
// リバーシ盤クラス
class Board {
public:
	/**
	 * コンストラクタ
	 */
	Board();

	/**
	 * デストラクタ
	 */
	virtual ~Board();

	/**
	 * 盤のクリア(全て石なしとする)
	 */
	void Clear();

	/**
	 * ゲーム開始前の初期化
	 */
	void InitializeGame();

	/**
	 * 盤に石情報をセットする
	 */
	void Put();

	/**
	 * 盤の座標に設定されている石の情報を取得する
	 * @param  x 座標X
	 * @param  y 座標Y
	 * @return   石情報
	 */
	ReversiConstant::BOARD_INFO GetStone(int x, int y);

private:
	// 盤
	int board[ReversiConstant::BOARD_SIZE];
	// 盤のXサイズ
	int boardSizeX;
	// 盤のYサイズ
	int boardSizeY;
};

}

#endif  // REVERSI_LOGIC_BASE_BOARD_H_
