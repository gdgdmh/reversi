#ifndef REVERSI_TEST_UNITTEST_H_
#define REVERSI_TEST_UNITTEST_H_

namespace reversi {

	// �P�̃e�X�g�N���X
	class UnitTest {
	public:
		/**
		 * �R���X�g���N�^
		 */
		UnitTest();

		/**
		 * �f�X�g���N�^
		 */
		virtual ~UnitTest();

		/**
		 * �P�̃e�X�g�����s����
		 */
		void Execute();
	};

}

#endif  // REVERSI_TEST_UNITTEST_H_
