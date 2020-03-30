#include "Board.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::Board::Board() {
	Clear();
	board.boardSizeX = reversi::ReversiConstant::BOARD_SIZE_X;
	board.boardSizeY = reversi::ReversiConstant::BOARD_SIZE_Y;
}

/**
 * デストラクタ
 */
reversi::Board::~Board() {
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
void reversi::Board::Render(IOutputConsole* const console) {
	if (console == NULL) {
		return;
	}
	RenderBoardTop(console);
	for (int i = 0; i < reversi::ReversiConstant::BOARD_SIZE_Y; ++i) {
		RenderBoardLine(console);
		RenderBoardHorizontalCells(console, i + 1);
	}
	RenderBoardLine(console);
	// 表示イメージ
/*
　　　ａ　　　ｂ　　　ｃ　　　ｄ　　　ｅ　　　ｆ　　　ｇ　　　ｈ　　
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
１｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
２｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
３｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
４｜　　　｜　　　｜　　　｜　○　｜　●　｜　　　｜　　　｜　　　｜
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
５｜　　　｜　　　｜　　　｜　●　｜　○　｜　　　｜　　　｜　　　｜
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
６｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
７｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
８｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜
　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋
*/
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
		dest.board.boardData[i] = board.boardData[i];
	}
	dest.board.boardSizeX = board.boardSizeX;
	dest.board.boardSizeY = board.boardSizeY;
	return dest;
}


/**
 * 盤のクリア(全て石なしとする)
 */
void reversi::Board::Clear() {
	for (int i = 0; i < reversi::ReversiConstant::BOARD_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::BOARD_SIZE, "Board::Clear() index over");
		board.boardData[i] = reversi::ReversiConstant::INVALID;
	}
}

/**
 * 空の盤を設定する
 */
void reversi::Board::SetEmpty() {
	for (int i = 0; i < reversi::ReversiConstant::POSITION_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::POSITION_SIZE, "Board::SetEmpty() index over positions");
		reversi::Assert::AssertArrayRange(reversi::ReversiConstant::POSITIONS[i], reversi::ReversiConstant::BOARD_SIZE, "Board::SetEmpty() index over board");
		board.boardData[reversi::ReversiConstant::POSITIONS[i]] = reversi::ReversiConstant::BOARD_INFO::NONE;
	}
}

/**
 * ゲーム開始のための初期配置設定
 */
void reversi::Board::Preset() {
	board.boardData[reversi::ReversiConstant::POSITION::D4] = reversi::ReversiConstant::BOARD_INFO::WHITE;
	board.boardData[reversi::ReversiConstant::POSITION::E5] = reversi::ReversiConstant::BOARD_INFO::WHITE;
	board.boardData[reversi::ReversiConstant::POSITION::E4] = reversi::ReversiConstant::BOARD_INFO::BLACK;
	board.boardData[reversi::ReversiConstant::POSITION::D5] = reversi::ReversiConstant::BOARD_INFO::BLACK;
}

/**
 * 盤の上部の表示
 * @param console コンソール出力先
 */
void reversi::Board::RenderBoardTop(IOutputConsole* const console) {
	if (console == NULL) {
		return;
	}
	std::string renderString = "　　　ａ　　　ｂ　　　ｃ　　　ｄ　　　ｅ　　　ｆ　　　ｇ　　　ｈ　　";
	console->PrintLine(renderString);
}

/**
 * 盤のラインの表示
 * @param console コンソール出力先
 */
void reversi::Board::RenderBoardLine(IOutputConsole* const console) {
	if (console == NULL) {
		return;
	}
	std::string renderString = "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋";
	console->PrintLine(renderString);
}

/**
 * 盤の横一列マスの表示
 * @param console コンソール出力先
 * @param y       何列目か(1～8)
 */
void reversi::Board::RenderBoardHorizontalCells(IOutputConsole* const console, int y) {
	if (console == NULL) {
		return;
	}
	reversi::Assert::AssertEquals((y > 0) && (y <= reversi::ReversiConstant::BOARD_SIZE_Y), "Board::RenderBoardHorizontalCells() invalid y range");
	// コンパイラ警告対応(index overする可能性があると出てしまうので)
	if ((y <= 0) || (y > reversi::ReversiConstant::BOARD_SIZE_Y)) {
		return;
	}
	std::string out = GetFullWidth1Number(y) + "｜";
	int posY = y - 1;
	// 横一列の情報を取得して表示の文字列に変換
	for (int i = 0; i < reversi::ReversiConstant::BOARD_SIZE_X; ++i) {
		// POSITION_HORIZONTALSのindex overチェック
		Assert::AssertArrayRange(posY, reversi::ReversiConstant::BOARD_SIZE_Y, "Board::RenderBoardHorizontalCells() index over y");
		Assert::AssertArrayRange(i, reversi::ReversiConstant::BOARD_SIZE_X, "Board::RenderBoardHorizontalCells() index over x");
		// 横一列の位置取得
		int position = reversi::ReversiConstant::POSITION_HORIZONTALS[posY][i];

		// boardのindex overチェック
		Assert::AssertArrayRange(position, reversi::ReversiConstant::BOARD_SIZE, "Board::RenderBoardHorizontalCells() index over board");
		// 盤の情報から表示文字列を結合
		out += "　" + GetBoardInfoString((reversi::ReversiConstant::BOARD_INFO)board.boardData[position]) + "　｜";
	}
	console->PrintLine(out);
}

/**
 * 盤の下部の表示
 * @param console コンソール出力先
 */
void reversi::Board::RenderBoardBottom(IOutputConsole* const console) {
	if (console == NULL) {
		return;
	}
	std::string renderString = "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋";
	console->PrintLine(renderString);
}

/**
 * 全角数字1桁を取得する
 * @param  number 0～9までの数字
 * @return        全角数字
 */
std::string reversi::Board::GetFullWidth1Number(int number) {
	switch (number) {
	case 0:
		return "０";
	case 1:
		return "１";
	case 2:
		return "２";
	case 3:
		return "３";
	case 4:
		return "４";
	case 5:
		return "５";
	case 6:
		return "６";
	case 7:
		return "７";
	case 8:
		return "８";
	case 9:
		return "９";
	default:
		return "";
	}
}

std::string reversi::Board::GetBoardInfoString(reversi::ReversiConstant::BOARD_INFO info) {
	switch (info) {
	case reversi::ReversiConstant::BOARD_INFO::NONE:
		return "　";
	case reversi::ReversiConstant::BOARD_INFO::BLACK:
		return "●";
	case reversi::ReversiConstant::BOARD_INFO::WHITE:
		return "○";
	case reversi::ReversiConstant::BOARD_INFO::INVALID:
		return "X"; // 本来表示しない
	default:
		return "";
	}
}
