#ifndef __GT_GTL_DEFINITION_HPP__
#define __GT_GTL_DEFINITION_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Definition used to define Context. 
 *
 * @author Mateusz Kubuszok
 */
class Definition : public virtual Root {
    /**
     * @brief Name of the property
     */
    const IdentifierPtr name;

    /**
     * @brief Value of the property.
     */
    const ObjectPtr value;

public:
    /**
     * @brief Constructor for name and value.
     *
     * @param definedName  name of the defined property
     * @param definedValue value of the defined property
     */
    Definition(
        IdentifierPtr definedName,
        ObjectPtr     definedValue
    );

    /**
     * @brief Default constructor.
     */
    ~Definition();

    /**
     * @brief Returns name of the property.
     *
     * @return value of the property
     */
    virtual IdentifierPtr getName();

    /**
     * @brief Returns value of the property.
     *
     * @return value of the property
     */
    virtual ObjectPtr getValue();

    /**
     * @brief Returns Message about Definition.
     *
     * @return Definition's Message
     */
    virtual Message toString();
}; /* END class Definition */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Definition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDefinition : public Definition {
public:
    NullDefinition() :
        Definition(
            Model::NullFactory::getInstance().createIdentifier(),
            NullFactory::getInstance().createObject()
        )
        {}

    virtual IdentifierPtr getName() {
        return Model::NullFactory::getInstance().createIdentifier();
    }

    virtual ObjectPtr getValue() {
        return NullFactory::getInstance().createObject();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullDefinition");
    }
}; /* END class NullDefinition */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_DEFINITION_HPP__ */