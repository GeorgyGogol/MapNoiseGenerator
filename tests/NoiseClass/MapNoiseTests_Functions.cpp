#include "pch.h"
#include "MapNoise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapNoiseGeneratorLibTest
{
    BEGIN_TEST_CLASS_ATTRIBUTE()
        TEST_PRIORITY(2)
    END_TEST_CLASS_ATTRIBUTE()
    TEST_CLASS(MapNoiseTests_Functions)
    {
    public:
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

