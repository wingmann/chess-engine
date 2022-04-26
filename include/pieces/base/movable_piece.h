#ifndef WINGMANN_CHESS_ENGINE_PIECES_BASE_MOVABLE_PIECE_H
#define WINGMANN_CHESS_ENGINE_PIECES_BASE_MOVABLE_PIECE_H

#include "piece.h"

/**
 *
 */
class MovablePiece : public Piece {
    Coords pieceProtectingKingCoords_;

public:
    MovablePiece() = delete;

protected:
    explicit MovablePiece(const PieceColor& color);
    ~MovablePiece() override = default;

public:
    [[nodiscard]] Coords getPieceProtectingKingCoords() const;
    void setPieceProtectingKingCoords(const Coords& coords);
};

#endif // WINGMANN_CHESS_ENGINE_PIECES_BASE_MOVABLE_PIECE_H
