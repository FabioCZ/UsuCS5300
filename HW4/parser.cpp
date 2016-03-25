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

#line 37 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 51 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 39 "parser.ypp" // lalr1.cc:408

# include "driver.hpp"

#line 57 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:408


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
#line 143 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:474

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
      case 86: // RecordType
      case 87: // FieldDecls
      case 88: // FieldDecl
      case 89: // IdentList
      case 90: // ArrayType
      case 95: // Assignment
      case 96: // IfStatement
      case 97: // IfHead
      case 98: // ThenPart
      case 99: // ElseIfList
      case 100: // ElseIfHead
      case 101: // ElseClause
      case 102: // WhileStatement
      case 105: // RepeatStatement
      case 106: // ForStatement
      case 107: // ForHead
      case 108: // ToHead
      case 109: // StopStatement
      case 110: // ReturnStatement
      case 111: // ReadStatement
      case 112: // ReadArgs
      case 113: // WriteStatement
      case 114: // WriteArgs
      case 115: // ProcedureCall
      case 116: // OptArguments
      case 117: // Arguments
      case 119: // FunctionCall
        value.move< int > (that.value);
        break;

      case 103: // WhileHead
      case 104: // WhileSuperHead
      case 118: // Expression
        value.move< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 120: // LVal
        value.move< std::shared_ptr<FC::LVal>  > (that.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 80: // StatementList
      case 94: // Statement
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
      case 86: // RecordType
      case 87: // FieldDecls
      case 88: // FieldDecl
      case 89: // IdentList
      case 90: // ArrayType
      case 95: // Assignment
      case 96: // IfStatement
      case 97: // IfHead
      case 98: // ThenPart
      case 99: // ElseIfList
      case 100: // ElseIfHead
      case 101: // ElseClause
      case 102: // WhileStatement
      case 105: // RepeatStatement
      case 106: // ForStatement
      case 107: // ForHead
      case 108: // ToHead
      case 109: // StopStatement
      case 110: // ReturnStatement
      case 111: // ReadStatement
      case 112: // ReadArgs
      case 113: // WriteStatement
      case 114: // WriteArgs
      case 115: // ProcedureCall
      case 116: // OptArguments
      case 117: // Arguments
      case 119: // FunctionCall
        value.copy< int > (that.value);
        break;

      case 103: // WhileHead
      case 104: // WhileSuperHead
      case 118: // Expression
        value.copy< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 120: // LVal
        value.copy< std::shared_ptr<FC::LVal>  > (that.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 80: // StatementList
      case 94: // Statement
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
    #line 30 "parser.ypp" // lalr1.cc:725
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 536 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:725

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
      case 86: // RecordType
      case 87: // FieldDecls
      case 88: // FieldDecl
      case 89: // IdentList
      case 90: // ArrayType
      case 95: // Assignment
      case 96: // IfStatement
      case 97: // IfHead
      case 98: // ThenPart
      case 99: // ElseIfList
      case 100: // ElseIfHead
      case 101: // ElseClause
      case 102: // WhileStatement
      case 105: // RepeatStatement
      case 106: // ForStatement
      case 107: // ForHead
      case 108: // ToHead
      case 109: // StopStatement
      case 110: // ReturnStatement
      case 111: // ReadStatement
      case 112: // ReadArgs
      case 113: // WriteStatement
      case 114: // WriteArgs
      case 115: // ProcedureCall
      case 116: // OptArguments
      case 117: // Arguments
      case 119: // FunctionCall
        yylhs.value.build< int > ();
        break;

      case 103: // WhileHead
      case 104: // WhileSuperHead
      case 118: // Expression
        yylhs.value.build< std::shared_ptr<FC::Expr> > ();
        break;

      case 120: // LVal
        yylhs.value.build< std::shared_ptr<FC::LVal>  > ();
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 80: // StatementList
      case 94: // Statement
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
#line 161 "parser.ypp" // lalr1.cc:847
    {FC::AddMain();}
#line 715 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 171 "parser.ypp" // lalr1.cc:847
    {FC::AddConst(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 721 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 177 "parser.ypp" // lalr1.cc:847
    {}
#line 727 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 178 "parser.ypp" // lalr1.cc:847
    {}
#line 733 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 180 "parser.ypp" // lalr1.cc:847
    {}
#line 739 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 182 "parser.ypp" // lalr1.cc:847
    {}
#line 745 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 183 "parser.ypp" // lalr1.cc:847
    {}
#line 751 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 185 "parser.ypp" // lalr1.cc:847
    {}
#line 757 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 187 "parser.ypp" // lalr1.cc:847
    {}
#line 763 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 188 "parser.ypp" // lalr1.cc:847
    {}
#line 769 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 190 "parser.ypp" // lalr1.cc:847
    {}
#line 775 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 191 "parser.ypp" // lalr1.cc:847
    {}
#line 781 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 193 "parser.ypp" // lalr1.cc:847
    {}
#line 787 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 195 "parser.ypp" // lalr1.cc:847
    {}
#line 793 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 196 "parser.ypp" // lalr1.cc:847
    {}
#line 799 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 197 "parser.ypp" // lalr1.cc:847
    {}
#line 805 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 199 "parser.ypp" // lalr1.cc:847
    {}
#line 811 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 201 "parser.ypp" // lalr1.cc:847
    {FC::WriteStatement();}
#line 817 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 203 "parser.ypp" // lalr1.cc:847
    {}
#line 823 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 204 "parser.ypp" // lalr1.cc:847
    {}
#line 829 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 212 "parser.ypp" // lalr1.cc:847
    {}
#line 835 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 214 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = yystack_[0].value.as< FC::Type > ();}
#line 841 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 215 "parser.ypp" // lalr1.cc:847
    {}
#line 847 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 37:
#line 216 "parser.ypp" // lalr1.cc:847
    {}
#line 853 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 38:
#line 218 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = FC::SimpleTypeLookup(yystack_[0].value.as< std::string > ());}
#line 859 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 39:
#line 220 "parser.ypp" // lalr1.cc:847
    {}
#line 865 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 222 "parser.ypp" // lalr1.cc:847
    {}
#line 871 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 223 "parser.ypp" // lalr1.cc:847
    {}
#line 877 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 225 "parser.ypp" // lalr1.cc:847
    {}
#line 883 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 227 "parser.ypp" // lalr1.cc:847
    {FC::AddIdent(yystack_[0].value.as< std::string > ());}
#line 889 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 228 "parser.ypp" // lalr1.cc:847
    {FC::AddIdent(yystack_[0].value.as< std::string > ());}
#line 895 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 230 "parser.ypp" // lalr1.cc:847
    {}
#line 901 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 238 "parser.ypp" // lalr1.cc:847
    {AddVariables(yystack_[1].value.as< FC::Type > ());}
#line 907 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 240 "parser.ypp" // lalr1.cc:847
    {}
#line 913 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 241 "parser.ypp" // lalr1.cc:847
    {}
#line 919 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 242 "parser.ypp" // lalr1.cc:847
    {}
#line 925 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 243 "parser.ypp" // lalr1.cc:847
    {}
#line 931 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 244 "parser.ypp" // lalr1.cc:847
    {}
#line 937 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 245 "parser.ypp" // lalr1.cc:847
    {}
#line 943 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 246 "parser.ypp" // lalr1.cc:847
    {}
#line 949 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 247 "parser.ypp" // lalr1.cc:847
    {}
#line 955 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 248 "parser.ypp" // lalr1.cc:847
    {}
#line 961 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 249 "parser.ypp" // lalr1.cc:847
    {}
#line 967 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 250 "parser.ypp" // lalr1.cc:847
    {}
#line 973 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 252 "parser.ypp" // lalr1.cc:847
    {FC::Assignment(yystack_[2].value.as< std::shared_ptr<FC::LVal>  > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 979 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 254 "parser.ypp" // lalr1.cc:847
    {}
#line 985 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 256 "parser.ypp" // lalr1.cc:847
    {}
#line 991 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 258 "parser.ypp" // lalr1.cc:847
    {}
#line 997 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 260 "parser.ypp" // lalr1.cc:847
    {}
#line 1003 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 261 "parser.ypp" // lalr1.cc:847
    {}
#line 1009 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 263 "parser.ypp" // lalr1.cc:847
    {}
#line 1015 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 264 "parser.ypp" // lalr1.cc:847
    {}
#line 1021 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 266 "parser.ypp" // lalr1.cc:847
    {}
#line 1027 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 267 "parser.ypp" // lalr1.cc:847
    {}
#line 1033 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 269 "parser.ypp" // lalr1.cc:847
    {FC::WhileEnd();}
#line 1039 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 271 "parser.ypp" // lalr1.cc:847
    {FC::WhileHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1045 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 273 "parser.ypp" // lalr1.cc:847
    {FC::WhileSuperHead();}
#line 1051 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 275 "parser.ypp" // lalr1.cc:847
    {}
#line 1057 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 277 "parser.ypp" // lalr1.cc:847
    {}
#line 1063 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 279 "parser.ypp" // lalr1.cc:847
    {}
#line 1069 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 281 "parser.ypp" // lalr1.cc:847
    {}
#line 1075 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 282 "parser.ypp" // lalr1.cc:847
    {}
#line 1081 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 284 "parser.ypp" // lalr1.cc:847
    {FC::Stop();}
#line 1087 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 286 "parser.ypp" // lalr1.cc:847
    {}
#line 1093 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 287 "parser.ypp" // lalr1.cc:847
    {}
#line 1099 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 289 "parser.ypp" // lalr1.cc:847
    {}
#line 1105 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 291 "parser.ypp" // lalr1.cc:847
    {FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1111 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 292 "parser.ypp" // lalr1.cc:847
    {std::cout << "dafuq" << std::endl;FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1117 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 294 "parser.ypp" // lalr1.cc:847
    {}
#line 1123 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 296 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1129 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 297 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1135 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 299 "parser.ypp" // lalr1.cc:847
    {}
#line 1141 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 301 "parser.ypp" // lalr1.cc:847
    {}
#line 1147 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 302 "parser.ypp" // lalr1.cc:847
    {}
#line 1153 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 304 "parser.ypp" // lalr1.cc:847
    {}
#line 1159 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 305 "parser.ypp" // lalr1.cc:847
    {}
#line 1165 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 307 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcOrExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1171 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 308 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcAndExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1177 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 309 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1183 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 310 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1189 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 311 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1195 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 312 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1201 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 313 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1207 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 314 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1213 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 315 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcPlusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1219 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 316 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMinusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1225 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 317 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcDivideExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1231 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 318 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMultiplyExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1237 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 319 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcModExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1243 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 320 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1249 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 321 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcUnaryMinusExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1255 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 322 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = yystack_[1].value.as< std::shared_ptr<FC::Expr> > ();}
#line 1261 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 323 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToChar(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1267 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 324 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToInt(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1273 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 325 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcDecrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1279 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 326 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIncrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1285 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 327 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::LValToExpr(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ()); }
#line 1291 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 328 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIntExpr(yystack_[0].value.as< int > ());}
#line 1297 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 329 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcStringExpr(yystack_[0].value.as< std::string > ());}
#line 1303 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 330 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcCharExpr(yystack_[0].value.as< char > ());}
#line 1309 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 331 "parser.ypp" // lalr1.cc:847
    {/*todo*/}
#line 1315 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 333 "parser.ypp" // lalr1.cc:847
    {}
#line 1321 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 335 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1327 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 121:
#line 336 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1333 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 122:
#line 337 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = FC::GetLValForIdent(yystack_[0].value.as< std::string > ());}
#line 1339 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;


#line 1343 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
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


  const short int Parser::yypact_ninf_ = -172;

  const signed char Parser::yytable_ninf_ = -72;

  const short int
  Parser::yypact_[] =
  {
      28,   -50,    26,    42,    18,    15,   -50,  -172,  -172,     3,
      14,    11,    46,    92,  -172,    66,    92,    80,     3,    92,
    -172,  -172,    82,    97,    -8,  -172,  -172,  -172,    52,  -172,
     135,    92,  -172,  -172,     4,  -172,  -172,  -172,  -172,  -172,
      50,  -172,   101,    11,  -172,    96,  -172,   108,   109,   110,
     118,    92,    92,    92,  -172,  -172,   125,  -172,   129,  -172,
      24,   122,   327,   119,   -21,   327,    92,    92,  -172,     3,
       3,  -172,     3,   327,    92,    92,   175,   121,    92,    92,
      -2,  -172,  -172,    51,    96,  -172,    40,    92,    92,    92,
      92,   359,    78,   150,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,  -172,    92,    92,
    -172,    58,    24,    92,    63,   327,   130,   142,   327,  -172,
     149,   136,    -7,   327,   327,     3,  -172,   174,   327,   147,
    -172,  -172,   151,  -172,  -172,  -172,   144,    -2,  -172,   146,
     155,  -172,   159,  -172,   171,   198,   219,   240,   261,  -172,
     170,   343,   359,   375,   384,   393,    78,   400,    23,    84,
      91,   -33,   -26,  -172,   327,   119,  -172,   327,    92,  -172,
    -172,    92,     3,    92,    52,   213,  -172,    -5,  -172,    92,
      -4,  -172,  -172,   176,   173,   178,    16,    27,  -172,  -172,
    -172,  -172,  -172,    24,   327,   327,   149,   327,  -172,  -172,
    -172,   282,  -172,  -172,    64,  -172,   -11,   -11,   177,    18,
     183,   188,   195,    92,    -2,  -172,  -172,   194,   197,  -172,
      96,   196,  -172,    46,  -172,  -172,  -172,   303,   199,   202,
      19,    90,  -172,    42,   210,  -172,    -2,  -172,    -2,  -172,
      -2,  -172,  -172,  -172
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       5,     0,     0,     0,    31,     0,     4,     7,     1,    61,
       0,     0,    47,     0,     6,     0,     0,     0,    61,    82,
      80,    74,     0,   122,     0,    29,    51,    52,     0,    53,
       0,     0,    54,    55,     0,    56,    57,    58,    59,    60,
       0,     2,     0,    30,    33,     0,    11,     0,     0,     0,
       0,     0,     0,     0,   117,   115,   122,   116,     0,   118,
     114,     0,    64,     0,     0,    81,     0,    91,    27,    61,
      61,    67,    61,    73,     0,     0,     0,     0,     0,     0,
       0,    32,    44,     0,    46,    49,     3,     0,     0,     0,
       0,   108,   107,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     0,
     122,     0,    85,     0,     0,    88,     0,    90,    93,    28,
      65,    69,     0,    79,    78,    61,   120,     0,    62,     0,
      41,    38,     0,    35,    36,    37,     0,     0,    48,     0,
       0,     9,     0,    10,     0,     0,     0,     0,     0,   109,
       0,   102,   103,   105,   104,    95,    94,    96,    97,   100,
      98,   101,    99,   106,    77,     0,    83,    75,     0,    86,
      89,     0,    61,     0,     0,     0,    72,     0,   121,     0,
       0,    34,    43,     0,     0,     0,     5,     5,   110,   111,
     112,   113,   119,    84,    87,    92,    70,    68,    66,    63,
      76,     0,    39,    40,     0,    50,    19,    19,     0,    31,
       0,     0,     0,     0,     0,    24,    23,     0,    18,    21,
       0,     0,    12,    47,    13,    15,    16,     0,     0,     0,
      25,     0,    14,     0,     0,    42,     0,    20,     0,    26,
       0,    17,    22,    45
  };

  const short int
  Parser::yypgoto_[] =
  {
    -172,  -172,  -172,   268,  -172,   255,  -172,  -172,  -172,  -172,
    -172,    62,  -172,    41,  -172,    83,    39,   -16,    65,  -172,
     239,  -120,  -172,  -172,  -172,  -172,  -171,  -172,    67,  -172,
     205,   222,  -172,  -172,  -172,   137,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,   201,  -172,   -13,  -172,    34
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,   209,     6,     7,    86,   141,   142,   143,
     144,   217,   218,   219,   220,   210,    10,    24,    12,    43,
      44,   132,   133,   134,   180,   203,    83,   135,    46,    84,
      85,    25,    26,    27,    28,    71,   121,   174,   175,    29,
      30,    31,    32,    33,    34,    76,    35,    36,    37,   111,
      38,   114,    39,   116,   117,   118,    59,    60
  };

  const short int
  Parser::yytable_[] =
  {
      58,   129,    64,    62,    68,   176,    65,   200,   202,   204,
     113,     5,   215,    74,   -72,   106,    15,   183,    73,    16,
     130,   216,   -72,     1,    17,   108,     8,    18,    19,    20,
     208,    69,   108,    75,     1,     1,    21,    22,    91,    92,
      93,   211,   215,    40,    69,    69,     9,    69,    11,   231,
     -25,   216,    40,   115,   120,   139,   122,    82,    13,   131,
     140,   123,   124,    41,    23,   127,   128,   -72,   103,   104,
     105,   106,    42,    77,   145,   146,   147,   148,    45,    78,
      70,   108,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   228,   163,   164,   112,    47,    77,
     167,   136,   137,    40,    40,    78,    40,    79,   165,   177,
      48,    49,   166,   168,   136,   214,   241,   169,   242,    50,
     243,   101,   102,   103,   104,   105,   106,    61,    51,   -72,
     104,   105,   106,    63,    52,    66,   108,   -72,   105,   106,
     136,   238,   108,    72,    80,    53,   172,   173,   -71,   108,
      67,    54,    55,    56,    57,   194,   196,    82,   195,    40,
     197,    87,    88,    89,    95,    96,   201,    97,    98,    99,
     100,    90,   101,   102,   103,   104,   105,   106,    94,   109,
     110,   107,   126,   125,   170,    95,    96,   108,    97,    98,
      99,   100,   171,   101,   102,   103,   104,   105,   106,   193,
     227,    69,   179,   181,   149,   182,    40,   184,   108,    95,
      96,   186,    97,    98,    99,   100,   185,   101,   102,   103,
     104,   105,   106,   187,   192,   199,   206,   240,   205,   222,
     178,   207,   108,    95,    96,   224,    97,    98,    99,   100,
     225,   101,   102,   103,   104,   105,   106,   226,   229,   230,
     232,   235,   188,   236,    95,    96,   108,    97,    98,    99,
     100,    14,   101,   102,   103,   104,   105,   106,     4,   221,
     212,   237,   239,   189,   223,    95,    96,   108,    97,    98,
      99,   100,    81,   101,   102,   103,   104,   105,   106,   138,
     233,   119,     0,     0,   190,   150,    95,    96,   108,    97,
      98,    99,   100,     0,   101,   102,   103,   104,   105,   106,
       0,   198,     0,     0,     0,   191,     0,    95,    96,   108,
      97,    98,    99,   100,     0,   101,   102,   103,   104,   105,
     106,     0,     0,   213,     0,     0,     0,     0,    95,    96,
     108,    97,    98,    99,   100,     0,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,   234,
       0,   108,    95,    96,     0,    97,    98,    99,   100,     0,
     101,   102,   103,   104,   105,   106,     0,     0,     0,    96,
       0,    97,    98,    99,   100,   108,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   108,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   108,   101,   102,
     103,   104,   105,   106,    99,   100,     0,   101,   102,   103,
     104,   105,   106,   108,   100,     0,   101,   102,   103,   104,
     105,   106,   108,   -72,   102,   103,   104,   105,   106,     0,
       0,   108,     0,     0,     0,     0,     0,     0,   108
  };

  const short int
  Parser::yycheck_[] =
  {
      13,     3,    18,    16,    12,    12,    19,    12,    12,   180,
      31,    61,    23,     9,    47,    48,    13,   137,    31,    16,
      22,    32,    48,     7,    21,    58,     0,    24,    25,    26,
      14,    52,    58,    29,     7,     7,    33,    34,    51,    52,
      53,    14,    23,     9,    52,    52,     4,    52,    30,   220,
      61,    32,    18,    66,    70,    15,    72,    61,    43,    61,
      20,    74,    75,    49,    61,    78,    79,    44,    45,    46,
      47,    48,    61,    49,    87,    88,    89,    90,    32,    55,
      28,    58,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   214,   108,   109,    63,     6,    49,
     113,    50,    51,    69,    70,    55,    72,    57,    50,   125,
      18,    19,    54,    50,    50,    51,   236,    54,   238,    27,
     240,    43,    44,    45,    46,    47,    48,    61,    36,    45,
      46,    47,    48,    53,    42,    53,    58,    46,    47,    48,
      50,    51,    58,     8,    43,    53,    10,    11,    12,    58,
      53,    59,    60,    61,    62,   168,   172,    61,   171,   125,
     173,    53,    53,    53,    35,    36,   179,    38,    39,    40,
      41,    53,    43,    44,    45,    46,    47,    48,    53,    57,
      61,    52,    61,     8,    54,    35,    36,    58,    38,    39,
      40,    41,    50,    43,    44,    45,    46,    47,    48,   165,
     213,    52,    55,    52,    54,    61,   172,    61,    58,    35,
      36,    52,    38,    39,    40,    41,    61,    43,    44,    45,
      46,    47,    48,    52,    54,    12,    53,    17,    52,    52,
      56,    53,    58,    35,    36,    52,    38,    39,    40,    41,
      52,    43,    44,    45,    46,    47,    48,    52,    54,    52,
      54,    52,    54,    51,    35,    36,    58,    38,    39,    40,
      41,     6,    43,    44,    45,    46,    47,    48,     0,   207,
     187,   230,   233,    54,   209,    35,    36,    58,    38,    39,
      40,    41,    43,    43,    44,    45,    46,    47,    48,    84,
     223,    69,    -1,    -1,    54,    94,    35,    36,    58,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      -1,   174,    -1,    -1,    -1,    54,    -1,    35,    36,    58,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    35,    36,
      58,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    58,    35,    36,    -1,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    36,
      -1,    38,    39,    40,    41,    58,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    58,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    58,    43,    44,
      45,    46,    47,    48,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    58,    41,    -1,    43,    44,    45,    46,
      47,    48,    58,    43,    44,    45,    46,    47,    48,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    58
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     7,    64,    65,    66,    61,    67,    68,     0,     4,
      79,    30,    81,    43,    68,    13,    16,    21,    24,    25,
      26,    33,    34,    61,    80,    94,    95,    96,    97,   102,
     103,   104,   105,   106,   107,   109,   110,   111,   113,   115,
     120,    49,    61,    82,    83,    32,    91,     6,    18,    19,
      27,    36,    42,    53,    59,    60,    61,    62,   118,   119,
     120,    61,   118,    53,    80,   118,    53,    53,    12,    52,
      28,    98,     8,   118,     9,    29,   108,    49,    55,    57,
      43,    83,    61,    89,    92,    93,    69,    53,    53,    53,
      53,   118,   118,   118,    53,    35,    36,    38,    39,    40,
      41,    43,    44,    45,    46,    47,    48,    52,    58,    57,
      61,   112,   120,    31,   114,   118,   116,   117,   118,    94,
      80,    99,    80,   118,   118,     8,    61,   118,   118,     3,
      22,    61,    84,    85,    86,    90,    50,    51,    93,    15,
      20,    70,    71,    72,    73,   118,   118,   118,   118,    54,
     116,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,    50,    54,   118,    50,    54,
      54,    50,    10,    11,   100,   101,    12,    80,    56,    55,
      87,    52,    61,    84,    61,    61,    52,    52,    54,    54,
      54,    54,    54,   120,   118,   118,    80,   118,    98,    12,
      12,   118,    12,    88,    89,    52,    53,    53,    14,    66,
      78,    14,    78,    51,    51,    23,    32,    74,    75,    76,
      77,    74,    52,    81,    52,    52,    52,   118,    84,    54,
      52,    89,    54,    91,    56,    52,    51,    76,    51,    79,
      17,    84,    84,    84
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
     101,   101,   102,   103,   104,   105,   106,   107,   108,   108,
     109,   110,   110,   111,   112,   112,   113,   114,   114,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     120,   120,   120
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
       2,     0,     4,     2,     1,     4,     5,     4,     2,     2,
       1,     2,     1,     4,     3,     1,     4,     3,     1,     4,
       1,     0,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       4,     4,     4,     4,     1,     1,     1,     1,     1,     4,
       3,     4,     1
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
  "WhileHead", "WhileSuperHead", "RepeatStatement", "ForStatement",
  "ForHead", "ToHead", "StopStatement", "ReturnStatement", "ReadStatement",
  "ReadArgs", "WriteStatement", "WriteArgs", "ProcedureCall",
  "OptArguments", "Arguments", "Expression", "FunctionCall", "LVal", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   161,   161,   163,   165,   166,   168,   169,   171,   173,
     174,   175,   177,   178,   180,   182,   183,   185,   187,   188,
     190,   191,   193,   195,   196,   197,   199,   201,   203,   204,
     206,   207,   209,   210,   212,   214,   215,   216,   218,   220,
     222,   223,   225,   227,   228,   230,   232,   233,   235,   236,
     238,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   252,   254,   256,   258,   260,   261,   263,   264,
     266,   267,   269,   271,   273,   275,   277,   279,   281,   282,
     284,   286,   287,   289,   291,   292,   294,   296,   297,   299,
     301,   302,   304,   305,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   333,
     335,   336,   337
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
#line 1936 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:1155
#line 339 "parser.ypp" // lalr1.cc:1156

void
yy::Parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
