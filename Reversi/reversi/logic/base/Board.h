#ifndef REVERSI_LOGIC_BASE_BOARD_H_
#define REVERSI_LOGIC_BASE_BOARD_H_

#include "ReversiConstant.h"
#include <string>
#include <vector>

// 前方宣言
namespace reversi {
class IOutputConsole;
}

namespace reversi {

typedef struct {
	// 盤
	int boardData[ReversiConstant::BOARD_SIZE];
	// 盤のXサイズ
	int boardSizeX;
	// 盤のYサイズ
	int boardSizeY;
}BOARD;

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
	 * ゲーム開始前の初期化
	 */
	void InitializeGame();

	/**
	 * 着手処理
	 * @param moveInfo 着手情報
	 */
	void Move(ReversiConstant::MOVE_INFO moveInfo);

	/**
	 * 盤の座標に設定されている石の情報を取得する
	 * @param  x 座標X
	 * @param  y 座標Y
	 * @return   石情報
	 */
	ReversiConstant::BOARD_INFO GetStone(int x, int y);

	/**
	 * 盤の表示(コンソール)
	 * @param console コンソール出力先
	 */
	void Render(IOutputConsole* const console);

	// get
	// clone

private:

	/**
	 * 盤のクリア(全て石なしとする)
	 */
	void Clear();

	/**
	 * 空の盤を設定する
	 */
	void SetEmpty();

	/**
	 * ゲーム開始のための初期配置設定
	 */
	void Preset();

	/**
	 * 盤の上部の表示
	 * @param console コンソール出力先
	 */
	void RenderBoardTop(IOutputConsole* const console);

	/**
	 * 盤のラインの表示
	 * @param console コンソール出力先
	 */
	void RenderBoardLine(IOutputConsole* const console);

	/**
	 * 盤の横一列マスの表示
	 * @param console コンソール出力先
	 * @param y       何列目か(1～8)
	 */
	void RenderBoardHorizontalCells(IOutputConsole* const console, int y);

	/**
	 * 盤の下部の表示
	 * @param console コンソール出力先
	 */
	void RenderBoardBottom(IOutputConsole* const console);

	/**
	 * 擬似的なsprintf
	 * @param  fmt  [description]
	 * @param  args [description]
	 * @return      [description]
	 */
	template <typename ... Args>
	std::string FormatString(const std::string& fmt, Args... args) {
		size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args ...);
		std::vector<char> buf(len + 1);
		std::snprintf(&buf[0], len + 1, fmt.c_str(), args ...);
		return std::string(&buf[0], &buf[0] + len);
	}

	/**
	 * 全角数字1桁を取得する
	 * @param  number 0～9までの数字
	 * @return        全角数字
	 */
	std::string GetFullWidth1Number(int number);

	/**
	 * 石の表示用の文字列を取得する
	 * @param  info 盤情報
	 * @return      盤情報表示用文字列
	 */
	std::string GetBoardInfoString(ReversiConstant::BOARD_INFO info);

private:
	BOARD board;
};

}

#endif  // REVERSI_LOGIC_BASE_BOARD_H_
