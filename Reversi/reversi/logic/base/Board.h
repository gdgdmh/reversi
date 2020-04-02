#ifndef REVERSI_LOGIC_BASE_BOARD_H_
#define REVERSI_LOGIC_BASE_BOARD_H_

#include "ReversiConstant.h"
#include "../render/IRenderBoard.h"
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
} BOARD;

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
	void Render();

	/**
	 * 盤の生データを取得する
	 * @return 盤の生データ
	 */
	const BOARD& GetRawData() const;

	/**
	 * DeepCopy
	 * @return 複製データ
	 */
	Board Clone() const;

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

private:

	/**
	 * 盤の情報をセットする
	 * @param info     セットする盤情報
	 * @param position セットする位置
	 */
	void SetBoardInfo(reversi::ReversiConstant::BOARD_INFO info, reversi::ReversiConstant::POSITION position);

	/**
	 * 石をひっくり返す(黒 -> 白, 白 -> 黒)
	 * 石がなかったら何もしない
	 * @param position [description]
	 */
	void ReverseStone(reversi::ReversiConstant::POSITION position);

private:
	BOARD board;
	IRenderBoard* renderBoard;
};

}

#endif  // REVERSI_LOGIC_BASE_BOARD_H_
