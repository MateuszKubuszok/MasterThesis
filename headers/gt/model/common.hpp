#ifndef __GT_MODEL_COMMON_HPP__
#define __GT_MODEL_COMMON_HPP__ 1

/* Include standard libraries */
#include <stdexcept>
#include <string>

/* Includes boost libraries */
#include <boost/container/vector.hpp>

/* GNU MultiPrecision library */
#include <gmpxx.h>

/* Includes GT model headers */
#include "gt/model/result.hpp"
#include "gt/model/result_factory.hpp"

/* Shortens comonly used names */
typedef std::string                           Identifier;
typedef boost::containers::vector<Identifier> Identifiers;
typedef mpz_class                             Number;

#endif /* END #ifndef __GT_MODEL_COMMON_HPP__ */
