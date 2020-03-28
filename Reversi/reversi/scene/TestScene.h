#ifndef REVERSI_SCENE_TESTSCENE_H_
#define REVERSI_SCENE_TESTSCENE_H_

namespace reversi {

	// 実装テスト用クラス
	class TestScene {
	public:
		/**
		 * コンストラクタ
		 */
		TestScene();

		/**
		 * デストラクタ
		 */
		virtual ~TestScene();

		/**
		 * 実行
		 */
		void Execute();

	protected:

		void Initialize();

		void Title();

		void MainMenu();

	};

}

#endif  // REVERSI_SCENE_TESTSCENE_H_
