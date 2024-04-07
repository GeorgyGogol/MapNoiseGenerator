#include "MapNoise.h"
#include <stdexcept>

mng::MapNoise::MapNoise(int height, int width) noexcept
    : Height(height)
    , Width(width)
{
    Data = new int[Height * Width];
}

mng::MapNoise::MapNoise(const MapNoise& src)
    : Height(src.Height)
    , Width(src.Width)
{
    int size = Height * Width;
    Data = new int[size];
    std::copy(src.Data, src.Data + size, Data);
}

mng::MapNoise::MapNoise(MapNoise&& src) noexcept
    : MapNoise(src.Height, src.Width)
{
    Data = src.Data;
    src.Data = nullptr;
}

mng::MapNoise::~MapNoise()
{
    delete[] Data;
}

mng::MapNoise& mng::MapNoise::operator=(const MapNoise& src)
{
    if (this != &src) {
        delete[] Data;

        Height = src.Height;
        Width = src.Width;

        int size = Height * Width;
        Data = new int[size];
        std::copy(src.Data, src.Data + size, Data);
    }
    return *this;
}

mng::MapNoise& mng::MapNoise::operator=(MapNoise&& src) noexcept
{
    Height = src.Height;
    Width = src.Width;

    if (Data) delete[] Data;
    Data = src.Data;
    src.Data = nullptr;

    return *this;
}

bool mng::MapNoise::isCoordValide(int x, int y) const noexcept
{
    bool xValide = x >= 0 && x < Width;
    bool yValide = y >= 0 && y < Height;
    return xValide && yValide;
}

int mng::MapNoise::getValueAt(int x, int y) const
{
    if (!isCoordValide(x, y)) throw std::range_error("Invalid coordinate");
    return Data[y * Width + x];
}

int mng::MapNoise::getHeight() const
{
    return Height;
}

int mng::MapNoise::getWidth() const
{
    return Width;
}

