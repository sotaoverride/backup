/*
 *          Copyright Andrey Semashev 2007 - 2015.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   text_multifile_backend.cpp
 * \author Andrey Semashev
 * \date   09.06.2009
 *
 * \brief  This header is the Boost.Log library implementation, see the library
 * documentation at
 * http://www.boost.org/doc/libs/release/libs/log/doc/html/index.html.
 */

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/log/detail/config.hpp>
#include <boost/log/detail/header.hpp>
#include <boost/log/sinks/text_multifile_backend.hpp>
#include <ios>

namespace boost
{

BOOST_LOG_OPEN_NAMESPACE

namespace sinks
{

//! Sink implementation data
struct text_multifile_backend::implementation
{
    //! File name composer
    file_name_composer_type m_FileNameComposer;
    //! Base path for absolute path composition
    const filesystem::path m_BasePath;
    //! File stream
    filesystem::ofstream m_File;

    implementation() : m_BasePath(filesystem::current_path())
    {
    }

    //! Makes relative path absolute with respect to the base path
    filesystem::path make_absolute(filesystem::path const& p)
    {
        return filesystem::absolute(p, m_BasePath);
    }
};

//! Default constructor
BOOST_LOG_API text_multifile_backend::text_multifile_backend() :
    m_pImpl(new implementation())
{
}

//! Destructor
BOOST_LOG_API text_multifile_backend::~text_multifile_backend()
{
    delete m_pImpl;
}

//! The method sets the file name composer
BOOST_LOG_API void text_multifile_backend::set_file_name_composer_internal(
    file_name_composer_type const& composer)
{
    m_pImpl->m_FileNameComposer = composer;
}

//! The method writes the message to the sink
BOOST_LOG_API void
    text_multifile_backend::consume(record_view const& rec,
                                    string_type const& formatted_message)
{
    if (!m_pImpl->m_FileNameComposer.empty())
    {
        filesystem::path file_name =
            m_pImpl->make_absolute(m_pImpl->m_FileNameComposer(rec));
        filesystem::create_directories(file_name.parent_path());
        m_pImpl->m_File.open(file_name,
                             std::ios_base::out | std::ios_base::app);
        if (m_pImpl->m_File.is_open())
        {
            m_pImpl->m_File.write(
                formatted_message.data(),
                static_cast<std::streamsize>(formatted_message.size()));
            m_pImpl->m_File.put(static_cast<string_type::value_type>('\n'));
            m_pImpl->m_File.close();
        }
    }
}

} // namespace sinks

BOOST_LOG_CLOSE_NAMESPACE // namespace log

} // namespace boost

#include <boost/log/detail/footer.hpp>
