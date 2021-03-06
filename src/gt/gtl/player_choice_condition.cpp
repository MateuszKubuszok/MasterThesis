/**
 * @file      gt/gtl/player_choice_condition.cpp
 * @brief     Defines GT::GTL::PlayerChoiceCondition methods.
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

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::stringstream;

using boost::dynamic_pointer_cast;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerChoiceCondition final : public Condition {
// public:

PlayerChoiceCondition::PlayerChoiceCondition(
    const ObjectPtr definedPlayer,
    const ObjectPtr definedStrategy
) :
    player(definedPlayer),
    strategy(definedStrategy)
    {}

Routines::ConditionPtr PlayerChoiceCondition::getCondition(
    const Context& context
) const {
    return Routines::ConditionFactory::getInstance().createPlayerChoiceCondition(
        createIdentifierPtr(getIdentifier(context, player)),
        createIdentifierPtr(getIdentifier(context, strategy))
    );
}

Message PlayerChoiceCondition::toString() const {
    static const IdentifierPtr playerName = createIdentifierPtr("Player");
    static const IdentifierPtr chosenName = createIdentifierPtr("Chosen");

    Message result = ResultFactory::getInstance().buildResult()
        ->addResult(playerName, createMessagePtr(player->toString()))
         .addResult(chosenName, createMessagePtr(strategy->toString()))
         .build()->getResult();

    static const IdentifierPtr name  = createIdentifierPtr("Condition");
    MessagePtr                 value = createMessagePtr(result);

    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
