#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensiveDataBuilder )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensiveDataBuilder_setPlayers_getPlayers ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*playerName, player) );

    // when
    GT::Model::ExtensiveDataBuilder extensiveDataBuilder;
    extensiveDataBuilder.setPlayers(players);
    GT::Model::PlayersPtr gotPlayers = extensiveDataBuilder.getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataBuilder_build ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*playerName, player) );

    // when
    GT::Model::ExtensiveDataBuilder extensiveDataBuilder;
    extensiveDataBuilder.setPlayers(players);

    // then
    BOOST_CHECK_NO_THROW(
        extensiveDataBuilder.build()
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataBuilder_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*playerName, player) );

    GT::NumbersPtr params1 = GT::createNumbersPtr();
    params1->push_back( GT::createNumberPtr(10) );
    GT::NumbersPtr params2 = GT::createNumbersPtr();
    params2->push_back( GT::createNumberPtr(20) );

    GT::PositionsPtr positions1 = GT::createPositionsPtr();
    positions1->insert( GT::Positions::value_type(*playerName, *strategy1) );
    GT::PositionsPtr positions2 = GT::createPositionsPtr();
    positions2->insert( GT::Positions::value_type(*playerName, *strategy2) );

    // when
    GT::Model::ExtensiveDataBuilder extensiveDataBuilder;
    extensiveDataBuilder.setPlayers(players);

    extensiveDataBuilder.clone()->addNextPositions(positions1).setParams(params1);
    extensiveDataBuilder.clone()->addNextPositions(positions2).setParams(params2);

    // then
    BOOST_CHECK_EQUAL(
        extensiveDataBuilder.toString(),
        GT::Message() +
        "Current Data:\n"
        "\tExtensiveData:\n"
        "\t\tPlayer:\n"
        "\t\t\tName:\n"
        "\t\t\t\tp1\n"
        "\t\t\t0:\n"
        "\t\t\t\tp1s1\n"
        "\t\t\t1:\n"
        "\t\t\t\tp1s2\n"
        "\t\tp1s1:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t10\n"
        "\t\tp1s2:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t20\n"
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataBuilder_functional ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*playerName, player) );

    GT::NumbersPtr params1 = GT::createNumbersPtr();
    params1->push_back( GT::createNumberPtr(10) );
    GT::NumbersPtr params2 = GT::createNumbersPtr();
    params2->push_back( GT::createNumberPtr(20) );

    GT::PositionsPtr positions1 = GT::createPositionsPtr();
    positions1->insert( GT::Positions::value_type(*playerName, *strategy1) );
    GT::PositionsPtr positions2 = GT::createPositionsPtr();
    positions2->insert( GT::Positions::value_type(*playerName, *strategy2) );

    // when
    GT::Model::ExtensiveDataBuilder extensiveDataBuilder;
    extensiveDataBuilder.setPlayers(players);

    extensiveDataBuilder.clone()->addNextPositions(positions1)
                                 .addNextPositions(positions2)
                                 .setParams(params1);
    extensiveDataBuilder.clone()->addNextPositions(positions2)
                                 .addNextPositions(positions1)
                                 .setParams(params2);

    GT::Model::DataPtr data = extensiveDataBuilder.build();

    // then
    BOOST_CHECK_EQUAL(
        data->toString(),
        GT::Message() +
        "ExtensiveData:\n"
        "\tPlayer:\n"
        "\t\tName:\n"
        "\t\t\tp1\n"
        "\t\t0:\n"
        "\t\t\tp1s1\n"
        "\t\t1:\n"
        "\t\t\tp1s2\n"
        "\tp1s1:\n"
        "\t\tPlayer:\n"
        "\t\t\tName:\n"
        "\t\t\t\tp1\n"
        "\t\t\t0:\n"
        "\t\t\t\tp1s1\n"
        "\t\t\t1:\n"
        "\t\t\t\tp1s2\n"
        "\t\tp1s2:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t10\n"
        "\tp1s2:\n"
        "\t\tPlayer:\n"
        "\t\t\tName:\n"
        "\t\t\t\tp1\n"
        "\t\t\t0:\n"
        "\t\t\t\tp1s1\n"
        "\t\t\t1:\n"
        "\t\t\t\tp1s2\n"
        "\t\tp1s1:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t20\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
