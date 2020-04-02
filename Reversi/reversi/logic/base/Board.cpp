#include "Board.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"
#include "../render/RenderBoardConsole.h"

/**
 * コンストラクタ
 */
reversi::Board::Board() {
	Clear();
	board.boardSizeX = reversi::ReversiConstant::BOARD_SIZE_X;
	board.boardSizeY = reversi::ReversiConstant::BOARD_SIZE_Y;
	renderBoard = NULL;
}

/**
 * デストラクタ
 */
reversi::Board::~Board() {
	if (renderBoard) {
		delete renderBoard;
		renderBoard = NULL;
	}
}

/**
 * ゲーム開始前の初期化
 */
void reversi::Board::InitializeGame() {
	Clear();
	SetEmpty();
	Preset();
}

/**
 * 着手処理
 * @param moveInfo 着手情報
 */
void reversi::Board::Move(ReversiConstant::MOVE_INFO moveInfo) {
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
void reversi::Board::Render() {
	if (renderBoard == NULL) {
		renderBoard = new RenderBoardConsole();
	}
	renderBoard->Render(*this);
}

/**
 * 盤の生データを取得する
 * @return 盤の生データ
 */
const reversi::BOARD& reversi::Board::GetRawData() const {
	return board;
}

/**
 * DeepCopy
 * @return 複製データ
 */
reversi::Board reversi::Board::Clone() const {
	Board dest;

	for (int i = 0; i < ReversiConstant::BOARD_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::BOARD_SIZE, "Board::Clone() index over");
		dest.SetBoardInfo((reversi::ReversiConstant::BOARD_INFO)board.boardData[i], (reversi::ReversiConstant::POSITION)i);
	}
	dest.board.boardSizeX = board.boardSizeX;
	dest.board.boardSizeY = board.boardSizeY;
	if (dest.renderBoard) {
		delete dest.renderBoard;
		dest.renderBoard = NULL;
	}
	dest.renderBoard = NULL;
	return dest;
}


/**
 * 盤のクリア(全て石なしとする)
 */
void reversi::Board::Clear() {
	for (int i = 0; i < reversi::ReversiConstant::BOARD_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::BOARD_SIZE, "Board::Clear() index over");
		SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::INVALID, (reversi::ReversiConstant::POSITION)i);
	}
}

/**
 * 空の盤を設定する
 */
void reversi::Board::SetEmpty() {
	for (int i = 0; i < reversi::ReversiConstant::POSITION_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::POSITION_SIZE, "Board::SetEmpty() index over positions");
		reversi::Assert::AssertArrayRange((int)reversi::ReversiConstant::POSITIONS[i], reversi::ReversiConstant::BOARD_SIZE, "Board::SetEmpty() index over board");
		SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::NONE, reversi::ReversiConstant::POSITIONS[i]);
	}
}

/**
 * ゲーム開始のための初期配置設定
 */
void reversi::Board::Preset() {
	SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::WHITE, reversi::ReversiConstant::POSITION::D4);
	SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::WHITE, reversi::ReversiConstant::POSITION::E5);
	SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::BLACK, reversi::ReversiConstant::POSITION::E4);
	SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::BLACK, reversi::ReversiConstant::POSITION::D5);
}

/**
 * 盤の情報をセットする
 * @param info     セットする盤情報
 * @param position セットする位置
 */
void reversi::Board::SetBoardInfo(reversi::ReversiConstant::BOARD_INFO info, reversi::ReversiConstant::POSITION position) {
	reversi::Assert::AssertArrayRange((int)position, reversi::ReversiConstant::BOARD_SIZE, "Board::SetBoardInfo index over");
	board.boardData[(int)position] = (int)info;
}

/**
 * 石をひっくり返す(黒 -> 白, 白 -> 黒)
 * 石がなかったら何もしない
 * @param position [description]
 */
void reversi::Board::ReverseStone(reversi::ReversiConstant::POSITION position) {
}
