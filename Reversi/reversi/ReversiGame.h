#ifndef REVERSI_REVERSIGAME_H_
#define REVERSI_REVERSIGAME_H_

namespace reversi {

// リバーシのゲーム統括クラス
class ReversiGame {
public:

	/**
	 * コンストラクタ
	 */
	ReversiGame();

	/**
	 * デストラクタ
	 */
	virtual ~ReversiGame();

	/**
	 * メイン処理
	 */
	void Task();

};

}

#endif  // REVERSI_REVERSIGAME_H_
