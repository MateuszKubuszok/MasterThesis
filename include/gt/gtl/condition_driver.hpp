#ifndef GT_GTL_CONDITION_DRIVER_HPP_INCLUDED
#define GT_GTL_CONDITION_DRIVER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/condition_driver.hpp
 * @brief     Defines GT::GTL::ConditionDriver interface.
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

/**
 * @class ConditionDriver
 * @brief Used for handling Games via Driver.
 *
 * @author Mateusz Kubuszok
 */
class ConditionDriver : public virtual Root {
public:
    /**
     * @brief Create condition for Player choosing strategy in information set.
     *
     * @param inputLocation input location of a created Condition
     * @param playerPtr         Player's name
     * @param informationSetPtr Player's information set
     * @param strategyPtr       chosen strategy
     * @return                  Condition
     */
    virtual ConditionPtr* informationSetChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     informationSetPtr,
        const ObjectPtr*     strategyPtr
    ) const = 0;

    /**
     * @brief Create condition for Player limiting allowed strategies in information set.
     *
     * @param inputLocation input location of a created Condition
     * @param playerPtr         Player's name
     * @param informationSetPtr Player's information set
     * @param strategiesPtr     allowed strategies
     * @return                  Condition
     */
    virtual ConditionPtr* informationSetWithin(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     informationSetPtr,
        const ObjectsPtr*    strategiesPtr
    ) const = 0;

    /**
     * @brief Create condition for Player choosing strategy.
     *
     * @param inputLocation input location of created Condition
     * @param playerPtr     Player's name
     * @param strategyPtr   chosen strategy
     * @return              Condition
     */
    virtual ConditionPtr* playerChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     strategyPtr
    ) const = 0;

    /**
     * @brief Create condition for Player limiting allowed strategies.
     *
     * @param inputLocation input location of a created Condition
     * @param playerPtr     Player's name
     * @param strategiesPtr allowed strategies
     * @return              Condition
     */
    virtual ConditionPtr* playerWithin(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectsPtr*    strategiesPtr
    ) const = 0;

    /**
     * @brief ConditionDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;
}; /* END class ConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullConditionDriver
 * @brief Null ConditionDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullConditionDriver final : public ConditionDriver {
public:
    NullConditionDriver() :
        Root(),
        ConditionDriver()
        {}

    virtual ConditionPtr* informationSetChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*,
        const ObjectPtr*,
        const ObjectPtr*
    ) const override {
        return new ConditionPtr(
            setupLocation<Condition>(
                NullFactory::getInstance().createCondition(),
                inputLocation
            )
        );
    }

    virtual ConditionPtr* informationSetWithin(
        const InputLocation& inputLocation,
        const ObjectPtr*,
        const ObjectPtr*,
        const ObjectsPtr*
    ) const override {
        return new ConditionPtr(
            setupLocation<Condition>(
                NullFactory::getInstance().createCondition(),
                inputLocation
            )
        );
    }

    virtual ConditionPtr* playerChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*,
        const ObjectPtr*
    ) const override {
        return new ConditionPtr(
            setupLocation<Condition>(
                NullFactory::getInstance().createCondition(),
                inputLocation
            )
        );
    }

    virtual ConditionPtr* playerWithin(
        const InputLocation& inputLocation,
        const ObjectPtr*,
        const ObjectsPtr*
    ) const override {
        return new ConditionPtr(
            setupLocation<Condition>(
                NullFactory::getInstance().createCondition(),
                inputLocation
            )
        );
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullConditionDriver");
    }
}; /* END class NullConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_CONDITION_DRIVER_HPP_INCLUDED */
