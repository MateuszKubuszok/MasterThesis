%require  "2.5"
%skeleton "lalr1.cc"
%debug

%defines
%define namespace         "GTL"
%define parser_class_name "Parser"

%code top {
    /************************************************************************
     *                              GTL Parser                              *
     ************************************************************************/
     
    /* System libraries */
    #include <iostream> /* Default I/O streams library */
    #include <fstream>  /* File Streams library */
    #include <cstdlib>  /* C Standard library */
    #include <string>   /* String library */

    /* GTL prototypes */
    #include "gtl/driver.hpp"     /* GTL::Driver class */
    #include "gtl/scanner.hpp"    /* GTL::Scanner class */
    #include "gtl/condition.hpp"  /* GTL::Condition class */
    #include "gtl/data.hpp"       /* GTL::Data class */
    #include "gtl/data_piece.hpp" /* GTL::DataPiece class */
    #include "gtl/definition.hpp" /* GTL::Definition class */
    #include "gtl/details.hpp"    /* GTL::Details class */
    #include "gtl/game.hpp"       /* GTL::Game class */
    #include "gtl/query.hpp"      /* GTL::Query class */
    #include "gtl/object.hpp"     /* GTL::Object class */
    #include "gtl/param.hpp"      /* GTL::Param class */
    #include "gtl/player.hpp"     /* GTL::Player class */

    /* Override default yylex function */
    static int yylex(GTL::Parser::semantic_type *yylval, GTL::Scanner &scanner, GTL::Driver &driver);
}

%code requires {
    namespace GTL {
        class Driver;
        class Scanner;
    }
}

%lex-param   { Scanner &scanner }
%parse-param { Scanner &scanner }

%lex-param   { Driver &driver }
%parse-param { Driver &driver }

/* Union containing values as either double or string */
%union {
    std::string identifier;
    double      number;
    Condition&  condition;
    Data&       data;
    DataPiece&  dataPiece;
    Definition& definition;
    Details&    details;
    Game&       game;
    Query&      query;
    Object&     object;
    Param&      param;
    Player&     player;
    boost::containers::slist<Condition>&   conditions;
    boost::containers::slist<std::string>& identifiers;
    boost::containers::slist<Object>&      objects;
    boost::containers::slist<Param>&       params;
}

/* Declared tokens */

%token LET               /*  */
%token BE                /*  */
%token PLAYER            /*  */
%token GAME              /*  */
%token PURE              /*  */
%token MIXED             /*  */
%token TREE              /*  */
%token WITH              /*  */
%token SUCH              /*  */
%token AS                /*  */
%token FIND              /*  */
%token FOR               /*  */
%token CHOOSE            /*  */
%token LCBR              /* { */
%token RCBR              /* } */
%token COLON             /* : */
%token COMA              /* , */
%token EOC               /* ; */
%token error             /* error marker */

%token <string>     identifier /* Identifier */
%token <identifier> number     /* Double number */

 /* Declared types */
%type <condition>   condition
%type <data>        data
%type <dataPiece>   data_piece
%type <definition>  definition
%type <details>     details
%type <game>        game
%type <query>       query
%type <object>      object
%type <param>       param
%type <player>      player

%type <conditions>  conditions
%type <identifiers> identifiers
%type <objects>     objects
%type <params>      params

%%

/* Statements */

statement
 : definition EOC { driver.storeDefinedObject($1); }
 | query EOC      { driver.executeQuery($1); }
 ;

definition
 : LET identifier BE object { $$ = driver.createDefinition($4, $2); }
 ;
 
query
 : FIND identifiers FOR objects conditions { $$ = driver.createQuery($2, $4, $5); }
 ;

/* Objects */

objects
 : objects COMA object { $$ = driver.addObjectToCollection($3, $1); }
 | object              { $$ = driver.createObjectsCollection($1); }

object
 : game   { $$ = $1; }
 | player { $$ = $1; }
 | param  { $$ = driver.getValueForIdentifier($1); }
 ;
 
/* Games */

game
 : PURE  GAME details { $$ = driver.createPureGameForDetails($3); }
 | MIXED GAME details { $$ = driver.createMixedGameForDetails($3); }
 | TREE  GAME details { $$ = driver.createTreeGameForDetails($3); }
 ;

details
 : WITH objects SUCH AS data { $$ = driver.createDetailsForGame($2, $5); }
 ;
 
/* Players */

player
 : PLAYER identifier LCBR objects RCBR { $$ = driver.createPlayerWithStrategies($2, $4); }
 ;

/* Params */

param
 : identifier { $$ = driver.getValueForIdentifier($1); }
 | number     { $$ = driver.getValueForNumber($1); }
 ;

/* Identifiers */

identifiers
 : identifiers COMA identifier { $$ = driver.addIdentifierToCollection($3, $1); }
 | identifier                  { $$ = driver.createIdentifiersCollection($1); }
 ;

/* Conditions */

conditions
 : conditions COMA condition { $$ = driver.addConditionToCollection($3, $1); }
 | WITH condition            { $$ = driver.createConditionsCollection($2); }
 |                           { $$ = driver.emptyConditionCollection(); }
 ;

condition
 : PLAYER object CHOOSE object { $$ = driver.createPlayerChoiceCondition($2, $4); }
 ;
 
/* Data */

data
 : data COMA data_piece  { $$ = driver.addDataPieceToData($1, $3); }
 | data_piece            { $$ = driver.createData($1); }
 ;

data_piece
 : identifier COLON param                        { $$ = driver.createOneDimensionData($1, $3); }
 | identifiers LCBR identifier COLON params RCBR { $$ = driver.createTwoDimensionalData($1, $3, $5); }
 | identifiers COLON data_piece                  { $$ = driver.createMultiDimensionalData($1, $3); }
 ;

params
 : params COMA param { $$ = driver.addParamToCollection($3, $1); }
 | param             { $$ = driver.createParamsCollection($1); }
 ;

%%

/* Error handling */
void GTL::Parser::error(const GTL::Parser::location_type &location, const std::string &message) {
    driver.errorInformation(loc, message);
}

/* Include for scanner.yylex */
static int yylex(GTL::Parser::semantic_type *yylval, GTL::Scanner &scanner, GTL::Driver &driver) {
    return scanner.yylex(yylval);
}