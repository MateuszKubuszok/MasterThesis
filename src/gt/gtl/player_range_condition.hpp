#ifndef GT_GTL_PLAYER_RANGE_CONDITION_HPP_INCLUDED
#define GT_GTL_PLAYER_RANGE_CONDITION_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/player_range_condition.hpp
 * @brief     Defines GT::GTL::PlayerRangeCondition class.
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
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class PlayerRangeCondition
 * @brief Condition used for selecting strategies for a Player.
 *
 * @author Mateusz Kubuszok
 */
class PlayerRangeCondition final : public Condition {
    /**
     * @brief Param with Player's name.
     */
    const ObjectPtr  player;
    /**
     * @brief Param with Player's strategies.
     */
    const ObjectsPtr strategies;

public:
    /**
     * @brief Initiates Condition with a Player's name and choice.
     *
     * @param player     Param with Player's name
     * @param strategies Param with Player's strategies
     */
    PlayerRangeCondition(
        const ObjectPtr  player,
        const ObjectsPtr strategies
    );

    /**
     * @brief Returns Condition applicable to Routine.
     *
     * @param context     Context
     * @return            Condition applicable to Routine
     * @throw InvalidType thrown when either player or strategy are not IdentifierParams
     */
    virtual Routines::ConditionPtr getCondition(
        const Context& context
    ) const override;

    /**
     * @brief Returns Message about Condition.
     *
     * @return Condition's Message
     */
    virtual Message toString() const override;
}; /* END class PlayerRangeCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_PLAYER_RANGE_CONDITION_HPP_INCLUDED */
