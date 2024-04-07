#include "pch.h"
#include "MapNoise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapNoiseGeneratorLibTest
{
    BEGIN_TEST_CLASS_ATTRIBUTE()
        TEST_PRIORITY(1)
    END_TEST_CLASS_ATTRIBUTE()
    TEST_CLASS(MapNoiseGeneratorTests)
    {
    public:
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
                    
                    std::string mes =
                        "At (" +
                        std::to_string(x) + ", " +
                        std::to_string(y) + ") val: " +
                        std::to_string(val);
                    
                    Assert::IsTrue(val > mapInfo.MinValue, charToWChar(mes.c_str()));
                    Assert::IsTrue(val < mapInfo.MaxValue, charToWChar(mes.c_str()));
                }
            }
            
        }

    };
}

