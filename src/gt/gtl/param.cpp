#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Param
// public:

Param::Param() :
    Object()
{
    registerProperty(Identifier("value"), ObjectPropertyPtr(new ParamValueProperty(this)));
    registerProperty(Identifier("type"),  ObjectPropertyPtr(new ParamTypeProperty()));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
