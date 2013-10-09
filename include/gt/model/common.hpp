#ifndef __GT_MODEL_COMMON_HPP__
#define __GT_MODEL_COMMON_HPP__

////////////////////////////////////////////////////////////////////////////////

/* Include standard libraries */
#include <stdexcept>
#include <string>
#include <memory>
#include <utility>

/* Includes GT helpers */
#include "gt/utils/singletons.hpp"

/* Includes boost libraries */
#include <boost/shared_ptr.hpp>
#include <boost/container/map.hpp>
#include <boost/container/set.hpp>
#include <boost/container/vector.hpp>

/* GNU MultiPrecision library */
#include <gmpxx.h>

namespace GT {

////////////////////////////////////////////////////////////////////////////////

/* Rename of some primary types */

typedef unsigned int Index;

/* Shortens commonly used names */

typedef std::istream                                  InputStream;
typedef std::ostream                                  OutputStream;
typedef std::string                                   Message;
typedef boost::shared_ptr<Message>                    MessagePtr;
typedef boost::container::vector<MessagePtr>          Messages;
typedef boost::shared_ptr<Messages>                   MessagesPtr;
typedef std::string                                   Identifier;
typedef boost::shared_ptr<Identifier>                 IdentifierPtr;
typedef boost::container::vector<IdentifierPtr>       Identifiers;
typedef boost::shared_ptr<Identifiers>                IdentifiersPtr;
typedef mpf_class                                     Number;
typedef boost::shared_ptr<Number>                     NumberPtr;
typedef boost::container::vector<NumberPtr>           Numbers;
typedef boost::shared_ptr<Numbers>                    NumbersPtr;
typedef boost::container::map<Identifier, Identifier> Positions;
typedef boost::shared_ptr<Positions>                  PositionsPtr;

/* Declares functions for equality check */

bool operator==(Messages&    messages1,   Messages&    messages2);
bool operator!=(Messages&    messages1,   Messages&    messages2);
bool operator==(Identifiers& identifier1, Identifiers& identifier2);
bool operator!=(Identifiers& identifier1, Identifiers& identifier2);
bool operator==(Numbers&     numbers1,    Numbers&     numbers2);
bool operator!=(Numbers&     numbers1,    Numbers&     numbers2);
bool operator==(Positions&   positions1,  Positions&   positions2);
bool operator!=(Positions&   positions1,  Positions&   positions2);

namespace Model {

////////////////////////////////////////////////////////////////////////////////

/* Exception declarations */

class IllegalInnerState;
class InvalidCoordinate;

/* Builder declarations */

class NullFactory;
class GameFactory;
class ResultFactory;

/* Model declarations */

class Player;        class NullPlayer;
class DataPiece;     class NullDataPiece;
class DataAccessor;  class NullDataAccessor;
class Data;          class NullData;
class DataBuilder;   class NullDataBuilder;
class Game;          class NullGame;
class GameBuilder;   class NullGameBuilder;
class Result;        class NullResult;
class ResultBuilder; class NullResultBuilder;

/* Shortens comonly used names */

typedef boost::shared_ptr<Player>                    PlayerPtr;
typedef boost::container::map<Identifier, PlayerPtr> Players;
typedef boost::shared_ptr<Players>                   PlayersPtr;
typedef boost::shared_ptr<Data>                      DataPtr;
typedef boost::shared_ptr<DataAccessor>              DataAccessorPtr;
typedef boost::shared_ptr<DataPiece>                 DataPiecePtr;
typedef boost::shared_ptr<DataBuilder>               DataBuilderPtr;
typedef boost::shared_ptr<Game>                      GamePtr;
typedef boost::shared_ptr<GameBuilder>               GameBuilderPtr;
typedef boost::shared_ptr<Result>                    ResultPtr;
typedef boost::shared_ptr<ResultBuilder>             ResultBuilderPtr;

/* Declares functions for equality check */

bool operator==(Players& players1, Players& players2);
bool operator!=(Players& players1, Players& players2);

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */

/* Includes GT model headers */

#include "gt/model/helpers.hpp"

#include "gt/model/exceptions.hpp"

#include "gt/model/null_factory.hpp"

#include "gt/model/root.hpp"
#include "gt/model/player.hpp"
#include "gt/model/data_piece.hpp"
#include "gt/model/data_accessor.hpp"
#include "gt/model/data.hpp"
#include "gt/model/data_builder.hpp"
#include "gt/model/game.hpp"
#include "gt/model/game_builder.hpp"
#include "gt/model/game_factory.hpp"
#include "gt/model/result.hpp"
#include "gt/model/result_builder.hpp"
#include "gt/model/result_factory.hpp"

////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_MODEL_COMMON_HPP__ */
