﻿#include "ReversiGameLoop.h"
#include "../util/Assert.h"


/**
 * コンストラクタ
 */
reversi::ReversiGameLoop::ReversiGameLoop() {
}

/**
 * デストラクタ
 */
reversi::ReversiGameLoop::~ReversiGameLoop() {
}

void reversi::ReversiGameLoop::Initialize() {
    reversi.Initialize();
    reversi.InitializeGame();
}

/**
 * メイン処理
 */
void reversi::ReversiGameLoop::Task() {
    while (true) {
        reversi.Task();
    }
}