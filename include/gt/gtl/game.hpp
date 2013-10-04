#ifndef __GT_GTL_GAME_HPP__
#define __GT_GTL_GAME_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Game.
 *
 * @author Mateusz Kubuszok
 */
class Game : public virtual Object {
public:
    /**
     * @brief Search pure Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr pureEquilibrium(
        const Context&    context,
        const Conditions& conditions
    );

    /**
     * @brief Search mixed Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr mixedEquilibrium(
        const Context&    context,
        const Conditions& conditions
    );

    /**
     * @brief Returns Message about Game.
     *
     * @return Game's state
     */
    virtual Message toString();
}; /* END class Game */

////////////////////////////////////////////////////////////////////////////////

class NullGame : public Game {
public:
    virtual ResultPtr pureEquilibrium(
        const Context&    context,
        const Conditions& conditions
    ) {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr mixedEquilibrium(
        const Context&    context,
        const Conditions& conditions
    ) {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullGame");
    }
}; /* END class NullGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_HPP__ */
