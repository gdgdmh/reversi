#include <iostream>
#include "MoveThinkingCpu4.h"
#include "../../util/IOutputConsole.h"
#include "../../util/Assert.h"
#include "ICalcBoardEvaluationPoint.h"
#include "CalcBoardEvaluationPointByPosition.h"

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

	// rootの子ノードを作成
	SetThinkingChildNode(&root, reversi, board, turn);

	reversi::ThinkingNode* node = &root;
	int size = node->GetChildSize();
	for (int i = 0; i < size; ++i) {
		reversi::ThinkingNode* child = node->GetChild(i);
		// 1手読み
		SetThinkingChildNode(child, child->GetReversi(), child->GetReversi().GetBoard(), turn);
		// 2手読み以上は全幅検索の都合上非常に重たくなるので現段階では使わない
		//for (int j = 0; j < child->GetChildSize(); ++j) {
		//	reversi::ThinkingNode* child2 = child->GetChild(j);
		//	// 2手読み
		//	SetThinkingChildNode(child2, child2->GetReversi(), child2->GetReversi().GetBoard(), turn);
			//for (int k = 0; k < child2->GetChildSize(); ++k) {
			//	reversi::ThinkingNode* child3 = child2->GetChild(k);
			//	// 3手読み
			//	SetThinkingChildNode(child3, child3->GetReversi(), child3->GetReversi().GetBoard(), turn);
			//}
		//}
	}

	reversi::ReversiConstant::POSITION topHighPosition = reversi::ReversiConstant::POSITION::A1;
	{
		const reversi::ThinkingNode* topHighNode = NULL;
		int topHighNodeIndex = -1;
		for (int i = 0; i < root.GetChildSize(); ++i) {
			reversi::ThinkingNode* child = node->GetChild(i);
			const reversi::ThinkingNode* highNode = child->FindHighEvaluationPointNode();
			if ((topHighNode == NULL) && (highNode != NULL)) {
				// 初回更新
				topHighNode = highNode;
				topHighNodeIndex = i;
			}
			else if (highNode != NULL) {
				if (topHighNode->GetEvaluationPoint() < highNode->GetEvaluationPoint()) {
					// 更新
					topHighNode = highNode;
					topHighNodeIndex = i;
				}
			}
		}
		reversi::Assert::AssertEquals(topHighNodeIndex != -1, "MoveThinkingCpu4::MoveThinking topHighNodeIndex -1");
		topHighPosition = root.GetChild(topHighNodeIndex)->GetMovePosition();
	}
	// 子ノードを削除(動的に作成しているので使い終わったら開放する必要がある)
	root.ReleaseChild();

	const reversi::ReverseInfo& reverseInfo = moveCache.GetReverseInfo(topHighPosition);
	// 着手情報を確定
	reversi::MoveInfo::MOVE_INFO moveInfoData;
	moveInfoData.position = reverseInfo.GetPosition();
	moveInfoData.info = GetTurnToStone(turn);
	moveInfoData.turn = turn;
	reversi::MoveInfo moveInfo(moveInfoData, reverseInfo);
	// 着手情報を入力
	move.Copy(moveInfo);
	return true;

	/*
	const reversi::ReverseInfo& reverseInfo = reversiMove.GetReverseInfoByIndex(useIndex);
	// 着手情報を確定
	reversi::MoveInfo::MOVE_INFO moveInfoData;
	moveInfoData.position = reverseInfo.GetPosition();
	moveInfoData.info = GetTurnToStone(turn);
	moveInfoData.turn = turn;
	reversi::MoveInfo moveInfo(moveInfoData, reverseInfo);
	// 着手情報を入力
	move.Copy(moveInfo);
	*/



	//return false;
}

reversi::ReversiConstant::BOARD_INFO reversi::MoveThinkingCpu4::GetTurnToStone(reversi::ReversiConstant::TURN turn) {
	if (turn == reversi::ReversiConstant::TURN::TURN_BLACK) {
		return reversi::ReversiConstant::BOARD_INFO::BLACK;
	} else {
		return reversi::ReversiConstant::BOARD_INFO::WHITE;
	}
}

void reversi::MoveThinkingCpu4::SetThinkingChildNode(reversi::ThinkingNode* node, const reversi::Reversi& reversi, const reversi::Board& board, reversi::ReversiConstant::TURN selfTurn) {

	reversi::ReversiConstant::POSITION moveEnablePositions[MOVE_ENABLE_DATA_SIZE];
	int moveEnableCount = 0;
	reversi::ReverseInfo reverseInfos[MOVE_ENABLE_DATA_SIZE];
	int reverseInfoCount = 0;
	// 初期化(reverseInfoは不要)
	for (int i = 0; i < MOVE_ENABLE_DATA_SIZE; ++i) {
		reversi::Assert::AssertArrayRange(i, MOVE_ENABLE_DATA_SIZE, "MoveThinkingCpu4::SetThinkingChildNode moveEnablePositions index over(initialize)");
		moveEnablePositions[i] = reversi::ReversiConstant::POSITION::A1;
	}

	// 終局している
	if ((reversi.GetScene() == reversi::Reversi::SCENE::END) || (reversi.GetScene() == reversi::Reversi::SCENE::RESULT)) {
		return;
	}

	// 今の手番
	reversi::ReversiConstant::TURN turn = reversi.GetTurn();

	// 打てる位置を取得
	GetMoveEnableData(moveEnablePositions, moveEnableCount, MOVE_ENABLE_DATA_SIZE, reverseInfos, reverseInfoCount, board, turn);

	// どこにも打てない
	if (moveEnableCount == 0) {
		return;
	}

	// 打てる場所分childを作成
	int size = moveEnableCount;
	for (int i = 0; i < size; ++i) {
		reversi::Assert::AssertArrayRange(i, size, "MoveThinkingCpu4::SetThinkingChildNode moveEnablePositions index over");
		reversi::ThinkingNode* child = new reversi::ThinkingNode();
		// リバーシをコピー
		reversi::Reversi childReversi;
		childReversi.CopyWithoutDynamicInstance(reversi);
		childReversi.SetOutputEnable(false); // 出力はoffにする

		/*
		// リバーシを着手シーンまで進める
		bool taskLoop = true;
		bool isEnded = false; // 対局が終わっている
		while (taskLoop) {
			childReversi.Task();
			// 終局してないかチェック
			if ((childReversi.GetScene() == reversi::Reversi::SCENE::RESULT)
				|| (childReversi.GetScene() == reversi::Reversi::SCENE::END)) {
				isEnded = true;
				taskLoop = false;
			}
			if (childReversi.GetScene() == reversi::Reversi::SCENE::MOVE_SELECT_START) {
				// 着手シーンに進んでいるのでタスク進行終了
				taskLoop = false;
			}
		}
		if (isEnded) {
			// 終局していたらNodeを作成しても意味がないので作らない
			continue;
		}
		*/

		// 着手を作成
		reversi::MoveInfo::MOVE_INFO moveInfoData;
		moveInfoData.position = moveEnablePositions[i];
		moveInfoData.info = GetTurnToStone(turn);
		moveInfoData.turn = childReversi.GetTurn(); // ゲーム上の手番
		reversi::MoveInfo moveInfo(moveInfoData, reverseInfos[i]);		

		// 着手
		childReversi.SetMoveSimulation(moveInfo);
		childReversi.Task();

		// リバーシを次の着手シーンまで進める
		bool taskLoop = true;
		bool isEnded = false; // 対局が終わっている
		while (taskLoop) {
			childReversi.Task();
			// 終局してないかチェック
			if ((childReversi.GetScene() == reversi::Reversi::SCENE::RESULT)
				|| (childReversi.GetScene() == reversi::Reversi::SCENE::END)) {
				isEnded = true;
				taskLoop = false;
			}
			if (childReversi.GetScene() == reversi::Reversi::SCENE::MOVE_SELECT_START) {
				// 着手シーンに進んでいるのでタスク進行終了
				taskLoop = false;
			}
		}

		child->CopyReversi(childReversi);
		child->SetMovePosition(moveInfoData.position);
		child->SetTurn(moveInfoData.turn);
		child->SetThinkingDepth(node->GetThinkingDepth() + 1);

		// 評価値計算
		ICalcBoardEvaluationPoint* calcEval = new CalcBoardEvaluationPointByPosition();
		int blackEval = 0, whiteEval = 0;
		calcEval->CalcBoardEvaluationPoint(board, blackEval, whiteEval, turn);
		if (calcEval) {
			delete calcEval;
			calcEval = NULL;
		}
		// selfTurnの人の評価値を取る
		int eval = 0;
		if (selfTurn == reversi::ReversiConstant::TURN::TURN_BLACK) {
			eval = blackEval;
		} else {
			eval = whiteEval;
		}
		child->SetEvaluationPoint(eval);

		// 親のノードにつなげる
		node->AddChild(child);
	}


}

// 着手可能情報を取得する
void reversi::MoveThinkingCpu4::GetMoveEnableData(reversi::ReversiConstant::POSITION* moveEnablePositions, int& moveEnablePositionCount, int moveEnablePositionSize, reversi::ReverseInfo* reverseInfos, int& reverseInfoCount, const reversi::Board& board, reversi::ReversiConstant::TURN turn) {
	moveEnablePositionCount = 0;
	reverseInfoCount = 0;
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
			// 裏返し情報も取得
			reverseInfos[reverseInfoCount] = reverseInfo;
			++reverseInfoCount;
		}
	}
}