#ifndef REVERSI_TEST_CODE_TESTBOARD_H_
#define REVERSI_TEST_CODE_TESTBOARD_H_

#include "../base/UnitTestBase.h"

namespace reversi {

// 盤テストクラス
class TestBoard : public UnitTestBase {
public:
	/**
	 * コンストラクタ
	 */
	TestBoard(reversi::IOutputConsole* outputConsole);

	/**
	 * デストラクタ
	 */
	virtual ~TestBoard();

	/**
	 * 実行
	 */
	void Execute();
};

}

#endif  // REVERSI_TEST_CODE_TESTBOARD_H_
