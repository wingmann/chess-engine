#include "utility_components/coords.h"

Coords::Coords(int row, int column)
{
    row_ = row;
    column_ = column;
}

int Coords::getRow() const
{
    return row_;
}

int Coords::getColumn() const
{
    return column_;
}
