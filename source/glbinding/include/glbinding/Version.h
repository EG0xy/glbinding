#pragma once

#include <glbinding/glbinding_api.h>

#include <ostream>
#include <string>
#include <set>
#include <utility>

#include <glbinding/types.h>


namespace glbinding
{

class GLBINDING_API Version
{
public:
    Version();
    Version(gl::GLint majorVersion, gl::GLint minorVersion);

    bool operator< (const Version & version) const;
    bool operator> (const Version & version) const;
    bool operator==(const Version & version) const;
    bool operator!=(const Version & version) const;
    bool operator>=(const Version & version) const;
    bool operator<=(const Version & version) const;

    operator std::pair<unsigned char,  unsigned char> () const;
    operator std::pair<unsigned short, unsigned short>() const;
    operator std::pair<unsigned int,   unsigned int>  () const;

	std::string toString() const;

    bool isValid() const;
    bool isNull() const;

    Version nearest() const;

    static const std::set<Version> & versions();

public:
    gl::GLint m_major;
    gl::GLint m_minor;

protected:
    static const std::set<Version> s_validVersions;
};

} // namespace glbinding

GLBINDING_API std::ostream & operator<<(std::ostream & stream, const glbinding::Version & version);