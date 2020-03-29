#ifndef REVERSI_UTIL_OUTPUTVISUALSTUDIOCONSOLE_H_
#define REVERSI_UTIL_OUTPUTVISUALSTUDIOCONSOLE_H_

#include <string>
#include "./IOutputConsole.h"

namespace reversi {

// コンソール出力クラス
class OutputVisualStudioConsole : public reversi::IOutputConsole {
public:
	/**
	 * コンストラクタ
	 */
	OutputVisualStudioConsole();

	/**
	 * デストラクタ
	 */
	virtual ~OutputVisualStudioConsole();

	/**
	 * 文字列を出力する
	 */
	void Print(std::string string);

	/**
	 * 改行付き文字列を出力する
	 */
	void PrintLine(std::string string);
};

}

#endif  // REVERSI_UTIL_OUTPUTVISUALSTUDIOCONSOLE_H_
