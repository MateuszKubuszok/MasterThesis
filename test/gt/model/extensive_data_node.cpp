#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensiveDataNode )

BOOST_AUTO_TEST_CASE( ExtensiveDataNode_functional ) {
    // given
    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");
    GT::Identifier s1 = GT::createIdentifier("s1");
    GT::Identifier s2 = GT::createIdentifier("s2");

    GT::Positions p11 = GT::createPositions();
    p11.insert( GT::Positions::value_type(l1, s1) );
    p11.insert( GT::Positions::value_type(l2, s1) );
    GT::Positions p12 = GT::createPositions();
    p12.insert( GT::Positions::value_type(l1, s1) );
    p12.insert( GT::Positions::value_type(l2, s2) );
    GT::Positions p21 = GT::createPositions();
    p21.insert( GT::Positions::value_type(l1, s2) );
    p21.insert( GT::Positions::value_type(l2, s1) );
    GT::Positions p22 = GT::createPositions();
    p22.insert( GT::Positions::value_type(l1, s2) );
    p22.insert( GT::Positions::value_type(l2, s2) );

    GT::NumbersPtr payoff11 = GT::createNumbersPtr();
    payoff11->push_back(GT::createNumberPtr(10));
    payoff11->push_back(GT::createNumberPtr(20));
    GT::NumbersPtr payoff12 = GT::createNumbersPtr();
    payoff12->push_back(GT::createNumberPtr(30));
    payoff12->push_back(GT::createNumberPtr(40));
    GT::NumbersPtr payoff21 = GT::createNumbersPtr();
    payoff21->push_back(GT::createNumberPtr(50));
    payoff21->push_back(GT::createNumberPtr(60));
    GT::NumbersPtr payoff22 = GT::createNumbersPtr();
    payoff22->push_back(GT::createNumberPtr(70));
    payoff22->push_back(GT::createNumberPtr(80));

    // when
    GT::Model::ExtensiveDataNode root;
    root.setValues( p11, payoff11 ).setValues( p12, payoff12 )
        .setValues( p21, payoff21 ).setValues( p22, payoff22 );
    GT::NumbersPtr got11 = root.getValues(p11);
    GT::NumbersPtr got12 = root.getValues(p12);
    GT::NumbersPtr got21 = root.getValues(p21);
    GT::NumbersPtr got22 = root.getValues(p22);

    // then
    BOOST_CHECK_EQUAL_COLLECTIONS(
        got11->begin(),    got11->end(),
        payoff11->begin(), payoff11->end()
    );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        got12->begin(),    got12->end(),
        payoff12->begin(), payoff12->end()
    );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        got21->begin(),    got21->end(),
        payoff21->begin(), payoff21->end()
    );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        got22->begin(),    got22->end(),
        payoff22->begin(), payoff22->end()
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataNode_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");
    GT::Identifier s1 = GT::createIdentifier("s1");
    GT::Identifier s2 = GT::createIdentifier("s2");

    GT::Positions p11 = GT::createPositions();
    p11.insert( GT::Positions::value_type(l1, s1) );
    p11.insert( GT::Positions::value_type(l2, s1) );
    GT::Positions p12 = GT::createPositions();
    p12.insert( GT::Positions::value_type(l1, s1) );
    p12.insert( GT::Positions::value_type(l2, s2) );
    GT::Positions p21 = GT::createPositions();
    p21.insert( GT::Positions::value_type(l1, s2) );
    p21.insert( GT::Positions::value_type(l2, s1) );
    GT::Positions p22 = GT::createPositions();
    p22.insert( GT::Positions::value_type(l1, s2) );
    p22.insert( GT::Positions::value_type(l2, s2) );

    GT::NumbersPtr payoff11 = GT::createNumbersPtr();
    payoff11->push_back(GT::createNumberPtr(10));
    payoff11->push_back(GT::createNumberPtr(20));
    GT::NumbersPtr payoff12 = GT::createNumbersPtr();
    payoff12->push_back(GT::createNumberPtr(30));
    payoff12->push_back(GT::createNumberPtr(40));
    GT::NumbersPtr payoff21 = GT::createNumbersPtr();
    payoff21->push_back(GT::createNumberPtr(50));
    payoff21->push_back(GT::createNumberPtr(60));
    GT::NumbersPtr payoff22 = GT::createNumbersPtr();
    payoff22->push_back(GT::createNumberPtr(70));
    payoff22->push_back(GT::createNumberPtr(80));

    // when
    GT::Model::ExtensiveDataNode root;
    root.setValues( p11, payoff11 ).setValues( p12, payoff12 )
        .setValues( p21, payoff21 ).setValues( p22, payoff22 );
    GT::NumbersPtr got11 = root.getValues(p11);
    GT::NumbersPtr got12 = root.getValues(p12);
    GT::NumbersPtr got21 = root.getValues(p21);
    GT::NumbersPtr got22 = root.getValues(p22);

    // then
    BOOST_CHECK_EQUAL(
        root.toString(),
        GT::Message() +
        "s1:\n"
        "\ts1:\n"
        "\t\tValue:\n"
        "\t\t\t10\n"
        "\t\tValue:\n"
        "\t\t\t20\n"
        "\ts2:\n"
        "\t\tValue:\n"
        "\t\t\t30\n"
        "\t\tValue:\n"
        "\t\t\t40\n"
        "s2:\n"
        "\ts1:\n"
        "\t\tValue:\n"
        "\t\t\t50\n"
        "\t\tValue:\n"
        "\t\t\t60\n"
        "\ts2:\n"
        "\t\tValue:\n"
        "\t\t\t70\n"
        "\t\tValue:\n"
        "\t\t\t80\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()