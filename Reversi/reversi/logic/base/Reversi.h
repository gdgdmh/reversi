#ifndef REVERSI_LOGIC_BASE_REVERSI_H_
#define REVERSI_LOGIC_BASE_REVERSI_H_

#include "ReversiConstant.h"
#include "Board.h"
#include "../player/IPlayer.h"

namespace reversi {

// リバーシクラス
class Reversi {
public:
	static const int PLAYER_COUNT = 2;
	static const int PLAYER_BLACK = 0;
	static const int PLAYER_WHITE = 1;
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
	void ResetPlayer();

	void ReleasePlayer();

private:
	reversi::Board board;
	reversi::ReversiConstant::TURN turn;
	reversi::IPlayer* player[PLAYER_COUNT];

};

}

#endif  // REVERSI_LOGIC_BASE_REVERSI_H_
