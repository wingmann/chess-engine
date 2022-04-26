#ifndef WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_SETTINGS_H
#define WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_SETTINGS_H

class Settings {
    // Player is white?
    bool whiteIsPlayer_{true};

    // Player is black?
    bool blackIsPlayer_{true};

    // Difficulty of Emulator playing white.
    int whiteDifficulty_{2};

    // Difficulty of Emulator playing black.
    int blackDifficulty_{2};

    // Minimal time (in seconds) of Emulator turn calculation.
    float calculationMinTime_{3.0f};

    // Whether new game request was confirmed.
    bool isNewGame_{true};

public:
    Settings() = default;

    Settings(
        bool whiteIsPlayer,
        bool blackIsPlayer,
        int whiteDifficulty,
        int blackDifficulty,
        float calculationMinTime,
        bool isNewGame);

    virtual ~Settings() = default;

public:
    [[nodiscard]] bool getWhiteIsPlayer() const;
    void setWhiteIsPlayer(bool value);

    [[nodiscard]] bool getBlackIsPlayer() const;
    void setBlackIsPlayer(bool value);

    [[nodiscard]] int getWhiteDifficulty() const;
    void setWhiteDifficulty(int value);

    [[nodiscard]] int getBlackDifficulty() const;
    void setBlackDifficulty(int value);

    [[nodiscard]] float getCalculationMinTime() const;
    void setCalculationMinTime(float value);

    [[nodiscard]] bool getIsNewGame() const;
    void setIsNewGame(bool value);
};

#endif // WINGMANN_CHESS_ENGINE_UTILITY_COMPONENTS_SETTINGS_H
