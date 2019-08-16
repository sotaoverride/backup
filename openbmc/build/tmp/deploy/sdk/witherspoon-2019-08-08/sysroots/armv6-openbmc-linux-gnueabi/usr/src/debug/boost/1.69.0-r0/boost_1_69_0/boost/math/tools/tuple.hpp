//  (C) Copyright John Maddock 2010.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_TUPLE_HPP_INCLUDED
#define BOOST_MATH_TUPLE_HPP_INCLUDED
#include <boost/config.hpp>
#include <boost/detail/workaround.hpp>

#if !defined(BOOST_NO_CXX11_HDR_TUPLE) &&                                      \
    !BOOST_WORKAROUND(BOOST_GCC_VERSION, < 40500)

#include <tuple>

namespace boost
{
namespace math
{

using ::std::tuple;

// [6.1.3.2] Tuple creation functions
using ::std::get;
using ::std::ignore;
using ::std::make_tuple;
using ::std::tie;

// [6.1.3.3] Tuple helper classes
using ::std::tuple_element;
using ::std::tuple_size;

} // namespace math
} // namespace boost

#elif (defined(__BORLANDC__) && (__BORLANDC__ <= 0x600)) || defined(__IBMCPP__)

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace boost
{
namespace math
{

using ::boost::tuple;

// [6.1.3.2] Tuple creation functions
using ::boost::make_tuple;
using ::boost::tie;
using ::boost::tuples::ignore;

// [6.1.3.3] Tuple helper classes
template <class T>
struct tuple_size
    : public ::boost::integral_constant<::std::size_t,
                                        ::boost::tuples::length<T>::value>
{
};

template <int I, class T>
struct tuple_element
{
    typedef typename boost::tuples::element<I, T>::type type;
};

#if !BOOST_WORKAROUND(__BORLANDC__, < 0x0582)
// [6.1.3.4] Element access
using ::boost::get;
#endif

} // namespace math
} // namespace boost

#else

#include <boost/fusion/include/std_pair.hpp>
#include <boost/fusion/include/tuple.hpp>

namespace boost
{
namespace math
{

using ::boost::fusion::tuple;

// [6.1.3.2] Tuple creation functions
using ::boost::fusion::get;
using ::boost::fusion::ignore;
using ::boost::fusion::make_tuple;
using ::boost::fusion::tie;

// [6.1.3.3] Tuple helper classes
using ::boost::fusion::tuple_element;
using ::boost::fusion::tuple_size;

} // namespace math
} // namespace boost

#endif

#endif
