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


#include <muzzley/text/convert.h>

#include <unistd.h>
#include <iomanip>

using namespace std;
#if !defined __APPLE__
using namespace __gnu_cxx;
#endif

void muzzley::base64_encode(string& _out) {
	istringstream in;
	ostringstream out;
	char buff1[3];
	char buff2[4];
	uint8_t i = 0, j;

	in.str(_out);
	_out.assign("");

	while (in.readsome(&buff1[i++], 1))
		if (i == 3) {
			_out.push_back(encodeCharacterTable[(buff1[0] & 0xfc) >> 2]);
			_out.push_back(encodeCharacterTable[((buff1[0] & 0x03) << 4) + ((buff1[1] & 0xf0) >> 4)]);
			_out.push_back(encodeCharacterTable[((buff1[1] & 0x0f) << 2) + ((buff1[2] & 0xc0) >> 6)]);
			_out.push_back(encodeCharacterTable[buff1[2] & 0x3f]);
			i = 0;
		}

	if (--i) {
		for (j = i; j < 3; j++)
			buff1[j] = '\0';

		buff2[0] = (buff1[0] & 0xfc) >> 2;
		buff2[1] = ((buff1[0] & 0x03) << 4) + ((buff1[1] & 0xf0) >> 4);
		buff2[2] = ((buff1[1] & 0x0f) << 2) + ((buff1[2] & 0xc0) >> 6);
		buff2[3] = buff1[2] & 0x3f;

		for (j = 0; j < (i + 1); j++)
			_out.push_back(encodeCharacterTable[(uint8_t) buff2[j]]);

		while (i++ < 3)
			_out.push_back('=');
	}
}

void muzzley::base64_decode(string& _out) {
	istringstream in;
	ostringstream out;
	char buff1[4];
	char buff2[4];
	uint8_t i = 0, j;

	in.str(_out);
	_out.assign("");

	while (in.readsome(&buff2[i], 1) && buff2[i] != '=') {
		if (++i == 4) {
			for (i = 0; i != 4; i++)
				buff2[i] = decodeCharacterTable[(uint8_t) buff2[i]];

			_out.push_back((char) ((buff2[0] << 2) + ((buff2[1] & 0x30) >> 4)));
			_out.push_back((char) (((buff2[1] & 0xf) << 4) + ((buff2[2] & 0x3c) >> 2)));
			_out.push_back((char) (((buff2[2] & 0x3) << 6) + buff2[3]));

			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; j++)
			buff2[j] = '\0';
		for (j = 0; j < 4; j++)
			buff2[j] = decodeCharacterTable[(uint8_t) buff2[j]];

		buff1[0] = (buff2[0] << 2) + ((buff2[1] & 0x30) >> 4);
		buff1[1] = ((buff2[1] & 0xf) << 4) + ((buff2[2] & 0x3c) >> 2);
		buff1[2] = ((buff2[2] & 0x3) << 6) + buff2[3];

		for (j = 0; j < (i - 1); j++)
			_out.push_back((char) buff1[j]);
	}
}

void muzzley::base64_encode(istream& _in, ostream& _out) {
	char buff1[3];
	char buff2[4];
	uint8_t i = 0, j;

	while (_in.readsome(&buff1[i++], 1))
		if (i == 3) {
			_out << encodeCharacterTable[(buff1[0] & 0xfc) >> 2];
			_out << encodeCharacterTable[((buff1[0] & 0x03) << 4) + ((buff1[1] & 0xf0) >> 4)];
			_out << encodeCharacterTable[((buff1[1] & 0x0f) << 2) + ((buff1[2] & 0xc0) >> 6)];
			_out << encodeCharacterTable[buff1[2] & 0x3f];
			i = 0;
		}

	if (--i) {
		for (j = i; j < 3; j++)
			buff1[j] = '\0';

		buff2[0] = (buff1[0] & 0xfc) >> 2;
		buff2[1] = ((buff1[0] & 0x03) << 4) + ((buff1[1] & 0xf0) >> 4);
		buff2[2] = ((buff1[1] & 0x0f) << 2) + ((buff1[2] & 0xc0) >> 6);
		buff2[3] = buff1[2] & 0x3f;

		for (j = 0; j < (i + 1); j++)
			_out << encodeCharacterTable[(uint8_t) buff2[j]];

		while (i++ < 3)
			_out << '=';
	}
}

void muzzley::base64_decode(istream& _in, ostream& _out) {
	char buff1[4];
	char buff2[4];
	uint8_t i = 0, j;

	while (_in.readsome(&buff2[i], 1) && buff2[i] != '=') {
		if (++i == 4) {
			for (i = 0; i != 4; i++)
				buff2[i] = decodeCharacterTable[(uint8_t) buff2[i]];

			_out << (char) ((buff2[0] << 2) + ((buff2[1] & 0x30) >> 4));
			_out << (char) (((buff2[1] & 0xf) << 4) + ((buff2[2] & 0x3c) >> 2));
			_out << (char) (((buff2[2] & 0x3) << 6) + buff2[3]);

			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; j++)
			buff2[j] = '\0';
		for (j = 0; j < 4; j++)
			buff2[j] = decodeCharacterTable[(uint8_t) buff2[j]];

		buff1[0] = (buff2[0] << 2) + ((buff2[1] & 0x30) >> 4);
		buff1[1] = ((buff2[1] & 0xf) << 4) + ((buff2[2] & 0x3c) >> 2);
		buff1[2] = ((buff2[2] & 0x3) << 6) + buff2[3];

		for (j = 0; j < (i - 1); j++)
			_out << (char) buff1[j];
	}
}

void muzzley::base64url_encode(string& _out) {
	istringstream in;
	ostringstream out;
	char buff1[4];
	char buff2[4];
	uint8_t i = 0, j;

	in.str(_out);

	while (in.readsome(&buff1[i++], 1))
		if (i == 3) {
			out << encodeCharacterTableUrl[(buff1[0] & 0xfc) >> 2];
			out << encodeCharacterTableUrl[((buff1[0] & 0x03) << 4) + ((buff1[1] & 0xf0) >> 4)];
			out << encodeCharacterTableUrl[((buff1[1] & 0x0f) << 2) + ((buff1[2] & 0xc0) >> 6)];
			out << encodeCharacterTableUrl[buff1[2] & 0x3f];
			i = 0;
		}

	if (--i) {
		for (j = i; j < 3; j++)
			buff1[j] = '\0';

		buff2[0] = (buff1[0] & 0xfc) >> 2;
		buff2[1] = ((buff1[0] & 0x03) << 4) + ((buff1[1] & 0xf0) >> 4);
		buff2[2] = ((buff1[1] & 0x0f) << 2) + ((buff1[2] & 0xc0) >> 6);
		buff2[3] = buff1[2] & 0x3f;

		for (j = 0; j < (i + 1); j++)
			out << encodeCharacterTableUrl[(uint8_t) buff2[j]];

//		while (i++ < 3)
//			out << '=';
	}
	out << flush;
	_out.assign(out.str());
}

void muzzley::base64url_decode(string& _out) {
	istringstream in;
	ostringstream out;
	char buff1[4];
	char buff2[4];
	uint8_t i = 0, j;

	while (in.readsome(&buff2[i], 1) && buff2[i] != '=') {
		if (++i == 4) {
			for (i = 0; i != 4; i++)
				buff2[i] = decodeCharacterTableUrl[(uint8_t) buff2[i]];

			out << (char) ((buff2[0] << 2) + ((buff2[1] & 0x30) >> 4));
			out << (char) (((buff2[1] & 0xf) << 4) + ((buff2[2] & 0x3c) >> 2));
			out << (char) (((buff2[2] & 0x3) << 6) + buff2[3]);

			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; j++)
			buff2[j] = '\0';
		for (j = 0; j < 4; j++)
			buff2[j] = decodeCharacterTableUrl[(uint8_t) buff2[j]];

		buff1[0] = (buff2[0] << 2) + ((buff2[1] & 0x30) >> 4);
		buff1[1] = ((buff2[1] & 0xf) << 4) + ((buff2[2] & 0x3c) >> 2);
		buff1[2] = ((buff2[2] & 0x3) << 6) + buff2[3];

		for (j = 0; j < (i - 1); j++)
			out << (char) buff1[j];
	}
	out << flush;
	_out.assign(out.str());
}
