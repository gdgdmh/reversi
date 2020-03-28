#include "Board.h"

/**
 * コンストラクタ
 */
reversi::Board::Board() {
}

/**
 * デストラクタ
 */
reversi::Board::~Board() {
}

/**
 * 盤のクリア(全て石なしとする)
 */
void reversi::Board::Clear() {
}

/**
 * ゲーム開始前の初期化
 */
void reversi::Board::InitializeGame() {
}

/**
 * 盤に石情報をセットする
 */
void reversi::Board::Put() {
}

/**
 * 盤の座標に設定されている石の情報を取得する
 * @param  x 座標X
 * @param  y 座標Y
 * @return   石情報
 */
reversi::ReversiConstant::BOARD_INFO GetStone(int x, int y) {
	// 仮(ビルドを通すため)
	return reversi::ReversiConstant::BOARD_INFO::NONE;
}
