#include "ReversiGameScene.h"
#include "../util/OutputConsole.h"
#include "../game/KeyboardSelectYesNo.h"

/**
 * コンストラクタ
 */
reversi::ReversiGameScene::ReversiGameScene() : console(NULL), scene(reversi::ReversiGameScene::SCENE::INITIALIZE), selectYesNo(NULL) {
}

/**
 * デストラクタ
 */
reversi::ReversiGameScene::~ReversiGameScene() {
	if (selectYesNo) {
		delete selectYesNo;
		selectYesNo = NULL;
	}
	if (console) {
		delete console;
		console = NULL;
	}
}

/**
 * 初期化
 */
void reversi::ReversiGameScene::Initialize() {
	console = new OutputConsole();
	selectYesNo = new KeyboardSelectYesNo();
}

/**
 * メイン処理
 * @return falseなら終了
 */
bool reversi::ReversiGameScene::Task() {
	switch (scene) {
	case reversi::ReversiGameScene::SCENE::INITIALIZE:
		TaskInitialize();
		break;
	case reversi::ReversiGameScene::SCENE::REVERSI_START:
		TaskReversiStart();
		break;
	case reversi::ReversiGameScene::SCENE::REVERSI_TASK:
		TaskReversiTask();
		break;
	case reversi::ReversiGameScene::SCENE::REVERSI_ASK_CONTINUE:
		TaskReversiAskContinue();
		break;
	}
	return true;
}

/**
 * 初期化シーン
 */
void reversi::ReversiGameScene::TaskInitialize() {
	SetScene(reversi::ReversiGameScene::SCENE::REVERSI_START);
}

/**
 * リバーシ開始シーン
 */
void reversi::ReversiGameScene::TaskReversiStart() {
	reversi.Initialize();
	reversi.InitializeGame();
	SetScene(reversi::ReversiGameScene::SCENE::REVERSI_TASK);
}

/**
 * リバーシメインシーン
 */
void reversi::ReversiGameScene::TaskReversiTask() {
	reversi.Task();
	if (reversi.GetScene() == reversi::Reversi::SCENE::END) {
		// 再対局確認
		console->PrintLine("再対局しますか？(入力例 Yes または No)");
		selectYesNo->Initialize();
		SetScene(reversi::ReversiGameScene::SCENE::REVERSI_ASK_CONTINUE);
	}
}

/**
 * リバーシ再対局確認シーン
 */
void reversi::ReversiGameScene::TaskReversiAskContinue() {
	selectYesNo->Task();
	if (selectYesNo->IsWrongInput()) {
		// 正しくない入力
		console->PrintLine("入力が間違っています、もう一度入力してください");
		return;
	}
	if (selectYesNo->IsSelected()) {
		if (selectYesNo->IsSelectYes()) {
			SetScene(reversi::ReversiGameScene::SCENE::REVERSI_START);
			return;
		}
	}
}

/**
 * シーンの設定
 * @param nextScene 次のシーン
 */
void reversi::ReversiGameScene::SetScene(reversi::ReversiGameScene::SCENE nextScene) {
	scene = nextScene;
}
