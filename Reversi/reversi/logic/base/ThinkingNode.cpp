#include "ThinkingNode.h"
#include "../../util/Assert.h"

/**
 * コンストラクタ
 */
reversi::ThinkingNode::ThinkingNode() : parent(NULL), turn(reversi::ReversiConstant::TURN::TURN_BLACK), evaluationPoint(0), thinkingDepth(0) {
}

/**
 * デストラクタ
 */
reversi::ThinkingNode::~ThinkingNode() {
}

/**
 * 親ノードの設定
 * @param parentNode 親ノード
 */
void reversi::ThinkingNode::SetParent(ThinkingNode* parentNode) {
	parent = parentNode;
}

/**
 * 親ノードを取得する
 * @return 親ノード
 */
const reversi::ThinkingNode* const reversi::ThinkingNode::GetParent() const {
	return parent;
}

/**
 * 子ノードを追加する
 * @param childNode 追加する子ノード
 */
void reversi::ThinkingNode::AddChild(reversi::ThinkingNode* childNode) {
	child.push_back(childNode);
}

/**
 * 子ノードを取得する
 * @param  index 子ノードのindex
 * @return       子ノード
 */
const reversi::ThinkingNode* const reversi::ThinkingNode::GetChild(int index) const {
	reversi::Assert::AssertArrayRange(index, GetChildSize(), "ThinkingNode::GetChild index over");
	return child[index];
}

/**
 * 子ノードの数を取得する
 * @return 子ノードの数
 */
int reversi::ThinkingNode::GetChildSize() const {
	return (int)child.size();
}

/**
 * 手番の取得
 * @return 手番
 */
const reversi::ReversiConstant::TURN& reversi::ThinkingNode::GetTurn() const {
	return turn;
}

/**
 * 評価値の取得
 * @return 評価値
 */
int reversi::ThinkingNode::GetEvaluationPoint() const {
	return evaluationPoint;
}

/**
 * 読みの深さの取得
 * @return 読みの深さ
 */
int reversi::ThinkingNode::GetThinkingDepth() const {
	return thinkingDepth;
}
