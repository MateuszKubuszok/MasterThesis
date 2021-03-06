#ifndef GT_GTL_LAZY_GAME_PROXY_HPP_INCLUDED
#define GT_GTL_LAZY_GAME_PROXY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/lazy_game_proxy.hpp
 * @brief     Defines GT::GTL::LazyGameProxy class.
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

using Model::DataAccessorPtr;
using Model::GameBuilderPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class LazyGameProxy
 * @brief Makes Game act in functional manner by building it from scratch each time some property is required.
 *
 * @author Mateusz Kubuszok
 *
 * @see Model::Game
 * @see Model::GameBuilder
 * @see Coordinate
 * @see Context
 */
class LazyGameProxy final : public Model::Game {
    /**
     * @brief Actual Game's builder.
     */
    const GameBuilderPtr gameBuilder;
    /**
     * @brief Players.
     */
    const ObjectsPtr     players;
    /**
     * @brief Coordinates to setup data.
     */
    const CoordinatesPtr coordinates;
    /**
     * @brief Context.
     */
    const Context*       context;

public:
    /**
     * @brief Initiates lazy proxy with data required to instantiate Game.
     *
     * @param gameBuilder builder that will create Game
     * @param players     Players definitions
     * @param coordinates Cooridnates with payoff
     * @param context     actual Context
     */
    LazyGameProxy(
        const GameBuilderPtr gameBuilder,
        const ObjectsPtr     players,
        const CoordinatesPtr coordinates,
        const Context*       context
    );

    /**
     * @brief Grants access to Coordinates used to build Game on request.
     *
     * @return Coordinates stored inside proxy
     */
    const CoordinatesPtr getCoordinates() const;

    /**
     * @brief Grants access to Players' Params used to build Game on request.
     *
     * @return Objects stored inside proxy
     */
    const ObjectsPtr getPlayersParams() const;

    /**
     * @brief Returns Game's Players.
     *
     * @return Players
     */
    virtual const Model::PlayersPtr getPlayers() const override;

    /**
     * @brief Grants access to Data specific to a Game.
     *
     * @return DataAccessor returns DataAccessor specific for a Game
     */
    virtual const DataAccessorPtr getData() const override;

    /**
     * @brief Game's Message.
     *
     * @return message
     */
    virtual Message toString() const override;

private:
    /**
     * @brief Create temporary instance of Game.
     *
     * @return Games instance
     */
    const Model::GamePtr accessGame() const;
}; /* END class LazyGameProxy */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_LAZY_GAME_PROXY_HPP_INCLUDED */
