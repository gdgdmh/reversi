#ifndef REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU2_H_
#define REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU2_H_

#include "IMoveThinking.h"
#include "../base/ReversiConstant.h"
#include "../base/MoveInfo.h"
#include "../base/Move.h"

// 前方宣言
namespace reversi {
class Board;
}

namespace reversi {

// プレイヤー(CPU)思考クラス LEVEL2
class MoveThinkingCpu2 : public IMoveThinking {
public:
	static const int MAX_COUNT_DEFAULT = 0; // 取れる石をチェックするときのデフォルト値
public:
	/**
	 * コンストラクタ
	 */
	MoveThinkingCpu2();

	/**
	 * デストラクタ
	 */
	virtual ~MoveThinkingCpu2();

	/**
	 * 思考初期化
	 * 手番が来たときに一度だけ呼ばれる
	 * @param  board    盤情報
	 * @param  turn     手番
	 * @return          trueなら思考が完了
	 */
	virtual void InitializeMoveThinking(const reversi::Board& board, reversi::ReversiConstant::TURN turn);

	/**
	 * 思考
	 * @param  board    盤情報
	 * @param  move     着手情報
	 * @param  turn     手番
	 * @return          trueなら思考が完了
	 */
	bool MoveThinking(const reversi::Board& board, reversi::MoveInfo& move, reversi::ReversiConstant::TURN turn);

private:

	reversi::ReversiConstant::BOARD_INFO GetTurnToStone(reversi::ReversiConstant::TURN turn);

	/**
	 * ひっくり返せる最大数の候補indexを取得する
	 * @param candidate 候補
	 * @param move      着手キャッシュ
	 */
	void GetMaxReverseCountCandidateIndex(std::vector<int>& candidate, const reversi::Move& move);

	/**
	 * 取れる角があるかチェック
	 * @param  cornerIndex 角のindex(ReverseInfo)
	 * @param  move        着手キャッシュ
	 * @return             trueなら見つかった
	 */
	bool CheckPutEnableCornerIndex(int& cornerIndex, const reversi::Move& move);

private:
	reversi::Move reversiMove;

};

}

#endif  // REVERSI_LOGIC_PLAYER_MOVETHINKINGCPU2_H_
