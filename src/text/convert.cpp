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

#include <time.h>
#include <sys/time.h>

void muzzley::tostr(string& s, int i){
	char oss[512];
	sprintf(oss,"%i", i);
	s.insert(s.length(), oss);
}

void muzzley::tostr(string& s, bool b){
	s.insert(s.length(), b ? "true" : "false");
}

void muzzley::tostr(std::string& s, int i, std::ios_base& (&hex)(std::ios_base&)) {
	char oss[512];
	sprintf(oss,"%x", i);
	s.insert(s.length(), oss);
}

#ifdef __LP64__
void muzzley::tostr(string& s, unsigned int i){
	char oss[512];
	sprintf(oss,"%u", i);
	s.insert(s.length(), oss);
}
#endif

void muzzley::tostr(string& s, size_t i){
	char oss[512];
#ifdef __LP64__
	sprintf(oss,"%lu", i);
#else
	sprintf(oss,"%u", i);
#endif
	s.insert(s.length(), oss);
}

void muzzley::tostr(string& s, long i){
	char oss[512];
	sprintf(oss,"%ld", i);
	s.insert(s.length(), oss);
}

void muzzley::tostr(string& s, long long i){
	char oss[512];
	sprintf(oss,"%lld", i);
	s.insert(s.length(), oss);
}

void muzzley::tostr(string& s, float i){
	char oss[512];
	sprintf(oss,"%f", i);
	s.insert(s.length(), oss);
}

void muzzley::tostr(string& s, double i){
	char oss[512];
	sprintf(oss,"%lf", i);
	s.insert(s.length(), oss);
}

void muzzley::tostr(string& s, char i){
	char oss[512];
	sprintf(oss,"%c", i);
	s.insert(s.length(), oss);
}

void muzzley::tostr(string& s, time_t i, const char* f){
	struct tm _ptm;
	char _buffer_date[80];
	bzero(_buffer_date, 80);
	localtime_r(&i, &_ptm);
	strftime(_buffer_date, 80, f, &_ptm);
	s.insert(s.length(), _buffer_date);
}

void muzzley::fromstr(string& s, int* i){
	sscanf(s.data(),"%i", i);
}

#ifdef __LP64__
void muzzley::fromstr(string& s, unsigned int* i){
	sscanf(s.data(),"%u", i);
}
#endif

void muzzley::fromstr(string& s, size_t* i){
#ifdef __LP64__
	sscanf(s.data(),"%lu", i);
#else
	sscanf(s.data(),"%u", i);
#endif
}

void muzzley::fromstr(string& s, long* i){
	sscanf(s.data(),"%ld", i);
}

void muzzley::fromstr(string& s, long long* i){
	sscanf(s.data(),"%lld", i);
}

void muzzley::fromstr(string& s, float* i){
	sscanf(s.data(),"%f", i);
}

void muzzley::fromstr(string& s, double* i){
	sscanf(s.data(),"%lf", i);
}

void muzzley::fromstr(string& s, char* i){
	sscanf(s.data(),"%c", i);
}

void muzzley::fromstr(string& s, bool* i){
	*i = s == string("true");
}

void muzzley::fromstr(string& s, time_t* i, const char* f){
	struct tm tm[1] = { { 0 } };
	strptime(s.data(), f, tm);
	if (string(f).find("%Z") == string::npos) {
		tzset();
		struct timeval tv;
		struct timezone _current_tz = { 0, 0 };
		gettimeofday(&tv, &_current_tz);

		tm->tm_isdst = _current_tz.tz_dsttime;
		tm->tm_gmtoff = muzzley::timezone_offset();
		tm->tm_zone =_current_tz.tz_dsttime == 0 ? tzname[0] : tzname[1];
	} 
	*i = mktime(tm);
}

time_t muzzley::timezone_offset() {
	time_t t;
	tm *ptr;
	int day;
	unsigned long num[2];
	t = time(NULL);
	ptr = gmtime(&t); // Standard UTC time
	// Get difference in seconds
	num[0] = (ptr->tm_hour * 3600) + (ptr->tm_min * 60);
	day = ptr->tm_mday;
	ptr = localtime(&t); // Local time w/ time zone
	num[1] = (ptr->tm_hour * 3600) + (ptr->tm_min * 60);
	// If not the same then get difference
	if (day == ptr->tm_mday) { // No date difference
		if (num[0] < num[1]) {
			return (num[1] - num[0]);// Positive ex. CUT +1
		}
		else if (num[0] > num[1]) {
			return -(num[0] - num[1]);// Negative ex. Pacific -8
		}
	}
	else if (day < ptr->tm_mday) {// Ex. 1: 30 am Jan 1 : 11: 30 pm Dec 31
		return (86400 - num[0]) + num[1];
	}
	else {
		return -((86400 - num[1]) + num[0]);// Opposite
	}
	return 0;
}
