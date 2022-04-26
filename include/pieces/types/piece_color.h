#ifndef WINGMANN_CHESS_ENGINE_PIECES_TYPES_PIECE_COLOR_H
#define WINGMANN_CHESS_ENGINE_PIECES_TYPES_PIECE_COLOR_H

#include <string>

/**
 *
 */
class PieceColor {
public:
    /**
     *
     */
    enum class Type {
        None,
        White,
        Black
    };

    /**
     *
     */
    enum class Token : char {
        None = '0',
        White = 'w',
        Black = 'b'
    };

private:
    Type color_{Type::None};

public:
    PieceColor() = default;
    explicit PieceColor(Type color);
    explicit PieceColor(Token token);
    virtual ~PieceColor() = default;

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

#endif // WINGMANN_CHESS_ENGINE_PIECES_TYPES_PIECE_COLOR_H
