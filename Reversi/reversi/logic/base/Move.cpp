#include "Move.h"
#include "Board.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::Move::Move() {
}

/**
 * デストラクタ
 */
reversi::Move::~Move() {
}

/**
 * 石の置かれていない場所を探す
 * @param board          盤データ
 * @param emptyPositions 結果をいれるための参照渡しオブジェクト
 */
void reversi::Move::FindEmptyPosition(const reversi::Board& board, EMPTY_POSITION& emptyPosition) {

	// データをクリアしておく
	emptyPosition.position.clear();

	int size = reversi::ReversiConstant::POSITION_SIZE;
	const reversi::BOARD boardData = board.GetRawData();
	for (int i = 0; i < size; ++i) {
		reversi::Assert::AssertArrayRange(i, size, "Move::FindEmptyPosition() position index over");
		// 位置を取得
		reversi::ReversiConstant::POSITION position = (reversi::ReversiConstant::POSITION)reversi::ReversiConstant::POSITIONS[i];

		reversi::Assert::AssertArrayRange((int)position, reversi::ReversiConstant::BOARD_SIZE, "Move::FindEmptyPosition() board index over");

		reversi::ReversiConstant::BOARD_INFO info = (reversi::ReversiConstant::BOARD_INFO)boardData.boardData[(int)position];
		if (info == reversi::ReversiConstant::BOARD_INFO::NONE) {
			emptyPosition.position.push_back(position);
		}
	}
}

/**
 * 打てる場所を探す
 * @param board          盤データ
 * @param emptyPositions 石の置かれてない場所が入ったデータ
 * @param turn           手番(黒,白)
 */
void reversi::Move::FindPutEnablePosition(const reversi::Board& board, const EMPTY_POSITION& emptyPosition, reversi::ReversiConstant::TURN turn) {
	
}

/**
 * その場所に打つことができるか
 * @param  board    盤データ
 * @param  position 打とうとする盤の位置
 * @param  turn     手番(黒,白)
 * @return          trueならその位置に打つことができる
 */
bool reversi::Move::CheckEnableMove(const reversi::Board& board, int position, reversi::ReversiConstant::TURN turn) {

	// それぞれの方向に対して打てるかチェック
	// 将来的にはpositionの位置に対してチェックする方向を減らすなど(一番左のマスは左側に対するチェックをしないなど)
	// 負荷軽減案はあるがいったん確実性を取る
	if (CheckEnableMoveDirection(board, position, reversi::Move::DIRECTION::UP, turn)) {
		return true;
	}
	if (CheckEnableMoveDirection(board, position, reversi::Move::DIRECTION::DOWN, turn)) {
		return true;
	}
	if (CheckEnableMoveDirection(board, position, reversi::Move::DIRECTION::LEFT, turn)) {
		return true;
	}
	if (CheckEnableMoveDirection(board, position, reversi::Move::DIRECTION::RIGHT, turn)) {
		return true;
	}
	if (CheckEnableMoveDirection(board, position, reversi::Move::DIRECTION::UP_LEFT, turn)) {
		return true;
	}
	if (CheckEnableMoveDirection(board, position, reversi::Move::DIRECTION::UP_RIGHT, turn)) {
		return true;
	}
	if (CheckEnableMoveDirection(board, position, reversi::Move::DIRECTION::DOWN_LEFT, turn)) {
		return true;
	}
	if (CheckEnableMoveDirection(board, position, reversi::Move::DIRECTION::DOWN_RIGHT, turn)) {
		return true;
	}
	// どの方向にも打てない
	return false;
}

/**
 * その位置の指定方向に打つことができるか
 * @param  board    盤データ
 * @param  position 打とうとする盤の位置
 * @param  direction 打とうとする方向
 * @param  turn     手番(黒,白)
 * @return          trueならその方向に打つことができる
 */
bool reversi::Move::CheckEnableMoveDirection(const reversi::Board& board, int position, reversi::Move::DIRECTION direction, reversi::ReversiConstant::TURN turn) {

	const reversi::BOARD boardData = board.GetRawData();

	// 盤のオフセットを取得
	int offset = ToDirectionOffset(direction);

	int currentPosition = position;
	reversi::Assert::AssertArrayRange(currentPosition, reversi::ReversiConstant::BOARD_SIZE, "Move::CheckEnableMoveDirection() board index over");
	reversi::ReversiConstant::BOARD_INFO info = (reversi::ReversiConstant::BOARD_INFO)boardData.boardData[currentPosition];
	if (info != reversi::ReversiConstant::BOARD_INFO::NONE) {
		// 初期指定位置は空でなければそもそも打てない
		return false;
	}
	// 次の方向の位置
	currentPosition += offset;

	bool loop = true;
	bool isSandwichStarted = false; // 挟まれているか
	int sandwichCount = 0; // 挟まれている数
	while (loop) {
		// 盤情報取得
		reversi::Assert::AssertArrayRange(currentPosition, reversi::ReversiConstant::BOARD_SIZE, "Move::CheckEnableMoveDirection() board index over(loop)");
		reversi::ReversiConstant::BOARD_INFO info = (reversi::ReversiConstant::BOARD_INFO)boardData.boardData[currentPosition];
		// 挟まれている状態の取得
		reversi::Move::SANDWICH_STATUS status = GetSandwichInfo(isSandwichStarted, sandwichCount, turn, info);
		switch (status) {
		case SANDWICH_STATUS::SANDWICH_OK:
			return true;
		case SANDWICH_STATUS::SANDWICH_CONTINUE:
			break;
		case SANDWICH_STATUS::SANDWICH_NG_INVALID:
			return false;
		case SANDWICH_STATUS::SANDWICH_NG_EMPTY:
			return false;
		case SANDWICH_STATUS::SANDWICH_NG_SELF:
			return false;
		default:
			return false;
		}
		// 次の方向の位置
		currentPosition += offset;
	}
    return false;
}

/**
 * 位置から盤のオフセットを取得する
 * @param  direction 方向
 * @return           盤のオフセット
 */
int reversi::Move::ToDirectionOffset(reversi::Move::DIRECTION direction) {
	int position = 0; // オフセットだけ欲しいので0とする
	switch (direction) {
	case DIRECTION::UP:
		return reversi::ReversiConstant::GetPositionUp(position);
	case DIRECTION::DOWN:
		return reversi::ReversiConstant::GetPositionDown(position);
	case DIRECTION::LEFT:
		return reversi::ReversiConstant::GetPositionLeft(position);
	case DIRECTION::RIGHT:
		return reversi::ReversiConstant::GetPositionRight(position);
	case DIRECTION::UP_LEFT:
		return reversi::ReversiConstant::GetPositionUpLeft(position);
	case DIRECTION::UP_RIGHT:
		return reversi::ReversiConstant::GetPositionUpRight(position);
	case DIRECTION::DOWN_LEFT:
		return reversi::ReversiConstant::GetPositionDownLeft(position);
	case DIRECTION::DOWN_RIGHT:
		return reversi::ReversiConstant::GetPositionDownRight(position);
	default:
		reversi::Assert::AssertEquals(0, "Move::ToDirectionOffset() invalid direction");
		return 0;
	}
}

/**
 * 挟まれている情報の取得
 * @param  isSandwichStarted 挟まれているか
 * @param  sandwichCount     いくつ挟まれているか
 * @param  turn              手番(黒,白)
 * @param  info              盤の情報
 * @return                   状態
 */
reversi::Move::SANDWICH_STATUS reversi::Move::GetSandwichInfo(bool& isSandwichStarted, int& sandwichCount, reversi::ReversiConstant::TURN turn, reversi::ReversiConstant::BOARD_INFO info) {

	if (info == reversi::ReversiConstant::BOARD_INFO::INVALID) {
		// 無効マスがあったので挟まれていない
		return reversi::Move::SANDWICH_STATUS::SANDWICH_NG_INVALID;
	}
	if (info == reversi::ReversiConstant::BOARD_INFO::NONE) {
		// 空マスがあったので挟まれていない
		return reversi::Move::SANDWICH_STATUS::SANDWICH_NG_EMPTY;
	}


	if (info == reversi::ReversiConstant::BOARD_INFO::BLACK) {
		if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
			if (isSandwichStarted) {
				// 挟んでいる状態で自分の石があったので挟んでいる
				return reversi::Move::SANDWICH_STATUS::SANDWICH_OK;
			} else {
				// 挟んでいない状態で自分の石があったら挟まれてない
				return reversi::Move::SANDWICH_STATUS::SANDWICH_NG_SELF;
			}
		} else if (turn == reversi::ReversiConstant::TURN::TURN_WHITE) {
			// 相手の石なので挟まれている + 石をカウント
			isSandwichStarted = true;
			++sandwichCount;
			return reversi::Move::SANDWICH_STATUS::SANDWICH_CONTINUE;
		}
	}
	if (info == reversi::ReversiConstant::BOARD_INFO::WHITE) {
		if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
			// 相手の石なので挟まれている + 石をカウント
			isSandwichStarted = true;
			++sandwichCount;
			return reversi::Move::SANDWICH_STATUS::SANDWICH_CONTINUE;
		} else if (turn == reversi::ReversiConstant::TURN::TURN_WHITE) {
			if (isSandwichStarted) {
				// 挟んでいる状態で自分の石があったので挟んでいる
				return reversi::Move::SANDWICH_STATUS::SANDWICH_OK;
			} else {
				// 挟んでいない状態で自分の石があったら挟まれてない
				return reversi::Move::SANDWICH_STATUS::SANDWICH_NG_SELF;
			}
		}
	}
	// ここには来ないはず
	reversi::Assert::AssertEquals(0, "Move::GetSandwichInfo() invalid status");
	return reversi::Move::SANDWICH_STATUS::SANDWICH_NG_UNKNOWN;
}
