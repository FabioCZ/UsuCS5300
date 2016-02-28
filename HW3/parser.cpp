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


// First part of user declarations.

#line 37 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 51 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 38 "parser.ypp" // lalr1.cc:408

# include "driver.hpp"

#line 57 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:408


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


namespace yy {
#line 143 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:474

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
  Parser::Parser (Driver& driver_yyarg)
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
      switch (that.type_get ())
    {
      case 84: // Type
      case 85: // SimpleType
        value.move< FC::Type > (that.value);
        break;

      case 59: // CharTok
        value.move< char > (that.value);
        break;

      case 60: // IntTok
      case 71: // PSignature
      case 73: // FSignature
      case 74: // OptFormalParameters
      case 75: // FormalParameters
      case 76: // FormalParameter
      case 77: // OptVar
      case 78: // Body
      case 79: // Block
      case 80: // StatementList
      case 86: // RecordType
      case 87: // FieldDecls
      case 88: // FieldDecl
      case 89: // IdentList
      case 90: // ArrayType
      case 94: // Statement
      case 95: // Assignment
      case 96: // IfStatement
      case 97: // IfHead
      case 98: // ThenPart
      case 99: // ElseIfList
      case 100: // ElseIfHead
      case 101: // ElseClause
      case 102: // WhileStatement
      case 103: // WhileHead
      case 104: // RepeatStatement
      case 105: // ForStatement
      case 106: // ForHead
      case 107: // ToHead
      case 108: // StopStatement
      case 109: // ReturnStatement
      case 110: // ReadStatement
      case 111: // ReadArgs
      case 112: // WriteStatement
      case 113: // WriteArgs
      case 114: // ProcedureCall
      case 115: // OptArguments
      case 116: // Arguments
      case 118: // FunctionCall
        value.move< int > (that.value);
        break;

      case 117: // Expression
        value.move< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 119: // LVal
        value.move< std::shared_ptr<FC::LVal>  > (that.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 84: // Type
      case 85: // SimpleType
        value.copy< FC::Type > (that.value);
        break;

      case 59: // CharTok
        value.copy< char > (that.value);
        break;

      case 60: // IntTok
      case 71: // PSignature
      case 73: // FSignature
      case 74: // OptFormalParameters
      case 75: // FormalParameters
      case 76: // FormalParameter
      case 77: // OptVar
      case 78: // Body
      case 79: // Block
      case 80: // StatementList
      case 86: // RecordType
      case 87: // FieldDecls
      case 88: // FieldDecl
      case 89: // IdentList
      case 90: // ArrayType
      case 94: // Statement
      case 95: // Assignment
      case 96: // IfStatement
      case 97: // IfHead
      case 98: // ThenPart
      case 99: // ElseIfList
      case 100: // ElseIfHead
      case 101: // ElseClause
      case 102: // WhileStatement
      case 103: // WhileHead
      case 104: // RepeatStatement
      case 105: // ForStatement
      case 106: // ForHead
      case 107: // ToHead
      case 108: // StopStatement
      case 109: // ReturnStatement
      case 110: // ReadStatement
      case 111: // ReadArgs
      case 112: // WriteStatement
      case 113: // WriteArgs
      case 114: // ProcedureCall
      case 115: // OptArguments
      case 116: // Arguments
      case 118: // FunctionCall
        value.copy< int > (that.value);
        break;

      case 117: // Expression
        value.copy< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 119: // LVal
        value.copy< std::shared_ptr<FC::LVal>  > (that.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

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
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 534 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:725

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
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 84: // Type
      case 85: // SimpleType
        yylhs.value.build< FC::Type > ();
        break;

      case 59: // CharTok
        yylhs.value.build< char > ();
        break;

      case 60: // IntTok
      case 71: // PSignature
      case 73: // FSignature
      case 74: // OptFormalParameters
      case 75: // FormalParameters
      case 76: // FormalParameter
      case 77: // OptVar
      case 78: // Body
      case 79: // Block
      case 80: // StatementList
      case 86: // RecordType
      case 87: // FieldDecls
      case 88: // FieldDecl
      case 89: // IdentList
      case 90: // ArrayType
      case 94: // Statement
      case 95: // Assignment
      case 96: // IfStatement
      case 97: // IfHead
      case 98: // ThenPart
      case 99: // ElseIfList
      case 100: // ElseIfHead
      case 101: // ElseClause
      case 102: // WhileStatement
      case 103: // WhileHead
      case 104: // RepeatStatement
      case 105: // ForStatement
      case 106: // ForHead
      case 107: // ToHead
      case 108: // StopStatement
      case 109: // ReturnStatement
      case 110: // ReadStatement
      case 111: // ReadArgs
      case 112: // WriteStatement
      case 113: // WriteArgs
      case 114: // ProcedureCall
      case 115: // OptArguments
      case 116: // Arguments
      case 118: // FunctionCall
        yylhs.value.build< int > ();
        break;

      case 117: // Expression
        yylhs.value.build< std::shared_ptr<FC::Expr> > ();
        break;

      case 119: // LVal
        yylhs.value.build< std::shared_ptr<FC::LVal>  > ();
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


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
#line 159 "parser.ypp" // lalr1.cc:847
    {FC::AddMain();}
#line 712 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 169 "parser.ypp" // lalr1.cc:847
    {FC::AddConst(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 718 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 175 "parser.ypp" // lalr1.cc:847
    {}
#line 724 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 176 "parser.ypp" // lalr1.cc:847
    {}
#line 730 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 178 "parser.ypp" // lalr1.cc:847
    {}
#line 736 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 180 "parser.ypp" // lalr1.cc:847
    {}
#line 742 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 181 "parser.ypp" // lalr1.cc:847
    {}
#line 748 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 183 "parser.ypp" // lalr1.cc:847
    {}
#line 754 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 185 "parser.ypp" // lalr1.cc:847
    {}
#line 760 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 186 "parser.ypp" // lalr1.cc:847
    {}
#line 766 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 188 "parser.ypp" // lalr1.cc:847
    {}
#line 772 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 189 "parser.ypp" // lalr1.cc:847
    {}
#line 778 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 191 "parser.ypp" // lalr1.cc:847
    {}
#line 784 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 193 "parser.ypp" // lalr1.cc:847
    {}
#line 790 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 194 "parser.ypp" // lalr1.cc:847
    {}
#line 796 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 195 "parser.ypp" // lalr1.cc:847
    {}
#line 802 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 197 "parser.ypp" // lalr1.cc:847
    {}
#line 808 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 199 "parser.ypp" // lalr1.cc:847
    {}
#line 814 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 201 "parser.ypp" // lalr1.cc:847
    {}
#line 820 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 202 "parser.ypp" // lalr1.cc:847
    {}
#line 826 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 210 "parser.ypp" // lalr1.cc:847
    {}
#line 832 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 212 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = yystack_[0].value.as< FC::Type > ();}
#line 838 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 213 "parser.ypp" // lalr1.cc:847
    {}
#line 844 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 214 "parser.ypp" // lalr1.cc:847
    {}
#line 850 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 216 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = FC::SimpleTypeLookup(yystack_[0].value.as< std::string > ());}
#line 856 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 218 "parser.ypp" // lalr1.cc:847
    {}
#line 862 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 220 "parser.ypp" // lalr1.cc:847
    {}
#line 868 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 221 "parser.ypp" // lalr1.cc:847
    {}
#line 874 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 223 "parser.ypp" // lalr1.cc:847
    {}
#line 880 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 225 "parser.ypp" // lalr1.cc:847
    {FC::AddIdent(yystack_[0].value.as< std::string > ());}
#line 886 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 226 "parser.ypp" // lalr1.cc:847
    {FC::AddIdent(yystack_[0].value.as< std::string > ());}
#line 892 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 228 "parser.ypp" // lalr1.cc:847
    {}
#line 898 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 236 "parser.ypp" // lalr1.cc:847
    {AddVariables(yystack_[1].value.as< FC::Type > ());}
#line 904 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 238 "parser.ypp" // lalr1.cc:847
    {}
#line 910 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 239 "parser.ypp" // lalr1.cc:847
    {}
#line 916 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 240 "parser.ypp" // lalr1.cc:847
    {}
#line 922 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 241 "parser.ypp" // lalr1.cc:847
    {}
#line 928 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 242 "parser.ypp" // lalr1.cc:847
    {}
#line 934 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 243 "parser.ypp" // lalr1.cc:847
    {}
#line 940 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 244 "parser.ypp" // lalr1.cc:847
    {}
#line 946 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 245 "parser.ypp" // lalr1.cc:847
    {}
#line 952 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 246 "parser.ypp" // lalr1.cc:847
    {}
#line 958 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 247 "parser.ypp" // lalr1.cc:847
    {}
#line 964 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 248 "parser.ypp" // lalr1.cc:847
    {}
#line 970 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 250 "parser.ypp" // lalr1.cc:847
    {FC::Assignment(yystack_[2].value.as< std::shared_ptr<FC::LVal>  > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 976 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 252 "parser.ypp" // lalr1.cc:847
    {}
#line 982 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 254 "parser.ypp" // lalr1.cc:847
    {}
#line 988 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 256 "parser.ypp" // lalr1.cc:847
    {}
#line 994 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 258 "parser.ypp" // lalr1.cc:847
    {}
#line 1000 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 259 "parser.ypp" // lalr1.cc:847
    {}
#line 1006 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 261 "parser.ypp" // lalr1.cc:847
    {}
#line 1012 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 262 "parser.ypp" // lalr1.cc:847
    {}
#line 1018 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 264 "parser.ypp" // lalr1.cc:847
    {}
#line 1024 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 265 "parser.ypp" // lalr1.cc:847
    {}
#line 1030 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 267 "parser.ypp" // lalr1.cc:847
    {}
#line 1036 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 269 "parser.ypp" // lalr1.cc:847
    {}
#line 1042 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 271 "parser.ypp" // lalr1.cc:847
    {}
#line 1048 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 273 "parser.ypp" // lalr1.cc:847
    {}
#line 1054 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 275 "parser.ypp" // lalr1.cc:847
    {}
#line 1060 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 277 "parser.ypp" // lalr1.cc:847
    {}
#line 1066 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 278 "parser.ypp" // lalr1.cc:847
    {}
#line 1072 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 280 "parser.ypp" // lalr1.cc:847
    {FC::Stop();}
#line 1078 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 282 "parser.ypp" // lalr1.cc:847
    {}
#line 1084 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 283 "parser.ypp" // lalr1.cc:847
    {}
#line 1090 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 285 "parser.ypp" // lalr1.cc:847
    {}
#line 1096 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 287 "parser.ypp" // lalr1.cc:847
    {FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1102 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 288 "parser.ypp" // lalr1.cc:847
    {FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1108 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 290 "parser.ypp" // lalr1.cc:847
    {}
#line 1114 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 292 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1120 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 293 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1126 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 295 "parser.ypp" // lalr1.cc:847
    {}
#line 1132 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 297 "parser.ypp" // lalr1.cc:847
    {}
#line 1138 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 298 "parser.ypp" // lalr1.cc:847
    {}
#line 1144 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 300 "parser.ypp" // lalr1.cc:847
    {}
#line 1150 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 301 "parser.ypp" // lalr1.cc:847
    {}
#line 1156 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 303 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcOrExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1162 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 304 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcAndExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1168 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 305 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1174 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 306 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1180 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 307 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1186 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 308 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1192 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 309 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1198 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 310 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1204 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 311 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcPlusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1210 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 312 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMinusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1216 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 313 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcDivideExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1222 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 314 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMultiplyExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1228 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 315 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcModExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1234 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 316 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1240 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 317 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcUnaryMinusExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1246 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 318 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = yystack_[1].value.as< std::shared_ptr<FC::Expr> > ();}
#line 1252 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 319 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToChar(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1258 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 320 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToInt(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1264 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 321 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcDecrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1270 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 322 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIncrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1276 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 323 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::LValToExpr(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ()); }
#line 1282 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 324 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIntExpr(yystack_[0].value.as< int > ());}
#line 1288 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 325 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcStringExpr(yystack_[0].value.as< std::string > ());}
#line 1294 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 326 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcCharExpr(yystack_[0].value.as< char > ());}
#line 1300 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 327 "parser.ypp" // lalr1.cc:847
    {/*todo*/}
#line 1306 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 329 "parser.ypp" // lalr1.cc:847
    {}
#line 1312 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 331 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1318 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 332 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1324 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;

  case 121:
#line 333 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = FC::GetLValForIdent(yystack_[0].value.as< std::string > ());}
#line 1330 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
    break;


#line 1334 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:847
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


  const short int Parser::yypact_ninf_ = -168;

  const signed char Parser::yytable_ninf_ = -72;

  const short int
  Parser::yypact_[] =
  {
      15,   -47,    46,    26,    18,    14,   -47,  -168,  -168,     7,
       9,    10,    47,    87,  -168,    42,    87,    27,     7,    87,
    -168,    87,    83,    89,    -8,  -168,  -168,  -168,   109,  -168,
     131,  -168,  -168,     6,  -168,  -168,  -168,  -168,  -168,    52,
    -168,   101,    10,  -168,    92,  -168,   105,   107,   108,   110,
      87,    87,    87,  -168,  -168,   113,  -168,   134,  -168,   -28,
     111,   336,   106,   -18,   336,   336,    87,    87,  -168,     7,
       7,  -168,     7,    87,    87,   154,   115,    87,    87,     2,
    -168,  -168,    71,    92,  -168,    30,    87,    87,    87,    87,
      72,   393,   162,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,  -168,    87,    87,  -168,
      91,   -28,    87,   102,   336,   129,   135,   336,  -168,   132,
      86,    -5,   336,   336,     7,  -168,   183,   336,   133,  -168,
    -168,   137,  -168,  -168,  -168,   126,     2,  -168,   130,   143,
    -168,   138,  -168,   141,   207,   228,   249,   270,  -168,   140,
     352,    72,   368,   377,   386,   393,   402,   167,    80,    85,
      19,   -29,  -168,   336,   106,  -168,   336,    87,  -168,  -168,
      87,     7,    87,   109,   184,  -168,    -1,  -168,    87,    -2,
    -168,  -168,   165,   142,   179,    29,    35,  -168,  -168,  -168,
    -168,  -168,   -28,   336,   336,   132,   336,  -168,  -168,  -168,
     291,  -168,  -168,    84,  -168,    -6,    -6,   181,    18,   182,
     185,   186,    87,     2,  -168,  -168,   190,   188,  -168,    92,
     195,  -168,    47,  -168,  -168,  -168,   312,   204,   206,    -7,
     100,  -168,    26,   218,  -168,     2,  -168,     2,  -168,     2,
    -168,  -168,  -168
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       5,     0,     0,     0,    31,     0,     4,     7,     1,    61,
       0,     0,    47,     0,     6,     0,     0,     0,    61,    81,
      79,     0,     0,   121,     0,    29,    51,    52,     0,    53,
       0,    54,    55,     0,    56,    57,    58,    59,    60,     0,
       2,     0,    30,    33,     0,    11,     0,     0,     0,     0,
       0,     0,     0,   116,   114,   121,   115,     0,   117,   113,
       0,    64,     0,     0,    80,    73,     0,    90,    27,    61,
      61,    67,    61,     0,     0,     0,     0,     0,     0,     0,
      32,    44,     0,    46,    49,     3,     0,     0,     0,     0,
     107,   106,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     0,   121,
       0,    84,     0,     0,    87,     0,    89,    92,    28,    65,
      69,     0,    78,    77,    61,   119,     0,    62,     0,    41,
      38,     0,    35,    36,    37,     0,     0,    48,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,   108,     0,
     101,   102,   104,   103,    94,    93,    95,    96,    99,    97,
     100,    98,   105,    76,     0,    82,    74,     0,    85,    88,
       0,    61,     0,     0,     0,    72,     0,   120,     0,     0,
      34,    43,     0,     0,     0,     5,     5,   109,   110,   111,
     112,   118,    83,    86,    91,    70,    68,    66,    63,    75,
       0,    39,    40,     0,    50,    19,    19,     0,    31,     0,
       0,     0,     0,     0,    24,    23,     0,    18,    21,     0,
       0,    12,    47,    13,    15,    16,     0,     0,     0,    25,
       0,    14,     0,     0,    42,     0,    20,     0,    26,     0,
      17,    22,    45
  };

  const short int
  Parser::yypgoto_[] =
  {
    -168,  -168,  -168,   236,  -168,   252,  -168,  -168,  -168,  -168,
    -168,    53,  -168,    31,  -168,    76,    38,   -16,    69,  -168,
     237,  -135,  -168,  -168,  -168,  -168,  -167,  -168,    56,  -168,
     197,   212,  -168,  -168,  -168,   118,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,   205,  -168,   -13,  -168,     0
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,   208,     6,     7,    85,   140,   141,   142,
     143,   216,   217,   218,   219,   209,    10,    24,    12,    42,
      43,   131,   132,   133,   179,   202,    82,   134,    45,    83,
      84,    25,    26,    27,    28,    71,   120,   173,   174,    29,
      30,    31,    32,    33,    75,    34,    35,    36,   110,    37,
     113,    38,   115,   116,   117,    58,    59
  };

  const short int
  Parser::yytable_[] =
  {
      57,   182,    63,    61,    68,   128,    64,   175,    65,    39,
     201,   199,   203,   112,     5,    73,   214,   214,    39,   -72,
      15,    76,     1,    16,   129,   215,   215,    77,    17,   107,
       9,    18,    19,    20,    69,    74,     1,    90,    91,    92,
      21,    22,     1,   207,    69,   138,     8,    69,    11,   210,
     139,    69,   230,   114,   119,   -25,   121,    13,    40,    81,
     122,   123,   111,   130,   126,   127,   -72,   105,    23,    39,
      39,    41,    39,   144,   145,   146,   147,   107,   227,    44,
      62,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    46,   162,   163,   171,   172,   -71,   166,
     240,    76,   241,    60,   242,    47,    48,    77,   176,    78,
      96,    97,    98,    99,    49,   100,   101,   102,   103,   104,
     105,   135,   136,    50,    39,   -72,   103,   104,   105,    51,
     107,   -72,   104,   105,   135,   213,    66,    70,   107,    72,
      52,   164,    67,   107,    79,   165,    53,    54,    55,    56,
     135,   237,   167,    81,   193,   195,   168,   194,    86,   196,
      87,    88,   124,    89,   192,   200,    93,   109,   108,    94,
      95,    39,    96,    97,    98,    99,   125,   100,   101,   102,
     103,   104,   105,   169,    69,   170,   106,   181,   178,   180,
     185,   183,   107,   186,   191,   205,   198,    94,    95,   226,
      96,    97,    98,    99,   184,   100,   101,   102,   103,   104,
     105,   -72,   102,   103,   104,   105,   148,   204,    94,    95,
     107,    96,    97,    98,    99,   107,   100,   101,   102,   103,
     104,   105,   206,   221,   223,   239,     4,   224,   225,   177,
     229,   107,    94,    95,   228,    96,    97,    98,    99,   231,
     100,   101,   102,   103,   104,   105,   234,   235,    14,   220,
     236,   187,   211,    94,    95,   107,    96,    97,    98,    99,
     238,   100,   101,   102,   103,   104,   105,   222,   232,    80,
     137,   118,   188,     0,    94,    95,   107,    96,    97,    98,
      99,   197,   100,   101,   102,   103,   104,   105,   149,     0,
       0,     0,     0,   189,     0,    94,    95,   107,    96,    97,
      98,    99,     0,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,   190,     0,    94,    95,   107,    96,
      97,    98,    99,     0,   100,   101,   102,   103,   104,   105,
       0,     0,   212,     0,     0,     0,     0,    94,    95,   107,
      96,    97,    98,    99,     0,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   233,     0,
     107,    94,    95,     0,    96,    97,    98,    99,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,    95,     0,
      96,    97,    98,    99,   107,   100,   101,   102,   103,   104,
     105,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     107,   100,   101,   102,   103,   104,   105,    98,    99,     0,
     100,   101,   102,   103,   104,   105,   107,    99,     0,   100,
     101,   102,   103,   104,   105,   107,   100,   101,   102,   103,
     104,   105,     0,     0,   107,   -72,   101,   102,   103,   104,
     105,   107,     0,     0,     0,     0,     0,     0,     0,     0,
     107
  };

  const short int
  Parser::yycheck_[] =
  {
      13,   136,    18,    16,    12,     3,    19,    12,    21,     9,
      12,    12,   179,    31,    61,     9,    23,    23,    18,    48,
      13,    49,     7,    16,    22,    32,    32,    55,    21,    58,
       4,    24,    25,    26,    52,    29,     7,    50,    51,    52,
      33,    34,     7,    14,    52,    15,     0,    52,    30,    14,
      20,    52,   219,    66,    70,    61,    72,    43,    49,    61,
      73,    74,    62,    61,    77,    78,    47,    48,    61,    69,
      70,    61,    72,    86,    87,    88,    89,    58,   213,    32,
      53,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     6,   107,   108,    10,    11,    12,   112,
     235,    49,   237,    61,   239,    18,    19,    55,   124,    57,
      38,    39,    40,    41,    27,    43,    44,    45,    46,    47,
      48,    50,    51,    36,   124,    45,    46,    47,    48,    42,
      58,    46,    47,    48,    50,    51,    53,    28,    58,     8,
      53,    50,    53,    58,    43,    54,    59,    60,    61,    62,
      50,    51,    50,    61,   167,   171,    54,   170,    53,   172,
      53,    53,     8,    53,   164,   178,    53,    61,    57,    35,
      36,   171,    38,    39,    40,    41,    61,    43,    44,    45,
      46,    47,    48,    54,    52,    50,    52,    61,    55,    52,
      52,    61,    58,    52,    54,    53,    12,    35,    36,   212,
      38,    39,    40,    41,    61,    43,    44,    45,    46,    47,
      48,    44,    45,    46,    47,    48,    54,    52,    35,    36,
      58,    38,    39,    40,    41,    58,    43,    44,    45,    46,
      47,    48,    53,    52,    52,    17,     0,    52,    52,    56,
      52,    58,    35,    36,    54,    38,    39,    40,    41,    54,
      43,    44,    45,    46,    47,    48,    52,    51,     6,   206,
     229,    54,   186,    35,    36,    58,    38,    39,    40,    41,
     232,    43,    44,    45,    46,    47,    48,   208,   222,    42,
      83,    69,    54,    -1,    35,    36,    58,    38,    39,    40,
      41,   173,    43,    44,    45,    46,    47,    48,    93,    -1,
      -1,    -1,    -1,    54,    -1,    35,    36,    58,    38,    39,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    35,    36,    58,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    35,    36,    58,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    35,    36,    -1,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    58,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      58,    43,    44,    45,    46,    47,    48,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    58,    41,    -1,    43,
      44,    45,    46,    47,    48,    58,    43,    44,    45,    46,
      47,    48,    -1,    -1,    58,    43,    44,    45,    46,    47,
      48,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     7,    64,    65,    66,    61,    67,    68,     0,     4,
      79,    30,    81,    43,    68,    13,    16,    21,    24,    25,
      26,    33,    34,    61,    80,    94,    95,    96,    97,   102,
     103,   104,   105,   106,   108,   109,   110,   112,   114,   119,
      49,    61,    82,    83,    32,    91,     6,    18,    19,    27,
      36,    42,    53,    59,    60,    61,    62,   117,   118,   119,
      61,   117,    53,    80,   117,   117,    53,    53,    12,    52,
      28,    98,     8,     9,    29,   107,    49,    55,    57,    43,
      83,    61,    89,    92,    93,    69,    53,    53,    53,    53,
     117,   117,   117,    53,    35,    36,    38,    39,    40,    41,
      43,    44,    45,    46,    47,    48,    52,    58,    57,    61,
     111,   119,    31,   113,   117,   115,   116,   117,    94,    80,
      99,    80,   117,   117,     8,    61,   117,   117,     3,    22,
      61,    84,    85,    86,    90,    50,    51,    93,    15,    20,
      70,    71,    72,    73,   117,   117,   117,   117,    54,   115,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,    50,    54,   117,    50,    54,    54,
      50,    10,    11,   100,   101,    12,    80,    56,    55,    87,
      52,    61,    84,    61,    61,    52,    52,    54,    54,    54,
      54,    54,   119,   117,   117,    80,   117,    98,    12,    12,
     117,    12,    88,    89,    52,    53,    53,    14,    66,    78,
      14,    78,    51,    51,    23,    32,    74,    75,    76,    77,
      74,    52,    81,    52,    52,    52,   117,    84,    54,    52,
      89,    54,    91,    56,    52,    51,    76,    51,    79,    17,
      84,    84,    84
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
     117,   117,   117,   117,   117,   117,   117,   117,   118,   119,
     119,   119
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     3,     4,     2,     0,     2,     1,     4,     2,
       2,     0,     4,     4,     5,     4,     4,     7,     1,     0,
       3,     1,     4,     1,     1,     0,     4,     3,     3,     1,
       2,     0,     2,     1,     4,     1,     1,     1,     1,     3,
       2,     0,     4,     3,     1,     8,     2,     0,     2,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     5,     2,     2,     3,     0,     2,     0,
       2,     0,     4,     2,     4,     5,     4,     2,     2,     1,
       2,     1,     4,     3,     1,     4,     3,     1,     4,     1,
       0,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     4,
       4,     4,     4,     1,     1,     1,     1,     1,     4,     3,
       4,     1
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
  "OpenBrktTok", "CloseBrktTok", "ColonEqualTok", "PercentTok", "CharTok",
  "IntTok", "IdentifierTok", "StringTok", "$accept", "Application",
  "ProgramHead", "OptConstDecls", "ConstDecls", "ConstDecl", "PFDecls",
  "ProcedureDecl", "PSignature", "FunctionDecl", "FSignature",
  "OptFormalParameters", "FormalParameters", "FormalParameter", "OptVar",
  "Body", "Block", "StatementList", "OptTypeDecls", "TypeDecls",
  "TypeDecl", "Type", "SimpleType", "RecordType", "FieldDecls",
  "FieldDecl", "IdentList", "ArrayType", "OptVarDecls", "VarDecls",
  "VarDecl", "Statement", "Assignment", "IfStatement", "IfHead",
  "ThenPart", "ElseIfList", "ElseIfHead", "ElseClause", "WhileStatement",
  "WhileHead", "RepeatStatement", "ForStatement", "ForHead", "ToHead",
  "StopStatement", "ReturnStatement", "ReadStatement", "ReadArgs",
  "WriteStatement", "WriteArgs", "ProcedureCall", "OptArguments",
  "Arguments", "Expression", "FunctionCall", "LVal", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   159,   159,   161,   163,   164,   166,   167,   169,   171,
     172,   173,   175,   176,   178,   180,   181,   183,   185,   186,
     188,   189,   191,   193,   194,   195,   197,   199,   201,   202,
     204,   205,   207,   208,   210,   212,   213,   214,   216,   218,
     220,   221,   223,   225,   226,   228,   230,   231,   233,   234,
     236,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   250,   252,   254,   256,   258,   259,   261,   262,
     264,   265,   267,   269,   271,   273,   275,   277,   278,   280,
     282,   283,   285,   287,   288,   290,   292,   293,   295,   297,
     298,   300,   301,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   329,   331,
     332,   333
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



} // yy
#line 1929 "/home/fabio/Desktop/UsuCS5300/HW3/parser.cpp" // lalr1.cc:1155
#line 335 "parser.ypp" // lalr1.cc:1156

void
yy::Parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
