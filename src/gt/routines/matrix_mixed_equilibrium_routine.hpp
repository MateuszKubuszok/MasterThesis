#ifndef GT_ROUTINES_MATRIX_MIXED_EQUILIBRIUM_ROUTINE_HPP_INCLUDED
#define GT_ROUTINES_MATRIX_MIXED_EQUILIBRIUM_ROUTINE_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/matrix_mixed_equilibrium_routine.hpp
 * @brief     Defines GT::Routines::MatrixMixedEquilibriumRoutine class.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class MatrixMixedEquilibriumRoutine
 * @brief Routune returning mixed strategy equilibrium for 0-sum Strategic Game with 2 Players.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class MatrixMixedEquilibriumRoutine final : public Routine {
public:
    /**
     * @brief Returns mixed strategy equilibrium for Strategic Game with 2 Players when game is 0-sum type.
     *
     * Routine uses linear programming to solve the problem. It's a typical 0-sum strategic game solution
     * where primal solution is `(distribution of Player 2 strategies ) * cost function value` and
     * dual solution is `(distribution of Player 1 strategies ) * cost function value`.
     *
     * @param game             Game definition
     * @param conditions       Conditions for this Routine
     * @return                 Result for fiven Game and Conditions
     * @throw InvalidCondition thrown when some Condition is invalid or when Conditions application leads to
     *                         an invalid RoutineConfig or no result
     * @throw InvalidGameType  thrown when Game's type doesn't match Routine's one
     */
    virtual ResultPtr findResultFor(
        const GamePtr       game,
        const ConditionsPtr conditions
    ) const override;

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString() const override;

private:
    /**
     * @brief Initializes GLPK's problem (LPProblem structure) with variables declarations.
     *
     * @param  players Players used to initialize problem
     * @return         initalized problem
     */
    LPProblemPtr initializeProblem(
        const Players& players
    ) const;

    /**
     * @brief Fills ProblemPtr instance with values.
     *
     * @param problem         instance of a LPProblem that needs to have its values filled
     * @param data            contains data with Payoff values
     * @param positionsHelper helper used to calculate positions in StrategicDataAccessor
     */
    void fillUpProblem(
        LPProblem*                          problem,
        const StrategicDataAccessor&        data,
        const StrategicGamePositionsHelper& positionsHelper
    ) const;

    /**
     * @brief Returns solution for the passed Problem.
     *
     * @param problem         instance of a LPProblem to solve
     * @param data            contains data with Payoff values
     * @param positionsHelper helper used to calculate positions in StrategicDataAccessor
     * @return                resuls
     */
    ResultPtr solveProblem(
        LPProblem*                          problem,
        const StrategicDataAccessor&        data,
        const StrategicGamePositionsHelper& positionsHelper
    ) const;
}; /* END class MatrixMixedEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef GT_ROUTINES_MATRIX_MIXED_EQUILIBRIUM_ROUTINE_HPP_INCLUDED */
