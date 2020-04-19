#ifndef REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU5_H_
#define REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU5_H_

#include "IMoveThinking.h"
#include "../base/ReversiConstant.h"
#include "../base/MoveInfo.h"
#include "../base/Move.h"
#include "../base/ThinkingNode2.h"
#include "../../util/IOutputConsole.h"
#include "../../util/PerformanceCounter.h"

// 前方宣言
namespace reversi {
class Board;
}

namespace reversi {

// プレイヤー(CPU)思考クラス LEVEL5
// LEVEL4の強化版
class MoveThinkingCpu5 : public IMoveThinking {
private:
	// 静的評価位置
	// 石が置いてある場所によって評価をつける(ここの位置はいい、悪いなど)
	static const int STATIC_EVALUATION_POINTS[reversi::ReversiConstant::POSITION_SIZE];
	static const int MOVE_ENABLE_DATA_SIZE = 32; // 移動可能位置の配列サイズ
public:
	/**
	 * コンストラクタ
	 */
	MoveThinkingCpu5();

	/**
	 * デストラクタ
	 */
	virtual ~MoveThinkingCpu5();

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

	/**
	 * 手番から石を取得
	 * @param  turn 手番
	 * @return      盤情報(石)
	 */
	reversi::ReversiConstant::BOARD_INFO GetTurnToStone(reversi::ReversiConstant::TURN turn);

	/**
	 * 指定されたノードに子の思考ノードを追加する
	 * @param node        追加対象ノード
	 * @param board       盤情報
	 * @param selfTurn    評価関数設定対象の手番
	 * @param currentTurn 現在の手番
	 */
	void SetThinkingChildNode(reversi::ThinkingNode2* node, const reversi::Board& board, reversi::ReversiConstant::TURN selfTurn, reversi::ReversiConstant::TURN currentTurn);

	/**
	 * 着手可能情報を取得する
	 * @param moveEnablePositions     着手可能位置配列
	 * @param moveEnablePositionCount 着手可能位置数
	 * @param moveEnablePositionSize  着手可能位置配列最大数
	 * @param reverseInfos            裏返し情報配列
	 * @param reverseInfoCount        裏返し情報数
	 * @param board                   盤情報
	 * @param turn                    手番
	 */
	void GetMoveEnableData(reversi::ReversiConstant::POSITION* moveEnablePositions, int& moveEnablePositionCount, int moveEnablePositionSize, reversi::ReverseInfo* reverseInfos, int& reverseInfoCount, const reversi::Board& board, reversi::ReversiConstant::TURN turn);

	/**
	 * 処理時関出力
	 * @param prefix  処理時間の前に出す出力文字列
	 * @param counter 処理時間計測カウンタ
	 */
	void PrintTimeDiff(std::string prefix, const reversi::PerformanceCounter& counter);

private:
	reversi::IOutputConsole* console; // コンソール出力クラス
};

}

#endif  // REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU5_H_
