#ifndef WINGMANN_CHESS_ENGINE_PIECES_TYPES_PIECE_ID_H
#define WINGMANN_CHESS_ENGINE_PIECES_TYPES_PIECE_ID_H

#include "pieces/types/status.h"
#include "pieces/types/piece_color.h"

/**
 *
 */
class PieceId {
    Status status_{};
    PieceColor pieceColor_{};

public:
    PieceId() = default;
    PieceId(const Status& status, const PieceColor& color);
    virtual ~PieceId() = default;

public:
    [[nodiscard]] Status getStatus() const;
    void setStatus(const Status& status);

    [[nodiscard]] PieceColor getPieceColor() const;
    void setPieceColor(const PieceColor& color);
};

#endif // WINGMANN_CHESS_ENGINE_PIECES_TYPES_PIECE_ID_H
