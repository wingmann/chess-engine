#include "pieces/base/piece.h"

#include <utility>

Piece::Piece(const PieceColor& color) : pieceColor_{std::make_shared<PieceColor>(color)}
{
}

std::shared_ptr<PieceColor> Piece::getPieceColor() const
{
    return pieceColor_;
}

bool Piece::getProtectingKing() const
{
    return protectingKing_;
}

void Piece::setProtectingKing(bool value)
{
    protectingKing_ = value;
}

std::shared_ptr<std::vector<Coords>> Piece::getPossibleMoves() const
{
    return possibleMoves_;
}

std::shared_ptr<std::vector<Coords>> Piece::getPossibleAttacks() const
{
    return possibleAttacks_;
}

void Piece::setPossibleMoves(std::shared_ptr<std::vector<Coords>> value)
{
    possibleMoves_ = std::move(value);
}

void Piece::setPossibleAttacks(std::shared_ptr<std::vector<Coords>> value)
{
    possibleAttacks_ = std::move(value);
}
