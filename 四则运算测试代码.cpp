#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int problemCount = 10; //��ʽ����
			int maxNumber = 100;  //�����
			int operandCount = 2;  //���Ӹ���
			int operation = 1;  //�û�����������
			int hasBracket = 0; //�Ƿ�������
			int isFloat = 0;  //�Ƿ���С��
			int outputType = 0;//�����ʽ
			char operators[4] = { '+','-','*','/' }; //�����

		};
		TEST_METHOD(TestMethod2)
		{
			int problemCount = 10; //��ʽ����
			int maxNumber = 100;  //�����
			int operandCount = 3;  //���Ӹ���
			int operation = 2;  //�û�����������
			int hasBracket = 1; //�Ƿ�������
			int isFloat = 0;  //�Ƿ���С��
			int outputType = 0;//�����ʽ
			char operators[4] = { '+','-','*','/' }; //�����

		}
		TEST_METHOD(TestMethod3)
		{
			int problemCount = 10; //��ʽ����
			int maxNumber = 100;  //�����
			int operandCount = 4;  //���Ӹ���
			int operation = 3;  //�û�����������
			int hasBracket = 1; //�Ƿ�������
			int isFloat = 0;  //�Ƿ���С��
			int outputType = 0;//�����ʽ
			char operators[4] = { '+','-','*','/' }; //�����

		};
		TEST_METHOD(TestMethod4)
		{
			int problemCount = 10; //��ʽ����
			int maxNumber = 100;  //�����
			int operandCount = 3;  //���Ӹ���
			int operation = 4;  //�û�����������
			int hasBracket = 1; //�Ƿ�������
			int isFloat = 0;  //�Ƿ���С��
			int outputType = 0;//�����ʽ
			char operators[4] = { '+','-','*','/' }; //�����
		}
	};
}