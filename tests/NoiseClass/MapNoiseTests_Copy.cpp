#include "pch.h"
#include "MapNoise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapNoiseGeneratorLibTest
{
    BEGIN_TEST_CLASS_ATTRIBUTE()
        TEST_PRIORITY(1)
    END_TEST_CLASS_ATTRIBUTE()
    TEST_CLASS(MapNoiseTests_Copy)
    {
        TEST_METHOD(Base) {
            mng::MapNoise origin(5, 15);
            mng::MapNoise map(origin);

            Assert::AreEqual(origin.getHeight(), map.getHeight(), L"Height must be equal");
            Assert::AreEqual(origin.getWidth(), map.getWidth(), L"Width must be equal");
        }

        TEST_METHOD(Equal)
        {
            mng::MapNoise origin(15, 5);
            mng::MapNoise map = origin;

            Assert::AreEqual(origin.getHeight(), map.getHeight(), L"Height must be equal");
            Assert::AreEqual(origin.getWidth(), map.getWidth(), L"Width must be equal");
        }

        TEST_METHOD(Move) {
            auto SomeCreateMethod = [](int W, int H) { return std::move(mng::MapNoise(W, H)); };

            mng::MapNoise map1 = SomeCreateMethod(4, 6);
            Assert::AreEqual(4, map1.getHeight(), L"Height not moved correctly");
            Assert::AreEqual(6, map1.getWidth(), L"Width not moved correctly");
        }

    };
}

