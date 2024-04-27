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
			int problemCount = 10; //算式数量
			int maxNumber = 100;  //最大数
			int operandCount = 2;  //因子个数
			int operation = 1;  //用户输入的运算符
			int hasBracket = 0; //是否有括号
			int isFloat = 0;  //是否有小数
			int outputType = 0;//输出形式
			char operators[4] = { '+','-','*','/' }; //运算符

		};
		TEST_METHOD(TestMethod2)
		{
			int problemCount = 10; //算式数量
			int maxNumber = 100;  //最大数
			int operandCount = 3;  //因子个数
			int operation = 2;  //用户输入的运算符
			int hasBracket = 1; //是否有括号
			int isFloat = 0;  //是否有小数
			int outputType = 0;//输出形式
			char operators[4] = { '+','-','*','/' }; //运算符

		}
		TEST_METHOD(TestMethod3)
		{
			int problemCount = 10; //算式数量
			int maxNumber = 100;  //最大数
			int operandCount = 4;  //因子个数
			int operation = 3;  //用户输入的运算符
			int hasBracket = 1; //是否有括号
			int isFloat = 0;  //是否有小数
			int outputType = 0;//输出形式
			char operators[4] = { '+','-','*','/' }; //运算符

		};
		TEST_METHOD(TestMethod4)
		{
			int problemCount = 10; //算式数量
			int maxNumber = 100;  //最大数
			int operandCount = 3;  //因子个数
			int operation = 4;  //用户输入的运算符
			int hasBracket = 1; //是否有括号
			int isFloat = 0;  //是否有小数
			int outputType = 0;//输出形式
			char operators[4] = { '+','-','*','/' }; //运算符
		}
	};
}