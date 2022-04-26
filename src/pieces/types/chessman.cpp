#include "pieces/types/chessman.h"

Chessman::Chessman(Chessman::Type chessman) : chessman_{chessman}
{
}

std::string Chessman::toString() const
{
    switch (chessman_) {
    case Type::PawnWhite:
        return {"Pawn White"};
    case Type::PawnBlack:
        return {"Pawn Black"};
    case Type::KnightWhite:
        return {"Knight White"};
    case Type::KnightBlack:
        return {"Knight Black"};
    case Type::BishopWhite:
        return {"Bishop White"};
    case Type::BishopBlack:
        return {"Bishop Black"};
    case Type::RookWhite:
        return {"Rook White"};
    case Type::RookBlack:
        return {"Rook Black"};
    case Type::QueenWhite:
        return {"Queen White"};
    case Type::QueenBlack:
        return {"Queen Black"};
    case Type::KingWhite:
        return {"Queen White"};
    case Type::KingBlack:
        return {"Queen Black"};
    }
}
