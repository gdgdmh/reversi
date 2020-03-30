#ifndef REVERSI_LOGIC_BASE_REVERSICONSTANT_H_
#define REVERSI_LOGIC_BASE_REVERSICONSTANT_H_

#include <string>

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

	//　盤の座標
	enum POSITION {
		A1 = 11, B1 = 12, C1 = 13, D1 = 14, E1 = 15, F1 = 16, G1 = 17, H1 = 18,
		A2 = 21, B2 = 22, C2 = 23, D2 = 24, E2 = 25, F2 = 26, G2 = 27, H2 = 28,
		A3 = 31, B3 = 32, C3 = 33, D3 = 34, E3 = 35, F3 = 36, G3 = 37, H3 = 38,
		A4 = 41, B4 = 42, C4 = 43, D4 = 44, E4 = 45, F4 = 46, G4 = 47, H4 = 48,
		A5 = 51, B5 = 52, C5 = 53, D5 = 54, E5 = 55, F5 = 56, G5 = 57, H5 = 58,
		A6 = 61, B6 = 62, C6 = 63, D6 = 64, E6 = 65, F6 = 66, G6 = 67, H6 = 68,
		A7 = 71, B7 = 72, C7 = 73, D7 = 74, E7 = 75, F7 = 76, G7 = 77, H7 = 78,
		A8 = 81, B8 = 82, C8 = 83, D8 = 84, E8 = 85, F8 = 86, G8 = 87, H8 = 88
	};

	// 着手情報
	typedef struct {
		POSITION position;	// 位置
		BOARD_INFO info;	// 着手する石
	}MOVE_INFO;

	static const int BOARD_SIZE = 10 * 10;     // 盤の大きさ(1次元配列) 8x8の盤だが斜め判定を考慮して全体を無効マスで囲う用にしている
	static const int BOARD_SIZE_X = 8;     	// 盤の大きさX(Xマスの数)
	static const int BOARD_SIZE_Y = 8;     	// 盤の大きさY(Yマスの数)
	static const int POSITION_SIZE = 64;	// 座標の最大数

	static const int POSITIONS[ReversiConstant::POSITION_SIZE];	// 全ての座標(通常使用するもののみ、番兵は含まない)

	static const int POSITION_HORIZONTALS[ReversiConstant::BOARD_SIZE_Y][ReversiConstant::BOARD_SIZE_X]; // 横方向の座標

};

}

#endif  // REVERSI_LOGIC_BASE_REVERSICONSTANT_H_
