/*
The MIT License (MIT)

Copyright (c) 2014 Pedro (n@zgul) Figueiredo <pedro.figueiredo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef PACKAGE
#include <muzzley/config.h>
#endif
#ifdef HAVE_HTTP_CLIENT

#include <muzzley/parsers/http.h>

muzzley::HTTPReq& muzzley::fromhttpstr(string& _in, muzzley::HTTPReq& _out) {
	istringstream _ss;
	_ss.str(_in);
	muzzley::HTTPParser _p;
	_p.switchRoots(_out);
	_p.switchStreams(_ss);
	_p.parse();
	return _out;
}

muzzley::HTTPRep& muzzley::fromhttpstr(string& _in, muzzley::HTTPRep& _out) {
	istringstream _ss;
	_ss.str(_in);
	muzzley::HTTPParser _p;
	_p.switchRoots(_out);
	_p.switchStreams(_ss);
	_p.parse();
	return _out;
}

muzzley::HTTPReq& muzzley::fromhttpfile(ifstream& _in, muzzley::HTTPReq& _out) {
	if (_in.is_open()) {
		muzzley::HTTPParser _p;
		_p.switchRoots(_out);
		_p.switchStreams(_in);
		_p.parse();
	}
	return _out;
}

muzzley::HTTPRep& muzzley::fromhttpfile(ifstream& _in, muzzley::HTTPRep& _out) {
	if (_in.is_open()) {
		muzzley::HTTPParser _p;
		_p.switchRoots(_out);
		_p.switchStreams(_in);
		_p.parse();
	}
	return _out;
}

muzzley::HTTPReq& muzzley::fromhttpstream(istream& _in, muzzley::HTTPReq& _out) {
	muzzley::HTTPParser _p;
	_p.switchRoots(_out);
	_p.switchStreams(_in);
	_p.parse();
	return _out;
}

muzzley::HTTPRep& muzzley::fromhttpstream(istream& _in, muzzley::HTTPRep& _out) {
	muzzley::HTTPParser _p;
	_p.switchRoots(_out);
	_p.switchStreams(_in);
	_p.parse();
	return _out;
}

void muzzley::tostr(string& _out, HTTPRep& _in)  {
	_in->stringify(_out);
}

void muzzley::tostr(string& _out, HTTPReq& _in)  {
	_in->stringify(_out);
}

void muzzley::tostr(ostream& _out, HTTPRep& _in)  {
	_in->stringify(_out);
	_out << flush;
}

void muzzley::tostr(ostream& _out, HTTPReq& _in)  {
	_in->stringify(_out);
	_out << flush;
}

#endif