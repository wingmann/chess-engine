#ifndef WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_HALF_TURN_H
#define WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_HALF_TURN_H

#include "coords.h"

class HalfTurn {
    Coords from_{};
    Coords to_{};
    int value_{};

public:
    HalfTurn() = default;
    HalfTurn(const Coords& from, const Coords& to);
    virtual ~HalfTurn() = default;

public:
    /**
     * Get From coords.
     * @return
     */
    [[nodiscard]] Coords getFrom() const;

    /**
     * Get To coords.
     * @return
     */
    [[nodiscard]] Coords getTo() const;

    /**
     * Get value.
     * @return
     */
    [[nodiscard]] int getValue() const;

    /**
     * Set only on initialization.
     * @param value
     */
    void setValue_(int value);
};

#endif // WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_HALF_TURN_H
