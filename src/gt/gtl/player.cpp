#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Player {
// public:

Player::Player(
    const IdentifierPtr  playerName,
    const IdentifiersPtr playerStrategies
) :
    Object(createIdentifier("Player")),
    Model::Player(playerName, playerStrategies)
{
    registerProperty(createIdentifier("name"),       ObjectPropertyPtr(new PlayerNameProperty(this)));
    registerProperty(createIdentifier("strategies"), ObjectPropertyPtr(new PlayerStrategiesProperty(this)));
}

GT::Message Player::toString() {
    return Model::Player::toString();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */