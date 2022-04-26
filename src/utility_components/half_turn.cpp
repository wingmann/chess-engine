#include "utility_components/half_turn.h"

HalfTurn::HalfTurn(const Coords& from, const Coords& to)
    : from_{from.getRow(), from.getColumn()},
      to_{to.getRow(), to.getColumn()},
      value_{}
{
}

Coords HalfTurn::getFrom() const
{
    return from_;
}

Coords HalfTurn::getTo() const
{
    return to_;
}

int HalfTurn::getValue() const
{
    return value_;
}

void HalfTurn::setValue_(int value)
{
    value_ = value;
}
