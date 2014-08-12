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

#define DEBUG 1

#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <muzzley.h>

using namespace std;
using namespace __gnu_cxx;

int main(int argc, char* argv[]) {

	muzzley::Client _client;

	// Register listener to be invoked when user succesfully logs in.
	//
	// Don't bother to store the returned deviceId or sessionId, the Client class already does that,
	// access it through the 'getDeviceId'  and 'getSessionId' method.
	//
	// Return 'false' if you want to stop other listeners from being invoked.
	_client.on(muzzley::UserLoggedIn, [] (muzzley::JSONObj& _data, muzzley::Client& _client) -> bool {
		_client.joinActivity();
		return true;
	});

	// Register listener to be invoked when user succesfully joins the activity.
	//
	// Return 'false' if you want to stop other listeners from being invoked.
	_client.on(muzzley::ActivityJoined, [] (muzzley::JSONObj& _data, muzzley::Client& _client) -> bool {
		_client.sendWidgetData("xpto", "a", "some", "value");
		return true;
	});

	// Register listener to be invoked when app receives a signal message.
	//
	// Return 'false' if you want to stop other listeners from being invoked.
	_client.on(muzzley::SignalingMessage, [] (muzzley::JSONObj& _data, muzzley::Client& _client) -> bool {
		cout << (bool) _data["s"] << endl << flush;
		cout << (string) _data["d"]["a"] << endl << flush;
		return true;
	});

	// Connects the application to the Muzzley server.
	//
	// Assuming that the program receives the activityId as argument.
	//
	// It will start the application loop synchronously,
	// i.e. the program will not execute anything below this line.
	_client.connectUser("c1bc8d7d6bc38873", string(argv[1]));

	return 0;
}
