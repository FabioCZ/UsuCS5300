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
    {/*TODO add main here*/}
#line 612 "parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 125 "parser.ypp" // lalr1.cc:847
    {/*TODO add cosntant*/}
#line 618 "parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 131 "parser.ypp" // lalr1.cc:847
    {}
#line 624 "parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 132 "parser.ypp" // lalr1.cc:847
    {}
#line 630 "parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 134 "parser.ypp" // lalr1.cc:847
    {}
#line 636 "parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 136 "parser.ypp" // lalr1.cc:847
    {}
#line 642 "parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 137 "parser.ypp" // lalr1.cc:847
    {}
#line 648 "parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 139 "parser.ypp" // lalr1.cc:847
    {}
#line 654 "parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 141 "parser.ypp" // lalr1.cc:847
    {}
#line 660 "parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 142 "parser.ypp" // lalr1.cc:847
    {}
#line 666 "parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 144 "parser.ypp" // lalr1.cc:847
    {}
#line 672 "parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 145 "parser.ypp" // lalr1.cc:847
    {}
#line 678 "parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 147 "parser.ypp" // lalr1.cc:847
    {}
#line 684 "parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 149 "parser.ypp" // lalr1.cc:847
    {}
#line 690 "parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 150 "parser.ypp" // lalr1.cc:847
    {}
#line 696 "parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 151 "parser.ypp" // lalr1.cc:847
    {}
#line 702 "parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 153 "parser.ypp" // lalr1.cc:847
    {}
#line 708 "parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 155 "parser.ypp" // lalr1.cc:847
    {}
#line 714 "parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 157 "parser.ypp" // lalr1.cc:847
    {}
#line 720 "parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 158 "parser.ypp" // lalr1.cc:847
    {}
#line 726 "parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 166 "parser.ypp" // lalr1.cc:847
    {}
#line 732 "parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 168 "parser.ypp" // lalr1.cc:847
    {}
#line 738 "parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 169 "parser.ypp" // lalr1.cc:847
    {}
#line 744 "parser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 170 "parser.ypp" // lalr1.cc:847
    {}
#line 750 "parser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 172 "parser.ypp" // lalr1.cc:847
    {/* todo type lookup */}
#line 756 "parser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 174 "parser.ypp" // lalr1.cc:847
    {}
#line 762 "parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 176 "parser.ypp" // lalr1.cc:847
    {}
#line 768 "parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 177 "parser.ypp" // lalr1.cc:847
    {}
#line 774 "parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 179 "parser.ypp" // lalr1.cc:847
    {}
#line 780 "parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 181 "parser.ypp" // lalr1.cc:847
    {}
#line 786 "parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 182 "parser.ypp" // lalr1.cc:847
    {}
#line 792 "parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 184 "parser.ypp" // lalr1.cc:847
    {}
#line 798 "parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 192 "parser.ypp" // lalr1.cc:847
    {/*todo add var*/}
#line 804 "parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 194 "parser.ypp" // lalr1.cc:847
    {}
#line 810 "parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 195 "parser.ypp" // lalr1.cc:847
    {}
#line 816 "parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 196 "parser.ypp" // lalr1.cc:847
    {}
#line 822 "parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 197 "parser.ypp" // lalr1.cc:847
    {}
#line 828 "parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 198 "parser.ypp" // lalr1.cc:847
    {}
#line 834 "parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 199 "parser.ypp" // lalr1.cc:847
    {}
#line 840 "parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 200 "parser.ypp" // lalr1.cc:847
    {}
#line 846 "parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 201 "parser.ypp" // lalr1.cc:847
    {}
#line 852 "parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 202 "parser.ypp" // lalr1.cc:847
    {}
#line 858 "parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 203 "parser.ypp" // lalr1.cc:847
    {}
#line 864 "parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 204 "parser.ypp" // lalr1.cc:847
    {}
#line 870 "parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 206 "parser.ypp" // lalr1.cc:847
    {/* todo assignment*/}
#line 876 "parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 208 "parser.ypp" // lalr1.cc:847
    {}
#line 882 "parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 210 "parser.ypp" // lalr1.cc:847
    {}
#line 888 "parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 212 "parser.ypp" // lalr1.cc:847
    {}
#line 894 "parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 214 "parser.ypp" // lalr1.cc:847
    {}
#line 900 "parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 215 "parser.ypp" // lalr1.cc:847
    {}
#line 906 "parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 217 "parser.ypp" // lalr1.cc:847
    {}
#line 912 "parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 218 "parser.ypp" // lalr1.cc:847
    {}
#line 918 "parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 220 "parser.ypp" // lalr1.cc:847
    {}
#line 924 "parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 221 "parser.ypp" // lalr1.cc:847
    {}
#line 930 "parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 223 "parser.ypp" // lalr1.cc:847
    {}
#line 936 "parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 225 "parser.ypp" // lalr1.cc:847
    {}
#line 942 "parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 227 "parser.ypp" // lalr1.cc:847
    {}
#line 948 "parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 229 "parser.ypp" // lalr1.cc:847
    {}
#line 954 "parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 231 "parser.ypp" // lalr1.cc:847
    {}
#line 960 "parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 233 "parser.ypp" // lalr1.cc:847
    {}
#line 966 "parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 234 "parser.ypp" // lalr1.cc:847
    {}
#line 972 "parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 236 "parser.ypp" // lalr1.cc:847
    {/* TODO stop*/}
#line 978 "parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 238 "parser.ypp" // lalr1.cc:847
    {}
#line 984 "parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 239 "parser.ypp" // lalr1.cc:847
    {}
#line 990 "parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 241 "parser.ypp" // lalr1.cc:847
    {}
#line 996 "parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 243 "parser.ypp" // lalr1.cc:847
    {/*todo readval */}
#line 1002 "parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 244 "parser.ypp" // lalr1.cc:847
    {/*todo*/}
#line 1008 "parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 246 "parser.ypp" // lalr1.cc:847
    {}
#line 1014 "parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 248 "parser.ypp" // lalr1.cc:847
    {}
#line 1020 "parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 249 "parser.ypp" // lalr1.cc:847
    {}
#line 1026 "parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 251 "parser.ypp" // lalr1.cc:847
    {}
#line 1032 "parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 253 "parser.ypp" // lalr1.cc:847
    {}
#line 1038 "parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 254 "parser.ypp" // lalr1.cc:847
    {}
#line 1044 "parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 256 "parser.ypp" // lalr1.cc:847
    {}
#line 1050 "parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 257 "parser.ypp" // lalr1.cc:847
    {}
#line 1056 "parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 259 "parser.ypp" // lalr1.cc:847
    {}
#line 1062 "parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 260 "parser.ypp" // lalr1.cc:847
    {}
#line 1068 "parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 261 "parser.ypp" // lalr1.cc:847
    {}
#line 1074 "parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 262 "parser.ypp" // lalr1.cc:847
    {}
#line 1080 "parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 263 "parser.ypp" // lalr1.cc:847
    {}
#line 1086 "parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 264 "parser.ypp" // lalr1.cc:847
    {}
#line 1092 "parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 265 "parser.ypp" // lalr1.cc:847
    {}
#line 1098 "parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 266 "parser.ypp" // lalr1.cc:847
    {}
#line 1104 "parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 267 "parser.ypp" // lalr1.cc:847
    {}
#line 1110 "parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 268 "parser.ypp" // lalr1.cc:847
    {}
#line 1116 "parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 269 "parser.ypp" // lalr1.cc:847
    {}
#line 1122 "parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 270 "parser.ypp" // lalr1.cc:847
    {}
#line 1128 "parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 271 "parser.ypp" // lalr1.cc:847
    {}
#line 1134 "parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 272 "parser.ypp" // lalr1.cc:847
    {}
#line 1140 "parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 273 "parser.ypp" // lalr1.cc:847
    {}
#line 1146 "parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 274 "parser.ypp" // lalr1.cc:847
    {}
#line 1152 "parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 275 "parser.ypp" // lalr1.cc:847
    {}
#line 1158 "parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 276 "parser.ypp" // lalr1.cc:847
    {}
#line 1164 "parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 277 "parser.ypp" // lalr1.cc:847
    {}
#line 1170 "parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 278 "parser.ypp" // lalr1.cc:847
    {}
#line 1176 "parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 279 "parser.ypp" // lalr1.cc:847
    {}
#line 1182 "parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 280 "parser.ypp" // lalr1.cc:847
    {}
#line 1188 "parser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 281 "parser.ypp" // lalr1.cc:847
    {}
#line 1194 "parser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 285 "parser.ypp" // lalr1.cc:847
    {}
#line 1200 "parser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 286 "parser.ypp" // lalr1.cc:847
    {}
#line 1206 "parser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 287 "parser.ypp" // lalr1.cc:847
    {}
#line 1212 "parser.cpp" // lalr1.cc:847
    break;


#line 1216 "parser.cpp" // lalr1.cc:847
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


  const short int Parser::yypact_ninf_ = -130;

  const signed char Parser::yytable_ninf_ = -93;

  const short int
  Parser::yypact_[] =
  {
      16,   -26,    39,    37,    15,     9,   -26,  -130,  -130,    -4,
      -2,     0,    35,    87,  -130,    14,    87,    22,    -4,    87,
    -130,    87,    34,    36,   -10,  -130,  -130,  -130,    67,  -130,
     105,  -130,  -130,    -1,  -130,  -130,  -130,  -130,  -130,    -9,
     101,    72,     0,  -130,    66,  -130,    77,   110,   114,   115,
      87,    87,    87,  -130,  -130,  -130,  -130,   247,    41,    84,
     308,    95,   -15,   308,   308,    87,    87,  -130,    -4,    -4,
    -130,    -4,    87,    87,   149,    99,    87,    87,  -130,     4,
    -130,   124,    66,  -130,    23,    87,    87,    87,    87,   319,
      74,   145,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,  -130,    87,    45,    41,    87,    42,   308,
     122,   129,   276,  -130,   125,   127,     1,   308,   308,    -4,
    -130,   162,   308,   132,  -130,  -130,   142,  -130,  -130,  -130,
       4,  -130,   136,   137,  -130,   151,  -130,   152,   179,   196,
     213,   230,  -130,    88,   319,   329,   338,    74,   344,    63,
     348,   104,    56,   163,   308,   170,  -130,   308,    87,  -130,
    -130,    87,    -4,    -4,    67,   200,  -130,     2,  -130,    87,
      -8,  -130,   161,   168,   175,    17,    18,  -130,  -130,  -130,
    -130,    95,   308,   292,   125,   125,  -130,  -130,  -130,   262,
    -130,   178,  -130,  -130,   -13,   -13,   185,    15,   186,   193,
     194,    41,    87,     4,  -130,  -130,   176,   195,  -130,   203,
     201,  -130,    35,  -130,  -130,  -130,   126,   202,   212,    -5,
    -130,    93,  -130,    37,   254,  -130,     4,  -130,   205,     4,
    -130,     4,  -130,  -130,  -130,  -130
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       5,     0,     0,     0,    31,     0,     4,     7,     1,    61,
       0,     0,    47,     0,     6,     0,     0,    81,    61,     0,
      79,     0,     0,   118,     0,    29,    51,    52,     0,    53,
       0,    54,    55,     0,    56,    57,    58,    59,    60,     0,
       0,     0,    30,    33,     0,    11,     0,     0,     0,     0,
       0,     0,     0,   118,   113,   114,   115,     0,   112,     0,
      64,     0,     0,    80,    73,     0,     0,    27,    61,    61,
      67,    61,     0,     0,     0,     0,     0,     0,     2,     0,
      32,     0,    46,    49,     3,     0,     0,     0,     0,   106,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,    84,     0,     0,    87,
       0,     0,    90,    28,    65,    69,     0,    78,    77,    61,
     116,     0,    62,     0,    41,    38,     0,    35,    36,    37,
       0,    48,     0,     0,     9,     0,    10,     0,     0,     0,
       0,     0,   107,   100,   101,   102,   103,    93,    94,    95,
      98,    96,    99,    97,    76,     0,    82,    74,     0,    85,
      88,     0,    61,    61,     0,     0,    72,     0,   117,     0,
       0,    34,     0,     0,     0,     5,     5,   108,   109,   110,
     111,     0,    86,    89,    70,    68,    66,    63,    75,     0,
      39,     0,    40,    50,    19,    19,     0,    31,     0,     0,
       0,    83,     0,     0,    24,    23,     0,    18,    21,     0,
       0,    12,    47,    13,    15,    16,     0,     0,     0,    25,
      44,     0,    14,     0,     0,    42,     0,    20,     0,     0,
      26,     0,    17,    43,    22,    45
  };

  const short int
  Parser::yypgoto_[] =
  {
    -130,  -130,  -130,   272,  -130,   273,  -130,  -130,  -130,  -130,
    -130,    85,  -130,    62,  -130,   112,    73,    -7,    92,  -130,
     261,  -129,  -130,  -130,  -130,  -130,  -130,  -130,   106,  -130,
     222,   249,  -130,  -130,  -130,   165,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,   -16,    -3
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,   197,     6,     7,    84,   134,   135,   136,
     137,   206,   207,   208,   209,   198,    10,    24,    12,    42,
      43,   126,   127,   128,   170,   192,   221,   129,    45,    82,
      83,    25,    26,    27,    28,    70,   115,   164,   165,    29,
      30,    31,    32,    33,    74,    34,    35,    36,   105,    37,
     108,    38,   110,   111,    57,    58
  };

  const short int
  Parser::yytable_[] =
  {
      60,   172,    67,    63,   190,    64,    39,   123,    72,    15,
     204,    62,    16,   166,   188,    39,   107,    17,   204,   205,
      18,    19,    20,     1,     1,     1,   124,   205,    73,    21,
      22,   196,   199,     5,    89,    90,    91,    68,   132,     8,
      75,     9,    68,   133,    76,    11,   -25,    40,    77,   109,
     112,   191,    13,    68,    68,    23,   117,   118,   106,    41,
     121,   122,   114,   125,   116,    39,    39,    44,    39,   138,
     139,   140,   141,    59,   217,    61,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    65,   154,    66,
      75,   157,   158,    46,    76,    69,   159,   232,   155,   156,
     234,    78,   235,   -93,   102,    47,    48,   -93,    99,   100,
     101,   102,   167,    71,    49,    79,    39,    97,    98,    99,
     100,   101,   102,    50,    93,    81,    94,    95,    96,    51,
      85,    97,    98,    99,   100,   101,   102,   162,   163,   -71,
      52,   104,   182,   228,   229,   183,    53,    54,    55,    56,
     -93,   101,   102,   189,    53,   184,   185,   119,   120,    39,
      39,    92,    93,    86,    94,    95,    96,    87,    88,    97,
      98,    99,   100,   101,   102,   130,   160,    68,   201,   161,
      92,    93,   224,    94,    95,    96,   216,   169,    97,    98,
      99,   100,   101,   102,   171,   173,   174,    92,    93,   142,
      94,    95,    96,   175,   176,    97,    98,    99,   100,   101,
     102,   -93,   187,   193,    92,    93,   168,    94,    95,    96,
     181,   194,    97,    98,    99,   100,   101,   102,   195,   203,
     218,    92,    93,   177,    94,    95,    96,   211,   213,    97,
      98,    99,   100,   101,   102,   214,   215,   219,    92,    93,
     178,    94,    95,    96,   225,   222,    97,    98,    99,   100,
     101,   102,   220,   226,   233,    92,    93,   179,    94,    95,
      96,   231,     4,    97,    98,    99,   100,   101,   102,    14,
     210,   227,    92,    93,   180,    94,    95,    96,   200,   212,
      97,    98,    99,   100,   101,   102,   230,    92,    93,   103,
      94,    95,    96,    80,   131,    97,    98,    99,   100,   101,
     102,    92,    93,   202,    94,    95,    96,   113,   223,    97,
      98,    99,   100,   101,   102,     0,   -92,    92,    93,   186,
      94,    95,    96,     0,     0,    97,    98,    99,   100,   101,
     102,     0,   -91,    92,    93,     0,    94,    95,    96,     0,
       0,    97,    98,    99,   100,   101,   102,    94,    95,    96,
       0,     0,    97,    98,    99,   100,   101,   102,    95,    96,
       0,     0,    97,    98,    99,   100,   101,   102,    96,     0,
       0,    97,    98,    99,   100,   101,   102,   -93,    98,    99,
     100,   101,   102,   -93,   100,   101,   102
  };

  const short int
  Parser::yycheck_[] =
  {
      16,   130,    12,    19,    12,    21,     9,     3,     9,    13,
      23,    18,    16,    12,    12,    18,    31,    21,    23,    32,
      24,    25,    26,     7,     7,     7,    22,    32,    29,    33,
      34,    14,    14,    59,    50,    51,    52,    52,    15,     0,
      49,     4,    52,    20,    53,    30,    59,    49,    57,    65,
      66,    59,    43,    52,    52,    59,    72,    73,    61,    59,
      76,    77,    69,    59,    71,    68,    69,    32,    71,    85,
      86,    87,    88,    59,   203,    53,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    53,   104,    53,
      49,   107,    50,     6,    53,    28,    54,   226,    53,    54,
     229,     0,   231,    47,    48,    18,    19,    44,    45,    46,
      47,    48,   119,     8,    27,    43,   119,    43,    44,    45,
      46,    47,    48,    36,    36,    59,    38,    39,    40,    42,
      53,    43,    44,    45,    46,    47,    48,    10,    11,    12,
      53,    57,   158,    50,    51,   161,    59,    60,    61,    62,
      46,    47,    48,   169,    59,   162,   163,     8,    59,   162,
     163,    35,    36,    53,    38,    39,    40,    53,    53,    43,
      44,    45,    46,    47,    48,    51,    54,    52,   181,    50,
      35,    36,    56,    38,    39,    40,   202,    55,    43,    44,
      45,    46,    47,    48,    52,    59,    59,    35,    36,    54,
      38,    39,    40,    52,    52,    43,    44,    45,    46,    47,
      48,    48,    12,    52,    35,    36,    54,    38,    39,    40,
      50,    53,    43,    44,    45,    46,    47,    48,    53,    51,
      54,    35,    36,    54,    38,    39,    40,    52,    52,    43,
      44,    45,    46,    47,    48,    52,    52,    52,    35,    36,
      54,    38,    39,    40,    52,    54,    43,    44,    45,    46,
      47,    48,    59,    51,    59,    35,    36,    54,    38,    39,
      40,    17,     0,    43,    44,    45,    46,    47,    48,     6,
     195,   219,    35,    36,    54,    38,    39,    40,   176,   197,
      43,    44,    45,    46,    47,    48,   223,    35,    36,    52,
      38,    39,    40,    42,    82,    43,    44,    45,    46,    47,
      48,    35,    36,    51,    38,    39,    40,    68,   212,    43,
      44,    45,    46,    47,    48,    -1,    50,    35,    36,   164,
      38,    39,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    -1,    50,    35,    36,    -1,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    38,    39,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    39,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    43,    44,    45,
      46,    47,    48,    45,    46,    47,    48
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     7,    64,    65,    66,    59,    67,    68,     0,     4,
      79,    30,    81,    43,    68,    13,    16,    21,    24,    25,
      26,    33,    34,    59,    80,    94,    95,    96,    97,   102,
     103,   104,   105,   106,   108,   109,   110,   112,   114,   118,
      49,    59,    82,    83,    32,    91,     6,    18,    19,    27,
      36,    42,    53,    59,    60,    61,    62,   117,   118,    59,
     117,    53,    80,   117,   117,    53,    53,    12,    52,    28,
      98,     8,     9,    29,   107,    49,    53,    57,     0,    43,
      83,    59,    92,    93,    69,    53,    53,    53,    53,   117,
     117,   117,    35,    36,    38,    39,    40,    43,    44,    45,
      46,    47,    48,    52,    57,   111,   118,    31,   113,   117,
     115,   116,   117,    94,    80,    99,    80,   117,   117,     8,
      59,   117,   117,     3,    22,    59,    84,    85,    86,    90,
      51,    93,    15,    20,    70,    71,    72,    73,   117,   117,
     117,   117,    54,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,    53,    54,   117,    50,    54,
      54,    50,    10,    11,   100,   101,    12,    80,    54,    55,
      87,    52,    84,    59,    59,    52,    52,    54,    54,    54,
      54,    50,   117,   117,    80,    80,    98,    12,    12,   117,
      12,    59,    88,    52,    53,    53,    14,    66,    78,    14,
      78,   118,    51,    51,    23,    32,    74,    75,    76,    77,
      74,    52,    81,    52,    52,    52,   117,    84,    54,    52,
      59,    89,    54,    91,    56,    52,    51,    76,    50,    51,
      79,    17,    84,    59,    84,    84
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    63,    64,    65,    66,    66,    67,    67,    68,    69,
      69,    69,    70,    70,    71,    72,    72,    73,    74,    74,
      75,    75,    76,    77,    77,    77,    78,    79,    80,    80,
      81,    81,    82,    82,    83,    84,    84,    84,    85,    86,
      87,    87,    88,    89,    89,    90,    91,    91,    92,    92,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    95,    96,    97,    98,    99,    99,   100,   100,
     101,   101,   102,   103,   104,   105,   106,   107,   107,   108,
     109,   109,   110,   111,   111,   112,   113,   113,   114,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   118
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     4,     4,     2,     0,     2,     1,     4,     2,
       2,     0,     4,     4,     5,     4,     4,     7,     1,     0,
       3,     1,     4,     1,     1,     0,     4,     3,     3,     1,
       2,     0,     2,     1,     4,     1,     1,     1,     1,     3,
       2,     0,     4,     3,     1,     8,     2,     0,     2,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     5,     2,     2,     3,     0,     2,     0,
       2,     0,     4,     2,     4,     5,     4,     2,     2,     1,
       2,     1,     4,     4,     1,     4,     3,     1,     4,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     4,     4,
       4,     4,     1,     1,     1,     1,     3,     4,     1
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
  "Application", "ProgramHead", "OptConstDecls", "ConstDecls", "ConstDecl",
  "PFDecls", "ProcedureDecl", "PSignature", "FunctionDecl", "FSignature",
  "OptFormalParameters", "FormalParameters", "FormalParameter", "OptVar",
  "Body", "Block", "StatementList", "OptTypeDecls", "TypeDecls",
  "TypeDecl", "Type", "SimpleType", "RecordType", "FieldDecls",
  "FieldDecl", "IdentList", "ArrayType", "OptVarDecls", "VarDecls",
  "VarDecl", "Statement", "Assignment", "IfStatement", "IfHead",
  "ThenPart", "ElseIfList", "ElseIfHead", "ElseClause", "WhileStatement",
  "WhileHead", "RepeatStatement", "ForStatement", "ForHead", "ToHead",
  "StopStatement", "ReturnStatement", "ReadStatement", "ReadArgs",
  "WriteStatement", "WriteArgs", "ProcedureCall", "OptArguments",
  "Arguments", "Expression", "LVal", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   116,   116,   118,   120,   120,   122,   123,   125,   127,
     128,   129,   131,   132,   134,   136,   137,   139,   141,   142,
     144,   145,   147,   149,   150,   151,   153,   155,   157,   158,
     160,   161,   163,   164,   166,   168,   169,   170,   172,   174,
     176,   177,   179,   181,   182,   184,   186,   187,   189,   190,
     192,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   206,   208,   210,   212,   214,   215,   217,   218,
     220,   221,   223,   225,   227,   229,   231,   233,   234,   236,
     238,   239,   241,   243,   244,   246,   248,   249,   251,   253,
     254,   256,   257,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   285,   286,   287
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
#line 1843 "parser.cpp" // lalr1.cc:1155
#line 289 "parser.ypp" // lalr1.cc:1156
 /*** Additional Code ***/

void FC::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
