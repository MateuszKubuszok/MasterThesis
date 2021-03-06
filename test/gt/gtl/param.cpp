#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Param )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ParamTestImpl : public GT::GTL::Param {
public:
    virtual const GT::GTL::ObjectPtr getObject(
        const GT::GTL::Context&,
        GT::GTL::Param::VisitedIdentifiers&
    ) const override {
        return GT::GTL::NullFactory::getInstance().createObject();
    }

    virtual const GT::NumberPtr getNumber(
        const GT::GTL::Context&,
        GT::GTL::Param::VisitedIdentifiers&
    ) const override {
        return GT::Model::NullFactory::getInstance().createNumber();
    }
}; /* END class ParaTestImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Param_respondsTo ) {
    // given
    GT::Identifier properties = GT::createIdentifier("properties");
    GT::Identifier type       = GT::createIdentifier("type");
    GT::Identifier value      = GT::createIdentifier("value");
    GT::Identifier error      = GT::createIdentifier("error");

    // when
    ParamTestImpl param;

    // then
    BOOST_CHECK(  param.respondsTo(properties) );
    BOOST_CHECK(  param.respondsTo(type) );
    BOOST_CHECK(  param.respondsTo(value) );
    BOOST_CHECK( !param.respondsTo(error) );
}

BOOST_AUTO_TEST_CASE( Param_Param ) {
    // given
    // when
    ParamTestImpl         param;
    const GT::GTL::Param& paramRef = param;

    // then
    BOOST_CHECK_EQUAL(
        param,
        paramRef
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
