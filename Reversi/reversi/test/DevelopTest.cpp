#include "DevelopTest.h"
// test include(�e�X�g������̂͂����ɒǉ�����)
#include "../util/OutputConsole.h"
#include "../test/UnitTest.h"

/**
 * �R���X�g���N�^
 */
reversi::DevelopTest::DevelopTest() {
}

/**
 * �f�X�g���N�^
 */
reversi::DevelopTest::~DevelopTest() {
}

/**
 * ���s
 */
void reversi::DevelopTest::Execute() {

	reversi::IOutputConsole* outputConsole = new reversi::OutputConsole();
	outputConsole->Print("aue");
	outputConsole->PrintLine("���C��");
	outputConsole->Print("123");

	reversi::UnitTest* unitTest = new reversi::UnitTest();
	unitTest->Execute();


}
