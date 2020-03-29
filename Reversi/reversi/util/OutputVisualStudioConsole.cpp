#include "OutputVisualStudioConsole.h"
#include <windows.h>
#include <iostream>

namespace {
    static const char* NEW_LINE = "\n";
}

/**
 * コンストラクタ
 */
reversi::OutputVisualStudioConsole::OutputVisualStudioConsole() {
}

/**
 * デストラクタ
 */
reversi::OutputVisualStudioConsole::~OutputVisualStudioConsole() {
}

/**
 * 文字列を出力する
 */
void reversi::OutputVisualStudioConsole::Print(std::string string) {
    // VC++環境のみ
#ifdef _MSC_VER
	OutputDebugStringA(string.c_str());
#endif // _MSC_VER
}

/**
 * 改行付き文字列を出力する
 */
void reversi::OutputVisualStudioConsole::PrintLine(std::string string) {
    std::string output = (string + NEW_LINE);
    // VC++環境のみ
#ifdef _MSC_VER
    OutputDebugStringA(output.c_str());
#endif // _MSC_VER
}
