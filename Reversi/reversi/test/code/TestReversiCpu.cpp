#include "TestReversiCpu.h"
// test
#include "../../logic/base/Reversi.h"
//#include "../../logic/base/Board.h"
//#include "../../logic/base/Move.h"
#include "../../util/Assert.h"
#include "../../util/StdStringFormatter.h"

/**
 * コンストラクタ
 */
reversi::TestReversiCpu::TestReversiCpu(reversi::IOutputConsole* outputConsole) : UnitTestBase(outputConsole) {
}

/**
 * デストラクタ
 */
reversi::TestReversiCpu::~TestReversiCpu() {
}

/**
 * 実行
 * @return trueなら成功 falseなら失敗
 */
bool reversi::TestReversiCpu::Execute() {

	reversi::Reversi reversi;
	reversi::Reversi::PLAYER_SETTING setting;
	setting.playerType[reversi::Reversi::PLAYER_BLACK] = reversi::Reversi::PLAYER::CPU3;
	setting.playerType[reversi::Reversi::PLAYER_WHITE] = reversi::Reversi::PLAYER::CPU2;

	reversi.Initialize();
	reversi.InitializeGame(setting);

	const int TEST_COUNT = 5;
	int testCount = 0;
	int blackWinCount = 0;
	int whiteWinCount = 0;
	int drawCount = 0;

	while (testCount < TEST_COUNT) {
		reversi.Task();
		if (reversi.GetScene() == reversi::Reversi::SCENE::END) {
			reversi::Reversi::RESULT result =  reversi.GetResult();
			switch (result) {
			case reversi::Reversi::RESULT::BLACK:
				++blackWinCount;
				break;
			case reversi::Reversi::RESULT::WHITE:
				++whiteWinCount;
				break;
			case reversi::Reversi::RESULT::DRAW:
				++drawCount;
				break;
			default:
				break;
			}
			reversi.InitializeGame(setting);
			++testCount;
		}
	}
	std::string resultMessage = reversi::StdStringFormatter::Format("black %d whilte %d draw %d", blackWinCount, whiteWinCount, drawCount);
	outputConsole->PrintLine(resultMessage);

	return true;
}

