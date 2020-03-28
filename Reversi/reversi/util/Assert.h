#ifndef REVERSI_SCENE_TESTSCENE_H_
#define REVERSI_SCENE_TESTSCENE_H_

#include <string>

namespace reversi {

// 実装テスト用クラス
class Assert {
public:

	/**
	 * 値の比較結果がfalseだったときにmessageを出力してプログラム停止する
	 * @param expected 比較結果
	 * @param message  出力するメッセージ
	 */
	static void AssertEquals(bool expected, std::string message);

	/**
	 * 値の比較結果が0だったときにmessageを出力してプログラム停止する
	 * @param expected 比較結果
	 * @param message  出力するメッセージ
	 */
	static void AssertEquals(int expected, std::string message);

};

}

#endif  // REVERSI_SCENE_TESTSCENE_H_
