#include "Board.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"
#include "../render/RenderBoardConsole.h"

/**
 * コンストラクタ
 */
reversi::Board::Board() {
	Clear();
	board.boardSizeX = reversi::ReversiConstant::BOARD_SIZE_X;
	board.boardSizeY = reversi::ReversiConstant::BOARD_SIZE_Y;
	renderBoard = NULL;
}

/**
 * デストラクタ
 */
reversi::Board::~Board() {
	if (renderBoard) {
		delete renderBoard;
		renderBoard = NULL;
	}
}

/**
 * ゲーム開始前の初期化
 */
void reversi::Board::InitializeGame() {
	Clear();
	SetEmpty();
	Preset();
}

/**
 * 着手処理
 * @param  moveInfo    着手情報
 * @param  reverseInfo 裏返し情報
 * @return             trueなら正常 falseなら何かしらの理由で失敗
 */
bool reversi::Board::Move(reversi::MoveInfo moveInfo) {
	reversi::MoveInfo::MOVE_INFO info = moveInfo.GetMoveInfo();
	reversi::ReverseInfo reverseInfo = moveInfo.GetReverseInfo();
	reversi::Assert::AssertEquals(info.position == reverseInfo.GetPosition(), "Board::Move position not same");

	// 着手位置のマスをチェック
	if (!CheckEmpty(info.position)) {
		// 空マスではない
		return false;
	}

	// 着手位置に石を置く
	reversi::ReversiConstant::BOARD_INFO boardInfo = GetTurnToStone(info.turn);
	SetBoardInfo(boardInfo, info.position);

	// 裏返し情報キャッシュから裏返す位置を取得
	for (int i = 0; i < reversi::ReverseInfo::MAX_DIRECTION; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReverseInfo::MAX_DIRECTION, "Board::Move index over i");
		int reverseCount = reverseInfo.GetReversePositionCount((reversi::ReverseInfo::DIRECTION)i);
		for (int j = 0; j < reverseCount; ++j) {
			reversi::Assert::AssertArrayRange(j, reverseCount, "Board::Move index over j");
			// 裏返す
			reversi::ReversiConstant::POSITION position = reverseInfo.GetReversePosition((reversi::ReverseInfo::DIRECTION)i, j);
			ReverseStone(position);
		}
	}

	return true;

}
/*
bool reversi::Board::Move(ReversiConstant::MOVE_INFO moveInfo, const reversi::ReverseInfo reverseInfo) {

	reversi::Assert::AssertEquals(moveInfo.position == reverseInfo.GetPosition(), "Board::Move position not same");

	// 着手位置のマスをチェック
	if (!CheckEmpty(moveInfo.position)) {
		// 空マスではない
		return false;
	}
	
	// 着手位置に石を置く
	reversi::ReversiConstant::BOARD_INFO info = GetTurnToStone(moveInfo.turn);
	SetBoardInfo(info, moveInfo.position);

	// 裏返し情報キャッシュから裏返す位置を取得
	for (int i = 0; i < reversi::ReverseInfo::MAX_DIRECTION; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReverseInfo::MAX_DIRECTION, "Board::Move index over i");
		int reverseCount = reverseInfo.GetReversePositionCount((reversi::ReverseInfo::DIRECTION)i); //reverseInfo.reversePositionCount[i];
		for (int j = 0; j < reverseCount; ++j) {
			reversi::Assert::AssertArrayRange(j, reverseCount, "Board::Move index over j");
			// 裏返す
			reversi::ReversiConstant::POSITION position = reverseInfo.GetReversePosition((reversi::ReverseInfo::DIRECTION)i, j);
			ReverseStone(position);
		}
	}

	return true;
}
*/

/**
 * 盤の情報を取得する
 * @param  position 盤の位置
 * @return          盤情報
 */
reversi::ReversiConstant::BOARD_INFO reversi::Board::GetBoardInfo(int position) {
	reversi::Assert::AssertArrayRange((int)position, reversi::ReversiConstant::BOARD_SIZE, "Board::GetBoardInfo index over");
	return (reversi::ReversiConstant::BOARD_INFO)board.boardData[(int)position];
}

/**
 * 盤の表示(コンソール)
 * @param console コンソール出力先
 */
void reversi::Board::Render() {
	if (renderBoard == NULL) {
		renderBoard = new RenderBoardConsole();
	}
	renderBoard->Render(*this);
}

/**
 * 盤の生データを取得する
 * @return 盤の生データ
 */
const reversi::BOARD& reversi::Board::GetRawData() const {
	return board;
}

/**
 * DeepCopy
 * @return 複製データ
 */
reversi::Board reversi::Board::Clone() const {
	Board dest;

	for (int i = 0; i < ReversiConstant::BOARD_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::BOARD_SIZE, "Board::Clone() index over");
		dest.SetBoardInfo((reversi::ReversiConstant::BOARD_INFO)board.boardData[i], (reversi::ReversiConstant::POSITION)i);
	}
	dest.board.boardSizeX = board.boardSizeX;
	dest.board.boardSizeY = board.boardSizeY;
	if (dest.renderBoard) {
		delete dest.renderBoard;
		dest.renderBoard = NULL;
	}
	dest.renderBoard = NULL;
	return dest;
}


/**
 * 盤のクリア(全て石なしとする)
 */
void reversi::Board::Clear() {
	for (int i = 0; i < reversi::ReversiConstant::BOARD_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::BOARD_SIZE, "Board::Clear() index over");
		SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::INVALID, (reversi::ReversiConstant::POSITION)i);
	}
}

/**
 * 空の盤を設定する
 */
void reversi::Board::SetEmpty() {
	for (int i = 0; i < reversi::ReversiConstant::POSITION_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, reversi::ReversiConstant::POSITION_SIZE, "Board::SetEmpty() index over positions");
		reversi::Assert::AssertArrayRange((int)reversi::ReversiConstant::POSITIONS[i], reversi::ReversiConstant::BOARD_SIZE, "Board::SetEmpty() index over board");
		SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::NONE, reversi::ReversiConstant::POSITIONS[i]);
	}
}

/**
 * ゲーム開始のための初期配置設定
 */
void reversi::Board::Preset() {
	SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::WHITE, reversi::ReversiConstant::POSITION::D4);
	SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::WHITE, reversi::ReversiConstant::POSITION::E5);
	SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::BLACK, reversi::ReversiConstant::POSITION::E4);
	SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::BLACK, reversi::ReversiConstant::POSITION::D5);
}

/**
 * 空マスかどうかチェック
 * @param  position 位置
 * @return          trueなら空マス
 */
bool reversi::Board::CheckEmpty(reversi::ReversiConstant::POSITION position) {
	reversi::Assert::AssertArrayRange((int)position, reversi::ReversiConstant::BOARD_SIZE, "Board::CheckEmpty index over");
	if ((reversi::ReversiConstant::BOARD_INFO)board.boardData[(int)position] == reversi::ReversiConstant::BOARD_INFO::NONE) {
		return true;
	}
	return false;
}

/**
 * 手番から石を取得する(黒の手番なら黒の石)
 * @param  turn 手番
 * @return      手番に対応した石
 */
reversi::ReversiConstant::BOARD_INFO reversi::Board::GetTurnToStone(reversi::ReversiConstant::TURN turn) {
	switch (turn) {
	case reversi::ReversiConstant::TURN::TURN_BLACK:
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	case reversi::ReversiConstant::TURN::TURN_WHITE:
		return reversi::ReversiConstant::BOARD_INFO::WHITE;
	default:
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	}
}

/**
 * 盤の情報をセットする
 * @param info     セットする盤情報
 * @param position セットする位置
 */
void reversi::Board::SetBoardInfo(reversi::ReversiConstant::BOARD_INFO info, reversi::ReversiConstant::POSITION position) {
	reversi::Assert::AssertArrayRange((int)position, reversi::ReversiConstant::BOARD_SIZE, "Board::SetBoardInfo index over");
	board.boardData[(int)position] = (int)info;
}

/**
 * 石をひっくり返す(黒 -> 白, 白 -> 黒)
 * 石がなかったら何もしない
 * @param position 位置
 */
void reversi::Board::ReverseStone(reversi::ReversiConstant::POSITION position) {
	reversi::Assert::AssertArrayRange((int)position, reversi::ReversiConstant::BOARD_SIZE, "Board::SetBoardInfo index over");
	reversi::ReversiConstant::BOARD_INFO info = (reversi::ReversiConstant::BOARD_INFO)board.boardData[(int)position];

	// ひっくり返す
	switch (info) {
	case reversi::ReversiConstant::BOARD_INFO::BLACK:
		SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::WHITE, position);
		break;
	case reversi::ReversiConstant::BOARD_INFO::WHITE:
		SetBoardInfo(reversi::ReversiConstant::BOARD_INFO::BLACK, position);
		break;
		// 石でない場所を指定したら何もしない
	default:
		reversi::Assert::AssertEquals(0, "Board::ReverseStone not info black or white");
		break;
	}
}
