#ifndef WINGMANN_CHESS_ENGINE_CONDITIONS_CONDITION_H
#define WINGMANN_CHESS_ENGINE_CONDITIONS_CONDITION_H

#include "pieces/types/piece_id.h"
#include "utility_components/coords.h"

#include <list>
#include <string>

class Condition {
    PieceId chessBoard_[8][8];
    int draw50_{};
    Coords kingCoords_{};
    bool whiteOnTurn_{};
    bool whiteKingMoved_{};
    bool whiteSmallRookMoved_{};
    bool whiteLargeRookMoved_{};
    bool blackKingMoved_{};
    bool blackSmallRookMoved_{};
    bool blackLargeRookMoved_{};

public:
    Condition();
    Condition(const Condition& condition);

public:
    [[nodiscard]] PieceId getFromChessBoard(int row, int column) const;
    void setToChessBoard(int row, int column, PieceId value);

    [[nodiscard]] int getDraw50() const;
    void setDraw50(int value);

    [[nodiscard]] Coords getKingCoords() const;

    [[nodiscard]] bool getWhiteOnTurn() const;
    void setWhiteOnTurn(bool value);

    [[nodiscard]] bool getWhiteKingMoved() const;
    void setWhiteKingMoved(bool value);

    [[nodiscard]] bool getWhiteSmallRookMoved() const;
    void setWhiteSmallRookMoved(bool value);

    [[nodiscard]] bool getWhiteLargeRookMoved() const;
    void setWhiteLargeRookMoved(bool value);

    [[nodiscard]] bool getBlackKingMoved() const;
    void setBlackKingMoved(bool value);

    [[nodiscard]] bool getBlackSmallRookMoved() const;
    void setBlackSmallRookMoved(bool value);

    [[nodiscard]] bool getBlackLargeRookMoved() const;
    void setBlackLargeRookMoved(bool value);

    std::string toString();
};

#endif // WINGMANN_CHESS_ENGINE_CONDITIONS_CONDITION_H
