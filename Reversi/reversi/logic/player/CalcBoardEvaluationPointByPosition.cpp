#include "CalcBoardEvaluationPointByPosition.h"
#include "../../util/Assert.h"

// 定数定義
// 静的評価(位置によるポイント)
const int reversi::CalcBoardEvaluationPointByPosition::STATIC_EVALUATION_POINTS[reversi::ReversiConstant::POSITION_SIZE] = {
	60,  -30,  20,   5,   5,  20, -30,  60,
	-30,  -40,  -5,  -5,  -5,  -5, -40, -30,
	20,   -5,  20,   3,   3,  20,  -5,  20,
	5,   -5,   3,   3,   3,   3,  -5,   5,
	5,   -5,   3,   3,   3,   3,  -5,   5,
	20,   -5,  20,   3,   3,  20,  -5,  20,
	-30,  -40,  -5,  -5,  -5,  -5, -40, -30,
	60,  -30,  20,   5,  20,  20, -30,  60,
};

/**
 * コンストラクタ
 */
reversi::CalcBoardEvaluationPointByPosition::CalcBoardEvaluationPointByPosition() {
}

/**
 * デストラクタ
 */
reversi::CalcBoardEvaluationPointByPosition::~CalcBoardEvaluationPointByPosition() {
}

/**
 * 盤評価値を計算する
 * @param board 盤
 * @param turn  どの手番を評価するか
 */
void reversi::CalcBoardEvaluationPointByPosition::CalcBoardEvaluationPoint(const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
}
