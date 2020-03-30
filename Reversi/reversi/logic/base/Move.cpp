#include "Move.h"

/**
 * コンストラクタ
 */
reversi::Move::Move() {
}

/**
 * デストラクタ
 */
reversi::Move::~Move() {
}

/**
 * 石の置かれていない場所を探す
 * @param board          盤データ
 * @param emptyPositions 結果をいれるための参照渡しオブジェクト
 */
void reversi::Move::FindEmptyPosition(const reversi::Board& board, EMPTY_POSITIONS& emptyPositions) {
}

/**
 * 打てる場所を探す
 * @param board          盤データ
 * @param emptyPositions 石の置かれてない場所が入ったデータ
 * @param turn           手番(黒,白)
 */
void reversi::Move::FindPutEnablePosition(const reversi::Board& board, const EMPTY_POSITIONS& emptyPositions, reversi::ReversiConstant::TURN turn) {
}
