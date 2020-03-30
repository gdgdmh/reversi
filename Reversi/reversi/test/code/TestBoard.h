#ifndef REVERSI_TEST_CODE_TESTBOARD_H_
#define REVERSI_TEST_CODE_TESTBOARD_H_

#include "../base/UnitTestBase.h"

namespace reversi {

// 盤テストクラス
class TestBoard {
public:
	/**
	 * コンストラクタ
	 */
	TestBoard();

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
