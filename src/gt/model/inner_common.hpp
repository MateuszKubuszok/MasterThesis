#ifndef __GT_MODEL_INNER_COMMON_HPP__
#define __GT_MODEL_INNER_COMMON_HPP__

////////////////////////////////////////////////////////////////////////////////

/* Include standard libraries */
#include <sstream>

/* Includes boost libraries */
#include <boost/foreach.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/thread/mutex.hpp>

/* Includes public interface */
#include "gt/model/common.hpp"

////////////////////////////////////////////////////////////////////////////////

namespace GT{
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/* Implementations declarations */

class PlainDataPiece;
class PlainData;
class PlainDataBuilder;
class PlainGameBuilder;

class PureGame;
class PureGameBuilder;

/* Shortens comonly used names */

typedef boost::shared_ptr<PlainDataBuilder>              PlainDataBuilderPtr;
typedef boost::bimaps::bimap<Identifier, Index>          IdentifierMap;
typedef boost::container::map<Identifier, IdentifierMap> StrategyMap;

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

////////////////////////////////////////////////////////////////////////////////

#include "gt/model/plain_data_piece.hpp"
#include "gt/model/plain_data.hpp"
#include "gt/model/plain_data_builder.hpp"
#include "gt/model/plain_game_builder.hpp"

#include "gt/model/pure_game.hpp"
#include "gt/model/pure_game_builder.hpp"

////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_MODEL_INNER_COMMON_HPP__ */