#ifndef REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU4_H_
#define REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU4_H_

#include "IMoveThinking.h"
#include "../base/ReversiConstant.h"
#include "../base/MoveInfo.h"
#include "../base/Move.h"
#include "../base/ThinkingNode.h"

// 前方宣言
namespace reversi {
class Board;
}

namespace reversi {

// プレイヤー(CPU)思考クラス LEVEL4
// 静的評価関数と全幅検索を使用する
class MoveThinkingCpu4 : public IMoveThinking {
private:
	// 静的評価位置
	// 石が置いてある場所によって評価をつける(ここの位置はいい、悪いなど)
	static const int STATIC_EVALUATION_POINTS[reversi::ReversiConstant::POSITION_SIZE];
	static const int MOVE_ENABLE_DATA_SIZE = 32; // 移動可能位置の配列サイズ
public:
	/**
	 * コンストラクタ
	 */
	MoveThinkingCpu4();

	/**
	 * デストラクタ
	 */
	virtual ~MoveThinkingCpu4();

	/**
	 * 思考初期化
	 * 手番が来たときに一度だけ呼ばれる
	 * @param reversi   リバーシクラス
	 * @param moveCache 着手キャッシュ
	 * @param board     盤情報
	 * @param turn      手番
	 */
	virtual void InitializeMoveThinking(const reversi::Reversi& reversi, const reversi::Move& moveCache, const reversi::Board& board, reversi::ReversiConstant::TURN turn);

	/**
	 * 思考
	 * @param  reversi   リバーシクラス
	 * @param  moveCache 着手キャッシュ
	 * @param  board     盤情報
	 * @param  move      着手情報
	 * @param  turn      手番
	 * @return           trueなら思考が完了
	 */
	virtual bool MoveThinking(const reversi::Reversi& reversi, const reversi::Move& moveCache, const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn);

private:

	reversi::ReversiConstant::BOARD_INFO GetTurnToStone(reversi::ReversiConstant::TURN turn);

	void SetThinkingChildNode(reversi::ThinkingNode* node, const reversi::Reversi& reversi, const reversi::Board& board, reversi::ReversiConstant::TURN selfTurn);

	// 着手可能情報を取得する
	void GetMoveEnableData(reversi::ReversiConstant::POSITION* moveEnablePositions, int& moveEnablePositionCount, int moveEnablePositionSize, reversi::ReverseInfo* reverseInfos, int& reverseInfoCount, const reversi::Board& board, reversi::ReversiConstant::TURN turn);

private:
	//reversi::Move reversiMove;

};

}

#endif  // REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU4_H_
