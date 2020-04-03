#ifndef REVERSI_GAME_REVERSIGAMELOOP_H_
#define REVERSI_GAME_REVERSIGAMELOOP_H_

#include "../logic/base/Reversi.h"

namespace reversi {

// ゲームループクラス
class ReversiGameLoop {
public:

	ReversiGameLoop();

	/**
	 * デストラクタ
	 */
	virtual ~ReversiGameLoop();

	void Initialize();

	/**
	 * メイン処理
	 */
	void Task();

private:
	reversi::Reversi reversi;
	
};

}

#endif  // REVERSI_GAME_REVERSIGAMELOOP_H_
