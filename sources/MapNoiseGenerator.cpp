#include "MapNoiseGenerator.h"
#include <random>
#include <ctime>

mng::MapNoiseGen::MapNoiseGen(MapNoiseGenInfo& mapInfo)
{
    Height = mapInfo.Height;
    Width = mapInfo.Width;
    MinValue = mapInfo.MinValue;
    MaxValue = mapInfo.MaxValue;
}

mng::MapNoise& mng::MapNoiseGen::genWithSeed(int seed)
{
    using namespace std;

    srand(seed);
    MapNoise* out = new MapNoise(Height, Width);

    const int maxRand = MaxValue + MinValue;
    for (int i = 0; i < Height * Width; ++i) {
        out->Data[i] = rand() % maxRand - MinValue;
    }

    return *out;
}

mng::MapNoise& mng::MapNoiseGen::genFullRandom()
{
    using namespace std;

    srand(time(0));
    MapNoise* out = new MapNoise(Height, Width);

    const int maxRand = MaxValue + MinValue;
    for (int i = 0; i < Height * Width; ++i) {
        out->Data[i] = rand() % maxRand - MinValue;
    }

    return *out;
}

mng::MapNoise& mng::MapNoiseGen::generate(int seed)
{
    if (seed > 0)
        return genWithSeed(seed);
    else
        return genFullRandom();
}
