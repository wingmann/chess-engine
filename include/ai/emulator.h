#ifndef WINGMANN_CHESS_ENGINE_AI_EMULATOR_H
#define WINGMANN_CHESS_ENGINE_AI_EMULATOR_H

#include "pieces/types/status.h"
#include "utility_components/half_turn.h"
#include "conditions/condition.h"
#include "conditions/calculated_condition.h"

#include <map>
#include <list>

/**
 *
 */
class Emulator {
    static std::map<Status, int> pieceValues_;

public:
    /**
     *
     */
    static bool interruptHalfTurn_;

public:
    /**
     *
     */
    void initialize();

    /**
     *
     * @param calculatedCondition
     * @param condition
     * @param depth
     * @return
     */
    static HalfTurn findBestHalfTurn(
        CalculatedCondition calculatedCondition,
        Condition condition,
        int depth);

private:
    static HalfTurn findBestHalfTurn(QList<HalfTurn> possibleMoves);
    static std::list<HalfTurn> getPossibleHalfTurns(CalculatedCondition calculatedCondition);
    static int getMinimax(CalculatedCondition calculatedCondition, Condition condition, int depth);
    static void evaluate(Condition condition, HalfTurn halfTurn);
};

#endif // WINGMANN_CHESS_ENGINE_AI_EMULATOR_H
