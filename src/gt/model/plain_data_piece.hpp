#ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__
#define __GT_MODEL_PLAIN_DATA_PIECE_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used to store values at lowest level.
 *
 * <p>Implements DataPiece interface.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see DataPiece
 * @see Data
 * @see DataAccessor
 */
class PlainDataPiece : public DataPiece {
    /**
     * @brief PositionsHelper used to properly locate Index in storage.
     */
    PositionsHelper positionsHelper;
    /**
     * @brief Values of payoff.
     */
    NumbersPtr      numbers;

public:
    /**
     * @brief Constructor initiated with Players and params definitions.
     *
     * @param players Players definitions
     * @param params  params definitions
     */
    PlainDataPiece(
        PlayersPtr players,
        NumbersPtr params
    );

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    virtual NumberPtr& getValue(
        Identifier& playerName
    ) override;

    /**
     * @brief Returns PlainDataPiece's message.
     *
     * @return message
     */
    virtual Message toString() override;
}; /* END class PlainDataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__ */
