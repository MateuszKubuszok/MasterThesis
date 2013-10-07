#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class PlayerStrategiesProperty {
// public:

PlayerStrategiesProperty::PlayerStrategiesProperty(
    Player* describedPlayer
) :
    player(describedPlayer)
    {}

ResultPtr PlayerStrategiesProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) {
    IdentifierPtr strategiesName  = createIdentifierPtr("Strategies");

    IdentifierPtr name  = createIdentifierPtr("Strategy");
    ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();
    BOOST_FOREACH(IdentifierPtr& strategy, *player->getStrategies()) {
        MessagePtr value = createMessagePtr(strategy);
        subResultBuilder->addResult(name, value);
    }
    MessagePtr strategiesValue = createMessagePtr(subResultBuilder->buildRaw()->getResult());

    return ResultFactory::getInstance().buildResult()->addResult(strategiesName, strategiesValue).build();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */