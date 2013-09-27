#ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__
#define __GT_MODEL_PLAIN_DATA_PIECE_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

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
    PositionsHelper positionsHelper;
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
    );

    /**
     * @brief Returns PlainDataPiece's message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class PlainDataPiece */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__ */
