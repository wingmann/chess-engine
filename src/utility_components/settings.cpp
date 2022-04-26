#include "utility_components/settings.h"

Settings::Settings(
    bool whiteIsPlayer,
    bool blackIsPlayer,
    int whiteDifficulty,
    int blackDifficulty,
    float calculationMinTime,
    bool isNewGame)
    : whiteIsPlayer_{whiteIsPlayer},
      blackIsPlayer_{blackIsPlayer},
      whiteDifficulty_{whiteDifficulty},
      blackDifficulty_{blackDifficulty},
      calculationMinTime_{calculationMinTime},
      isNewGame_{isNewGame}
{
}

bool Settings::getWhiteIsPlayer() const
{
    return whiteIsPlayer_;
}

void Settings::setWhiteIsPlayer(bool value)
{
    whiteIsPlayer_ = value;
}

bool Settings::getBlackIsPlayer() const
{
    return blackIsPlayer_;
}

void Settings::setBlackIsPlayer(bool value)
{
    blackIsPlayer_ = value;
}

int Settings::getWhiteDifficulty() const
{
    return whiteDifficulty_;
}

void Settings::setWhiteDifficulty(int value)
{
    whiteDifficulty_ = value;
}

int Settings::getBlackDifficulty() const
{
    return blackDifficulty_;
}

void Settings::setBlackDifficulty(int value)
{
    blackDifficulty_ = value;
}

float Settings::getCalculationMinTime() const
{
    return calculationMinTime_;
}

void Settings::setCalculationMinTime(float value)
{
    calculationMinTime_ = value;
}

bool Settings::getIsNewGame() const
{
    return isNewGame_;
}

void Settings::setIsNewGame(bool value)
{
    isNewGame_ = value;
}
