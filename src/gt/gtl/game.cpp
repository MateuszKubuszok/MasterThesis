#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Game : public Object {
// public:

Game::Game(
    Model::GamePtr gameImplementation
) :
    Object(createIdentifier("Game")),
    game(gameImplementation)
{
    registerProperty(
        Identifier("pure_equilibrium"),     ObjectPropertyPtr(new GamePureEquilibriumProperty(this))
    );
    registerProperty(
        Identifier("mixed_equilibrium"),    ObjectPropertyPtr(new GameMixedEquilibriumProperty(this))
    );
    registerProperty(
        Identifier("behavior_equilibrium"), ObjectPropertyPtr(new GameBehaviorEquilibriumProperty(this))
    );
}

ResultPtr Game::pureEquilibrium(
    const Context&,
    const Conditions&
) {
    return ResultFactory::getInstance().constResult("Not yet implemented");
}

ResultPtr Game::mixedEquilibrium(
    const Context&,
    const Conditions&
) {
    return ResultFactory::getInstance().constResult("Not yet implemented");
}

ResultPtr Game::behaviorEquilibrium(
    const Context&,
    const Conditions&
) {
    return ResultFactory::getInstance().constResult("Not yet implemented");
}

Message Game::toString() {
    return game->toString();
}

Game::operator Game&() {
    return *this;
}

// }; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
