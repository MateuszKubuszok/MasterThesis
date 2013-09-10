#include <sstream>
#include <boost/foreach.hpp>
#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

boost::mutex resultFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

class ConstResult : public Result {
    Message result;

public:
    ConstResult(
        const Message& content
    ) :
        result(content)
        {}

    Message getResult() {
        return result;
    }
}; /* END class ConstResult */

////////////////////////////////////////////////////////////////////////////////

class EmptyResult : public Result {
public:
    EmptyResult() {}

    Message getResult() {
        return Message("");
    }
}; /* END class EmptyString */

////////////////////////////////////////////////////////////////////////////////


class AbstractResultBuilder : public ResultBuilder {
public:
    AbstractResultBuilder(Message indentation) :
        properties(),
        partialResults(),
        indent(indentation)
        {}

    virtual ResultBuilder& setHeaders(
        IdentifiersPtr& newProperties
    ) {
        properties = newProperties;
        return *this;
    }

    virtual ResultBuilder& addRecord(
        IdentifierPtr& object,
        MessagesPtr&   results
    ) {
        PartialResult partialResult = std::make_pair(object, results);
        partialResults.push_back(partialResult);
        return *this;
    }

    virtual ResultPtr build() = 0;

    virtual Message toString() {
        return (*build()).getResult();
    }

protected:
    typedef std::pair<IdentifierPtr, MessagesPtr>   PartialResult;
    typedef boost::container::vector<PartialResult> PartialResults;
    
    IdentifiersPtr properties;
    PartialResults partialResults;
    Message        indent;

    void checkPropertyToResultMatching() {
        int propertiesSize = (*properties).size();
        BOOST_FOREACH(PartialResult partialResult, partialResults)
            if ((*partialResult.second).size() != propertiesSize)
                throw std::runtime_error("Properties size and Result\'s size does not match");
    }
}; /* END class AbstractResultBuilder */

////////////////////////////////////////////////////////////////////////////////

class PlainResultBuilder : public AbstractResultBuilder {
    PlainResultBuilder(Message indentation) :
        AbstractResultBuilder(indentation)
        {}

    virtual ResultPtr build() {
        checkPropertyToResultMatching();

        std::stringstream result;
        
        result << indent;
        BOOST_FOREACH(IdentifierPtr property, (*properties))
            result << indent << (*property) << ',';
        result << std::endl;

        BOOST_FOREACH(PartialResult partialResult, partialResults) {
            result << (*partialResult.first) << std::endl << indent;
            BOOST_FOREACH(MessagePtr message, (*partialResult.second))
                result << indent << (*message) << ',';
            result << std::endl;
        }

        return ResultFactory::getInstance().constResult(Message(result.str()));
    }
}; /* END class PlainResultBuilder */

////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {
ResultFactory* volatile ResultFactory::instance = 0;

// public:
ResultFactory& ResultFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(resultFactoryMutex);
        if (!instance) {
            ResultFactory* volatile tmp = new ResultFactory();
            instance = tmp;
        }
    }
    return *instance;
}

ResultPtr ResultFactory::constResult(
    const Message& content
) {
    return ResultPtr(new ConstResult(content));
}

ResultPtr ResultFactory::emptyResult() {
    return ResultPtr(new EmptyResult());
}

ResultBuilderMode ResultFactory::getBuilderMode() {
    return builderMode;
}

ResultFactory& ResultFactory::setBuilderMode(
    ResultBuilderMode newBuilderMode
) {
    builderMode = newBuilderMode;
    return *this;
}

ResultIndentationMode ResultFactory::getIndentationMode() {
    return indentationMode;
}

ResultFactory& ResultFactory::setIndentationMode(
    ResultIndentationMode newIndentationMode
) {
    indentationMode = newIndentationMode;
    return *this;
}

// private:
ResultFactory::ResultFactory() {
    builderMode     = PLAIN;
    indentationMode = TABS;
}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
