#ifndef REVERSI_LOGIC_PLAYER_PLAYERFACTORY_H_
#define REVERSI_LOGIC_PLAYER_PLAYERFACTORY_H_

#include "IPlayer.h"

namespace reversi {

// 
class PlayerFactory {
public:
	enum class TYPE {
		PLAYER_MAN,
		PLAYER_CPU1,
		PLAYER_CPU2,
		PLAYER_CPU3
	};
public:

	/**
	 * コンストラクタ
	 */
	PlayerFactory();

	/**
	 * デストラクタ
	 */
	virtual ~PlayerFactory();

	// seisei
	reversi::IPlayer* Create(reversi::PlayerFactory::TYPE type);


private:
};

}

#endif  // REVERSI_LOGIC_PLAYER_PLAYERFACTORY_H_
