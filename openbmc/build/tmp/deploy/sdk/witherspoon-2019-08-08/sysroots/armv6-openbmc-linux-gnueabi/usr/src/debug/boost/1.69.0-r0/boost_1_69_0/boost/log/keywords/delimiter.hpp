/*
 *          Copyright Andrey Semashev 2007 - 2015.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   keywords/delimiter.hpp
 * \author Andrey Semashev
 * \date   14.03.2009
 *
 * The header contains the \c delimiter keyword declaration.
 */

#ifndef BOOST_LOG_KEYWORDS_DELIMITER_HPP_INCLUDED_
#define BOOST_LOG_KEYWORDS_DELIMITER_HPP_INCLUDED_

#include <boost/log/detail/config.hpp>
#include <boost/parameter/keyword.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

namespace boost
{

BOOST_LOG_OPEN_NAMESPACE

namespace keywords
{

//! The keyword for passing delimiter between scopes to the \c named_scope
//! formatter
BOOST_PARAMETER_KEYWORD(tag, delimiter)

} // namespace keywords

BOOST_LOG_CLOSE_NAMESPACE // namespace log

} // namespace boost

#endif // BOOST_LOG_KEYWORDS_DELIMITER_HPP_INCLUDED_