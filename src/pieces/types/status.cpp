#include "pieces/types/status.h"

Status::Status(Type status) : status_{status}
{
}

Status::Status(Token token)
{
    switch (token) {
    case Token::Empty:
        status_ = Type::Empty;
        break;
    case Token::EnPassant:
        status_ = Type::EnPassant;
        break;
    case Token::King:
        status_ = Type::King;
        break;
    case Token::Queen:
        status_ = Type::Queen;
        break;
    case Token::Rook:
        status_ = Type::Rook;
        break;
    case Token::Bishop:
        status_ = Type::Bishop;
        break;
    case Token::Knight:
        status_ = Type::Knight;
        break;
    case Token::Pawn:
        status_ = Type::Pawn;
        break;
    }
}

Status::Status(char symbol)
{
    switch (symbol) {
    case static_cast<char>(Token::EnPassant):
        status_ = Type::EnPassant;
        break;
    case static_cast<char>(Token::King):
        status_ = Type::King;
        break;
    case static_cast<char>(Token::Queen):
        status_ = Type::Queen;
        break;
    case static_cast<char>(Token::Rook):
        status_ = Type::Rook;
        break;
    case static_cast<char>(Token::Bishop):
        status_ = Type::Bishop;
        break;
    case static_cast<char>(Token::Knight):
        status_ = Type::Knight;
        break;
    case static_cast<char>(Token::Pawn):
        status_ = Type::Pawn;
        break;
    default:
        status_ = Type::Empty;
        break;
    }
}

Status::Type Status::getType() const
{
    return status_;
}

std::string Status::toString() const
{
    switch (status_) {
    case Type::Empty:
        return {"Empty"};
    case Type::EnPassant:
        return {"EnPassant"};
    case Type::King:
        return {"King"};
    case Type::Queen:
        return {"Queen"};
    case Type::Rook:
        return {"Rook"};
    case Type::Bishop:
        return {"Bishop"};
    case Type::Knight:
        return {"Knight"};
    case Type::Pawn:
        return {"Pawn"};
    }
}

char Status::toChar() const
{
    switch (status_) {
    case Type::Empty:
        return static_cast<char>(Token::Empty);
    case Type::EnPassant:
        return static_cast<char>(Token::EnPassant);
    case Type::King:
        return static_cast<char>(Token::King);
    case Type::Queen:
        return static_cast<char>(Token::Queen);
    case Type::Rook:
        return static_cast<char>(Token::Rook);
    case Type::Bishop:
        return static_cast<char>(Token::Bishop);
    case Type::Knight:
        return static_cast<char>(Token::Knight);
    case Type::Pawn:
        return static_cast<char>(Token::Pawn);
    }
}
