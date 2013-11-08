#ifndef __GT_GTL_CHECKING_DRIVER_HPP__
#define __GT_GTL_CHECKING_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for executing only checking actions.
 *
 * <p>Performs only syntax/type checking on input stream.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Driver
 */
class CheckingDriver : public Driver {
    /**
     * @brief Driver for Coordinates.
     */
    CheckingCoordinateDriver               coordinate;
    /**
     * @brief Driver for Coordinates' collections.
     */
    CollectionsDriver<GT::GTL::Coordinate> coordinates;
    /**
     * @brief Driver for Conditions.
     */
    CheckingConditionDriver                condition;
    /**
     * @brief Driver for Conditions' collections.
     */
    CollectionsDriver<GT::GTL::Condition>  conditions;
    /**
     * @brief Driver for Games.
     */
    CheckingGameDriver                     game;
    /**
     * @brief Driver for Identifiers' collections.
     */
    CollectionsDriver<GT::Identifier>      identifiers;
    /**
     * @brief Driver for Objects' collections.
     */
    CollectionsDriver<GT::GTL::Object>     objects;
    /**
     * @brief Driver for Params' collections.
     */
    CollectionsDriver<GT::GTL::Param>      params;
    /**
     * @brief Driver for values.
     */
    CheckingValueDriver                    value;
    /**
     * @brief Driver for statements.
     */
    CheckingStatementDriver                statement;

    /**
     * @brief Error stream for displaying informations about errors.
     */
    std::ostream*                          errorStream;

public:
    /**
     * @brief Initiates CheckingDriver with a output stream.
     *
     * @param errorStream error stream
     */
    explicit CheckingDriver(
        std::ostream* errorStream
    );

    /**
     * @brief Destructor.
     */
    virtual ~CheckingDriver();

    /**
     * @brief Driver for Coordinate.
     *
     * @return CoordinateDriver
     */
    virtual CoordinateDriver& forCoordinate() override;

    /**
     * @brief Driver for Coordinates.
     *
     * @return CollectionDriver for Coordinates
     */
    virtual CollectionsDriver<Coordinate>& forCoordinates() override;

    /**
     * @brief Driver for Condition.
     *
     * @return ConditionDriver
     */
    virtual ConditionDriver& forCondition() override;

    /**
     * @brief Driver for Conditions.
     *
     * @return CollectionDriver for Conditions
     */
    virtual CollectionsDriver<Condition>& forConditions() override;

    /**
     * @brief Driver for Game.
     *
     * @return GameDriver
     */
    virtual GameDriver& forGame() override;

    /**
     * @brief Driver for Identifiers.
     *
     * @return CollectionDriver for Identifiers
     */
    virtual CollectionsDriver<Identifier>& forIdentifiers() override;

    /**
     * @brief Driver for Objects.
     *
     * @return CollectionDriver for Objects
     */
    virtual CollectionsDriver<Object>& forObjects() override;

    /**
     * @brief Driver for Params.
     *
     * @return CollectionDriver for Params
     */
    virtual CollectionsDriver<Param>& forParams() override;

    /**
     * @brief Driver for value.
     *
     * @return ValueDriver
     */
    virtual ValueDriver& forValue() override;

    /**
     * @brief Driver for Statement.
     *
     * @return StatementDriver
     */
    virtual StatementDriver& forStatement() override;

    /**
     * @brief Displays results.
     *
     * @param result Result to show
     */
    virtual void showResult(
        ResultPtr result
    ) override;

    /**
     * @brief Displays error.
     *
     * @param location error's location
     * @param message  Message to display
     */
    virtual void showError(
        InputLocation& location,
        const Message& message
    ) override;

    /**
     * @brief Displays error.
     *
     * @param symbol invalid symbol to display
     */
    virtual void showError(
        ValidableSymbol& symbol
    ) override;

    /**
     * @brief Driver's Message.
     *
     * @return message
     */
    virtual Message toString() override;
}; /* END class CheckingDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_DRIVER_HPP__ */
