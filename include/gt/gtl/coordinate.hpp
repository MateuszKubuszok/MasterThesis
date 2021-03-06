#ifndef GT_GTL_COORDINATE_HPP_INCLUDED
#define GT_GTL_COORDINATE_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/coordinate.hpp
 * @brief     Defines GT::GTL::Coordinate class.
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

using Model::DataBuilderPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Coordinate
 * @brief Contains some Coordinate as well as data bound to it.
 *
 * They can be considered pieces from which sets of pure strategies will be built. For strategic-form games it
 * means putting together all player-strategy pairs as to create whole vector for payoff function. For
 * extensive-form games it means going from root to leafs, one node at a time.
 *
 * Example of piece of code recognized by Parser:
 *
 * @code
   {
      p1 = p1s1 :
      { p2 = p2s1 : 10, 20 },
      { p2 = p2s2 : 30, 40 }
   },
   {
      p1 = p1s2 :
      { p2 = p2s1 : 50, 60 },
      { p2 = p2s2 : 70, 80 }
   }
   @endcode
 *
 * @author Mateusz Kubuszok
 *
 * @see CoordinateDriver
 * @see Parser
 */
class Coordinate : public virtual ValidableSymbol {

    /**
     * @brief Defined Positions.
     */
    const PositionsPtr positions;

    /**
     * @brief Defined Params.
     */
    const ParamsPtr params;

    /**
     * @brief Defined subCoordinetes.
     */
    const CoordinatesPtr subCoordinates;

public:
    /**
     * @brief Default constructor.
     */
    Coordinate();

    /**
     * @brief Constructor for initial strategies.
     *
     * @param player   player   identifier
     * @param strategy strategy identifier
     */
    Coordinate(
        const IdentifierPtr player,
        const IdentifierPtr strategy
    );

    /**
     * @brief Adds Param to the list.
     *
     * @param param single Param
     * @return      reference to itself
     */
    virtual Coordinate& addParam(
        const ParamPtr param
    );

     /**
     * @brief Adds Params to the list.
     *
     * @param params Params' vector
     * @return       reference to itself
     */
    virtual Coordinate& addParams(
        const ParamsPtr params
    );

    /**
     * @brief Add Position to known Coordinates.
     *
     * @param player   player (dimension)
     * @param strategy strategy (position on dimension)
     * @return         reference to itself
     */
    virtual Coordinate& addPosition(
        const IdentifierPtr player,
        const IdentifierPtr strategy
    );

    /**
     * @brief Adds SubCoordinate.
     *
     * @param subCoordinate SubCoordinate
     * @return              reference to itself
     */
    virtual Coordinate& addSubCoordinate(
        const CoordinatePtr subCoordinate
    );

    /**
     * @brief Adds SubCoordinates.
     *
     * @param subCoordinates SubCoordinate
     * @return               reference to itself
     */
    virtual Coordinate& addSubCoordinates(
        const CoordinatesPtr subCoordinates
    );

    /**
     * @brief Obtains Params.
     *
     * @return Params
     */
    virtual const ParamsPtr getParams() const;

     /**
     * @brief Obtains Positions.
     *
     * @return Positions
     */
    virtual const PositionsPtr getPositions() const;

    /**
     * @brief Obtain SubCoordinates.
     *
     * @return SubCoordinates
     */
    virtual const CoordinatesPtr getSubCoordinates() const;

    /**
     * @brief Fill DataBuilder with its data.
     *
     * @param context               Context with params
     * @param dataBuilder           DataBuilder to fill
     * @throw CyclicIdentifiers     thrown when some Identfiers create the cycle
     * @throw InvalidContentRequest thrown when some Param does not contain Number
     * @throw NotDefinedParam       thrown when some Param cannot find value inside Context
     * @throw IllegalInnerState     thrown when some of positions are already set
     * @throw InvalidCoordinate     thrown when some of values are not valid strategies names
     * @throw IllegalInnerState     thrown when attempting to set params when
     *                              not all coordinates are known
     */
    virtual void fillDataBuilder(
        const Context&  context,
        DataBuilderPtr& dataBuilder
    ) const;

    /**
     * @brief Returns serialized Message for a Coordinate.
     *
     * @return serialization result
     */
    virtual Message serialize() const override;

    /**
     * @brief Returns Coordinate Message
     *
     * @return Message
     */
    virtual Message toString() const override;

    /**
     * @brief Merges two Coordinates into one.
     *
     * @param coordinate1 first Coordinate
     * @param coordinate2 second Coordinate
     * @return            merged Coordinates
     */
    friend Coordinate operator+(
        const Coordinate& coordinate1,
        const Coordinate& coordinate2
    );
}; /* END class Coordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullCoordinate
 * @brief Null Coordinate for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCoordinate final : public Coordinate {
public:
    virtual Coordinate& addParam(
        const ParamPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addParams(
        const ParamsPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addPosition(
        const IdentifierPtr,
        const IdentifierPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addSubCoordinate(
        const CoordinatePtr
    ) override {
        return *this;
    }

    virtual Coordinate& addSubCoordinates(
        const CoordinatesPtr
    ) override {
        return *this;
    }

    virtual const ParamsPtr getParams() const override {
        return NullFactory::getInstance().createParams();
    }

    virtual const PositionsPtr getPositions() const override {
        return NullFactory::getInstance().createPositions();
    }

    virtual const CoordinatesPtr getSubCoordinates() const override {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual void fillDataBuilder(
        const Context&,
        DataBuilderPtr&
    ) const {}

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullCoordinate");
    }
}; /* END class NullCoordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ErrorCoordinate
 * @brief Error Coordinate for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorCoordinate final : public Coordinate {
    /**
     * @brief Error message.
     */
    Message message;

public:
    ErrorCoordinate(
        Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual Coordinate& addParam(
        const ParamPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addParams(
        const ParamsPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addPosition(
        const IdentifierPtr,
        const IdentifierPtr
    ) override {
        return *this;
    }

    virtual Coordinate& addSubCoordinate(
        const CoordinatePtr
    ) override {
        return *this;
    }

    virtual Coordinate& addSubCoordinates(
        const CoordinatesPtr
    ) override {
        return *this;
    }

    virtual const ParamsPtr getParams() const override {
        return NullFactory::getInstance().createParams();
    }

    virtual const PositionsPtr getPositions() const override {
        return NullFactory::getInstance().createPositions();
    }

    virtual const CoordinatesPtr getSubCoordinates() const override {
        return NullFactory::getInstance().createCoordinates();
    }

    virtual void fillDataBuilder(
        const Context&,
        DataBuilderPtr&
    ) const {}

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorCoordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_COORDINATE_HPP_INCLUDED */
