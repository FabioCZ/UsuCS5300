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
#line 38 "parser.ypp" // lalr1.cc:399


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
    #line 28 "parser.ypp" // lalr1.cc:725
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
#line 193 "parser.ypp" // lalr1.cc:847
    {}
#line 852 "parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 196 "parser.ypp" // lalr1.cc:847
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
#line 208 "parser.ypp" // lalr1.cc:847
    {}
#line 924 "parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 210 "parser.ypp" // lalr1.cc:847
    {}
#line 930 "parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 212 "parser.ypp" // lalr1.cc:847
    {}
#line 936 "parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 213 "parser.ypp" // lalr1.cc:847
    {}
#line 942 "parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 216 "parser.ypp" // lalr1.cc:847
    {}
#line 948 "parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 219 "parser.ypp" // lalr1.cc:847
    {}
#line 954 "parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 221 "parser.ypp" // lalr1.cc:847
    {}
#line 960 "parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 223 "parser.ypp" // lalr1.cc:847
    {}
#line 966 "parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 225 "parser.ypp" // lalr1.cc:847
    {}
#line 972 "parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 226 "parser.ypp" // lalr1.cc:847
    {}
#line 978 "parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 228 "parser.ypp" // lalr1.cc:847
    {}
#line 984 "parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 230 "parser.ypp" // lalr1.cc:847
    {}
#line 990 "parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 231 "parser.ypp" // lalr1.cc:847
    {}
#line 996 "parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 233 "parser.ypp" // lalr1.cc:847
    {}
#line 1002 "parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 235 "parser.ypp" // lalr1.cc:847
    {}
#line 1008 "parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 236 "parser.ypp" // lalr1.cc:847
    {}
#line 1014 "parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 238 "parser.ypp" // lalr1.cc:847
    {}
#line 1020 "parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 240 "parser.ypp" // lalr1.cc:847
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

  case 82:
#line 245 "parser.ypp" // lalr1.cc:847
    {}
#line 1044 "parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 248 "parser.ypp" // lalr1.cc:847
    {}
#line 1050 "parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 249 "parser.ypp" // lalr1.cc:847
    {}
#line 1056 "parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 252 "parser.ypp" // lalr1.cc:847
    {}
#line 1062 "parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 255 "parser.ypp" // lalr1.cc:847
    {}
#line 1068 "parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 256 "parser.ypp" // lalr1.cc:847
    {}
#line 1074 "parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 257 "parser.ypp" // lalr1.cc:847
    {}
#line 1080 "parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 258 "parser.ypp" // lalr1.cc:847
    {}
#line 1086 "parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 259 "parser.ypp" // lalr1.cc:847
    {}
#line 1092 "parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 260 "parser.ypp" // lalr1.cc:847
    {}
#line 1098 "parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 261 "parser.ypp" // lalr1.cc:847
    {}
#line 1104 "parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 262 "parser.ypp" // lalr1.cc:847
    {}
#line 1110 "parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 263 "parser.ypp" // lalr1.cc:847
    {}
#line 1116 "parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 264 "parser.ypp" // lalr1.cc:847
    {}
#line 1122 "parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 265 "parser.ypp" // lalr1.cc:847
    {}
#line 1128 "parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 266 "parser.ypp" // lalr1.cc:847
    {}
#line 1134 "parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 267 "parser.ypp" // lalr1.cc:847
    {}
#line 1140 "parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 268 "parser.ypp" // lalr1.cc:847
    {}
#line 1146 "parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 269 "parser.ypp" // lalr1.cc:847
    {}
#line 1152 "parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 271 "parser.ypp" // lalr1.cc:847
    {}
#line 1158 "parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 272 "parser.ypp" // lalr1.cc:847
    {}
#line 1164 "parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 273 "parser.ypp" // lalr1.cc:847
    {}
#line 1170 "parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 274 "parser.ypp" // lalr1.cc:847
    {}
#line 1176 "parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 275 "parser.ypp" // lalr1.cc:847
    {}
#line 1182 "parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 276 "parser.ypp" // lalr1.cc:847
    {}
#line 1188 "parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 277 "parser.ypp" // lalr1.cc:847
    {}
#line 1194 "parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 278 "parser.ypp" // lalr1.cc:847
    {}
#line 1200 "parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 280 "parser.ypp" // lalr1.cc:847
    {}
#line 1206 "parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 281 "parser.ypp" // lalr1.cc:847
    {}
#line 1212 "parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 282 "parser.ypp" // lalr1.cc:847
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


  const signed char Parser::yypact_ninf_ = -110;

  const signed char Parser::yytable_ninf_ = -87;

  const short int
  Parser::yypact_[] =
  {
      17,    -3,    88,    60,  -110,    52,    -3,  -110,  -110,    41,
      65,  -110,   148,  -110,    62,    41,    69,    49,  -110,    90,
      91,    95,    98,   148,   148,   148,   102,  -110,  -110,  -110,
     345,   -28,     1,    41,  -110,   -43,    69,  -110,    81,    97,
      55,  -110,  -110,   148,   148,   148,   148,   398,    77,   260,
     100,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,  -110,   111,   148,    53,    69,  -110,    61,  -110,
    -110,  -110,   115,     1,  -110,   130,   158,     4,    49,   165,
     277,   294,   311,   328,  -110,   151,   168,   374,   387,   398,
     152,   407,    77,   232,    86,   141,   156,    32,   171,  -110,
      38,   148,    -6,   -15,  -110,  -110,   175,    34,    34,   169,
     148,   176,     4,   148,  -110,   148,   178,   181,     2,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,    47,   230,  -110,  -110,  -110,  -110,  -110,   148,  -110,
     360,  -110,    69,     1,  -110,  -110,  -110,   184,   187,    69,
     194,   195,   225,   203,   -26,   374,   133,   148,   100,  -110,
       4,   148,  -110,   374,   148,   214,   236,   -13,    87,   231,
     148,     4,  -110,    37,   -28,   148,     4,    57,   374,   234,
    -110,   374,   211,  -110,     1,  -110,     1,    54,   197,    -2,
     203,  -110,   374,     3,   148,  -110,  -110,   280,   249,  -110,
     250,    60,   257,  -110,  -110,   148,   148,   136,   -28,  -110,
     374,     1,    58,  -110,    65,  -110,   177,   246,     4,   299,
     306,  -110,   259,   267,   322,     4,     4,   275,  -110,  -110,
    -110,  -110,     6,   275,  -110
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       8,     0,     0,    27,     7,     0,     9,    10,     1,     0,
      42,    26,     0,    11,     0,    28,     0,     6,    41,     0,
       0,     0,     0,     0,     0,     0,   112,   109,   110,   111,
       0,   108,     0,    30,    40,     0,    43,    45,     0,     0,
       0,     3,     4,     0,     0,     0,     0,   101,   100,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,    34,     0,    31,
      32,    33,     0,     0,    44,     0,     0,    87,     5,     0,
       0,     0,     0,     0,   102,     0,    82,    85,    95,    96,
      97,    98,    88,    89,    90,    93,    91,    94,    92,   113,
       0,     0,     0,     0,    29,    39,     0,    19,    19,     0,
       0,     0,    87,    73,    72,     0,     0,   112,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,   104,   105,   106,   107,   103,     0,   114,
       0,    35,    37,     0,    46,    22,    21,     0,    17,     0,
       0,     0,     0,     0,     0,    74,     0,     0,    83,    25,
      87,     0,     2,    84,     0,     0,     0,    23,     0,     0,
       0,    87,   112,     0,    77,     0,    87,     0,    79,     0,
      47,    60,     0,    36,     0,    18,     0,     8,     0,    64,
       0,    75,    68,     0,     0,    78,    81,     0,     0,    20,
       0,    27,     0,    71,    70,     0,     0,    64,    76,    67,
      80,     0,     8,    13,    42,    14,     0,     0,    87,    62,
       0,    38,     0,     0,     0,    87,    87,    65,    61,    15,
      16,    24,     0,    63,    69
  };

  const short int
  Parser::yypgoto_[] =
  {
    -110,  -110,   318,   336,  -110,  -110,   337,  -110,  -110,   220,
     185,  -110,   132,   121,   159,  -110,   344,   -72,  -110,  -110,
     295,  -110,   -14,   155,  -110,  -110,   326,  -109,   210,  -110,
    -110,   188,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,   221,  -110,  -110,   -12,   -61
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,    78,   201,     4,     6,     7,    41,    42,   147,
     148,   149,   202,    79,    10,    11,    33,    68,    69,    70,
     142,    71,   103,    17,    18,    36,    37,   118,   119,   120,
     121,   219,   220,   122,   123,   124,   205,   125,   126,   127,
     173,   128,   177,   129,    85,    86,   130,    87,    31
  };

  const short int
  Parser::yytable_[] =
  {
      30,   106,    35,   154,    65,   175,   141,    72,    73,   206,
     145,    47,    48,    49,   159,   209,   131,   109,   234,   146,
     110,    63,    35,    66,     1,   111,   160,    64,   112,   113,
     114,    80,    81,    82,    83,    72,   143,   115,   116,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     160,   131,   100,    34,   160,   160,     5,   145,   160,    77,
      67,     1,   189,   117,    38,     1,   146,   193,   200,    39,
      38,   165,   222,    51,    52,    39,    53,    54,    55,   -87,
      61,    56,    57,    58,    59,    60,    61,   190,     8,   140,
       9,   191,   174,   -23,   139,    12,    63,    16,   152,   131,
      14,   155,    64,   156,   161,    32,    19,   194,   101,   227,
     131,   195,   198,   104,   199,   131,   232,   233,    20,    21,
      56,    57,    58,    59,    60,    61,   163,    22,    34,   208,
     -87,    58,    59,    60,    61,   168,    23,    72,   186,   221,
      75,   176,    24,    43,    44,   178,   218,   206,    45,   181,
     -86,    46,   182,    25,    19,    50,    76,   131,   188,    26,
      27,    28,    29,   192,   131,   131,    20,    21,    51,    52,
      99,    53,    54,    55,   105,    22,    56,    57,    58,    59,
      60,    61,   210,   107,    23,   225,   -87,    59,    60,    61,
      24,    54,    55,   216,   217,    56,    57,    58,    59,    60,
      61,    25,   -87,    60,    61,   137,   203,    26,    27,    28,
      29,   108,    51,    52,   132,    53,    54,    55,   138,   -87,
      56,    57,    58,    59,    60,    61,   204,   144,   151,   153,
     162,   157,    51,    52,   158,    53,    54,    55,   166,   167,
      56,    57,    58,    59,    60,    61,    51,    52,   169,    53,
      54,    55,   170,   171,    56,    57,    58,    59,    60,    61,
      51,    52,   172,    53,    54,    55,   183,   197,    56,    57,
      58,    59,    60,    61,   226,   -87,    57,    58,    59,    60,
      61,    51,    52,   187,    53,    54,    55,   184,   196,    56,
      57,    58,    59,    60,    61,    51,    52,   211,    53,    54,
      55,   212,   213,    56,    57,    58,    59,    60,    61,   215,
     206,   229,    51,    52,    84,    53,    54,    55,   228,   230,
      56,    57,    58,    59,    60,    61,    77,   160,   150,    51,
      52,   133,    53,    54,    55,    40,     3,    56,    57,    58,
      59,    60,    61,    13,   223,   231,    51,    52,   134,    53,
      54,    55,   185,    15,    56,    57,    58,    59,    60,    61,
     214,   102,    74,    51,    52,   135,    53,    54,    55,   224,
     180,    56,    57,    58,    59,    60,    61,   207,     0,   179,
      51,    52,   136,    53,    54,    55,     0,     0,    56,    57,
      58,    59,    60,    61,     0,    51,    52,    62,    53,    54,
      55,     0,     0,    56,    57,    58,    59,    60,    61,    51,
      52,   164,    53,    54,    55,     0,     0,    56,    57,    58,
      59,    60,    61,    52,     0,    53,    54,    55,     0,     0,
      56,    57,    58,    59,    60,    61,    53,    54,    55,     0,
       0,    56,    57,    58,    59,    60,    61,    55,     0,     0,
      56,    57,    58,    59,    60,    61
  };

  const short int
  Parser::yycheck_[] =
  {
      12,    73,    16,   112,     3,    31,    12,    50,    51,    11,
      23,    23,    24,    25,    12,    12,    77,    13,    12,    32,
      16,    49,    36,    22,     7,    21,    52,    55,    24,    25,
      26,    43,    44,    45,    46,    50,    51,    33,    34,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      52,   112,    64,    59,    52,    52,    59,    23,    52,     4,
      59,     7,   171,    59,    15,     7,    32,   176,    14,    20,
      15,   143,    14,    35,    36,    20,    38,    39,    40,    47,
      48,    43,    44,    45,    46,    47,    48,    50,     0,   101,
      30,    54,   153,    59,    56,    43,    49,    32,   110,   160,
      59,   113,    55,   115,    57,    43,     6,    50,    55,   218,
     171,    54,   184,    52,   186,   176,   225,   226,    18,    19,
      43,    44,    45,    46,    47,    48,   138,    27,    59,   190,
      44,    45,    46,    47,    48,   149,    36,    50,    51,   211,
      59,     8,    42,    53,    53,   157,    10,    11,    53,   161,
      50,    53,   164,    53,     6,    53,    59,   218,   170,    59,
      60,    61,    62,   175,   225,   226,    18,    19,    35,    36,
      59,    38,    39,    40,    59,    27,    43,    44,    45,    46,
      47,    48,   194,    53,    36,     8,    45,    46,    47,    48,
      42,    39,    40,   205,   206,    43,    44,    45,    46,    47,
      48,    53,    46,    47,    48,    54,     9,    59,    60,    61,
      62,    53,    35,    36,    49,    38,    39,    40,    50,    48,
      43,    44,    45,    46,    47,    48,    29,    52,    59,    53,
       0,    53,    35,    36,    53,    38,    39,    40,    54,    52,
      43,    44,    45,    46,    47,    48,    35,    36,    54,    38,
      39,    40,    57,    28,    43,    44,    45,    46,    47,    48,
      35,    36,    59,    38,    39,    40,    52,    56,    43,    44,
      45,    46,    47,    48,    28,    43,    44,    45,    46,    47,
      48,    35,    36,    52,    38,    39,    40,    51,    54,    43,
      44,    45,    46,    47,    48,    35,    36,    17,    38,    39,
      40,    52,    52,    43,    44,    45,    46,    47,    48,    52,
      11,    52,    35,    36,    54,    38,    39,    40,    12,    52,
      43,    44,    45,    46,    47,    48,     4,    52,   108,    35,
      36,    54,    38,    39,    40,    17,     0,    43,    44,    45,
      46,    47,    48,     6,   212,   224,    35,    36,    54,    38,
      39,    40,   167,     9,    43,    44,    45,    46,    47,    48,
     201,    66,    36,    35,    36,    54,    38,    39,    40,   214,
     160,    43,    44,    45,    46,    47,    48,   189,    -1,   158,
      35,    36,    54,    38,    39,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    -1,    35,    36,    52,    38,    39,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    35,
      36,    51,    38,    39,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    36,    -1,    38,    39,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     7,    64,    66,    67,    59,    68,    69,     0,    30,
      77,    78,    43,    69,    59,    79,    32,    86,    87,     6,
      18,    19,    27,    36,    42,    53,    59,    60,    61,    62,
     110,   111,    43,    79,    59,    85,    88,    89,    15,    20,
      65,    70,    71,    53,    53,    53,    53,   110,   110,   110,
      53,    35,    36,    38,    39,    40,    43,    44,    45,    46,
      47,    48,    52,    49,    55,     3,    22,    59,    80,    81,
      82,    84,    50,    51,    89,    59,    59,     4,    65,    76,
     110,   110,   110,   110,    54,   107,   108,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,    59,
     110,    55,    83,    85,    52,    59,    80,    53,    53,    13,
      16,    21,    24,    25,    26,    33,    34,    59,    90,    91,
      92,    93,    96,    97,    98,   100,   101,   102,   104,   106,
     109,   111,    49,    54,    54,    54,    54,    54,    50,    56,
     110,    12,    83,    51,    52,    23,    32,    72,    73,    74,
      72,    59,   110,    53,    90,   110,   110,    53,    53,    12,
      52,    57,     0,   110,    51,    80,    54,    52,    85,    54,
      57,    28,    59,   103,   111,    31,     8,   105,   110,   107,
      91,   110,   110,    52,    51,    73,    51,    52,   110,    90,
      50,    54,   110,    90,    50,    54,    54,    56,    80,    80,
      14,    66,    75,     9,    29,    99,    11,    94,   111,    12,
     110,    17,    52,    52,    77,    52,   110,   110,    10,    94,
      95,    80,    14,    75,    86,     8,    28,    90,    12,    52,
      52,    76,    90,    90,    12
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    63,    64,    65,    65,    65,    65,    66,    66,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      73,    74,    74,    74,    75,    76,    77,    77,    78,    79,
      79,    80,    80,    80,    81,    82,    83,    83,    84,    85,
      85,    86,    86,    87,    88,    88,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    93,    94,    94,    94,    95,    95,    96,    97,    98,
      99,    99,   100,   101,   101,   102,   103,   103,   104,   105,
     105,   106,   107,   107,   108,   108,   108,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   111
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     7,     1,     1,     2,     0,     1,     0,     2,
       1,     2,     4,     8,     8,    10,    10,     1,     3,     0,
       4,     1,     1,     0,     4,     3,     1,     0,     2,     4,
       2,     1,     1,     1,     1,     3,     4,     2,     8,     3,
       1,     1,     0,     2,     2,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     7,     2,     4,     0,     2,     0,     5,     4,     9,
       1,     1,     1,     1,     2,     4,     3,     1,     4,     1,
       3,     4,     1,     0,     3,     1,     0,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     4,     4,     4,     4,     4,     1,     1,
       1,     1,     1,     3,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "ArrayTok", "BeginTok",
  "EndProgTok", "ChrTok", "ConstTok", "DoTok", "DowntoTok", "ElseTok",
  "ElseifTok", "EndTok", "ForTok", "ForwardTok", "FunctionTok", "IfTok",
  "OfTok", "OrdTok", "PredTok", "ProcedureTok", "ReadTok", "RecordTok",
  "RefTok", "RepeatTok", "ReturnTok", "StopTok", "SuccTok", "ThenTok",
  "ToTok", "TypeTok", "UntilTok", "VarTok", "WhileTok", "WriteTok",
  "PlusTok", "MinusTok", "UnaryMinusTok", "MultiplyTok", "DivideTok",
  "AndTok", "OrTok", "NotTok", "EqualsTok", "NotEqualTok", "LessThanTok",
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
  "StatementSequence", "Statement", "Assignment", "IfStatement",
  "ElseIfStatements", "ElseOptional", "WhileStatement", "RepeatStatement",
  "ForStatement", "ToDown", "StopStatement", "ReturnStatement",
  "ReadStatement", "LValOptional", "WriteStatement", "WriteExpressions",
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
     178,   181,   182,   184,   186,   187,   189,   192,   193,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     208,   210,   212,   213,   214,   216,   217,   219,   221,   223,
     225,   226,   228,   230,   231,   233,   235,   236,   238,   240,
     241,   243,   245,   246,   248,   249,   250,   252,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   280,   281,   282
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
#line 1859 "parser.cpp" // lalr1.cc:1155
#line 285 "parser.ypp" // lalr1.cc:1156
 /*** Additional Code ***/

void FC::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
