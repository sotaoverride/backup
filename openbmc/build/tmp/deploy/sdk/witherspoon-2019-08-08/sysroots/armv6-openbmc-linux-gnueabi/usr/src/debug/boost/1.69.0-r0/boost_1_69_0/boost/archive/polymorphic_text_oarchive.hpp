#ifndef BOOST_ARCHIVE_POLYMORPHIC_TEXT_OARCHIVE_HPP
#define BOOST_ARCHIVE_POLYMORPHIC_TEXT_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
#pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// polymorphic_text_oarchive.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com .
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <boost/archive/detail/polymorphic_oarchive_route.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/config.hpp>

namespace boost
{
namespace archive
{

class BOOST_SYMBOL_VISIBLE polymorphic_text_oarchive
    : public detail::polymorphic_oarchive_route<text_oarchive>
{
  public:
    polymorphic_text_oarchive(std::ostream& os, unsigned int flags = 0) :
        detail::polymorphic_oarchive_route<text_oarchive>(os, flags)
    {
    }
    ~polymorphic_text_oarchive()
    {
    }
};

} // namespace archive
} // namespace boost

// required by export
BOOST_SERIALIZATION_REGISTER_ARCHIVE(boost::archive::polymorphic_text_oarchive)

#endif // BOOST_ARCHIVE_POLYMORPHIC_TEXT_OARCHIVE_HPP
