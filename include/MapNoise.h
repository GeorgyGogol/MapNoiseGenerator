#pragma once

#include "framework.h"

namespace mng {

    class MapNoiseGen;

    class DLL_EXPORT MapNoise
    {
    public:
        friend class MapNoiseGen;

    public:
        MapNoise(int height, int width) noexcept;

        MapNoise(const MapNoise&);
        MapNoise(MapNoise&&) noexcept;
        ~MapNoise();

        MapNoise& operator=(const MapNoise&);
        MapNoise& operator=(MapNoise&&) noexcept;

    private:
        int Height, Width;
        int* Data = nullptr;

        bool isCoordValide(int x, int y) const noexcept;

    public:
        int getValueAt(int x, int y) const;
        int getHeight() const;
        int getWidth() const;

    };

}

