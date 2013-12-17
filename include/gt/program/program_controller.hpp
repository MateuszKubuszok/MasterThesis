#ifndef __GT_PROGRAM_PROGRAM_CONTROLLER_HPP__
#define __GT_PROGRAM_PROGRAM_CONTROLLER_HPP__

namespace GT {
namespace Program {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Sets up Parser and runs it.
 *
 * @author Mateusz Kubuszok
 *
 * @see GTL::Parser
 */
class ProgramController final {
    /**
     * @brief Debug level - if its different to 0 parser messages are shown.
     */
    int            debugLevel;
    /**
     * @brief Whether ExcutionDriver should be used instead of CheckingDriver.
     */
    bool           shouldExecute;

    /**
     * @brief Pointer to input stream.
     */
    InputStream*   inputStream;
    /**
     * @brief Pointer to output stream.
     */
    OutputStream*  outputStream;
    /**
     * @brief Pointer to error stream.
     */
    OutputStream*  errorStream;

    /**
     * @brief Whether input stream is interactive (read from std input).
     */
    bool isInteractiveInput;

    /**
     * @brief Whether input stream need to be released after usage.
     */
    bool shouldFreeInputStream;
    /**
     * @brief Whether output stream need to be released after usage.
     */
    bool shouldFreeOutputStream;
    /**
     * @brief Whether error stream need to be released after usage.
     */
    bool shouldFreeErrorStream;

    /**
     * @brief Contains current Builder Mode setting.
     */
    Model::ResultBuilderMode     resultBuilderMode;

     /**
     * @brief Contains current Indentation Mode setting.
     */
    Model::ResultIndentationMode resultIndentationMode;

public:
    /**
     * @brief Initiates controller with default settings.
     *
     * <p>By default stream are set to standard ones (without freeing), debug level is set to 0 and driver
     * executes input.</p>
     */
    ProgramController();

    /**
     * @brief Default destructor - frees resources if necessary.
     */
    virtual ~ProgramController();

    /**
     * @brief Sets used driver to Checking Driver.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setCheckingOnly();

    /**
     * @brief Sets used driver to Execution Driver.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setCheckingAndExecution();

    /**
     * @brief Sets debug level.
     *
     * @param debugLevel new debug level
     * @return           reference to itself for chaining
     */
    ProgramController& setDebugLevel(
        int debugLevel
    );

    /**
     * @brief Sets used input stream to standard input stream.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setDefaultInputStream();

    /**
     * @brief Sets used input stream to file input stream.
     *
     * @param filename name of file to read
     * @return         reference to itself for chaining
     */
    ProgramController& setInputStream(
        const std::string filename
    );

    /**
     * @brief Sets used input stream to given input stream.
     *
     * @param inputStream   name of new input stream
     * @param shouldBeFreed whether resource should be freed after usage
     * @param isInteractive whether input should be treated as interactive
     * @return              reference to itself for chaining
     */
    ProgramController& setInputStream(
        InputStream* inputStream,
        bool         shouldBeFreed,
        bool         isInteractive
    );

    /**
     * @brief Sets used output stream to standard output stream.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setDefaultOutputStream();

    /**
     * @brief Sets used output stream to file output stream.
     *
     * @param filename name of file to write
     * @return         reference to itself for chaining
     */
    ProgramController& setOutputStream(
        const std::string filename
    );

    /**
     * @brief Sets used output stream to given output stream.
     *
     * @param outputStream  name of new output stream
     * @param shouldBeFreed whether resource should be freed after usage
     * @return              reference to itself for chaining
     */
    ProgramController& setOutputStream(
        OutputStream* outputStream,
        bool          shouldBeFreed
    );

    /**
     * @brief Sets used error stream to standard error stream.
     *
     * @return reference to itself for chaining
     */
    ProgramController& setDefaultErrorStream();

    /**
     * @brief Sets used error stream to file output stream.
     *
     * @param filename name of file to write
     * @return         reference to itself for chaining
     */
    ProgramController& setErrorStream(
        const std::string filename
    );

    /**
     * @brief Sets used error stream to given error stream.
     *
     * @param errorStream   name of new error stream
     * @param shouldBeFreed whether resource should be freed after usage
     * @return              reference to itself for chaining
     */
    ProgramController& setErrorStream(
        OutputStream* errorStream,
        bool          shouldBeFreed
    );

    /**
     * @brief Defines type of returned result (output).
     *
     * @param resultBuilderMode new builder mode
     * @return                  reference to itself for chaining
     */
    ProgramController& setResultBuilderMode(
        const Model::ResultBuilderMode resultBuilderMode
    );

    /**
     * @brief Defines type of used indentation (output).
     *
     * @param resultIndentationMode new indentation mode
     * @return                      reference to itself for chaining
     */
    ProgramController& setResultIndentationMode(
        const Model::ResultIndentationMode resultIndentationMode
    );

    /**
     * @brief Executes Parser as a program.
     *
     * @return 0 of no error occurred, number of errors otherwise
     */
    int run() const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Program */
} /* END namespace GT */

#endif /* #ifndef __GT_PROGRAM_PROGRAM_CONTROLLER_HPP__ */
