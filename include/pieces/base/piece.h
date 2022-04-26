#ifndef WINGMANN_CHESS_ENGINE_PIECES_BASE_PIECE_H
#define WINGMANN_CHESS_ENGINE_PIECES_BASE_PIECE_H

#include "conditions/condition.h"
#include "types/piece_color.h"
#include "utility_components/coords.h"

#include <vector>
#include <memory>

/**
 *
 */
class Piece {
    std::shared_ptr<PieceColor> pieceColor_;
    bool protectingKing_{};

protected:
    std::shared_ptr<std::vector<Coords>> possibleMoves_;
    std::shared_ptr<std::vector<Coords>> possibleAttacks_;

public:
    Piece() = delete;

protected:
    explicit Piece(const PieceColor& color);
    virtual ~Piece() = default;

public:
    [[nodiscard]] std::shared_ptr<PieceColor> getPieceColor() const;

    [[nodiscard]] bool getProtectingKing() const;
    void setProtectingKing(bool value);

    [[nodiscard]] std::shared_ptr<std::vector<Coords>> getPossibleMoves() const;
    [[nodiscard]] std::shared_ptr<std::vector<Coords>> getPossibleAttacks() const;

protected:
    void setPossibleMoves(std::shared_ptr<std::vector<Coords>> value);
    void setPossibleAttacks(std::shared_ptr<std::vector<Coords>> value);

public:
    /**
     * Updates possible moves based on check condition.
     * @param condition
     * @param check
     * @param coords
     */
    virtual void updatePossibleMoves(Condition condition, bool check, Coords coords) = 0;

    /**
     * Updates possible attacks based on check condition.
     * @param condition
     * @param coords
     */
    virtual void updatePossibleAttacks(Condition condition, Coords coords) = 0;
};

#endif // WINGMANN_CHESS_ENGINE_PIECES_BASE_PIECE_H
