#include "PerformanceCounter.h"
#include <windows.h>
#include <iostream>

/*
// あらかじめタイマーの周波数を取得しておく
LARGE_INTEGER    frequency;
QueryPerformanceFrequency( &frequency );


// 時間計測したい始点でカウンタを取得
LARGE_INTEGER    start;
QueryPerformanceCounter( &start );

//         ↑
// この間の時間を計測
//         ↓

// 時間計測したい終点でカウンタを取得
LARGE_INTEGER    end;
QueryPerformanceCounter( &end );


// カウンタの差分を周波数で割れば経過時間を秒で取得できる
LONGLONG span = end.QuadPart - start.QuadPart;
double sec = (double)span / (double)frequency.QuadPart;

// マイクロ秒が欲しければこんな？。数が大きいと溢れそうなので double 経由の方がいいのかも
LONGLONG usec = (span * 1000000L) / frequency.QuadPart;
*/

/**
 * コンストラクタ
 */
reversi::PerformanceCounter::PerformanceCounter() {
}

/**
 * デストラクタ
 */
reversi::PerformanceCounter::~PerformanceCounter() {
}

/**
 * 計測開始
 */
void reversi::PerformanceCounter::Start() {
	// タイマー周波数の取得
	QueryPerformanceFrequency(&frequency);
	// 計測開始
	QueryPerformanceCounter(&start);
}

/**
 * 計測終了
 */
void reversi::PerformanceCounter::End() {
	// 計測開始
	QueryPerformanceCounter(&end);
}

/**
 * 差分取得(ミリ秒)
 * @return StartとEndの時間差分
 */
double reversi::PerformanceCounter::GetDiff() {
	LONGLONG timeDiff = end.QuadPart - start.QuadPart;
	// 差分をdouble型に変換
	double doubleDiff = (double)timeDiff;
	// ミリ秒
	doubleDiff = ((doubleDiff * 1000) / (double)frequency.QuadPart);
	return doubleDiff;
}
