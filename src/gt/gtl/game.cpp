#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Game : public Object {
// public:

Game::Game(
    const Model::GamePtr gameImplementation
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
    const Context&    context,
    const Conditions& conditions
) const {
    Routines::RoutinePtr routine =
        Routines::RoutineFactory::getInstance().pureStrategyEquilibriumFindingRoutineFor(game);

    Routines::ConditionsPtr routineConditions(new Routines::Conditions());
    for (const ConditionPtr& condition : conditions)
        routineConditions->push_back(condition->getCondition(context));

    return routine->findResultFor(game, routineConditions);
}

ResultPtr Game::mixedEquilibrium(
    const Context&    context,
    const Conditions& conditions
) const {
    Routines::RoutinePtr routine =
        Routines::RoutineFactory::getInstance().mixedStrategyEquilibriumFindingRoutineFor(game);

    Routines::ConditionsPtr routineConditions(new Routines::Conditions());
    for (const ConditionPtr& condition : conditions)
        routineConditions->push_back(condition->getCondition(context));

    return routine->findResultFor(game, routineConditions);
}

ResultPtr Game::behaviorEquilibrium(
    const Context&    context,
    const Conditions& conditions
) const {
    Routines::RoutinePtr routine =
        Routines::RoutineFactory::getInstance().behaviourStrategyEquilibriumFindingRoutineFor(game);

    Routines::ConditionsPtr routineConditions(new Routines::Conditions());
    for (const ConditionPtr& condition : conditions)
        routineConditions->push_back(condition->getCondition(context));

    return routine->findResultFor(game, routineConditions);
}

Message Game::toString() const {
    return game->toString();
}

Game::operator const Game&() const {
    return *this;
}

// }; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
