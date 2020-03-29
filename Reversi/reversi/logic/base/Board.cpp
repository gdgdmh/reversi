#include "Board.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::Board::Board() : boardSizeX(reversi::ReversiConstant::BOARD_SIZE_X), boardSizeY(reversi::ReversiConstant::BOARD_SIZE_Y) {
	Clear();
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

	/*
	    std::cout << "　　　ａ　　　ｂ　　　ｃ　　　ｄ　　　ｅ　　　ｆ　　　ｇ　　　ｈ　　" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	    std::cout << "１｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	    std::cout << "２｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	    std::cout << "３｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	    std::cout << "４｜　　　｜　　　｜　　　｜　◯　｜　Ｘ　｜　　　｜　　　｜　　　｜" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	    std::cout << "５｜　　　｜　　　｜　　　｜　Ｘ　｜　◯　｜　　　｜　　　｜　　　｜" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	    std::cout << "６｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	    std::cout << "７｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	    std::cout << "８｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜　　　｜" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;

	 */
}

/**
 * 盤のクリア(全て石なしとする)
 */
void reversi::Board::Clear() {
	for (int i = 0; i < reversi::ReversiConstant::BOARD_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::BOARD_SIZE, "Board::Clear() index over");
		board[i] = reversi::ReversiConstant::INVALID;
	}
}

/**
 * 空の盤を設定する
 */
void reversi::Board::SetEmpty() {
	for (int i = 0; i < reversi::ReversiConstant::POSITION_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::POSITION_SIZE, "Board::SetEmpty() index over positions");
		reversi::Assert::AssertArrayRange(reversi::ReversiConstant::POSITIONS[i], reversi::ReversiConstant::BOARD_SIZE, "Board::SetEmpty() index over board");
		board[reversi::ReversiConstant::POSITIONS[i]] = reversi::ReversiConstant::BOARD_INFO::NONE;
	}
}

/**
 * ゲーム開始のための初期配置設定
 */
void reversi::Board::Preset() {
	board[reversi::ReversiConstant::POSITION::D4] = reversi::ReversiConstant::BOARD_INFO::WHITE;
	board[reversi::ReversiConstant::POSITION::E5] = reversi::ReversiConstant::BOARD_INFO::WHITE;
	board[reversi::ReversiConstant::POSITION::E4] = reversi::ReversiConstant::BOARD_INFO::BLACK;
	board[reversi::ReversiConstant::POSITION::D5] = reversi::ReversiConstant::BOARD_INFO::BLACK;
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
	/*
	    std::cout << "　　　ａ　　　ｂ　　　ｃ　　　ｄ　　　ｅ　　　ｆ　　　ｇ　　　ｈ　　" << std::endl;
	    std::cout << "　＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋ーーー＋" << std::endl;
	 */
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
