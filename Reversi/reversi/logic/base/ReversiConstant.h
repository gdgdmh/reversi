#ifndef REVERSI_LOGIC_BASE_REVERSICONSTANT_H_
#define REVERSI_LOGIC_BASE_REVERSICONSTANT_H_

namespace reversi {

// リバーシ定数クラス
class ReversiConstant {
public:
	// 盤の情報
	enum BOARD_INFO {
		NONE,       // 石が置かれていない
		BLACK,      // 黒が置かれている
		WHITE,      // 白が置かれている
		INVALID,    // 無効マス
	};

	static const int BOARD_SIZE = 10 * 10;     // 盤の大きさ(1次元配列) 8x8の盤だが斜め判定を考慮して全体を無効マスで囲う用にしている
	static const int BOARD_SIZE_X = 8;     // 盤の大きさX(Xマスの数)
	static const int BOARD_SIZE_Y = 8;     // 盤の大きさY(Yマスの数)
};

}

#endif  // REVERSI_LOGIC_BASE_REVERSICONSTANT_H_
