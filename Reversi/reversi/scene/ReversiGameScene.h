#ifndef REVERSI_SCENE_REVERSIGAMESCENE_H_
#define REVERSI_SCENE_REVERSIGAMESCENE_H_

#include "../logic/base/Reversi.h"

namespace reversi {

// リバーシゲームシーン
class ReversiGameScene {
public:
	enum class SCENE {
		INITIALIZE,
		REVERSI_START,
		REVERSI_TASK,
		REVERSI_ASK_CONTINUE,
	};
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
	/**
	 * 初期化シーン
	 */
	void TaskInitialize();

	/**
	 * リバーシ開始シーン
	 */
	void TaskReversiStart();

	/**
	 * リバーシメインシーン
	 */
	void TaskReversiTask();

	/**
	 * リバーシ再対局確認シーン
	 */
	void TaskReversiAskContinue();

	/**
	 * シーンの設定
	 * @param nextScene 次のシーン
	 */
	void SetScene(reversi::ReversiGameScene::SCENE nextScene);

private:
	SCENE scene;
	reversi::Reversi reversi;
};

}

#endif  // REVERSI_SCENE_REVERSIGAMESCENE_H_
