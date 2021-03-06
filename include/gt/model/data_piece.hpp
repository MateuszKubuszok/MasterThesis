#ifndef GT_MODEL_DATA_PIECE_HPP_INCLUDED
#define GT_MODEL_DATA_PIECE_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/data_piece.hpp
 * @brief     Defines GT::Model::DataPiece interface.
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
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class DataPiece
 * @brief Interface for accessing Data coordinates for better access to values.
 *
 * @author Mateusz Kubuszok
 */
class DataPiece : public virtual Root {
public:
    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when Player name is not known
     */
    virtual const NumberPtr& getPayoff(
        const Identifier& playerName
    ) const = 0;

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when Player name is not known
     */
    const NumberPtr& getPayoff(
        const IdentifierPtr playerName
    ) const;

    /**
     * @brief Returns whether this Data piece is 0-sum one.
     *
     * DataPiece is 0-sum if it's defined for 2 Players with 1 Payoff (first Player's one) or if sum of
     * Payoffs is equal to 0.
     *
     * @return true if it is 0-sum data piece
     */
    virtual bool is0Sum() const = 0;

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when Player name is not known
     */
    const NumberPtr& operator[](
        const Identifier& playerName
    ) const;

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when Player name is not known
     */
    const NumberPtr& operator[](
        const IdentifierPtr playerName
    ) const;

    /**
     * @brief Returns DataPiece's message.
     *
     * @return Message
     */
    virtual Message toString() const = 0;
}; /* END class DataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullDataPiece
 * @brief Null DataPiece for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataPiece final : public DataPiece {
    /**
     * @brief Null Number to return.
     */
    const NumberPtr nullNumber;

public:
    NullDataPiece() :
        nullNumber(NullFactory::getInstance().createNumber())
        {}

    virtual const NumberPtr& getPayoff(
        const Identifier&
    ) const override {
        return nullNumber;
    }

    virtual bool is0Sum() const override {
        return false;
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullDataPiece");
    }
}; /* END class NullDataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_DATA_PIECE_HPP_INCLUDED */
