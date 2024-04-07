#include "pch.h"
#include "MapNoise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapNoiseTests
{
    TEST_CLASS(MapNoiseTests_Copy)
    {
    public:
        BEGIN_TEST_METHOD_ATTRIBUTE(Base)
            TEST_PRIORITY(0)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(Base) {
            mng::MapNoise origin(5, 15);
            mng::MapNoise map(origin);

            Assert::AreEqual(origin.getHeight(), map.getHeight(), L"Height must be equal");
            Assert::AreEqual(origin.getWidth(), map.getWidth(), L"Width must be equal");
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(EqualOperand)
            TEST_PRIORITY(0)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(EqualOperand)
        {
            mng::MapNoise origin(15, 5);
            mng::MapNoise map = origin;

            Assert::AreEqual(origin.getHeight(), map.getHeight(), L"Height must be equal");
            Assert::AreEqual(origin.getWidth(), map.getWidth(), L"Width must be equal");
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(Move)
            TEST_PRIORITY(0)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(Move) {
            auto SomeCreateMethod = [](int W, int H) { return std::move(mng::MapNoise(W, H)); };

            mng::MapNoise map1 = SomeCreateMethod(4, 6);
            Assert::AreEqual(4, map1.getHeight(), L"Height not moved correctly");
            Assert::AreEqual(6, map1.getWidth(), L"Width not moved correctly");
        }

    };
}

