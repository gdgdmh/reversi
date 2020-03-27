#ifndef REVERSI_UTIL_IOUTPUTCONSOLE_H_
#define REVERSI_UTIL_IOUTPUTCONSOLE_H_

#include <string>

namespace reversi {

	// �R���\�[���o�͂̃C���^�[�t�F�[�X�N���X
	class IOutputConsole {
	public:

		/**
		 * �f�X�g���N�^
		 */
		virtual ~IOutputConsole() {}

		/**
		 * ��������o�͂���
		 */
		virtual void Print(std::string string) = 0;

		/**
		 * ���s�t����������o�͂���
		 */
		virtual void PrintLine(std::string string) = 0;
	};
}

#endif  // REVERSI_UTIL_IOUTPUTCONSOLE_H_

