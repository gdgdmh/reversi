#include <iostream>
#include "MoveThinkingMan.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::MoveThinkingMan::MoveThinkingMan() {
}

/**
 * デストラクタ
 */
reversi::MoveThinkingMan::~MoveThinkingMan() {
}

/**
 * 思考初期化
 * 手番が来たときに一度だけ呼ばれる
 * @param  board    盤情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
void reversi::MoveThinkingMan::InitializeMoveThinking(const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	// 空の位置を探す
	reversi::EMPTY_POSITION emptyPosition;
	reversiMove.FindEmptyPosition(board, emptyPosition);
	// 打てる位置を探す
	reversiMove.FindPutEnablePosition(board, emptyPosition, turn);
}

/**
 * 思考
 * @param  board    盤情報
 * @param  move     着手情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
bool reversi::MoveThinkingMan::MoveThinking(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {

	// 入力
	reversi::ReversiConstant::POSITION position = reversi::ReversiConstant::POSITION::A1;
	if (GetPositionByInput(position)) {
		// 入力した
		if (reversiMove.CheckEnableMoveByCache(position)) {
			// 打てるので確定
			reversi::MoveInfo::MOVE_INFO moveInfoData;
			moveInfoData.position = position;
			moveInfoData.info = GetTurnToStone(turn);
			moveInfoData.turn = turn;
			reversi::ReverseInfo reverseInfo = reversiMove.GetReverseInfo(position);
			reversi::MoveInfo moveInfo(moveInfoData, reverseInfo);
			// 着手情報を入力
			move.Copy(moveInfo);
			return true;
		}
	}
	return false;
	

	//if (move.CheckEnableMoveByCache(position)) {
	//}
/*
		reversi::Board board;
		board.InitializeGame();

		// 初期化した盤に対して空の位置を取得する(初期位置の石には置けない)
		reversi::Move move;
		reversi::EMPTY_POSITION emptyPosition;
		move.FindEmptyPosition(board, emptyPosition);

		{
			// 黒の打てる位置を探す
			move.FindPutEnablePosition(board, emptyPosition, reversi::ReversiConstant::TURN::TURN_BLACK);

			// 空いている盤座標
			size_t size = emptyPosition.position.size();
			for (int i = 0; i < size; ++i) {
				reversi::ReversiConstant::POSITION position = emptyPosition.position[i];
				switch (position) {
					// 黒はこの座標に打つことができる
				case reversi::ReversiConstant::POSITION::D3:
				case reversi::ReversiConstant::POSITION::C4:
				case reversi::ReversiConstant::POSITION::F5:
				case reversi::ReversiConstant::POSITION::E6:
					AssertEqual(move.CheckEnableMoveByCache(position), "TestMove::Execute invalid CheckEnableMoveByCache black enable");
					break;
				default:
					// 打てない
					AssertEqual(!move.CheckEnableMoveByCache(position), "TestMove::Execute invalid CheckEnableMoveByCache black disable");
					break;
				}
			}
		}

	*/
}

bool reversi::MoveThinkingMan::GetPositionByInput(reversi::ReversiConstant::POSITION& position) {

	std::string positionName = "";
	std::getline(std::cin, positionName);

	if (reversi::ReversiConstant::GetStringToPosition(positionName, position)) {
		return true;
	}
	return false;
}

reversi::ReversiConstant::BOARD_INFO reversi::MoveThinkingMan::GetTurnToStone(reversi::ReversiConstant::TURN turn) {
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	} else {
		return reversi::ReversiConstant::BOARD_INFO::WHITE;
	}
}