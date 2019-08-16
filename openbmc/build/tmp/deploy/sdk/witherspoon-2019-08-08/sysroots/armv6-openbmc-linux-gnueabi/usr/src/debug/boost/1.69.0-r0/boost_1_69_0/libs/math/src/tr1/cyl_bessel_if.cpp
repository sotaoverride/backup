//  Copyright John Maddock 2008.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0.  (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <pch.hpp>
#ifndef BOOST_MATH_TR1_SOURCE
#define BOOST_MATH_TR1_SOURCE
#endif
#include "c_policy.hpp"

#include <boost/math/special_functions/bessel.hpp>
#include <boost/math/tr1.hpp>

extern "C" float BOOST_MATH_TR1_DECL boost_cyl_bessel_if
    BOOST_PREVENT_MACRO_SUBSTITUTION(float nu,
                                     float x) BOOST_MATH_C99_THROW_SPEC
{
    return c_policies::cyl_bessel_i BOOST_PREVENT_MACRO_SUBSTITUTION(nu, x);
}
