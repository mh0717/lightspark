/**************************************************************************
    Lightspark, a free flash player implementation

    Copyright (C) 2009,2010  Alessandro Pignotti (a.pignotti@sssup.it)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

#ifndef _CROSSDOMAINPOLICY_H
#define _CROSSDOMAINPOLICY_H

#include <libxml++/libxml++.h>
#include <libxml++/parsers/textreader.h>

#include "compat.h"
#include <string>
#include "swftypes.h"

namespace lightspark
{
	class CrossDomainPolicy
	{
	public:
		enum POLICYFILETYPE { URL, SOCKET };
		enum POLICYFILESUBTYPE { NONE, HTTP, HTTPS, FTP };
	private:
		xmlpp::TextReader xml;
		POLICYFILETYPE type;
		POLICYFILESUBTYPE subtype;
		bool master;

		//Ease-of-use variables
		int depth;
		std::string tagName;
		int attrCount;
		std::string attrValue;

		bool siteControlFound;

		//Parsed element attributes
		//site-control
		std::string permittedCrossDomainPolicies;
		//allow-access-from & allow-http-request-headers-from
		std::string domain;
		bool secure;
		bool secureSpecified;
		//allow-access-from
		std::string toPorts;
		//allow-http-request-headers-from
		std::string headers;
	public:
		CrossDomainPolicy(const unsigned char* buffer, size_t length, POLICYFILETYPE _type, POLICYFILESUBTYPE _subtype, bool _master);
		enum ELEMENTTYPE { END_OF_FILE, INVALID_FILE, SITE_CONTROL, ALLOW_ACCESS_FROM, ALLOW_HTTP_REQUEST_HEADERS_FROM };
		ELEMENTTYPE getNextElement();
		//site-control
		const std::string& getPermittedCrossDomainPolicies() const { return permittedCrossDomainPolicies; }
		//allow-access-from & allow-http-request-headers-from
		const std::string& getDomain() const { return domain; }
		bool getSecure() { return secure; };
		bool getSecureSpecified() { return secureSpecified; }
		//allow-access-from
		const std::string& getToPorts() const { return toPorts; }
		//allow-http-request-headers-from
		const std::string& getHeaders() const { return headers; }
	};
}

#endif
