#include "pch.h"
#include "MapNoise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapNoiseTests
{
    void CreatePtr(int Width, int Height) {
        mng::MapNoise* o = new mng::MapNoise(Width, Height);
        Assert::IsNotNull(o, L"Object must be created");
        Assert::AreEqual(Width, o->getWidth(), L"In the created object (ptr), the Width does not match the required one");
        Assert::AreEqual(Height, o->getHeight(), L"In the created object (ptr), the Height does not match the required one");
        delete o;
    }

    void CreateRef(int Width, int Height) {
        mng::MapNoise o(Width, Height);
        Assert::AreEqual(Width, o.getWidth(), L"In the created object (ref), the Width does not match the required one");
        Assert::AreEqual(Height, o.getHeight(), L"In the created object (ref), the Height does not match the required one");
    }

    TEST_CLASS(MapNoise_Create)
    {
    public:
        BEGIN_TEST_METHOD_ATTRIBUTE(Ptr_Base)
            TEST_PRIORITY(0)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(Ptr_Base)
        {
            CreatePtr(10, 10);
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(Ptr_Large)
            TEST_PRIORITY(1)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(Ptr_Large)
        {
            CreatePtr(100, 100);
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(Ptr_VerySmall)
            TEST_PRIORITY(1)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(Ptr_VerySmall)
        {
            for (int i = 5; i > 0; --i) {
                CreatePtr(i, i);
            }
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(Ptr_Uncorrect)
            TEST_PRIORITY(1)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(Ptr_Uncorrect)
        {
            Assert::ExpectException<std::range_error>([]() {CreatePtr(0, 0); }, L"Some error neeeded");
            Assert::ExpectException<std::range_error>([]() {CreatePtr(0, 1); }, L"Some error neeeded");
            Assert::ExpectException<std::range_error>([]() {CreatePtr(1, 0); }, L"Some error neeeded");

            Assert::ExpectException<std::range_error>([]() {CreatePtr(-1, -1); }, L"Some error neeeded");
            Assert::ExpectException<std::range_error>([]() {CreatePtr(-1, 0); }, L"Some error neeeded");
            Assert::ExpectException<std::range_error>([]() {CreatePtr(0, -1); }, L"Some error neeeded");
        }

        BEGIN_TEST_METHOD_ATTRIBUTE(Ref_Base)
            TEST_PRIORITY(0)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(Ref_Base) {
            CreateRef(5, 5);
        }

    };
}

