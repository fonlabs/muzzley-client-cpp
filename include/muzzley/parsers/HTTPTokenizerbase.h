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

// Generated by Bisonc++ V4.05.00 on Fri, 27 Jun 2014 01:36:57 +0100

#ifndef muzzleyHTTPTokenizerBase_h_included
#define muzzleyHTTPTokenizerBase_h_included

#include <exception>
#include <vector>
#include <iostream>

// $insert preincludes
#include <muzzley/parsers/HTTPinc.h>

namespace // anonymous
{
    struct PI__;
}

// $insert namespace-open
namespace muzzley
{


class HTTPTokenizerBase
{
    public:
// $insert tokens

#ifdef VERSION
#undef VERSION
#endif

    // Symbolic tokens:
    enum Tokens__
    {
        METHOD = 257,
        VERSION,
        URL,
        STATUS,
        CR_LF,
        COLON,
        STRING,
        SPACE,
        BODY,
        QMARK,
        EQ,
        E,
    };

// $insert STYPE
typedef int STYPE__;

    private:
        int d_stackIdx__;
        std::vector<size_t>   d_stateStack__;
        std::vector<STYPE__>  d_valueStack__;

    protected:
        enum Return__
        {
            PARSE_ACCEPT__ = 0,   // values used as parse()'s return values
            PARSE_ABORT__  = 1
        };
        enum ErrorRecovery__
        {
            DEFAULT_RECOVERY_MODE__,
            UNEXPECTED_TOKEN__,
        };
        bool        d_debug__;
        size_t      d_nErrors__;
        size_t      d_requiredTokens__;
        size_t      d_acceptedTokens__;
        int         d_token__;
        int         d_nextToken__;
        size_t      d_state__;
        STYPE__    *d_vsp__;
        STYPE__     d_val__;
        STYPE__     d_nextVal__;

        HTTPTokenizerBase();

        void ABORT() const;
        void ACCEPT() const;
        void ERROR() const;
        void clearin();
        bool debug() const;
        void pop__(size_t count = 1);
        void push__(size_t nextState);
        void popToken__();
        void pushToken__(int token);
        void reduce__(PI__ const &productionInfo);
        void errorVerbose__();
        size_t top__() const;

    public:
        void setDebug(bool mode);
}; 

inline bool HTTPTokenizerBase::debug() const
{
    return d_debug__;
}

inline void HTTPTokenizerBase::setDebug(bool mode)
{
    d_debug__ = mode;
}

inline void HTTPTokenizerBase::ABORT() const
{
    throw PARSE_ABORT__;
}

inline void HTTPTokenizerBase::ACCEPT() const
{
    throw PARSE_ACCEPT__;
}

inline void HTTPTokenizerBase::ERROR() const
{
    throw UNEXPECTED_TOKEN__;
}


// As a convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define HTTPTokenizer HTTPTokenizerBase

// $insert namespace-close
}

#endif


