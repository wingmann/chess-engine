#include "pieces/base/movable_piece.h"

MovablePiece::MovablePiece(const PieceColor& color) : Piece{color}
{
}

Coords MovablePiece::getPieceProtectingKingCoords() const
{
    return pieceProtectingKingCoords_;
}

void MovablePiece::setPieceProtectingKingCoords(const Coords& coords)
{
    pieceProtectingKingCoords_ = coords;
}



