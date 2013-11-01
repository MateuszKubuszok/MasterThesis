#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingConditionDriver : public ConditionDriver {
// public:

CheckingConditionDriver::CheckingConditionDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

ConditionPtr* CheckingConditionDriver::playerChoosed(
    InputLocation& inputLocation,
    ObjectPtr*     playerPtr,
    ObjectPtr*     strategyPtr
) {
    Object& playerObject   = **playerPtr;
    Object& strategyObject = **strategyPtr;

    if (!playerObject) {
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() +
            "Invalid Object: " + playerObject.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                inputLocation
            )
        );
    }

    Player& player       = playerObject;
    Param&  playerParam  = playerObject;
    if (!player && !playerParam) {
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() + "Object does not define a Player: " + player.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                inputLocation
            )
        );
    }

    Param& strategyParam = strategyObject;
    if (!strategyParam) {
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() +
            "Object does not define a Param with strategy: " + strategyParam.toString();
        return new ConditionPtr(
            setupLocation<Condition>(
                ErrorFactory::getInstance().createCondition(errorMessage),
                inputLocation
            )
        );
    }

    return new ConditionPtr(
        setupLocation<Condition>(
            NullFactory::getInstance().createCondition(),
            inputLocation
        )
    );
}

Message CheckingConditionDriver::toString() {
    return Message("CheckingConditionDriver");
}

// }; /* END class CheckingConditionDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
