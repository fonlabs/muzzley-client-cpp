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

// $insert class.ih
#include <muzzley/parsers/HTTPTokenizerimpl.h>

// The FIRST element of SR arrays shown below uses `d_type', defining the
// state's type, and `d_lastIdx' containing the last element's index. If
// d_lastIdx contains the REQ_TOKEN bitflag (see below) then the state needs
// a token: if in this state d_token__ is _UNDETERMINED_, nextToken() will be
// called

// The LAST element of SR arrays uses `d_token' containing the last retrieved
// token to speed up the (linear) seach.  Except for the first element of SR
// arrays, the field `d_action' is used to determine what to do next. If
// positive, it represents the next state (used with SHIFT); if zero, it
// indicates `ACCEPT', if negative, -d_action represents the number of the
// rule to reduce to.

// `lookup()' tries to find d_token__ in the current SR array. If it fails, and
// there is no default reduction UNEXPECTED_TOKEN__ is thrown, which is then
// caught by the error-recovery function.

// The error-recovery function will pop elements off the stack until a state
// having bit flag ERR_ITEM is found. This state has a transition on _error_
// which is applied. In this _error_ state, while the current token is not a
// proper continuation, new tokens are obtained by nextToken(). If such a
// token is found, error recovery is successful and the token is
// handled according to the error state's SR table and parsing continues.
// During error recovery semantic actions are ignored.

// A state flagged with the DEF_RED flag will perform a default
// reduction if no other continuations are available for the current token.

// The ACCEPT STATE never shows a default reduction: when it is reached the
// parser returns ACCEPT(). During the grammar
// analysis phase a default reduction may have been defined, but it is
// removed during the state-definition phase.

// So:
//      s_x[] = 
//      {
//                  [_field_1_]         [_field_2_]
//
// First element:   {state-type,        idx of last element},
// Other elements:  {required token,    action to perform},
//                                      ( < 0: reduce, 
//                                          0: ACCEPT,
//                                        > 0: next state)
// Last element:    {set to d_token__,    action to perform}
//      }

// When the --thread-safe option is specified, all static data are defined as
// const. If --thread-safe is not provided, the state-tables are not defined
// as const, since the lookup() function below will modify them


namespace // anonymous
{
    char const author[] = "Frank B. Brokken (f.b.brokken@rug.nl)";

    enum 
    {
        STACK_EXPANSION = 5     // size to expand the state-stack with when
                                // full
    };

    enum ReservedTokens
    {
        PARSE_ACCEPT     = 0,   // `ACCEPT' TRANSITION
        _UNDETERMINED_   = -2,
        _EOF_            = -1,
        _error_          = 256
    };
    enum StateType       // modify statetype/data.cc when this enum changes
    {
        NORMAL,
        ERR_ITEM,
        REQ_TOKEN,
        ERR_REQ,    // ERR_ITEM | REQ_TOKEN
        DEF_RED,    // state having default reduction
        ERR_DEF,    // ERR_ITEM | DEF_RED
        REQ_DEF,    // REQ_TOKEN | DEF_RED
        ERR_REQ_DEF // ERR_ITEM | REQ_TOKEN | DEF_RED
    };    
    struct PI__     // Production Info
    {
        size_t d_nonTerm; // identification number of this production's
                            // non-terminal 
        size_t d_size;    // number of elements in this production 
    };

    struct SR__     // Shift Reduce info, see its description above
    {
        union
        {
            int _field_1_;      // initializer, allowing initializations 
                                // of the SR s_[] arrays
            int d_type;
            int d_token;
        };
        union
        {
            int _field_2_;

            int d_lastIdx;          // if negative, the state uses SHIFT
            int d_action;           // may be negative (reduce), 
                                    // postive (shift), or 0 (accept)
            size_t d_errorState;    // used with Error states
        };
    };

    // $insert staticdata
    
// Productions Info Records:
PI__ const s_productionInfo[] = 
{
     {0, 0}, // not used: reduction values are negative
     {269, 10}, // 1: exp (METHOD) ->  METHOD #0001 SPACE URL #0002 params SPACE VERSION headers rest
     {270, 0}, // 2: #0001 ->  <empty>
     {272, 0}, // 3: #0002 ->  <empty>
     {269, 10}, // 4: exp (VERSION) ->  VERSION #0003 SPACE STATUS #0004 SPACE STRING #0005 headers rest
     {275, 0}, // 5: #0003 ->  <empty>
     {276, 0}, // 6: #0004 ->  <empty>
     {277, 0}, // 7: #0005 ->  <empty>
     {271, 0}, // 8: params ->  <empty>
     {271, 2}, // 9: params (QMARK) ->  QMARK paramslist
     {278, 4}, // 10: paramslist (STRING) ->  STRING #0006 EQ STRING
     {279, 0}, // 11: #0006 ->  <empty>
     {278, 6}, // 12: paramslist (E) ->  paramslist E STRING #0007 EQ STRING
     {280, 0}, // 13: #0007 ->  <empty>
     {273, 3}, // 14: headers (CR_LF) ->  CR_LF headerslist CR_LF
     {273, 2}, // 15: headers (CR_LF) ->  CR_LF headerslist
     {281, 4}, // 16: headerslist (STRING) ->  STRING #0008 COLON STRING
     {282, 0}, // 17: #0008 ->  <empty>
     {281, 6}, // 18: headerslist (CR_LF) ->  headerslist CR_LF STRING #0009 COLON STRING
     {283, 0}, // 19: #0009 ->  <empty>
     {274, 1}, // 20: rest (BODY) ->  BODY
     {274, 0}, // 21: rest ->  <empty>
     {284, 1}, // 22: exp_$ ->  exp
};

// State info and SR__ transitions for each state.


SR__ const s_0[] =
{
    { { REQ_TOKEN}, { 4} },           
    { {       269}, { 1} }, // exp    
    { {       257}, { 2} }, // METHOD 
    { {       258}, { 3} }, // VERSION
    { {         0}, { 0} },           
};

SR__ const s_1[] =
{
    { { REQ_TOKEN}, {            2} }, 
    { {     _EOF_}, { PARSE_ACCEPT} }, 
    { {         0}, {            0} }, 
};

SR__ const s_2[] =
{
    { { DEF_RED}, {  2} },         
    { {     270}, {  4} }, // #0001
    { {       0}, { -2} },         
};

SR__ const s_3[] =
{
    { { DEF_RED}, {  2} },         
    { {     275}, {  5} }, // #0003
    { {       0}, { -5} },         
};

SR__ const s_4[] =
{
    { { REQ_TOKEN}, { 2} },         
    { {       264}, { 6} }, // SPACE
    { {         0}, { 0} },         
};

SR__ const s_5[] =
{
    { { REQ_TOKEN}, { 2} },         
    { {       264}, { 7} }, // SPACE
    { {         0}, { 0} },         
};

SR__ const s_6[] =
{
    { { REQ_TOKEN}, { 2} },       
    { {       259}, { 8} }, // URL
    { {         0}, { 0} },       
};

SR__ const s_7[] =
{
    { { REQ_TOKEN}, { 2} },          
    { {       260}, { 9} }, // STATUS
    { {         0}, { 0} },          
};

SR__ const s_8[] =
{
    { { DEF_RED}, {  2} },         
    { {     272}, { 10} }, // #0002
    { {       0}, { -3} },         
};

SR__ const s_9[] =
{
    { { DEF_RED}, {  2} },         
    { {     276}, { 11} }, // #0004
    { {       0}, { -6} },         
};

SR__ const s_10[] =
{
    { { REQ_DEF}, {  3} },          
    { {     271}, { 12} }, // params
    { {     266}, { 13} }, // QMARK 
    { {       0}, { -8} },          
};

SR__ const s_11[] =
{
    { { REQ_TOKEN}, {  2} },         
    { {       264}, { 14} }, // SPACE
    { {         0}, {  0} },         
};

SR__ const s_12[] =
{
    { { REQ_TOKEN}, {  2} },         
    { {       264}, { 15} }, // SPACE
    { {         0}, {  0} },         
};

SR__ const s_13[] =
{
    { { REQ_TOKEN}, {  3} },              
    { {       278}, { 16} }, // paramslist
    { {       263}, { 17} }, // STRING    
    { {         0}, {  0} },              
};

SR__ const s_14[] =
{
    { { REQ_TOKEN}, {  2} },          
    { {       263}, { 18} }, // STRING
    { {         0}, {  0} },          
};

SR__ const s_15[] =
{
    { { REQ_TOKEN}, {  2} },           
    { {       258}, { 19} }, // VERSION
    { {         0}, {  0} },           
};

SR__ const s_16[] =
{
    { { REQ_DEF}, {  2} },     
    { {     268}, { 20} }, // E
    { {       0}, { -9} },     
};

SR__ const s_17[] =
{
    { { DEF_RED}, {   2} },         
    { {     279}, {  21} }, // #0006
    { {       0}, { -11} },         
};

SR__ const s_18[] =
{
    { { DEF_RED}, {  2} },         
    { {     277}, { 22} }, // #0005
    { {       0}, { -7} },         
};

SR__ const s_19[] =
{
    { { REQ_TOKEN}, {  3} },           
    { {       273}, { 23} }, // headers
    { {       261}, { 24} }, // CR_LF  
    { {         0}, {  0} },           
};

SR__ const s_20[] =
{
    { { REQ_TOKEN}, {  2} },          
    { {       263}, { 25} }, // STRING
    { {         0}, {  0} },          
};

SR__ const s_21[] =
{
    { { REQ_TOKEN}, {  2} },      
    { {       267}, { 26} }, // EQ
    { {         0}, {  0} },      
};

SR__ const s_22[] =
{
    { { REQ_TOKEN}, {  3} },           
    { {       273}, { 27} }, // headers
    { {       261}, { 24} }, // CR_LF  
    { {         0}, {  0} },           
};

SR__ const s_23[] =
{
    { { REQ_DEF}, {   3} },        
    { {     274}, {  28} }, // rest
    { {     265}, {  29} }, // BODY
    { {       0}, { -21} },        
};

SR__ const s_24[] =
{
    { { REQ_TOKEN}, {  3} },               
    { {       281}, { 30} }, // headerslist
    { {       263}, { 31} }, // STRING     
    { {         0}, {  0} },               
};

SR__ const s_25[] =
{
    { { DEF_RED}, {   2} },         
    { {     280}, {  32} }, // #0007
    { {       0}, { -13} },         
};

SR__ const s_26[] =
{
    { { REQ_TOKEN}, {  2} },          
    { {       263}, { 33} }, // STRING
    { {         0}, {  0} },          
};

SR__ const s_27[] =
{
    { { REQ_DEF}, {   3} },        
    { {     274}, {  34} }, // rest
    { {     265}, {  29} }, // BODY
    { {       0}, { -21} },        
};

SR__ const s_28[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -1} }, 
};

SR__ const s_29[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -20} }, 
};

SR__ const s_30[] =
{
    { { REQ_DEF}, {   2} },         
    { {     261}, {  35} }, // CR_LF
    { {       0}, { -15} },         
};

SR__ const s_31[] =
{
    { { DEF_RED}, {   2} },         
    { {     282}, {  36} }, // #0008
    { {       0}, { -17} },         
};

SR__ const s_32[] =
{
    { { REQ_TOKEN}, {  2} },      
    { {       267}, { 37} }, // EQ
    { {         0}, {  0} },      
};

SR__ const s_33[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -10} }, 
};

SR__ const s_34[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -4} }, 
};

SR__ const s_35[] =
{
    { { REQ_DEF}, {   2} },          
    { {     263}, {  38} }, // STRING
    { {       0}, { -14} },          
};

SR__ const s_36[] =
{
    { { REQ_TOKEN}, {  2} },         
    { {       262}, { 39} }, // COLON
    { {         0}, {  0} },         
};

SR__ const s_37[] =
{
    { { REQ_TOKEN}, {  2} },          
    { {       263}, { 40} }, // STRING
    { {         0}, {  0} },          
};

SR__ const s_38[] =
{
    { { DEF_RED}, {   2} },         
    { {     283}, {  41} }, // #0009
    { {       0}, { -19} },         
};

SR__ const s_39[] =
{
    { { REQ_TOKEN}, {  2} },          
    { {       263}, { 42} }, // STRING
    { {         0}, {  0} },          
};

SR__ const s_40[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -12} }, 
};

SR__ const s_41[] =
{
    { { REQ_TOKEN}, {  2} },         
    { {       262}, { 43} }, // COLON
    { {         0}, {  0} },         
};

SR__ const s_42[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -16} }, 
};

SR__ const s_43[] =
{
    { { REQ_TOKEN}, {  2} },          
    { {       263}, { 44} }, // STRING
    { {         0}, {  0} },          
};

SR__ const s_44[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -18} }, 
};


// State array:
SR__ const *s_state[] =
{
  s_0,  s_1,  s_2,  s_3,  s_4,  s_5,  s_6,  s_7,  s_8,  s_9,
  s_10,  s_11,  s_12,  s_13,  s_14,  s_15,  s_16,  s_17,  s_18,  s_19,
  s_20,  s_21,  s_22,  s_23,  s_24,  s_25,  s_26,  s_27,  s_28,  s_29,
  s_30,  s_31,  s_32,  s_33,  s_34,  s_35,  s_36,  s_37,  s_38,  s_39,
  s_40,  s_41,  s_42,  s_43,  s_44,
};

} // anonymous namespace ends


// $insert namespace-open
namespace muzzley
{

// If the parsing function call uses arguments, then provide an overloaded
// function.  The code below doesn't rely on parameters, so no arguments are
// required.  Furthermore, parse uses a function try block to allow us to do
// ACCEPT and ABORT from anywhere, even from within members called by actions,
// simply throwing the appropriate exceptions.

HTTPTokenizerBase::HTTPTokenizerBase()
:
    d_stackIdx__(-1),
    // $insert debuginit
    d_debug__(false),
    d_nErrors__(0),
    // $insert requiredtokens
    d_requiredTokens__(0),
    d_acceptedTokens__(d_requiredTokens__),
    d_token__(_UNDETERMINED_),
    d_nextToken__(_UNDETERMINED_)
{}


void HTTPTokenizer::print__()
{
// $insert print
}

void HTTPTokenizerBase::clearin()
{
    d_token__ = d_nextToken__ = _UNDETERMINED_;
}

void HTTPTokenizerBase::push__(size_t state)
{
    if (static_cast<size_t>(d_stackIdx__ + 1) == d_stateStack__.size())
    {
        size_t newSize = d_stackIdx__ + STACK_EXPANSION;
        d_stateStack__.resize(newSize);
        d_valueStack__.resize(newSize);
    }
    ++d_stackIdx__;
    d_stateStack__[d_stackIdx__] = d_state__ = state;
    *(d_vsp__ = &d_valueStack__[d_stackIdx__]) = d_val__;
}

void HTTPTokenizerBase::popToken__()
{
    d_token__ = d_nextToken__;

    d_val__ = d_nextVal__;
    d_nextVal__ = STYPE__();

    d_nextToken__ = _UNDETERMINED_;
}
     
void HTTPTokenizerBase::pushToken__(int token)
{
    d_nextToken__ = d_token__;
    d_nextVal__ = d_val__;
    d_token__ = token;
}
     
void HTTPTokenizerBase::pop__(size_t count)
{
    if (d_stackIdx__ < static_cast<int>(count))
    {
        ABORT();
    }

    d_stackIdx__ -= count;
    d_state__ = d_stateStack__[d_stackIdx__];
    d_vsp__ = &d_valueStack__[d_stackIdx__];
}

inline size_t HTTPTokenizerBase::top__() const
{
    return d_stateStack__[d_stackIdx__];
}

void HTTPTokenizer::executeAction(int production)
try
{
    if (d_token__ != _UNDETERMINED_)
        pushToken__(d_token__);     // save an already available token

                                    // save default non-nested block $$
    if (int size = s_productionInfo[production].d_size)
        d_val__ = d_vsp__[1 - size];

    switch (production)
    {
        // $insert actioncases
        
        case 1:
        {
         if (d_scanner.d_content_length != 0) {
         d_scanner.body();
         d_scanner.d_content_length = 0;
         }
         }
        break;

        case 2:
        d_val__ = d_vsp__[0];
        {
         d_scanner.d_content_length = 0;
         d_scanner.init(muzzley::HTTPRequest);
         }
        break;

        case 3:
        d_val__ = d_vsp__[-3];
        {
         d_scanner.url();
         }
        break;

        case 4:
        {
         if (d_scanner.d_content_length != 0) {
         d_scanner.body();
         d_scanner.d_content_length = 0;
         }
         }
        break;

        case 5:
        d_val__ = d_vsp__[0];
        {
         d_scanner.d_content_length = 0;
         d_scanner.init(muzzley::HTTPReply);
         }
        break;

        case 6:
        d_val__ = d_vsp__[-3];
        {
         d_scanner.status();
         }
        break;

        case 7:
        d_val__ = d_vsp__[-6];
        {
         }
        break;

        case 9:
        {
         }
        break;

        case 10:
        {
         d_scanner.value();
         }
        break;

        case 11:
        d_val__ = d_vsp__[0];
        {
         d_scanner.name();
         }
        break;

        case 12:
        {
         d_scanner.value();
         }
        break;

        case 13:
        d_val__ = d_vsp__[-2];
        {
         d_scanner.name();
         }
        break;

        case 16:
        {
         d_scanner.add();
         }
        break;

        case 17:
        d_val__ = d_vsp__[0];
        {
         d_scanner.add();
         }
        break;

        case 18:
        {
         d_scanner.add();
         }
        break;

        case 19:
        d_val__ = d_vsp__[-2];
        {
         d_scanner.add();
         }
        break;

        case 20:
        {
         d_scanner.body();
         d_scanner.d_content_length = 0;
         }
        break;

    }
}
catch (std::exception const &exc)
{
    exceptionHandler__(exc);
}

inline void HTTPTokenizerBase::reduce__(PI__ const &pi)
{
    d_token__ = pi.d_nonTerm;
    pop__(pi.d_size);

}

// If d_token__ is _UNDETERMINED_ then if d_nextToken__ is _UNDETERMINED_ another
// token is obtained from lex(). Then d_nextToken__ is assigned to d_token__.
void HTTPTokenizer::nextToken()
{
    if (d_token__ != _UNDETERMINED_)        // no need for a token: got one
        return;                             // already

    if (d_nextToken__ != _UNDETERMINED_)
    {
        popToken__();                       // consume pending token
    }
    else
    {
        ++d_acceptedTokens__;               // accept another token (see
                                            // errorRecover())
        d_token__ = lex();
        if (d_token__ <= 0)
            d_token__ = _EOF_;
    }
    print();
}

// if the final transition is negative, then we should reduce by the rule
// given by its positive value. Note that the `recovery' parameter is only
// used with the --debug option
int HTTPTokenizer::lookup(bool recovery)
{
    // $insert threading
    SR__ const *sr = s_state[d_state__];  // get the appropriate state-table
    int lastIdx = sr->d_lastIdx;        // sentinel-index in the SR_ array

    SR__ const *lastElementPtr = sr + lastIdx;
    SR__ const *elementPtr = sr + 1;      // start the search at s_xx[1]

    while (elementPtr != lastElementPtr && elementPtr->d_token != d_token__)
        ++elementPtr;

    if (elementPtr == lastElementPtr)   // reached the last element
    {
        if (elementPtr->d_action < 0)   // default reduction
        {
            return elementPtr->d_action;                
        }

        // No default reduction, so token not found, so error.
        throw UNEXPECTED_TOKEN__;
    }

    // not at the last element: inspect the nature of the action
    // (< 0: reduce, 0: ACCEPT, > 0: shift)

    int action = elementPtr->d_action;


    return action;
}

    // When an error has occurred, pop elements off the stack until the top
    // state has an error-item. If none is found, the default recovery
    // mode (which is to abort) is activated. 
    //
    // If EOF is encountered without being appropriate for the current state,
    // then the error recovery will fall back to the default recovery mode.
    // (i.e., parsing terminates)
void HTTPTokenizer::errorRecovery()
try
{
    if (d_acceptedTokens__ >= d_requiredTokens__)// only generate an error-
    {                                           // message if enough tokens 
        ++d_nErrors__;                          // were accepted. Otherwise
        error("Syntax error");                  // simply skip input

    }


    // get the error state
    while (not (s_state[top__()][0].d_type & ERR_ITEM))
    {
        pop__();
    }

    // In the error state, lookup a token allowing us to proceed.
    // Continuation may be possible following multiple reductions,
    // but eventuall a shift will be used, requiring the retrieval of
    // a terminal token. If a retrieved token doesn't match, the catch below 
    // will ensure the next token is requested in the while(true) block
    // implemented below:

    int lastToken = d_token__;                  // give the unexpected token a
                                                // chance to be processed
                                                // again.

    pushToken__(_error_);                       // specify _error_ as next token
    push__(lookup(true));                       // push the error state

    d_token__ = lastToken;                      // reactivate the unexpected
                                                // token (we're now in an
                                                // ERROR state).

    bool gotToken = true;                       // the next token is a terminal

    while (true)
    {
        try
        {
            if (s_state[d_state__]->d_type & REQ_TOKEN)
            {
                gotToken = d_token__ == _UNDETERMINED_;
                nextToken();                    // obtain next token
            }
            
            int action = lookup(true);

            if (action > 0)                 // push a new state
            {
                push__(action);
                popToken__();

                if (gotToken)
                {

                    d_acceptedTokens__ = 0;
                    return;
                }
            }
            else if (action < 0)
            {
                // no actions executed on recovery but save an already 
                // available token:
                if (d_token__ != _UNDETERMINED_)
                    pushToken__(d_token__);
 
                                            // next token is the rule's LHS
                reduce__(s_productionInfo[-action]); 
            }
            else
                ABORT();                    // abort when accepting during
                                            // error recovery
        }
        catch (...)
        {
            if (d_token__ == _EOF_)
                ABORT();                    // saw inappropriate _EOF_
                      
            popToken__();                   // failing token now skipped
        }
    }
}
catch (ErrorRecovery__)       // This is: DEFAULT_RECOVERY_MODE
{
    ABORT();
}

    // The parsing algorithm:
    // Initially, state 0 is pushed on the stack, and d_token__ as well as
    // d_nextToken__ are initialized to _UNDETERMINED_. 
    //
    // Then, in an eternal loop:
    //
    //  1. If a state does not have REQ_TOKEN no token is assigned to
    //     d_token__. If the state has REQ_TOKEN, nextToken() is called to
    //      determine d_nextToken__ and d_token__ is set to
    //     d_nextToken__. nextToken() will not call lex() unless d_nextToken__ is 
    //     _UNDETERMINED_. 
    //
    //  2. lookup() is called: 
    //     d_token__ is stored in the final element's d_token field of the
    //     state's SR_ array. 
    //
    //  3. The current token is looked up in the state's SR_ array
    //
    //  4. Depending on the result of the lookup() function the next state is
    //     shifted on the parser's stack, a reduction by some rule is applied,
    //     or the parsing function returns ACCEPT(). When a reduction is
    //     called for, any action that may have been defined for that
    //     reduction is executed.
    //
    //  5. An error occurs if d_token__ is not found, and the state has no
    //     default reduction. Error handling was described at the top of this
    //     file.

int HTTPTokenizer::parse()
try 
{
    push__(0);                              // initial state
    clearin();                              // clear the tokens.

    while (true)
    {
        try
        {
            if (s_state[d_state__]->d_type & REQ_TOKEN)
                nextToken();                // obtain next token


            int action = lookup(false);     // lookup d_token__ in d_state__

            if (action > 0)                 // SHIFT: push a new state
            {
                push__(action);
                popToken__();               // token processed
            }
            else if (action < 0)            // REDUCE: execute and pop.
            {
                executeAction(-action);
                                            // next token is the rule's LHS
                reduce__(s_productionInfo[-action]); 
            }
            else 
                ACCEPT();
        }
        catch (ErrorRecovery__)
        {
            errorRecovery();
        }
    }
}
catch (Return__ retValue)
{
    return retValue;
}


// $insert namespace-close
}


