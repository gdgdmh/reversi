#ifndef REVERSI_LOGIC_BASE_REVERSI_H_
#define REVERSI_LOGIC_BASE_REVERSI_H_

#include "ReversiConstant.h"
#include "Board.h"

namespace reversi {

// リバーシクラス
class Reversi {
public:

	/**
	 * コンストラクタ
	 */
	Reversi();

	/**
	 * デストラクタ
	 */
	virtual ~Reversi();

	/**
	 *  初期化
	 */
	void Initialize();

	/**
	 * ゲーム開始のための初期化
	 */
	void InitializeGame();

	/**
	 * 更新処理
	 */
	void Task();


	reversi::ReversiConstant::TURN GetTurn() {
		return turn;
	}

private:
	reversi::Board board;
	reversi::ReversiConstant::TURN turn;

};

}

#endif  // REVERSI_LOGIC_BASE_REVERSI_H_
