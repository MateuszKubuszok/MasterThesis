#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( StrategicDataBuilder )

BOOST_AUTO_TEST_CASE( StrategicDataBuilder_setPlayers_getPlayers ) {
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
    GT::Model::StrategicDataBuilder strategicDataBuilder;
    strategicDataBuilder.setPlayers(players);
    GT::Model::PlayersPtr gotPlayers = strategicDataBuilder.getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( StrategicDataBuilder_build ) {
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
    GT::Model::StrategicDataBuilder strategicDataBuilder;
    strategicDataBuilder.setPlayers(players);

    // then
    BOOST_CHECK_NO_THROW(
        strategicDataBuilder.build();
    );
}

BOOST_AUTO_TEST_CASE( StrategicDataBuilder_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setIndentationMode(GT::Model::TABS)
        .setBuilderMode(GT::Model::PLAIN);

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
    GT::Model::StrategicDataBuilder strategicDataBuilder;
    strategicDataBuilder.setPlayers(players);
    
    strategicDataBuilder.clone()->addNextPositions(positions1).setParams(params1);
    strategicDataBuilder.clone()->addNextPositions(positions2).setParams(params2);

    // then
    BOOST_CHECK_EQUAL(
        strategicDataBuilder.toString(),
        GT::Message() +
        "Current Data:\n"
        "\tValue:\n"
        "\t\t\t\tp1,\n"
        "\t\tPosition:\n"
        "\t\t\t\tp1s1,\n"
        "\t\tPayoff:\n"
        "\t\t\t\t10,\n"
        "\tValue:\n"
        "\t\t\t\tp1,\n"
        "\t\tPosition:\n"
        "\t\t\t\tp1s2,\n"
        "\t\tPayoff:\n"
        "\t\t\t\t20,\n"
    );
}

BOOST_AUTO_TEST_CASE( StrategicDataBuilder_functional ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setIndentationMode(GT::Model::TABS)
        .setBuilderMode(GT::Model::PLAIN);

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
    positions1->insert( GT::Positions::value_type(*playerName, *strategy1 ) );
    GT::PositionsPtr positions2 = GT::createPositionsPtr();
    positions2->insert( GT::Positions::value_type(*playerName, *strategy2 ) );

    // when
    GT::Model::StrategicDataBuilder strategicDataBuilder;
    strategicDataBuilder.setPlayers(players);
    
    strategicDataBuilder.clone()->addNextPositions(positions1).setParams(params1);
    strategicDataBuilder.clone()->addNextPositions(positions2).setParams(params2);

    GT::Model::DataPtr data = strategicDataBuilder.build();

    // then
    BOOST_CHECK_EQUAL(
        data->toString(),
        GT::Message() +
        "Value:\n"
        "\t\t\tp1,\n"
        "\tPosition:\n"
        "\t\t\tp1s1,\n"
        "\tPayoff:\n"
        "\t\t\t10,\n"
        "Value:\n"
        "\t\t\tp1,\n"
        "\tPosition:\n"
        "\t\t\tp1s2,\n"
        "\tPayoff:\n"
        "\t\t\t20,\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()