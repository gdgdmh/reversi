#ifndef REVERSI_TEST_UNITTEST_H_
#define REVERSI_TEST_UNITTEST_H_

namespace reversi {

	// 単体テストクラス
	class UnitTest {
	public:
		/**
		 * コンストラクタ
		 */
		UnitTest();

		/**
		 * デストラクタ
		 */
		virtual ~UnitTest();

		/**
		 * 単体テストを実行する
		 */
		void Execute();
	};

}

#endif  // REVERSI_TEST_UNITTEST_H_
