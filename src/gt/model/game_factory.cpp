#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class GameFactory {

SINGLETON_DEFINITION(GameFactory, getInstance, gameFactoryMutex)

// public:

GameBuilderPtr GameFactory::buildStrategicGame() const {
    return GameBuilderPtr(new StrategicGameBuilder());
}

GameBuilderPtr GameFactory::buildExtensiveGame() const {
    return GameBuilderPtr(new ExtensiveGameBuilder());
}

// private:

GameFactory::GameFactory() {}

GameFactory::~GameFactory() {}

// }; /* END class GameFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
