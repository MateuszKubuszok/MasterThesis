#ifndef GT_ROUTINES_EXCEPTION_FACTORY_HPP_INCLUDED
#define GT_ROUTINES_EXCEPTION_FACTORY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/exception_factory.hpp
 * @brief     Defines GT::Routines::ExceptionFactory class.
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
 * @class ExceptionFactory
 * @brief Used for creation of exception instances for Routines classes.
 *
 * @author Mateusz Kubuszok
 */
class ExceptionFactory final {
public:
    /**
     * @brief Returns the instance of an ExceptionFactory.
     *
     * @return ExceptionFactory instance
     */
    static ExceptionFactory& getInstance();

    /**
     * @brief Thrown when Condition is invalid for some Routine.
     *
     * @param exception exception to pass
     * @return          InvalidCondition exception to throw
     */
    InvalidCondition invalidCondition(
        const std::exception& exception
    ) const;

    /**
     * @brief Thrown when Conditions create invalid RoutineConfig.
     *
     * @return InvalidCondition exception to throw
     */
    InvalidCondition contradictoryConditions() const;

    /**
     * @brief Thrown when Condition is invalid for some Routine.
     *
     * @param expectedGame expected Game type
     * @return             InvalidGameType exception to throw
     */
    InvalidGameType invalidGameType(
        const Identifier& expectedGame
    ) const;

    /**
     * @brief Thrown when non existing Player is chosen.
     *
     * @param playerName name of sought Player
     * @return           InvalidPlayerChoice exception to throw
     */
    InvalidPlayerChoice playerNotFound(
        const Identifier& playerName
    ) const;

    /**
     * @brief Thrown when non existing information set is chosen.
     *
     * @param playerName     name of Player
     * @param informationSet name of sought information set
     * @return               InvalidPlayerChoice exception to throw
     */
    InvalidPlayerChoice informationSetNotFound(
        const Identifier& playerName,
        const Identifier& informationSet
    ) const;

    /**
     * @brief Thrown when non existing strategy is chosen.
     *
     * @param playerName name of Player
     * @param strategy   name of strategy
     * @return           InvalidPlayerChoice exception to throw
     */
    InvalidPlayerChoice strategyNotFound(
        const Identifier& playerName,
        const Identifier& strategy
    ) const;

    /**
     * @brief Thrown when payoff is not available for some Player's strategy.
     *
     * @param playerName name of Player
     * @param strategy   name of strategy
     * @return           IncompletePayoffInformation exception to throw
     */
    IncompletePayoffInformation incompletePayoffInformation(
        const Identifier& playerName,
        const Identifier& strategy
    ) const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    ExceptionFactory() = default;

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param exceptionFactory object to copy
     */
    ExceptionFactory(
        const ExceptionFactory& exceptionFactory
    ) = delete;

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ExceptionFactory() = default;
}; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef GT_ROUTINES_EXCEPTION_FACTORY_HPP_INCLUDED */
