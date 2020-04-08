#ifndef REVERSI_GAME_KEYBOARDSELECTYESNO_H_
#define REVERSI_GAME_KEYBOARDSELECTYESNO_H_

#include "ISelectYesNo.h"

namespace reversi {

// キーボードによるYesNo選択クラス
class KeyboardSelectYesNo : public ISelectYesNo {
public:

	/**
	 * コンストラクタ
	 */
	KeyboardSelectYesNo();

	/**
	 * デストラクタ
	 */
	virtual ~KeyboardSelectYesNo();

	/**
	 * 初期化
	 */
	void Initialize();

	/**
	 * メイン処理
	 */
	void Task();

	/**
	 * Yesを選択したか
	 * @return trueならyes falseならno
	 */
	bool IsSelectYes();

private:

	//void GetInputString();

};

}

#endif  // REVERSI_GAME_KEYBOARDSELECTYESNO_H_
