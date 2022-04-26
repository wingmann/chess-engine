#include "pieces/types/piece_color.h"

PieceColor::PieceColor(PieceColor::Type color) : color_{color}
{
}

PieceColor::PieceColor(PieceColor::Token token)
{
    switch (token) {
    case Token::None:
        color_ = Type::None;
        break;
    case Token::White:
        color_ = Type::White;
        break;
    case Token::Black:
        color_ = Type::Black;
        break;
    }
}

PieceColor::Type PieceColor::getType() const
{
    return color_;
}

std::string PieceColor::toString() const
{
    switch (color_) {
    case Type::None:
        return {"None"};
        break;
    case Type::White:
        return {"White"};
        break;
    case Type::Black:
        return {"Black"};
        break;
    }
}

char PieceColor::toChar() const
{
    switch (color_) {
    case Type::None:
        return static_cast<char>(Token::None);
    case Type::White:
        return static_cast<char>(Token::White);
    case Type::Black:
        return static_cast<char>(Token::Black);
    }
}
