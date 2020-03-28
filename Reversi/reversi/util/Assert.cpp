#include "Assert.h"
#include "OutputConsole.h"

/**
 * 値の比較結果がfalseだったときにmessageを出力してプログラム停止する
 * @param expected 比較結果
 * @param message  出力するメッセージ
 */
void reversi::Assert::AssertEquals(bool expected, std::string message) {
	if (expected == false) {
		OutputConsole* output = new OutputConsole();
		output->PrintLine(message);
		if (output) {
			delete output;
			output = NULL;
		}
	}
}

/**
 * 値の比較結果が0だったときにmessageを出力してプログラム停止する
 * @param expected 比較結果
 * @param message  出力するメッセージ
 */
void reversi::Assert::AssertEquals(int expected, std::string message) {
	if (expected == 0) {
		OutputConsole* output = new OutputConsole();
		output->PrintLine(message);
		if (output) {
			delete output;
			output = NULL;
		}
	}
}
