#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Query )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Query_execute ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back( GT::createIdentifierPtr("properties") );
    properties->push_back( GT::createIdentifierPtr("type") );

    GT::GTL::ObjectsPtr objects(new GT::GTL::Objects());
    objects->push_back( GT::GTL::ObjectPtr(new GT::GTL::Object()) );
    objects->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ParamFactory::getInstance().createParam(GT::createIdentifierPtr("Name"))
    ) );

    GT::GTL::ConditionsPtr conditions(new GT::GTL::Conditions());

    GT::GTL::Context context;

    // when
    GT::GTL::Query query(properties, objects, conditions);

    // then
    BOOST_CHECK_EQUAL(
        query.execute(context)->getResult(),
        GT::Message() +
        "properties:\n"
        "\t1:\n"
        "\t\t\t\tKnown Properties,\n"
        "\t\tProperty:\n"
        "\t\t\t\tproperties,\n"
        "\t\tProperty:\n"
        "\t\t\t\ttype,\n"
        "\t2:\n"
        "\t\t\t\tKnown Properties,\n"
        "\t\tProperty:\n"
        "\t\t\t\tproperties,\n"
        "\t\tProperty:\n"
        "\t\t\t\ttype,\n"
        "\t\tProperty:\n"
        "\t\t\t\tvalue,\n"
        "type:\n"
        "\t1:\n"
        "\t\tType:\n"
        "\t\t\tObject\n"
        "\t2:\n"
        "\t\tType:\n"
        "\t\t\tObject\n"
    );
}

BOOST_AUTO_TEST_CASE( Query_toString ) {
    //given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back( GT::createIdentifierPtr("properties") );
    properties->push_back( GT::createIdentifierPtr("type") );

    GT::GTL::ObjectsPtr objects(new GT::GTL::Objects());
    objects->push_back( GT::GTL::ObjectPtr(new GT::GTL::Object()) );
    objects->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ParamFactory::getInstance().createParam(GT::createIdentifierPtr("Name"))
    ) );

    GT::GTL::ConditionsPtr conditions(new GT::GTL::Conditions());

    // when
    GT::GTL::Query query(properties, objects, conditions);

    // then
    BOOST_CHECK_EQUAL(
        query.toString(),
        GT::Message() +
        "\t\tProperties,\n"
        "Property Name:\n"
        "\t\tproperties,\n"
        "Property Name:\n"
        "\t\ttype,\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
