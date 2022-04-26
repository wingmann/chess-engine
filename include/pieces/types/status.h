#ifndef WINGMANN_CHESS_ENGINE_PIECES_TYPES_STATUS_H
#define WINGMANN_CHESS_ENGINE_PIECES_TYPES_STATUS_H

#include <string>

/**
 *
 */
class Status {
public:
    /**
     *
     */
    enum class Type {
        Empty,
        EnPassant,
        King,
        Queen,
        Rook,
        Bishop,
        Knight,
        Pawn
    };

    /**
     *
     */
    enum class Token : char {
        Empty = '[',
        EnPassant = 'e',
        King = 'K',
        Queen = 'Q',
        Rook = 'R',
        Bishop = 'B',
        Knight = 'N',
        Pawn = 'P'
    };

private:
    Type status_{Type::Empty};

public:
    Status() = default;
    explicit Status(Status::Type status);
    explicit Status(Status::Token token);
    explicit Status(char symbol);
    virtual ~Status() = default;

public:
    /**
     *
     * @return
     */
    [[nodiscard]] Type getType() const;

public:
    /**
     *
     * @return
     */
    [[nodiscard]] std::string toString() const;

    /**
     *
     * @return
     */
    [[nodiscard]] char toChar() const;
};

#endif // WINGMANN_CHESS_ENGINE_PIECES_TYPES_STATUS_H
