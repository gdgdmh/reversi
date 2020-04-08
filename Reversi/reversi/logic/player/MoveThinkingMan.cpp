#include <iostream>
#include <algorithm>
#include "MoveThinkingMan.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"
#include "../../util/IInputKeyboard.h"
#include "../../util/ConsoleInputKeyboard.h"

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
	reversi::ReversiConstant::EMPTY_POSITION emptyPosition;
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
}

/**
 * 入力から位置を取得する
 * @param  position 入力された位置
 * @return          trueなら入力された
 */
bool reversi::MoveThinkingMan::GetPositionByInput(reversi::ReversiConstant::POSITION& position) {

	reversi::IInputKeyboard* inputKeyboard = new ConsoleInputKeyboard();
	std::string positionName = "";
	// キーボードから位置の文字列を取得する
	positionName = inputKeyboard->GetStringLine();
	if (inputKeyboard) {
		delete inputKeyboard;
		inputKeyboard = NULL;
	}
	// 小文字で入力したときのために大文字に変換する
	TransformStringUpper(positionName);
	// 文字列から座標へ変換
	if (reversi::ReversiConstant::GetStringToPosition(positionName, position)) {
		return true;
	}
	return false;
}

/**
 * 手番から対応した石情報を取得する
 * @param  turn 手番
 * @return      対応した石
 */
reversi::ReversiConstant::BOARD_INFO reversi::MoveThinkingMan::GetTurnToStone(reversi::ReversiConstant::TURN turn) {
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	} else {
		return reversi::ReversiConstant::BOARD_INFO::WHITE;
	}
}

/**
 * 大文字に変換する
 * @param targetString 変換対象の文字列
 */
void reversi::MoveThinkingMan::TransformStringUpper(std::string& targetString) {
	std::transform(targetString.begin(), targetString.end(), targetString.begin(), std::toupper);
}

