#include "ReversiGameScene.h"

/**
 * コンストラクタ
 */
reversi::ReversiGameScene::ReversiGameScene() {
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
    reversi.Initialize();
    reversi.InitializeGame();
}

/**
 * メイン処理
 * @return falseなら終了
 */
bool reversi::ReversiGameScene::Task() {
    reversi.Task();
	return true;
}
