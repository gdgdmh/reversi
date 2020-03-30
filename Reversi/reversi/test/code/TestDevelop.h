#ifndef REVERSI_TEST_TESTDEVELOP_H_
#define REVERSI_TEST_TESTDEVELOP_H_

#include "../base/UnitTestBase.h"

namespace reversi {

	// 実装テスト用クラス
	class TestDevelop : public UnitTestBase {
	public:
		/**
		 * コンストラクタ
		 */
		TestDevelop(reversi::IOutputConsole* outputConsole);

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
