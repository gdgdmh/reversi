#include "Board.h"
#include "../../util/IOutputConsole.h"

/**
 * コンストラクタ
 */
reversi::Board::Board() {
	for (int i = 0; i < reversi::ReversiConstant::BOARD_SIZE; ++i) {
		board[i] = reversi::ReversiConstant::INVALID;
	}
	boardSizeX = reversi::ReversiConstant::BOARD_SIZE_X;
	boardSizeY = reversi::ReversiConstant::BOARD_SIZE_Y;
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
	for (int i = 0; i < reversi::ReversiConstant::BOARD_SIZE; ++i) {
		board[i] = reversi::ReversiConstant::INVALID;
	}
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

/**
 * 盤の表示(コンソール)
 * @param console コンソール出力先
 */
void reversi::Board::Render(IOutputConsole* console) {
}
