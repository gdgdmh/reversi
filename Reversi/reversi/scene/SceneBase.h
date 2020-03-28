#ifndef REVERSI_SCENE_SCENEBASE_H_
#define REVERSI_SCENE_SCENEBASE_H_

namespace reversi {

// シーンのベースクラス
class SceneBase {
public:

	/**
	 * シーンタスク実行
	 */
	virtual void Task() = 0;

	/**
	 * 描画処理
	 */
	virtual void Render() = 0;
};

}

#endif  // REVERSI_SCENE_SCENEBASE_H_
