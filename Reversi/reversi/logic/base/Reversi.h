#ifndef REVERSI_LOGIC_BASE_REVERSI_H_
#define REVERSI_LOGIC_BASE_REVERSI_H_

#include "ReversiConstant.h"
#include "Board.h"
#include "../player/IPlayer.h"
#include "../../util/IOutputConsole.h"

namespace reversi {

// リバーシクラス
class Reversi {
public:
	static const int PLAYER_COUNT = 2;
	static const int PLAYER_BLACK = 0;
	static const int PLAYER_WHITE = 1;
	enum class SCENE {
		INITIALIZE,
		MOVE_SELECT_START,
		MOVE_SELECT,
		PASS,
		MOVE_AFTER,
		RESULT,
		END
	};
	enum class RESULT {
		NONE,   // 勝敗がついていない
		BLACK,  // 黒の勝ち
		WHITE,  // 白の勝ち
		DRAW    // 引き分け
	};
	typedef struct {
		bool passBlack;
		bool passWhite;
	} PASS_CHECK;
	// 結果データ
	typedef struct {
		RESULT result;
		int blackRawCount;      // 純粋な黒石の数
		int whiteRawCount;      // 純粋な白石の数
		int noneRawCount;       // 純粋な空白の数
		int blackResultCount;   // 結果を適用した黒石の数
		int whiteResultCount;   // 結果を適用した黒石の数
		int noneResultCount;    // 結果を適用した空白の数
	} RESULT_DATA;
public:

	/**
	 * コンストラクタ
	 */
	Reversi();

	/**
	 * デストラクタ
	 */
	virtual ~Reversi();

	/**
	 *  初期化
	 */
	void Initialize();

	/**
	 * ゲーム開始のための初期化
	 */
	void InitializeGame();

	/**
	 * 更新処理
	 */
	void Task();

	/**
	 * 盤面をコピーする(デバッグ用途)
	 * @param source コピー元
	 */
	void CopyBoard(const reversi::Board& source);

	/**
	 * 現在のシーンを取得する
	 * @return シーン
	 */
	reversi::Reversi::SCENE GetScene() const {
		return scene;
	}

	/**
	 * 結果を取得する
	 * @return 結果
	 */
	reversi::Reversi::RESULT GetResult() const {
		return resultData.result;
	}

	/**
	 * 最終結果の石や空白の数を取得する
	 * @param black 黒石
	 * @param white 白石
	 * @param none  空白
	 */
	void GetResultStone(int& black, int& white, int& none);

private:

	/**
	 * 初期化
	 */
	void TaskInitialize();

	/**
	 * 着手選択開始
	 */
	void TaskMoveSelectStart();

	/**
	 * 着手選択
	 */
	void TaskMoveSelect();

	/**
	 * パス
	 */
	void TaskPass();

	/**
	 * 着手後処理
	 */
	void TaskMoveAfter();

	/**
	 * 結果処理
	 */
	void TaskResult();

	/**
	 * 対局終了
	 */
	void TaskEnd();

	/**
	 * プレイヤーをリセットする(NULLクリア)
	 */
	void ResetPlayer();

	/**
	 * プレイヤーを削除する(DELETE)
	 */
	void ReleasePlayer();

	/**
	 * シーンをセットする
	 * @param nextScene 次のシーン
	 */
	void SetScene(reversi::Reversi::SCENE nextScene);

	/**
	 * 手番からプレイヤーのindexを取得する
	 * @param  targetTurn 手番
	 * @return            プレイヤーindex
	 */
	int TurnToPlayerIndex(reversi::ReversiConstant::TURN targetTurn);

	/**
	 * 手番の切り替え
	 * @param targetTurn 現在の手番
	 */
	void ChangeTurn(reversi::ReversiConstant::TURN& targetTurn);

	/**
	 * 終局したか
	 * @return trueなら終局している
	 */
	bool IsEnded();

	/**
	 * 打つ場所がなくてパスかどうかチェック
	 * @param  targetTurn 現在の手番
	 * @return            trueならパス(打つ場所がない)
	 */
	bool CheckPass(reversi::ReversiConstant::TURN targetTurn);

	/**
	 * パスのチェックフラグをリセットする
	 */
	void ResetPassCheck();

	/**
	 * パスのチェックフラグをセットする
	 * @param targetTurn 現在の手番
	 */
	void SetPassCheck(reversi::ReversiConstant::TURN targetTurn);

	/**
	 * プレイヤー2人ともパスしているか
	 * @return trueなら2人ともパスしている
	 */
	bool IsEveryonePass() const;

	/**
	 * 結果データをリセットする
	 */
	void ResetResultData();

	/**
	 * 結果の石をセットする(空白を勝者の石とする)
	 * @param black  現在の黒石の数
	 * @param white  現在の白石の数
	 * @param none   現在の空白の数
	 * @param result 勝敗結果
	 */
	void SetResultStone(int& black, int& white, int& none, reversi::Reversi::RESULT result);

private:
	reversi::Board board;                       // 盤
	reversi::ReversiConstant::TURN turn;        // 現在の手番
	reversi::IPlayer* player[PLAYER_COUNT];     // プレイヤークラス
	reversi::Reversi::SCENE scene;              // シーン
	reversi::MoveInfo moveInfo;                 // 着手キャッシュ
	reversi::IOutputConsole* console;           // コンソール出力クラス
	//reversi::Reversi::RESULT result;            // 対局の結果
	reversi::Reversi::PASS_CHECK passCheck;     // パス確認用(どっちもパスしかできなかったら終局)
	reversi::Reversi::RESULT_DATA resultData;   // 結果データ
	//int resultBlackCount;                       // 黒石最終結果
	//int resultWhiteCount;                       // 白石最終結果
	//int resultNoneCount;                        // 空白最終結果(あくまで盤の空きマスの数)
};

}

#endif  // REVERSI_LOGIC_BASE_REVERSI_H_
