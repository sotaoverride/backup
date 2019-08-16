// Copyright (C) 2013-2014 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// 2013/10 Vicente J. Botet Escriba
//   Creation using interprocess::unique_ptr.
// 2014/09 Vicente J. Botet Escriba
//   Adaptation to movelib::unique_ptr

#ifndef BOOST_CSBL_MEMORY_UNIQUE_PTR_HPP
#define BOOST_CSBL_MEMORY_UNIQUE_PTR_HPP

#include <boost/move/make_unique.hpp>
#include <boost/move/unique_ptr.hpp>
#include <boost/thread/csbl/memory/config.hpp>

namespace boost
{
namespace csbl
{
using ::boost::movelib::make_unique;
using ::boost::movelib::unique_ptr;

} // namespace csbl
} // namespace boost
#endif // header
