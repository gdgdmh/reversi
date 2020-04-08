#include "ReversiGameScene.h"

/**
 * コンストラクタ
 */
reversi::ReversiGameScene::ReversiGameScene() : scene(reversi::ReversiGameScene::SCENE::INITIALIZE) {
}

/**
 * デストラクタ
 */
reversi::ReversiGameScene::~ReversiGameScene() {
}

/**
 * 初期化
 */
void reversi::ReversiGameScene::Initialize() {
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
}

/**
 * リバーシ再対局確認シーン
 */
void reversi::ReversiGameScene::TaskReversiAskContinue() {
	SetScene(reversi::ReversiGameScene::SCENE::REVERSI_START);
}

/**
 * シーンの設定
 * @param nextScene 次のシーン
 */
void reversi::ReversiGameScene::SetScene(reversi::ReversiGameScene::SCENE nextScene) {
	scene = nextScene;
}
