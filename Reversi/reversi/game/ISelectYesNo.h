#ifndef REVERSI_GAME_ISELECTYESNO_H_
#define REVERSI_GAME_ISELECTYESNO_H_

namespace reversi {

// Yes,No選択インターフェース
class ISelectYesNo {
public:

	/**
	 * デストラクタ
	 */
	virtual ~ISelectYesNo() {
	}

	/**
	 * 初期化
	 */
	virtual void Initialize() = 0;

	/**
	 * メイン処理
	 */
	virtual void Task() = 0;

	/**
	 * Yesを選択したか
	 * @return trueならyes falseならno
	 */
	virtual bool IsSelectYes() = 0;
};

}

#endif  // REVERSI_GAME_ISELECTYESNO_H_
