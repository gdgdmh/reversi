﻿#include "ThinkingNode.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::ThinkingNode::ThinkingNode() : parent(NULL), turn(reversi::ReversiConstant::TURN::TURN_BLACK), evaluationPoint(0), thinkingDepth(0) {
	for (int i = 0; i < CHILDREN_SIZE; ++i) {
		children[i] = NULL;
	}
	childrenCount = 0;
}

/**
 * デストラクタ
 */
reversi::ThinkingNode::~ThinkingNode() {
}

/**
 * リバーシのコピー
 * @param source コピー元
 */
void reversi::ThinkingNode::CopyReversi(const reversi::Reversi& source) {
	reversi.CopyWithoutDynamicInstance(source);
    // 出力機能は必要ないのでoff
    reversi.SetOutputEnable(false);
}

/**
 * 親ノードの設定
 * @param parentNode 親ノード
 */
//void reversi::ThinkingNode::SetParent(ThinkingNode* parentNode) {
//	parent = parentNode;
//}

/**
 * 親ノードを取得する
 * @return 親ノード
 */
reversi::ThinkingNode* const reversi::ThinkingNode::GetParent() const {
	return parent;
}

/**
 * 子ノードを追加する
 * @param childNode 追加する子ノード
 */
void reversi::ThinkingNode::AddChild(reversi::ThinkingNode* childNode) {

	// 親を設定
	childNode->parent = this;

	// size and index over check
	reversi::Assert::AssertEquals(childrenCount < CHILDREN_SIZE, "ThinkingNode::AddChild size over");
	reversi::Assert::AssertArrayRange(childrenCount, CHILDREN_SIZE, "ThinkingNode::AddChild index over");
    if (childrenCount >= CHILDREN_SIZE) {
        // バッファオーバーラン コンパイラ警告対応
        return;
    }
	children[childrenCount] = childNode;
	++childrenCount;
}

/**
 * 子ノードを取得する
 * @param  index 子ノードのindex
 * @return       子ノード
 */
reversi::ThinkingNode* const reversi::ThinkingNode::GetChild(int index) const {
	reversi::Assert::AssertArrayRange(index, childrenCount, "ThinkingNode::GetChild index over");
	return children[index];
}

/**
 * 子ノードの数を取得する
 * @return 子ノードの数
 */
int reversi::ThinkingNode::GetChildSize() const {
	return childrenCount;
}

/**
 * 着手位置の設定
 * @param position 位置情報
 */
void reversi::ThinkingNode::SetMovePosition(reversi::ReversiConstant::POSITION position) {
	movePosition = position;
}

/**
 * 着手位置の取得
 * @return 位置
 */
const reversi::ReversiConstant::POSITION& reversi::ThinkingNode::GetMovePosition() const {
	return movePosition;
}

/**
 * 手番の設定
 * @param setTurn 手番
 */
void reversi::ThinkingNode::SetTurn(reversi::ReversiConstant::TURN setTurn) {
	turn = setTurn;
}

/**
 * 手番の取得
 * @return 手番
 */
const reversi::ReversiConstant::TURN& reversi::ThinkingNode::GetTurn() const {
	return turn;
}

/**
 * 評価値の設定
 * @param evalPoint 評価値
 */
void reversi::ThinkingNode::SetEvaluationPoint(int evalPoint) {
	evaluationPoint = evalPoint;
}

/**
 * 評価値の取得
 * @return 評価値
 */
int reversi::ThinkingNode::GetEvaluationPoint() const {
	return evaluationPoint;
}

/**
 * 読みの深さの設定
 * @param depth 読みの深さ
 */
void reversi::ThinkingNode::SetThinkingDepth(int depth) {
	thinkingDepth = depth;
}

/**
 * 読みの深さの取得
 * @return 読みの深さ
 */
int reversi::ThinkingNode::GetThinkingDepth() const {
	return thinkingDepth;
}

/**
 * 子ノードのメモリを開放する(rootのノードが実行すること)
 */
void reversi::ThinkingNode::ReleaseChild() {
	for (int i = 0; i < childrenCount; ++i) {
		reversi::Assert::AssertArrayRange(i, CHILDREN_SIZE, "ThinkingNode::ReleaseChild index over");
		if (children[i] == NULL) {
			continue;
		}
		// 子のノードも開放
		children[i]->ReleaseChild();
		delete children[i];
		children[i] = NULL;
	}
}

/**
 * 自分の子ノードから一番評価値が高くなるノードを見つける
 * @return 評価値が一番高いノード
 */
reversi::ThinkingNode* const reversi::ThinkingNode::FindHighEvaluationPointNode() {
	return NULL;
}

/**
 * 自分の1つ下の子ノードから一番評価値が高くなるノードを見つける
 * @return 評価値が一番高いノード
 */
reversi::ThinkingNode* const reversi::ThinkingNode::FindHighEvaluationPointOneUnderNode() {
	reversi::ThinkingNode* currentHighNode = NULL;
	int currentHighPoint = FIND_DEFAULT_EVALUATION_POINT; // 可能な限り低い値にする
	for (int i = 0; i < childrenCount; ++i) {
		reversi::Assert::AssertArrayRange(i, CHILDREN_SIZE, "ThinkingNode::FindHighEvaluationPointOneUnderNode index over");
		if (children[i] == NULL) {
			continue;
		}
		if (children[i]->GetEvaluationPoint() > currentHighPoint) {
			// 大きい評価値が来たので更新
			currentHighNode = children[i];
			currentHighPoint = children[i]->GetEvaluationPoint();
		}
	}
	return currentHighNode;
}
