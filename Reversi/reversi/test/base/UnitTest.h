#ifndef REVERSI_TEST_UNITTEST_H_
#define REVERSI_TEST_UNITTEST_H_

namespace reversi {

	// ユニットテストクラス
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
		 * 実行
		 */
		void Execute();
	};

}

#endif  // REVERSI_TEST_UNITTEST_H_
