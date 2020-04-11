﻿#ifndef REVERSI_LOGIC_BASE_THINKINGTREE_H_
#define REVERSI_LOGIC_BASE_THINKINGTREE_H_

#include "ReversiConstant.h"
#include "Reversi.h"

//#include "ReverseInfo.h"

namespace reversi {

// 思考ノードクラス
class ThinkingNode {
public:
	static const int CHILDREN_SIZE = 32;
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
	 * リバーシのコピー
	 * @param source コピー元
	 */
	void CopyReversi(const reversi::Reversi& source);

	/**
	 * 親ノードの設定
	 * @param parentNode 親ノード
	 */
	//void SetParent(ThinkingNode* parentNode);

	/**
	 * 親ノードを取得する
	 * @return 親ノード
	 */
	ThinkingNode* const GetParent() const;

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
	ThinkingNode* const GetChild(int index) const;

	/**
	 * 子ノードの数を取得する
	 * @return 子ノードの数
	 */
	int GetChildSize() const;

	/**
	 * 着手位置の設定
	 * @param position 位置情報
	 */
	void SetMovePosition(reversi::ReversiConstant::POSITION position);

	/**
	 * 着手位置の取得
	 * @return 位置
	 */
	const reversi::ReversiConstant::POSITION& GetMovePosition() const;

	/**
	 * 手番の設定
	 * @param setTurn 手番
	 */
	void SetTurn(reversi::ReversiConstant::TURN setTurn);

	/**
	 * 手番の取得
	 * @return 手番
	 */
	const reversi::ReversiConstant::TURN& GetTurn() const;

	/**
	 * 評価値の設定
	 * @param evalPoint 評価値
	 */
	void SetEvaluationPoint(int evalPoint);

	/**
	 * 評価値の取得
	 * @return 評価値
	 */
	int GetEvaluationPoint() const;

	/**
	 * 読みの深さの設定
	 * @param depth 読みの深さ
	 */
	void SetThinkingDepth(int depth);

	/**
	 * 読みの深さの取得
	 * @return 読みの深さ
	 */
	int GetThinkingDepth() const;

	/**
	 * 子ノードのメモリを開放する(rootのノードが実行すること)
	 */
	void ReleaseChild();

	// 自分の子ノードから一番評価値が高くなるノードを見つける
	//const reversi::ThinkingNode* const FindHighEvaluationPointNode();

private:

	// やっぱboardだけでいいかも？
	reversi::Reversi reversi;                           // リバーシクラス
	ThinkingNode* parent;                               // 親(自分より上層のノード)
	ThinkingNode* children[CHILDREN_SIZE];              // 子(下層のノード)
	int childrenCount;                                  // 子のノード数
	reversi::ReversiConstant::POSITION movePosition;    // 着手位置
	reversi::ReversiConstant::TURN turn;                // 手番
	int evaluationPoint;                                // 評価値
	int thinkingDepth;                                  // 読みの深さ
};

}

#endif  // REVERSI_LOGIC_BASE_THINKINGTREE_H_
