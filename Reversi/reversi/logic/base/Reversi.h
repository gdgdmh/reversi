#ifndef REVERSI_LOGIC_BASE_REVERSI_H_
#define REVERSI_LOGIC_BASE_REVERSI_H_

#include "ReversiConstant.h"
#include "Board.h"
#include "../player/IPlayer.h"
#include "../../util/IOutputConsole.h"

namespace reversi {

// リバーシクラス
class Reversi {
public:
	static const int PLAYER_COUNT = 2;
	static const int PLAYER_BLACK = 0;
	static const int PLAYER_WHITE = 1;
	enum class SCENE {
		INITIALIZE,
		MOVE_SELECT_START,
		MOVE_SELECT,
		MOVE_AFTER,
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
	 * 初期化
	 */
	void TaskInitialize();

	/**
	 * 着手選択開始
	 */
	void TaskMoveSelectStart();

	/**
	 * 着手選択
	 */
	void TaskMoveSelect();

	/**
	 * 着手後処理
	 */
	void TaskMoveAfter();

	/**
	 * 対局終了
	 */
	void TaskEnd();

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

	/**
	 * 手番からプレイヤーのindexを取得する
	 * @param  turn 手番
	 * @return      プレイヤーindex
	 */
	int TurnToPlayerIndex(reversi::ReversiConstant::TURN turn);

	void ChangeTurn(reversi::ReversiConstant::TURN& turn);

	// 終局したか
	bool IsEnded();

private:
	reversi::Board board;
	reversi::ReversiConstant::TURN turn;
	reversi::IPlayer* player[PLAYER_COUNT];
	reversi::Reversi::SCENE scene;
	reversi::MoveInfo moveInfo;
	reversi::IOutputConsole* console;
};

}

#endif  // REVERSI_LOGIC_BASE_REVERSI_H_
