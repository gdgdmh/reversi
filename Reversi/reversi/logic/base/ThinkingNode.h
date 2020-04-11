#ifndef REVERSI_LOGIC_BASE_THINKINGTREE_H_
#define REVERSI_LOGIC_BASE_THINKINGTREE_H_

#include <vector>
#include "ReversiConstant.h"
#include "Reversi.h"

//#include "ReverseInfo.h"

namespace reversi {

// 思考ノードクラス
class ThinkingNode {
public:

	/**
	 * コンストラクタ
	 */
	ThinkingNode();

	/**
	 * デストラクタ
	 */
	virtual ~ThinkingNode();

	/**
	 * 親ノードの設定
	 * @param parentNode 親ノード
	 */
	void SetParent(ThinkingNode* parentNode);

	/**
	 * 親ノードを取得する
	 * @return 親ノード
	 */
	const ThinkingNode* const GetParent() const;

	/**
	 * 子ノードを追加する
	 * @param childNode 追加する子ノード
	 */
	void AddChild(ThinkingNode* childNode);

	/**
	 * 子ノードを取得する
	 * @param  index 子ノードのindex
	 * @return       子ノード
	 */
	const ThinkingNode* const GetChild(int index) const;

	/**
	 * 子ノードの数を取得する
	 * @return 子ノードの数
	 */
	int GetChildSize() const;

	/**
	 * 手番の取得
	 * @return 手番
	 */
	const reversi::ReversiConstant::TURN& GetTurn() const;

	/**
	 * 評価値の取得
	 * @return 評価値
	 */
	int GetEvaluationPoint() const;

	/**
	 * 読みの深さの取得
	 * @return 読みの深さ
	 */
	int GetThinkingDepth() const;

private:

	reversi::Reversi reversi;               // リバーシクラス
	ThinkingNode* parent;                   // 親(自分より上層のノード)
	std::vector<ThinkingNode*> child;       // 子(下層のノード)
	reversi::ReversiConstant::TURN turn;    // 手番
	int evaluationPoint;                    // 評価値
	int thinkingDepth;                      // 読みの深さ
};

}

#endif  // REVERSI_LOGIC_BASE_THINKINGTREE_H_
