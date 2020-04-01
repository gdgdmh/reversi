#include "TestReverseInfo.h"
// test
#include "../../logic/base/ReverseInfo.h"

/**
 * コンストラクタ
 */
reversi::TestReverseInfo::TestReverseInfo(reversi::IOutputConsole* outputConsole) : UnitTestBase(outputConsole) {
}

/**
 * デストラクタ
 */
reversi::TestReverseInfo::~TestReverseInfo() {
}

/**
 * 実行
 * @return trueなら成功 falseなら失敗
 */
bool reversi::TestReverseInfo::Execute() {

	{
		reversi::ReverseInfo info(reversi::ReversiConstant::POSITION::B4, reversi::ReversiConstant::TURN::TURN_BLACK);
		AssertEqual(reversi::ReversiConstant::POSITION::B4 == info.GetPosition(), "TestReverseInfo::Execute invalid position");
		AssertEqual(reversi::ReversiConstant::TURN::TURN_BLACK == info.GetTurn(), "TestReverseInfo::Execute invalid turn");

		info.AddReversePosition(reversi::ReverseInfo::DIRECTION::UP, reversi::ReversiConstant::POSITION::B3);
		info.AddReversePosition(reversi::ReverseInfo::DIRECTION::UP, reversi::ReversiConstant::POSITION::B2);
		info.AddReversePosition(reversi::ReverseInfo::DIRECTION::DOWN, reversi::ReversiConstant::POSITION::D3);
		info.AddReversePosition(reversi::ReverseInfo::DIRECTION::DOWN_LEFT, reversi::ReversiConstant::POSITION::A3);

		AssertEqual(info.GetReversePositionCount(reversi::ReverseInfo::DIRECTION::UP) == 2, "TestReverseInfo::Execute invalid up count");
		AssertEqual(info.GetReversePositionCount(reversi::ReverseInfo::DIRECTION::DOWN) == 1, "TestReverseInfo::Execute invalid down count");
		AssertEqual(info.GetReversePositionCount(reversi::ReverseInfo::DIRECTION::DOWN_LEFT) == 1, "TestReverseInfo::Execute invalid down left count");

		AssertEqual(info.GetReversePosition(reversi::ReverseInfo::DIRECTION::UP, 0) == reversi::ReversiConstant::POSITION::B3, "TestReverseInfo::Execute invalid get reverse positon 1");
		AssertEqual(info.GetReversePosition(reversi::ReverseInfo::DIRECTION::UP, 1) == reversi::ReversiConstant::POSITION::B2, "TestReverseInfo::Execute invalid get reverse positon 2");
		AssertEqual(info.GetReversePosition(reversi::ReverseInfo::DIRECTION::DOWN, 0) == reversi::ReversiConstant::POSITION::D3, "TestReverseInfo::Execute invalid get reverse positon 3");
		AssertEqual(info.GetReversePosition(reversi::ReverseInfo::DIRECTION::DOWN_LEFT, 0) == reversi::ReversiConstant::POSITION::A3, "TestReverseInfo::Execute invalid get reverse positon 4");

	}
	return true;
}

