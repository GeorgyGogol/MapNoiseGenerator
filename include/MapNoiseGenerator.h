#pragma once

#include "framework.h"
#include "MapNoiseGenInfo.h"
#include "MapNoise.h"

namespace mng {

    class DLL_EXPORT MapNoiseGen
    {
    public:
        MapNoiseGen(MapNoiseGenInfo& mapInfo);

    private:
        int Height, Width;

        MapNoise& genWithSeed(int seed);
        MapNoise& genFullRandom();

    public:
        int MinValue = 0;
        int MaxValue = 100;

        MapNoise& generate(int seed = -1);

    };

}

