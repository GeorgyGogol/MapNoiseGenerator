#include "pch.h"
#include "MapNoise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapNoiseTests
{
    TEST_CLASS(ClassFunctions)
    {
    public:
        BEGIN_TEST_METHOD_ATTRIBUTE(getValueAt_Correct)
            TEST_PRIORITY(3)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(getValueAt_Correct)
        {
            mng::MapNoise map(5, 5);
            map.getValueAt(3, 3);
            map.getValueAt(0, 0);

            Assert::ExpectException<std::range_error>([&]() {map.getValueAt(10, 10); }, L"Some error neeeded");
            Assert::ExpectException<std::range_error>([&]() {map.getValueAt(-1, 0); }, L"Some error neeeded");
            Assert::ExpectException<std::range_error>([&]() {map.getValueAt(0, -12); }, L"Some error neeeded");
        }

    };

}

