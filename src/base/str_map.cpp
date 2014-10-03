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


#include <base/str_map.h>

unsigned int muzzley::djb2(string key) {
    unsigned int hash = 5381;

    for (unsigned int i = 0; i < key.length(); i++)
        hash = ((hash << 5) + hash) + (unsigned int) key[i];

    return hash % HASH_SIZE;
}
