#ifndef REVERSI_SCENE_REVERSIGAMESCENE_H_
#define REVERSI_SCENE_REVERSIGAMESCENE_H_

#include "../util/IOutputConsole.h"
#include "../logic/base/Reversi.h"
#include "../game/ISelectYesNoWatching.h"
#include "../game/ISelectCpuLevel.h"
#include "../game/ISelectYesNo.h"

namespace reversi {

// リバーシゲームシーン
class ReversiGameScene {
public:
	enum class SCENE {
		INITIALIZE,
		REVERSI_ASK_PLAYER_SETTING,
		REVERSI_ASK_CPU_SETTING,
		REVERSI_ASK_CPU2_SETTING,
		REVERSI_START,
		REVERSI_TASK,
		REVERSI_ASK_CONTINUE,
		END
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
	 * プレイヤー設定確認シーン
	 */
	void TaskAskPlayerSetting();

	/**
	 * CPU設定確認シーン
	 */
	void TaskAskCpuSetting();

	/**
	 * CPU2人目瀬底確認シーン
	 */
	void TaskAskCpu2Setting();

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
	 * 終了シーン
	 */
	void TaskEnd();

	/**
	 * シーンの設定
	 * @param nextScene 次のシーン
	 */
	void SetScene(reversi::ReversiGameScene::SCENE nextScene);

	/**
	 * ゲームの初期化に必要なインスタンスの生成
	 * ゲームを開始するたびに初期化される
	 */
	void CreateInitializeGameInstance();

	/**
	 * int数値からCPUプレイヤーを取得する
	 * @param  cpuLevel CPUレベル数値
	 * @return          レベルに対応したCPUプレイヤー
	 */
	reversi::Reversi::PLAYER NumberToCpuLevel(int cpuLevel);

private:
	reversi::IOutputConsole* console;
	SCENE scene;
	reversi::Reversi reversi;
	reversi::ISelectYesNoWatching* selectYesNoWatching;
	reversi::ISelectCpuLevel* selectCpuLevel;
	reversi::ISelectCpuLevel* selectCpuLevel2;
	reversi::ISelectYesNo* selectYesNo;
};

}

#endif  // REVERSI_SCENE_REVERSIGAMESCENE_H_
