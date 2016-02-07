// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   FClex

// First part of user declarations.
#line 4 "parser.ypp" // lalr1.cc:399
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>
#define YYDEBUG 1
#line 39 "parser.ypp" // lalr1.cc:399


#include "driver.hpp"
#include "scanner.hpp"
#undef yylex
#define yylex driver.lexer->lex


#line 54 "parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 68 "parser.cpp" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace FC {
#line 154 "parser.cpp" // lalr1.cc:474

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 29 "parser.ypp" // lalr1.cc:725
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 498 "parser.cpp" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 116 "parser.ypp" // lalr1.cc:847
    {}
#line 612 "parser.cpp" // lalr1.cc:847
    break;

  case 3:
#line 118 "parser.ypp" // lalr1.cc:847
    {}
#line 618 "parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 119 "parser.ypp" // lalr1.cc:847
    {}
#line 624 "parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 120 "parser.ypp" // lalr1.cc:847
    {}
#line 630 "parser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 124 "parser.ypp" // lalr1.cc:847
    {}
#line 636 "parser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 127 "parser.ypp" // lalr1.cc:847
    {}
#line 642 "parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 129 "parser.ypp" // lalr1.cc:847
    {}
#line 648 "parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 130 "parser.ypp" // lalr1.cc:847
    {}
#line 654 "parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 132 "parser.ypp" // lalr1.cc:847
    {}
#line 660 "parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 135 "parser.ypp" // lalr1.cc:847
    {}
#line 666 "parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 136 "parser.ypp" // lalr1.cc:847
    {}
#line 672 "parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 138 "parser.ypp" // lalr1.cc:847
    {}
#line 678 "parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 139 "parser.ypp" // lalr1.cc:847
    {}
#line 684 "parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 141 "parser.ypp" // lalr1.cc:847
    {}
#line 690 "parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 142 "parser.ypp" // lalr1.cc:847
    {}
#line 696 "parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 145 "parser.ypp" // lalr1.cc:847
    {}
#line 702 "parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 147 "parser.ypp" // lalr1.cc:847
    {}
#line 708 "parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 148 "parser.ypp" // lalr1.cc:847
    {}
#line 714 "parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 151 "parser.ypp" // lalr1.cc:847
    {}
#line 720 "parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 153 "parser.ypp" // lalr1.cc:847
    {}
#line 726 "parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 156 "parser.ypp" // lalr1.cc:847
    {}
#line 732 "parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 159 "parser.ypp" // lalr1.cc:847
    {}
#line 738 "parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 161 "parser.ypp" // lalr1.cc:847
    {}
#line 744 "parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 162 "parser.ypp" // lalr1.cc:847
    {}
#line 750 "parser.cpp" // lalr1.cc:847
    break;

  case 31:
#line 164 "parser.ypp" // lalr1.cc:847
    {}
#line 756 "parser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 165 "parser.ypp" // lalr1.cc:847
    {}
#line 762 "parser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 166 "parser.ypp" // lalr1.cc:847
    {}
#line 768 "parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 168 "parser.ypp" // lalr1.cc:847
    {}
#line 774 "parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 170 "parser.ypp" // lalr1.cc:847
    {}
#line 780 "parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 172 "parser.ypp" // lalr1.cc:847
    {}
#line 786 "parser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 173 "parser.ypp" // lalr1.cc:847
    {}
#line 792 "parser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 175 "parser.ypp" // lalr1.cc:847
    {}
#line 798 "parser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 177 "parser.ypp" // lalr1.cc:847
    {}
#line 804 "parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 178 "parser.ypp" // lalr1.cc:847
    {}
#line 810 "parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 181 "parser.ypp" // lalr1.cc:847
    {}
#line 816 "parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 184 "parser.ypp" // lalr1.cc:847
    {}
#line 822 "parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 186 "parser.ypp" // lalr1.cc:847
    {}
#line 828 "parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 187 "parser.ypp" // lalr1.cc:847
    {}
#line 834 "parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 189 "parser.ypp" // lalr1.cc:847
    {}
#line 840 "parser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 192 "parser.ypp" // lalr1.cc:847
    {}
#line 846 "parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 194 "parser.ypp" // lalr1.cc:847
    {}
#line 852 "parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 195 "parser.ypp" // lalr1.cc:847
    {}
#line 858 "parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 197 "parser.ypp" // lalr1.cc:847
    {}
#line 864 "parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 198 "parser.ypp" // lalr1.cc:847
    {}
#line 870 "parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 199 "parser.ypp" // lalr1.cc:847
    {}
#line 876 "parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 200 "parser.ypp" // lalr1.cc:847
    {}
#line 882 "parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 201 "parser.ypp" // lalr1.cc:847
    {}
#line 888 "parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 202 "parser.ypp" // lalr1.cc:847
    {}
#line 894 "parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 203 "parser.ypp" // lalr1.cc:847
    {}
#line 900 "parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 204 "parser.ypp" // lalr1.cc:847
    {}
#line 906 "parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 205 "parser.ypp" // lalr1.cc:847
    {}
#line 912 "parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 206 "parser.ypp" // lalr1.cc:847
    {}
#line 918 "parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 207 "parser.ypp" // lalr1.cc:847
    {}
#line 924 "parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 209 "parser.ypp" // lalr1.cc:847
    {}
#line 930 "parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 211 "parser.ypp" // lalr1.cc:847
    {}
#line 936 "parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 213 "parser.ypp" // lalr1.cc:847
    {}
#line 942 "parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 214 "parser.ypp" // lalr1.cc:847
    {}
#line 948 "parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 217 "parser.ypp" // lalr1.cc:847
    {}
#line 954 "parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 220 "parser.ypp" // lalr1.cc:847
    {}
#line 960 "parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 222 "parser.ypp" // lalr1.cc:847
    {}
#line 966 "parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 224 "parser.ypp" // lalr1.cc:847
    {}
#line 972 "parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 226 "parser.ypp" // lalr1.cc:847
    {}
#line 978 "parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 227 "parser.ypp" // lalr1.cc:847
    {}
#line 984 "parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 229 "parser.ypp" // lalr1.cc:847
    {}
#line 990 "parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 231 "parser.ypp" // lalr1.cc:847
    {}
#line 996 "parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 232 "parser.ypp" // lalr1.cc:847
    {}
#line 1002 "parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 234 "parser.ypp" // lalr1.cc:847
    {}
#line 1008 "parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 236 "parser.ypp" // lalr1.cc:847
    {}
#line 1014 "parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 237 "parser.ypp" // lalr1.cc:847
    {}
#line 1020 "parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 239 "parser.ypp" // lalr1.cc:847
    {}
#line 1026 "parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 241 "parser.ypp" // lalr1.cc:847
    {}
#line 1032 "parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 243 "parser.ypp" // lalr1.cc:847
    {}
#line 1038 "parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 246 "parser.ypp" // lalr1.cc:847
    {}
#line 1044 "parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 247 "parser.ypp" // lalr1.cc:847
    {}
#line 1050 "parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 250 "parser.ypp" // lalr1.cc:847
    {}
#line 1056 "parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 253 "parser.ypp" // lalr1.cc:847
    {}
#line 1062 "parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 254 "parser.ypp" // lalr1.cc:847
    {}
#line 1068 "parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 255 "parser.ypp" // lalr1.cc:847
    {}
#line 1074 "parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 256 "parser.ypp" // lalr1.cc:847
    {}
#line 1080 "parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 257 "parser.ypp" // lalr1.cc:847
    {}
#line 1086 "parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 258 "parser.ypp" // lalr1.cc:847
    {}
#line 1092 "parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 259 "parser.ypp" // lalr1.cc:847
    {}
#line 1098 "parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 260 "parser.ypp" // lalr1.cc:847
    {}
#line 1104 "parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 261 "parser.ypp" // lalr1.cc:847
    {}
#line 1110 "parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 262 "parser.ypp" // lalr1.cc:847
    {}
#line 1116 "parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 263 "parser.ypp" // lalr1.cc:847
    {}
#line 1122 "parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 264 "parser.ypp" // lalr1.cc:847
    {}
#line 1128 "parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 265 "parser.ypp" // lalr1.cc:847
    {}
#line 1134 "parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 266 "parser.ypp" // lalr1.cc:847
    {}
#line 1140 "parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 267 "parser.ypp" // lalr1.cc:847
    {}
#line 1146 "parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 268 "parser.ypp" // lalr1.cc:847
    {}
#line 1152 "parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 270 "parser.ypp" // lalr1.cc:847
    {}
#line 1158 "parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 271 "parser.ypp" // lalr1.cc:847
    {}
#line 1164 "parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 272 "parser.ypp" // lalr1.cc:847
    {}
#line 1170 "parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 273 "parser.ypp" // lalr1.cc:847
    {}
#line 1176 "parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 274 "parser.ypp" // lalr1.cc:847
    {}
#line 1182 "parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 275 "parser.ypp" // lalr1.cc:847
    {}
#line 1188 "parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 276 "parser.ypp" // lalr1.cc:847
    {}
#line 1194 "parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 277 "parser.ypp" // lalr1.cc:847
    {}
#line 1200 "parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 279 "parser.ypp" // lalr1.cc:847
    {}
#line 1206 "parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 280 "parser.ypp" // lalr1.cc:847
    {}
#line 1212 "parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 281 "parser.ypp" // lalr1.cc:847
    {}
#line 1218 "parser.cpp" // lalr1.cc:847
    break;


#line 1222 "parser.cpp" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int Parser::yypact_ninf_ = -162;

  const signed char Parser::yytable_ninf_ = -24;

  const short int
  Parser::yypact_[] =
  {
      36,    -3,    46,    35,  -162,    30,    -3,  -162,  -162,    23,
      64,  -162,   132,  -162,    66,    23,    52,    84,  -162,    74,
      76,    80,    87,   132,   132,   132,  -162,  -162,  -162,  -162,
      32,     9,     4,    23,  -162,    95,    52,  -162,    83,    88,
      34,  -162,  -162,   132,   132,   132,   132,   435,   181,   281,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,  -162,    90,   132,    97,    52,  -162,   120,  -162,  -162,
    -162,   108,     4,  -162,   122,   125,    26,    84,   124,   298,
     315,   332,   349,  -162,   424,   435,   445,    47,   181,   451,
     -32,    78,    67,    70,   131,  -162,   217,   132,    -6,   105,
    -162,  -162,   128,   -15,   -15,   123,   132,   133,    26,   101,
    -162,   132,   134,   135,   169,  -162,   138,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,    48,  -162,
    -162,  -162,  -162,  -162,  -162,   381,  -162,    52,     4,  -162,
    -162,  -162,   130,   143,    52,   136,   141,   253,   144,   171,
    -162,   366,   161,   132,   132,  -162,    26,   132,   132,   164,
     166,   -13,   115,   178,   132,    26,    51,   132,  -162,    26,
     395,   177,   395,  -162,   411,   231,  -162,     4,  -162,     4,
      11,   203,   222,   144,     7,   411,   223,   132,   180,  -162,
    -162,   219,   185,  -162,   188,    35,   192,  -162,  -162,   132,
     132,   160,     9,   144,  -162,  -162,   395,  -162,     4,    41,
    -162,    64,  -162,   175,   267,    26,   222,   233,     9,  -162,
    -162,   202,   206,   255,    26,    26,  -162,  -162,  -162,  -162,
    -162,   256,  -162,  -162
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       8,     0,     0,    27,     7,     0,     9,    10,     1,     0,
      42,    26,     0,    11,     0,    28,     0,     6,    41,     0,
       0,     0,     0,     0,     0,     0,   111,   108,   109,   110,
       0,   107,     0,    30,    40,     0,    43,    45,     0,     0,
       0,     3,     4,     0,     0,     0,     0,    87,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,    34,     0,    31,    32,
      33,     0,     0,    44,     0,     0,    86,     5,     0,     0,
       0,     0,     0,   102,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,   112,     0,     0,     0,     0,
      29,    39,     0,    19,    19,     0,     0,     0,    86,     0,
      73,     0,     0,   111,     0,    47,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     2,
     103,   104,   105,   106,   113,     0,    35,    37,     0,    46,
      22,    21,     0,    17,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,    82,    25,    86,     0,     0,     0,
       0,    23,     0,     0,     0,    86,     0,     0,    75,    86,
      85,     0,    85,    48,    61,     0,    36,     0,    18,     0,
       8,     0,    65,     0,     0,    69,     0,     0,     0,    80,
      81,     0,     0,    20,     0,    27,     0,    72,    71,     0,
       0,    65,    78,     0,    76,    68,    83,    79,     0,     8,
      13,    42,    14,     0,     0,    86,    63,     0,    77,    84,
      38,     0,     0,     0,    86,    86,    66,    62,    15,    16,
      24,     0,    64,    70
  };

  const short int
  Parser::yypgoto_[] =
  {
    -162,  -162,   263,   272,  -162,  -162,   276,  -162,  -162,   179,
     129,  -162,    75,    62,    91,  -162,   285,   -69,  -162,  -162,
     239,  -162,   -12,    98,  -162,  -162,   282,  -103,  -162,   152,
    -162,  -162,   140,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -161,  -162,   -23,   -67
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,    77,   195,     4,     6,     7,    41,    42,   142,
     143,   144,   196,    78,    10,    11,    33,    67,    68,    69,
     137,    70,    99,    17,    18,    36,    37,   114,   115,   116,
     117,   118,   216,   217,   119,   120,   121,   199,   122,   123,
     124,   184,   125,   126,   171,   188,   127,    30,    31
  };

  const short int
  Parser::yytable_[] =
  {
      47,    48,    49,   102,    35,   149,   136,    64,   140,   128,
     140,   190,   -24,    57,    58,    59,    60,   141,     1,   141,
      79,    80,    81,    82,    35,   194,    65,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    76,   105,
      96,   128,   106,     1,   -23,   219,     8,   107,     1,    38,
     108,   109,   110,    34,    39,   221,     5,   203,    62,   111,
     112,   204,   182,    66,    63,     9,   186,    50,    51,   159,
      52,    53,    54,    12,   135,    55,    56,    57,    58,    59,
      60,   166,    14,   147,    61,   113,   151,    54,   152,   128,
      55,    56,    57,    58,    59,    60,    16,    62,   128,    38,
      62,   183,   128,    63,    39,   157,    63,    19,   192,    32,
     193,    34,   226,   -24,    59,    60,   202,   -24,    60,    20,
      21,   231,   232,   -24,    58,    59,    60,    43,    22,    44,
     170,   172,   162,    45,   174,   175,   218,    23,    19,   220,
      46,   181,    74,    24,   185,    71,    72,    75,   128,    95,
      20,    21,    97,   150,    25,    71,   138,   128,   128,    22,
      26,    27,    28,    29,   206,    71,   179,   101,    23,   169,
     215,   200,   100,   129,    24,   103,   213,   214,   104,   -24,
     139,   155,   146,   224,   160,    25,   148,   153,   154,   156,
     163,    26,    27,    28,    29,   161,    50,    51,   164,    52,
      53,    54,   167,    26,    55,    56,    57,    58,    59,    60,
      50,    51,   197,    52,    53,    54,   176,   177,    55,    56,
      57,    58,    59,    60,    55,    56,    57,    58,    59,    60,
     180,   189,   198,   200,   207,   205,   208,   209,    50,    51,
     210,    52,    53,    54,   212,   227,    55,    56,    57,    58,
      59,    60,    50,    51,   228,    52,    53,    54,   229,    76,
      55,    56,    57,    58,    59,    60,    50,    51,   233,    52,
      53,    54,     3,   134,    55,    56,    57,    58,    59,    60,
      40,   165,    13,   145,   222,   230,   211,   191,    50,    51,
     178,    52,    53,    54,    15,   225,    55,    56,    57,    58,
      59,    60,    50,    51,    98,    52,    53,    54,   173,   223,
      55,    56,    57,    58,    59,    60,    50,    51,    73,    52,
      53,    54,   201,     0,    55,    56,    57,    58,    59,    60,
       0,     0,     0,    50,    51,    83,    52,    53,    54,     0,
       0,    55,    56,    57,    58,    59,    60,     0,     0,     0,
      50,    51,   130,    52,    53,    54,     0,     0,    55,    56,
      57,    58,    59,    60,     0,     0,     0,    50,    51,   131,
      52,    53,    54,     0,     0,    55,    56,    57,    58,    59,
      60,     0,     0,     0,    50,    51,   132,    52,    53,    54,
       0,     0,    55,    56,    57,    58,    59,    60,     0,     0,
       0,    50,    51,   133,    52,    53,    54,     0,     0,    55,
      56,    57,    58,    59,    60,     0,    50,    51,   168,    52,
      53,    54,     0,     0,    55,    56,    57,    58,    59,    60,
      50,    51,   158,    52,    53,    54,     0,     0,    55,    56,
      57,    58,    59,    60,     0,   187,    50,    51,     0,    52,
      53,    54,     0,     0,    55,    56,    57,    58,    59,    60,
      51,     0,    52,    53,    54,     0,     0,    55,    56,    57,
      58,    59,    60,    52,    53,    54,     0,     0,    55,    56,
      57,    58,    59,    60,    53,    54,     0,     0,    55,    56,
      57,    58,    59,    60,   -24,    56,    57,    58,    59,    60
  };

  const short int
  Parser::yycheck_[] =
  {
      23,    24,    25,    72,    16,   108,    12,     3,    23,    76,
      23,   172,    44,    45,    46,    47,    48,    32,     7,    32,
      43,    44,    45,    46,    36,    14,    22,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,     4,    13,
      63,   108,    16,     7,    59,   206,     0,    21,     7,    15,
      24,    25,    26,    59,    20,    14,    59,    50,    49,    33,
      34,    54,   165,    59,    55,    30,   169,    35,    36,   138,
      38,    39,    40,    43,    97,    43,    44,    45,    46,    47,
      48,   148,    59,   106,    52,    59,   109,    40,   111,   156,
      43,    44,    45,    46,    47,    48,    32,    49,   165,    15,
      49,    50,   169,    55,    20,    57,    55,     6,   177,    43,
     179,    59,   215,    46,    47,    48,   183,    47,    48,    18,
      19,   224,   225,    45,    46,    47,    48,    53,    27,    53,
     153,   154,   144,    53,   157,   158,   203,    36,     6,   208,
      53,   164,    59,    42,   167,    50,    51,    59,   215,    59,
      18,    19,    55,    52,    53,    50,    51,   224,   225,    27,
      59,    60,    61,    62,   187,    50,    51,    59,    36,     8,
      10,    11,    52,    49,    42,    53,   199,   200,    53,    48,
      52,    12,    59,     8,    54,    53,    53,    53,    53,    51,
      54,    59,    60,    61,    62,    52,    35,    36,    57,    38,
      39,    40,    31,    59,    43,    44,    45,    46,    47,    48,
      35,    36,     9,    38,    39,    40,    52,    51,    43,    44,
      45,    46,    47,    48,    43,    44,    45,    46,    47,    48,
      52,    54,    29,    11,    54,    12,    17,    52,    35,    36,
      52,    38,    39,    40,    52,    12,    43,    44,    45,    46,
      47,    48,    35,    36,    52,    38,    39,    40,    52,     4,
      43,    44,    45,    46,    47,    48,    35,    36,    12,    38,
      39,    40,     0,    56,    43,    44,    45,    46,    47,    48,
      17,    28,     6,   104,   209,   223,   195,    56,    35,    36,
     161,    38,    39,    40,     9,    28,    43,    44,    45,    46,
      47,    48,    35,    36,    65,    38,    39,    40,   156,   211,
      43,    44,    45,    46,    47,    48,    35,    36,    36,    38,
      39,    40,   182,    -1,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    35,    36,    54,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      35,    36,    54,    38,    39,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    35,    36,    54,
      38,    39,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    35,    36,    54,    38,    39,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    35,    36,    54,    38,    39,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    -1,    35,    36,    52,    38,
      39,    40,    -1,    -1,    43,    44,    45,    46,    47,    48,
      35,    36,    51,    38,    39,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    -1,    50,    35,    36,    -1,    38,
      39,    40,    -1,    -1,    43,    44,    45,    46,    47,    48,
      36,    -1,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    38,    39,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    39,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    43,    44,    45,    46,    47,    48
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     7,    64,    66,    67,    59,    68,    69,     0,    30,
      77,    78,    43,    69,    59,    79,    32,    86,    87,     6,
      18,    19,    27,    36,    42,    53,    59,    60,    61,    62,
     110,   111,    43,    79,    59,    85,    88,    89,    15,    20,
      65,    70,    71,    53,    53,    53,    53,   110,   110,   110,
      35,    36,    38,    39,    40,    43,    44,    45,    46,    47,
      48,    52,    49,    55,     3,    22,    59,    80,    81,    82,
      84,    50,    51,    89,    59,    59,     4,    65,    76,   110,
     110,   110,   110,    54,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,    59,   110,    55,    83,    85,
      52,    59,    80,    53,    53,    13,    16,    21,    24,    25,
      26,    33,    34,    59,    90,    91,    92,    93,    94,    97,
      98,    99,   101,   102,   103,   105,   106,   109,   111,    49,
      54,    54,    54,    54,    56,   110,    12,    83,    51,    52,
      23,    32,    72,    73,    74,    72,    59,   110,    53,    90,
      52,   110,   110,    53,    53,    12,    51,    57,    51,    80,
      54,    52,    85,    54,    57,    28,   111,    31,    52,     8,
     110,   107,   110,    92,   110,   110,    52,    51,    73,    51,
      52,   110,    90,    50,   104,   110,    90,    50,   108,    54,
     108,    56,    80,    80,    14,    66,    75,     9,    29,   100,
      11,    95,   111,    50,    54,    12,   110,    54,    17,    52,
      52,    77,    52,   110,   110,    10,    95,    96,   111,   108,
      80,    14,    75,    86,     8,    28,    90,    12,    52,    52,
      76,    90,    90,    12
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    63,    64,    65,    65,    65,    65,    66,    66,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      73,    74,    74,    74,    75,    76,    77,    77,    78,    79,
      79,    80,    80,    80,    81,    82,    83,    83,    84,    85,
      85,    86,    86,    87,    88,    88,    89,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    94,    95,    95,    95,    96,    96,    97,    98,
      99,   100,   100,   101,   102,   102,   103,   104,   104,   105,
     106,   107,   107,   108,   108,   108,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   111
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     6,     1,     1,     2,     0,     1,     0,     2,
       1,     2,     4,     8,     8,    10,    10,     1,     3,     0,
       4,     1,     1,     0,     4,     3,     1,     0,     2,     4,
       2,     1,     1,     1,     1,     3,     4,     2,     8,     3,
       1,     1,     0,     2,     2,     1,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     7,     2,     4,     0,     2,     0,     5,     4,
       9,     1,     1,     1,     2,     3,     5,     3,     2,     5,
       4,     2,     0,     2,     3,     0,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     4,     4,     4,     4,     1,     1,     1,
       1,     1,     3,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "ArrayTok", "BeginTok", "EndProgTok",
  "ChrTok", "ConstTok", "DoTok", "DowntoTok", "ElseTok", "ElseifTok",
  "EndTok", "ForTok", "ForwardTok", "FunctionTok", "IfTok", "OfTok",
  "OrdTok", "PredTok", "ProcedureTok", "ReadTok", "RecordTok", "RefTok",
  "RepeatTok", "ReturnTok", "StopTok", "SuccTok", "ThenTok", "ToTok",
  "TypeTok", "UntilTok", "VarTok", "WhileTok", "WriteTok", "PlusTok",
  "MinusTok", "UnaryMinusTok", "MultiplyTok", "DivideTok", "AndTok",
  "OrTok", "NotTok", "EqualsTok", "NotEqualTok", "LessThanTok",
  "LessEqualTok", "GreaterTok", "GreaterEqualTok", "DotTok", "CommaTok",
  "ColonTok", "SemicolonTok", "OpenParenTok", "CloseParenTok",
  "OpenBrktTok", "CloseBrktTok", "ColonEqualTok", "PercentTok",
  "IdentifierTok", "IntTok", "StringTok", "CharTok", "$accept",
  "Application", "ProcedureFunctionOptional", "ConstDeclOptional",
  "ConstDecl", "ConstDecls", "ConstDeclOne", "ProcedureDecl",
  "FunctionDecl", "FormalParametersOptional", "FormalParameter",
  "VarRefOptional", "Body", "Block", "TypeDeclOptional", "TypeDecls",
  "TypeDecl", "Type", "SimpleType", "RecordType", "Records", "ArrayType",
  "IdentList", "VarDeclOptional", "VarDecl", "VarDecls", "VarDeclOne",
  "StatementSequence", "Statements", "Statement", "Assignment",
  "IfStatement", "ElseIfStatements", "ElseOptional", "WhileStatement",
  "RepeatStatement", "ForStatement", "ToDown", "StopStatement",
  "ReturnStatement", "ReadStatement", "LValOptional", "WriteStatement",
  "ProcedureCall", "ExpressionsOptional", "ExpressionOptional",
  "NullStatement", "Expression", "LVal", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   116,   116,   118,   119,   120,   121,   124,   125,   127,
     129,   130,   132,   135,   136,   138,   139,   141,   142,   143,
     145,   147,   148,   149,   151,   153,   156,   157,   159,   161,
     162,   164,   165,   166,   168,   170,   172,   173,   175,   177,
     178,   181,   182,   184,   186,   187,   189,   192,   194,   195,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   209,   211,   213,   214,   215,   217,   218,   220,   222,
     224,   226,   227,   229,   231,   232,   234,   236,   237,   239,
     241,   243,   244,   246,   247,   248,   250,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   270,   271,   272,   273,   274,   275,   276,
     277,   279,   280,   281
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
    };
    const unsigned int user_token_number_max_ = 317;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // FC
#line 1867 "parser.cpp" // lalr1.cc:1155
#line 284 "parser.ypp" // lalr1.cc:1156
 /*** Additional Code ***/

void FC::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
