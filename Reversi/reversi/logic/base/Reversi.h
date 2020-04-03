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
	enum class SCENE {
		INITIALIZE,
		MOVE_START,
		MOVE_SELECT,
		END
	};
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

private:

	/**
	 * プレイヤーをリセットする(NULLクリア)
	 */
	void ResetPlayer();

	/**
	 * プレイヤーを削除する(DELETE)
	 */
	void ReleasePlayer();

	/**
	 * シーンをセットする
	 * @param nextScene 次のシーン
	 */
	void SetScene(reversi::Reversi::SCENE nextScene);

private:
	reversi::Board board;
	reversi::ReversiConstant::TURN turn;
	reversi::IPlayer* player[PLAYER_COUNT];
	reversi::Reversi::SCENE scene;

};

}

#endif  // REVERSI_LOGIC_BASE_REVERSI_H_
