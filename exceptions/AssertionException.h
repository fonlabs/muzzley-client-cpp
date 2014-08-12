/*
Copyright (c) 2014, Muzzley

Permission to use, copy, modify, and/or distribute this software for 
any purpose with or without fee is hereby granted, provided that the 
above copyright notice and this permission notice appear in all 
copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL 
WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE 
AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL 
DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR 
PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER 
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR 
PERFORMANCE OF THIS SOFTWARE.
*/


#pragma once

#include <exception>
#include <string>

using namespace std;
using namespace __gnu_cxx;

namespace muzzley {

	class AssertionException: public std::exception {
		private:
			string __what;
			int __http_code;
			int __code;
			string __description;
			int __line;
			string __file;

		public:
			AssertionException(string _what,  int _http_code, int _code, string _desc, int _line, string _file);
			virtual ~AssertionException() throw();

			const char* what();
			const char* description();
			int code();
			int status();
	};

}
