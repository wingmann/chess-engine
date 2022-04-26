#ifndef WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_COORDS_H
#define WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_COORDS_H

class Coords {
    int row_{};
    int column_{};

public:
    Coords() = default;
    Coords(int row, int column);
    virtual ~Coords() = default;

public:
    /**
     *
     * @return
     */
    [[nodiscard]] int getRow() const;

    /**
     *
     * @return
     */
    [[nodiscard]] int getColumn() const;
};

#endif // WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_COORDS_H
