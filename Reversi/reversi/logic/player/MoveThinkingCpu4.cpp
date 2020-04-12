#include <iostream>
#include "MoveThinkingCpu4.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"

// 定数定義
// 静的評価位置
const int reversi::MoveThinkingCpu4::STATIC_EVALUATION_POINTS[reversi::ReversiConstant::POSITION_SIZE] = {
	60,  -30,  20,   5,   5,  20, -30,  60,
	-30,  -40,  -5,  -5,  -5,  -5, -40, -30,
	20,   -5,  20,   3,   3,  20,  -5,  20,
	5,   -5,   3,   3,   3,   3,  -5,   5,
	5,   -5,   3,   3,   3,   3,  -5,   5,
	20,   -5,  20,   3,   3,  20,  -5,  20,
	-30,  -40,  -5,  -5,  -5,  -5, -40, -30,
	60,  -30,  20,   5,  20,  20, -30,  60,
};

/**
 * コンストラクタ
 */
reversi::MoveThinkingCpu4::MoveThinkingCpu4() {
}

/**
 * デストラクタ
 */
reversi::MoveThinkingCpu4::~MoveThinkingCpu4() {
}

/**
 * 思考初期化
 * 手番が来たときに一度だけ呼ばれる
 * @param  board    盤情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
void reversi::MoveThinkingCpu4::InitializeMoveThinking(const reversi::Reversi& reversi, const reversi::Move& moveCache, const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	// 計算済みのキャッシュをコピー
	//reversiMove = moveCache;
}

/**
 * 思考
 * @param  board    盤情報
 * @param  move     着手情報
 * @param  turn     手番
 * @return          trueなら思考が完了
 */
bool reversi::MoveThinkingCpu4::MoveThinking(const reversi::Reversi& reversi, const reversi::Move& moveCache, const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn) {

	// rootを作成
	reversi::ThinkingNode root;
	// root設定
	{
		reversi::ReversiConstant::POSITION dummyPosition = reversi::ReversiConstant::POSITION::A1;
		root.CopyReversi(reversi);
		root.SetMovePosition(dummyPosition); // rootにはMovePosition設定は不要
		root.SetTurn(reversi.GetTurn());
		root.SetEvaluationPoint(0); // 設定不要
		root.SetThinkingDepth(0); // rootなので0
	}

	SetThinkingChildNode(&root, reversi, board, turn);

	//void reversi::MoveThinkingCpu4::SetThinkingChildNode(reversi::ThinkingNode* node, const reversi::Reversi& reversi, const reversi::Board& board, reversi::ReversiConstant::TURN turn) {

	/*
	int size = reversiMove.GetReverseInfoSize();
	bool isUpdate = false;
	for (int i = 0; i < size; ++i) {
		const reversi::ReverseInfo& reverseInfo = reversiMove.GetReverseInfoByIndex(i);
		int total = reverseInfo.GetReversePositionCountTotal();
		// 取れる数が少ない + 打てる
		if ((total < minCount) && (reversiMove.CheckEnableMoveByCache(reverseInfo.GetPosition()))) {
			minPosition = reverseInfo.GetPosition();
			minCount = total;
			minIndex = i;
			isUpdate = true;
		}
	}

	*/


	/*
	// root set
	reversi::ThinkingNode root;
	{
		reversi::ThinkingNode* parent = NULL;
		reversi::ReversiConstant::POSITION position = reversi::ReversiConstant::POSITION::A2;
		reversi::ReversiConstant::TURN turn = reversi::ReversiConstant::TURN::TURN_WHITE;
		int evalPoint = 10;
		int thinkDepth = 0;
		bool visited = true;

		root.CopyReversi(reversi);
		//root.SetParent(parent);
		root.SetMovePosition(position);
		root.SetTurn(turn);
		root.SetEvaluationPoint(evalPoint);
		root.SetThinkingDepth(thinkDepth);
		root.SetVisited(visited);

	*/

	// ある一定の階層まで

	/*
	reversi::ReversiConstant::POSITION maxPosition = reversi::ReversiConstant::POSITION::A1; // 仮
	int currentPoint = DEFAULT_POINTS; // 現在の最高評価値
	int reverseInfoIndex = 0;
	bool isUpdate = false; // 更新したか(バグチェック用)

	int size = reversiMove.GetReverseInfoSize();
	for (int i = 0; i < size; ++i) {
		const reversi::ReverseInfo& reverseInfo = reversiMove.GetReverseInfoByIndex(i);
		reversi::Assert::AssertArrayRange(i, size, "MoveThinkingCpu4::MoveThinking index over reverseInfo");
		reversi::ReversiConstant::POSITION position = reverseInfo.GetPosition();
		if (!reversiMove.CheckEnableMoveByCache(position)) {
			// うてないならスキップ
			continue;
		}

		int positionIndex = reversi::ReversiConstant::GetPositionToIndex(position);
		reversi::Assert::AssertArrayRange(positionIndex, reversi::ReversiConstant::POSITION_SIZE, "MoveThinkingCpu4::MoveThinking index over position index");
		if (currentPoint < STATIC_EVALUATION_POINTS[positionIndex]) {
			// 現在の評価値より高いなら更新
			maxPosition = position;
			reverseInfoIndex = i;
			currentPoint = STATIC_EVALUATION_POINTS[positionIndex];
			isUpdate = true;
		}
	}
	// 最低でも1度は更新されるはず
	reversi::Assert::AssertEquals(isUpdate, "MoveThinkingCpu4::MoveThinking not update");

	// 着手情報を作成
	const reversi::ReverseInfo& reverseInfo = reversiMove.GetReverseInfoByIndex(reverseInfoIndex);
	reversi::MoveInfo::MOVE_INFO moveInfoData;
	moveInfoData.position = reverseInfo.GetPosition();
	moveInfoData.info = GetTurnToStone(turn);
	moveInfoData.turn = turn;
	reversi::MoveInfo moveInfo(moveInfoData, reverseInfo);
	// 着手情報を入力
	move.Copy(moveInfo);
	return true;
	*/
	return false;
}

reversi::ReversiConstant::BOARD_INFO reversi::MoveThinkingCpu4::GetTurnToStone(reversi::ReversiConstant::TURN turn) {
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	} else {
		return reversi::ReversiConstant::BOARD_INFO::WHITE;
	}
}

void reversi::MoveThinkingCpu4::SetThinkingChildNode(reversi::ThinkingNode* node, const reversi::Reversi& reversi, const reversi::Board& board, reversi::ReversiConstant::TURN turn) {


	reversi::ReversiConstant::POSITION moveEnablePositions[MOVE_ENABLE_DATA_SIZE];
	int moveEnableCount = 0;
	// A1で初期化
	for (int i = 0; i < MOVE_ENABLE_DATA_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, MOVE_ENABLE_DATA_SIZE, "MoveThinkingCpu4::SetThinkingChildNode index over");
		moveEnablePositions[i] = reversi::ReversiConstant::POSITION::A1;
	}

	// 打てる位置を取得
	GetMoveEnablePosition(moveEnablePositions, moveEnableCount, MOVE_ENABLE_DATA_SIZE, board, turn);

}

// 着手可能位置を取得する
void reversi::MoveThinkingCpu4::GetMoveEnablePosition(reversi::ReversiConstant::POSITION* moveEnablePositions, int& moveEnablePositionCount, int moveEnablePositionSize, const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	moveEnablePositionCount = 0;
	// 着手キャッシュを作成
	reversi::Move moveCache;
	{
		// 空の位置を探す
		reversi::ReversiConstant::EMPTY_POSITION emptyPosition;
		moveCache.FindEmptyPosition(board, emptyPosition);
		// 打てる位置を探す
		moveCache.FindPutEnablePosition(board, emptyPosition, turn);
	}

	int size = moveCache.GetReverseInfoSize();
	for (int i = 0; i < size; ++i) {
		reversi::Assert::AssertArrayRange(i, size, "MoveThinkingCpu4::GetMoveEnablePosition reverseInfo index over");
		const reversi::ReverseInfo& reverseInfo = moveCache.GetReverseInfoByIndex(i);
		// 打てる
		if (moveCache.CheckEnableMoveByCache(reverseInfo.GetPosition())) {
			reversi::Assert::AssertArrayRange(moveEnablePositionCount, moveEnablePositionSize, "MoveThinkingCpu4::GetMoveEnablePosition moveEnablePositionSize index over");
			// 打てる位置を保存
			moveEnablePositions[moveEnablePositionCount] = reverseInfo.GetPosition();
			++moveEnablePositionCount;
		}
	}
}