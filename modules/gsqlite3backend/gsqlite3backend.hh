/*
 * This file is part of PowerDNS or dnsdist.
 * Copyright -- PowerDNS.COM B.V. and its contributors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * In addition, for the avoidance of any doubt, permission is granted to
 * link this program with OpenSSL and to (re)distribute the binaries
 * produced as the result of such linking.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#pragma once
#include <string>
#include "pdns/backends/gsql/gsqlbackend.hh"

//! The gSQLiteBackend retrieves it's data from a SQLite database (http://www.sqlite.org/)
class gSQLite3Backend : public GSQLBackend
{
public:
  //! Constructs the backend, throws an exception if it failed..
  gSQLite3Backend( const std::string & mode, const std::string & suffix );
};


class gSQLite3Factory : public BackendFactory
{
public:
  //! Constructor.
  gSQLite3Factory( const std::string & mode );
  //! Declares all needed arguments.
  void declareArguments( const std::string & suffix = "" );

  //! Constructs a new gSQLite3Backend object.
  DNSBackend *make( const string & suffix = "" );

private:
  const string d_mode;
};
