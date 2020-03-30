#ifndef REVERSI_TEST_TESTDEVELOP_H_
#define REVERSI_TEST_TESTDEVELOP_H_

namespace reversi {

	// 実装テスト用クラス
	class TestDevelop {
	public:
		/**
		 * コンストラクタ
		 */
		TestDevelop();

		/**
		 * デストラクタ
		 */
		virtual ~TestDevelop();

		/**
		 * 実行
		 */
		void Execute();
	};

}

#endif  // REVERSI_TEST_TESTDEVELOP_H_
