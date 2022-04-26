#ifndef WINGMANN_CHESS_ENGINE_PIECES_BISHOP_H
#define WINGMANN_CHESS_ENGINE_PIECES_BISHOP_H

#include "base/movable_piece.h"

class Bishop : public MovablePiece {
public:
    Bishop() = delete;
    explicit Bishop(const PieceColor& color);
    ~Bishop() override = default;

public:
    /**
     * Updates possible moves based on check condition.
     * @param condition
     * @param check
     * @param coords
     */
    void updatePossibleMoves(Condition condition, bool check, Coords coords) override;

    /**
     * Updates possible attacks based on check condition.
     * @param condition
     * @param coords
     */
    void updatePossibleAttacks(Condition condition, Coords coords) override;
};

#endif // WINGMANN_CHESS_ENGINE_PIECES_BISHOP_H
