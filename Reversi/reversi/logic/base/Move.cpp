﻿#include "Move.h"
#include "Board.h"
#include "../../util/Assert.h"

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
void reversi::Move::FindEmptyPosition(const reversi::Board& board, EMPTY_POSITION& emptyPosition) {

	// データをクリアしておく
	emptyPosition.position.clear();

	int size = reversi::ReversiConstant::POSITION_SIZE;
	const reversi::BOARD boardData = board.GetRawData();
	for (int i = 0; i < size; ++i) {
		reversi::Assert::AssertArrayRange(i, size, "Move::FindEmptyPosition() position index over");
		
		reversi::ReversiConstant::POSITION position = (reversi::ReversiConstant::POSITION)reversi::ReversiConstant::POSITIONS[i];

		reversi::Assert::AssertArrayRange(position, reversi::ReversiConstant::BOARD_SIZE, "Move::FindEmptyPosition() board index over");

		reversi::ReversiConstant::BOARD_INFO info = (reversi::ReversiConstant::BOARD_INFO)boardData.boardData[(int)position];
		if (info == reversi::ReversiConstant::NONE) {
			emptyPosition.position.push_back(position);
		}
	}
}

/**
 * 打てる場所を探す
 * @param board          盤データ
 * @param emptyPositions 石の置かれてない場所が入ったデータ
 * @param turn           手番(黒,白)
 */
void reversi::Move::FindPutEnablePosition(const reversi::Board& board, const EMPTY_POSITION& emptyPosition, reversi::ReversiConstant::TURN turn) {
}
