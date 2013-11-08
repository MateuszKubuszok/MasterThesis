#ifndef __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__
#define __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Common base class of all actual implemetations used in Model.
 *
 * <p>Implements ResultBuilder interface.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ResultBuilder
 */
class AbstractResultBuilder : public ResultBuilder {
public:
    /**
     * @brief Constructor initiating class with indentation.
     *
     * @param indentation sequence used for indentation
     */
    explicit AbstractResultBuilder(
        Message indentation
    );

    /**
     * @brief Sets headers used for displaying records.
     *
     * <p>Size of headers must match size of each record.</p>
     *
     * @param   propertiesNames headers' names that will be used in a Result
     * @return                  refernce to self for chaining
     *
     * @see #addRecord(IdentifierPtr&,MessagesPtr&)
     */
    virtual ResultBuilder& setHeaders(
        IdentifiersPtr& propertiesNames
    ) override;

    /**
     * @brief Adds record to displayed Result.
     *
     * <p>Results size must match headers size.</p>
     *
     * @param name             name of added record
     * @param propertiesValues properties that should be displayed
     * @return                 refernce to self for chaining
     *
     * @see #setHeaders(IdentifiersPtr&)
     */
    virtual ResultBuilder& addRecord(
        IdentifierPtr& name,
        MessagesPtr&   propertiesValues
    ) override;

    /**
     * @brief Adds single named subresult.
     *
     * @param name   name subresult is build
     * @param result subresult
     * @result       reference for itself for chaining
     */
    virtual ResultBuilder& addResult(
        IdentifierPtr& name,
        MessagePtr&    result
    ) override;

    /**
     * @brief Build Result.
     *
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages of any Object does not match properties' one
     *
     * @see #buildRaw()
     */
    virtual ResultPtr build() = 0;

    /**
     * @brief Build raw Result - one that can be inserted into other results.
     *
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages of any Object does not match properties' one
     *
     * @see #build()
     */
    virtual ResultPtr buildRaw() = 0;

    /**
     * Displays what would be build or error message that would be thrown.
     *
     * @return current result or error message
     *
     * @see #build()
     */
    virtual Message toString() override;

protected:
    /**
     * @brief Type containing name-properties pair.
     */
    typedef std::pair<IdentifierPtr, MessagesPtr>   PartialResult;
    /**
     * @brief Type containing name to properties mapping.
     */
    typedef boost::container::vector<PartialResult> PartialResults;
    /**
     * @brief Type containing name-subresult pair.
     */
    typedef std::pair<IdentifierPtr, MessagePtr>    SubResult;
    /**
     * @brief Type containing name to subresult mapping.
     */
    typedef boost::container::vector<SubResult>     SubResults;

    /**
     * @brief Names of properties.
     */
    IdentifiersPtr propertiesNames;
    /**
     * @brief Values of declared properties.
     */
    PartialResults partialResults;
    /**
     * @brief SubResults.
     */
    SubResults     subResults;
    /**
     * @brief Indent used.
     */
    Message        indent;

    /**
     * @brief Check whether all records has the same size as headers.
     *
     * @throw IllegalInnerState thrown when some record does not match headers size
     */
    void checkPropertyToResultMatching();

    /**
     * @brief Adds indent to the beginning of each line of passes content.
     *
     * @param content content that should be indented
     * @return        indented content
     */
    Message addIndent(
        Message content
    );
}; /* END class AbstractResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__ */
