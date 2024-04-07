#include "pch.h"
#include "MapNoiseGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NoiseGeneratorClass
{
    TEST_CLASS(GenerateMapTests)
    {
    private:
        wchar_t* UncorrectValueMessage(int x, int y, int value) {
            std::string mes =
                "Unexcepted value at (" +
                std::to_string(x) + ", " +
                std::to_string(y) + ") val: " +
                std::to_string(value);
            return ts::charToWChar(mes.c_str());
        }

    public:
        BEGIN_TEST_METHOD_ATTRIBUTE(WorkCase_One)
            TEST_PRIORITY(0)
        END_TEST_METHOD_ATTRIBUTE()
        TEST_METHOD(WorkCase_One)
        {
            mng::MapNoiseGenInfo mapInfo;
            mapInfo.Height = 5;
            mapInfo.Width = 5;
            mapInfo.MinValue = 0;
            mapInfo.MaxValue = 10;

            mng::MapNoiseGen generator(mapInfo);
            
            mng::MapNoise map = generator.generate();
            
            Assert::AreEqual(mapInfo.Height, map.getHeight());
            Assert::AreEqual(mapInfo.Width, map.getWidth());

            for (int y = 0; y < mapInfo.Height; ++y) {
                for (int x = 0; x < mapInfo.Width; ++x) {
                    int val = map.getValueAt(x, y);
                    

                    
                    Assert::IsTrue(val > mapInfo.MinValue, UncorrectValueMessage(x, y, val));
                    Assert::IsTrue(val < mapInfo.MaxValue, UncorrectValueMessage(x, y, val));
                }
            }
            
        }

    };
}

