#include "PlayerFactory.h"
#include "../../util/Assert.h"
#include "../../util/OutputConsole.h"
#include "PlayerMan.h"
#include "PlayerCpu.h"

/**
 * コンストラクタ
 */
reversi::PlayerFactory::PlayerFactory() {
}

/**
 * デストラクタ
 */
reversi::PlayerFactory::~PlayerFactory() {
}

// seisei
reversi::IPlayer* reversi::PlayerFactory::Create(reversi::PlayerFactory::TYPE type) {
	reversi::IPlayer* player = NULL;
	switch (type) {
	case reversi::PlayerFactory::TYPE::PLAYER_MAN:
		return new PlayerMan();
	case reversi::PlayerFactory::TYPE::PLAYER_CPU1:
		return new PlayerCpu(reversi::PlayerCpu::LEVEL::LEVEL1);
	case reversi::PlayerFactory::TYPE::PLAYER_CPU2:
		return new PlayerCpu(reversi::PlayerCpu::LEVEL::LEVEL2);
	case reversi::PlayerFactory::TYPE::PLAYER_CPU3:
		return new PlayerCpu(reversi::PlayerCpu::LEVEL::LEVEL3);
	case reversi::PlayerFactory::TYPE::PLAYER_CPU4:
		return new PlayerCpu(reversi::PlayerCpu::LEVEL::LEVEL4);
	default:
		return NULL;
	}
}

