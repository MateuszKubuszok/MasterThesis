#ifndef __GT_MODEL_PLAYER_HPP__
#define __GT_MODEL_PLAYER_HPP__

#include "gt/model/common.hpp"

namespace GT {
namespace Model {

/**
 * @brief Defines Player.
 *
 * @author Mateusz Kubuszok
 */
class Player {
    /**
     * @breif Player's name.
     */
    const IdentifierPtr name;

    /**
     * @breif Player's strategies.
     */
    const IdentifiersPtr strategies;

    /**
     * @breif Mapps strategies to its ordnial.
     */
    const boost::container::map<std::string, int> strategyMapping;

public:
    /**
     * @brief Constructor of the Player.
     *
     * @param playerName     name of the player
     * @param playerStrategy declared strategies
     */
    Player(
        const IdentifierPtr  playerName,
        const IdentifiersPtr playerStrategies
    );

    /**
     * @brief Returns name ot the Player.
     *
     * @return Player's name
     */
    Identifier getName();

    /**
     * @brief Returns Player's strategies.
     *
     * @return Player's strategies
     */
    Identifiers getStrategies();

    /**
     * @brief Returns number of strategies.
     *
     * @return number of strategies
     */    
    int getStrategiesNumber();

     /**
     * @brief Returns ordinal of a strategy with giben identifier.
     *
     * @return ordinal of strategy with given identifier
     */
    int getStrategyOrdinal(
        const Identifier& strategy
    );
}; /* END class Player */

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_PLAYER_HPP__ */