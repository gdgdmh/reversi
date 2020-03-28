#ifndef REVERSI_UTIL_METHODTRANSITION_H_
#define REVERSI_UTIL_METHODTRANSITION_H_

namespace reversi {

// クラス内メソッド遷移クラス
template<typename T>
class MethodTransition {
public:
	/**
	 * コンストラクタ
	 * @param execute_method 最初に実行するメソッドポインタ
	 */
	MethodTransition(MethodTransition<T>(T::*execute_method)()) : method(execute_method) {
	};

	/**
	 * デストラクタ
	 */
	virtual ~MethodTransition() {
	}

	/**
	 * シーン実行
	 * @param  object 実行するクラスのthisポインタ
	 * @return        メソッド遷移クラス
	 */
	MethodTransition<T> Execute(T* object) {
		return (object->*scene)();
	}

private:
	// 実行するクラスのメソッドポインタ
	MethodTransition<T> (T::*method)();
};

}

#endif  // REVERSI_UTIL_METHODTRANSITION_H_
