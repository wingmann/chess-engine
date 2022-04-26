#ifndef WINGMANN_CHESS_ENGINE_PIECES_TYPES_CHESSMAN_TYPE_H
#define WINGMANN_CHESS_ENGINE_PIECES_TYPES_CHESSMAN_TYPE_H

#include <string>

/**
 *
 */
class Chessman {
public:
    /**
     *
     */
    enum class Type {
        PawnWhite,
        PawnBlack,
        KnightWhite,
        KnightBlack,
        BishopWhite,
        BishopBlack,
        RookWhite,
        RookBlack,
        QueenWhite,
        QueenBlack,
        KingWhite,
        KingBlack
    };

private:
    Type chessman_;

public:
    Chessman() = delete;
    explicit Chessman(Type chessman);
    virtual ~Chessman() = default;

public:
    /**
     *
     * @return
     */
    [[nodiscard]] std::string toString() const;
};


#endif // WINGMANN_CHESS_ENGINE_PIECES_TYPES_CHESSMAN_TYPE_H
