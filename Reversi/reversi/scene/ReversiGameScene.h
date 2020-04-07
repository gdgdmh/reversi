#ifndef REVERSI_SCENE_REVERSIGAMESCENE_H_
#define REVERSI_SCENE_REVERSIGAMESCENE_H_

#include "../logic/base/Reversi.h"

namespace reversi {

// リバーシゲームシーン
class ReversiGameScene {
public:

	/**
	 * コンストラクタ
	 */
	ReversiGameScene();

	/**
	 * デストラクタ
	 */
	virtual ~ReversiGameScene();

	/**
	 * 初期化
	 */
	void Initialize();

	/**
	 * メイン処理
	 * @return falseなら終了
	 */
	bool Task();

private:
	reversi::Reversi reversi;
};

}

#endif  // REVERSI_SCENE_REVERSIGAMESCENE_H_
