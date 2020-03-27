#ifndef REVERSI_TEST_UNITTESTBASE_H_
#define REVERSI_TEST_UNITTESTBASE_H_

#include <string>
#include "../util/IOutputConsole.h"

namespace reversi {

// 単体テスト用のベースクラス
class UnitTestBase {
public:
	/**
	 * コンストラクタ
	 * @param outputConsole コンソール出力クラス
	 */
	UnitTestBase(reversi::IOutputConsole* outputConsole);

	/**
	 * デストラクタ
	 */
	virtual ~UnitTestBase();

	/**
	 * 実行
	 */
	virtual void Execute();

protected:

	/**
	 * 条件のチェックの成否をチェックして失敗したときはメッセージを表示する
	 * @param expected 条件チェックした値(0なら失敗とする)
	 * @param message  失敗した際のメッセージ
	 */
	void Equal(int expected, std::string message);

protected:

	reversi::IOutputConsole* outputConsole;

};

}

#endif  // REVERSI_TEST_UNITTESTBASE_H_
