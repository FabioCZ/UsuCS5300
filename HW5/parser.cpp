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
      case 102: // ElseClause
      case 104: // WhileStatement
      case 107: // RepeatStatement
      case 110: // ForStatement
      case 111: // ForHead
      case 112: // ToHead
      case 113: // StopStatement
      case 114: // ReturnStatement
      case 115: // ReadStatement
      case 116: // ReadArgs
      case 117: // WriteStatement
      case 118: // WriteArgs
      case 119: // ProcedureCall
      case 120: // OptArguments
      case 121: // Arguments
      case 123: // FunctionCall
        value.move< int > (that.value);
        break;

      case 105: // WhileHead
      case 106: // WhileSuperHead
      case 122: // Expression
        value.move< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 124: // LVal
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
      case 102: // ElseClause
      case 104: // WhileStatement
      case 107: // RepeatStatement
      case 110: // ForStatement
      case 111: // ForHead
      case 112: // ToHead
      case 113: // StopStatement
      case 114: // ReturnStatement
      case 115: // ReadStatement
      case 116: // ReadArgs
      case 117: // WriteStatement
      case 118: // WriteArgs
      case 119: // ProcedureCall
      case 120: // OptArguments
      case 121: // Arguments
      case 123: // FunctionCall
        value.copy< int > (that.value);
        break;

      case 105: // WhileHead
      case 106: // WhileSuperHead
      case 122: // Expression
        value.copy< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 124: // LVal
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
      case 102: // ElseClause
      case 104: // WhileStatement
      case 107: // RepeatStatement
      case 110: // ForStatement
      case 111: // ForHead
      case 112: // ToHead
      case 113: // StopStatement
      case 114: // ReturnStatement
      case 115: // ReadStatement
      case 116: // ReadArgs
      case 117: // WriteStatement
      case 118: // WriteArgs
      case 119: // ProcedureCall
      case 120: // OptArguments
      case 121: // Arguments
      case 123: // FunctionCall
        yylhs.value.build< int > ();
        break;

      case 105: // WhileHead
      case 106: // WhileSuperHead
      case 122: // Expression
        yylhs.value.build< std::shared_ptr<FC::Expr> > ();
        break;

      case 124: // LVal
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
    {FC::IfEnd();}
#line 985 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 256 "parser.ypp" // lalr1.cc:847
    {FC::IfHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
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
    {FC::ElseIfHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1015 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 264 "parser.ypp" // lalr1.cc:847
    {}
#line 1021 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 266 "parser.ypp" // lalr1.cc:847
    {FC::ElseIfSuperHead();}
#line 1027 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 268 "parser.ypp" // lalr1.cc:847
    {}
#line 1033 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 269 "parser.ypp" // lalr1.cc:847
    {FC::ElseHead();}
#line 1039 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 271 "parser.ypp" // lalr1.cc:847
    {FC::ElseHead();}
#line 1045 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 273 "parser.ypp" // lalr1.cc:847
    {FC::WhileEnd();}
#line 1051 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 275 "parser.ypp" // lalr1.cc:847
    {FC::WhileHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1057 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 277 "parser.ypp" // lalr1.cc:847
    {FC::WhileSuperHead();}
#line 1063 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 279 "parser.ypp" // lalr1.cc:847
    {}
#line 1069 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 281 "parser.ypp" // lalr1.cc:847
    {FC::RepeatEnd(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1075 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 283 "parser.ypp" // lalr1.cc:847
    {FC::RepeatHead();}
#line 1081 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 285 "parser.ypp" // lalr1.cc:847
    {FC::ForEnd();}
#line 1087 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 287 "parser.ypp" // lalr1.cc:847
    {FC::ForHead(yystack_[2].value.as< std::string > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1093 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 289 "parser.ypp" // lalr1.cc:847
    {FC::ToHead(true,yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1099 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 290 "parser.ypp" // lalr1.cc:847
    {FC::ToHead(false,yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1105 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 292 "parser.ypp" // lalr1.cc:847
    {FC::Stop();}
#line 1111 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 294 "parser.ypp" // lalr1.cc:847
    {}
#line 1117 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 295 "parser.ypp" // lalr1.cc:847
    {}
#line 1123 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 297 "parser.ypp" // lalr1.cc:847
    {}
#line 1129 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 299 "parser.ypp" // lalr1.cc:847
    {FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1135 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 300 "parser.ypp" // lalr1.cc:847
    {std::cout << "dafuq" << std::endl;FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1141 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 302 "parser.ypp" // lalr1.cc:847
    {}
#line 1147 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 304 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1153 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 305 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1159 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 307 "parser.ypp" // lalr1.cc:847
    {}
#line 1165 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 309 "parser.ypp" // lalr1.cc:847
    {}
#line 1171 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 310 "parser.ypp" // lalr1.cc:847
    {}
#line 1177 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 312 "parser.ypp" // lalr1.cc:847
    {}
#line 1183 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 313 "parser.ypp" // lalr1.cc:847
    {}
#line 1189 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 315 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcOrExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1195 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 316 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcAndExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1201 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 317 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1207 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 318 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1213 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 319 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1219 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 320 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1225 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 321 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1231 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 322 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1237 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 323 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcPlusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1243 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 324 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMinusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1249 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 325 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcDivideExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1255 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 326 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMultiplyExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1261 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 327 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcModExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1267 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 328 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1273 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 329 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcUnaryMinusExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1279 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 330 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = yystack_[1].value.as< std::shared_ptr<FC::Expr> > ();}
#line 1285 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 331 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToChar(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1291 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 332 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToInt(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1297 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 333 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcDecrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1303 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 334 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIncrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1309 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 335 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::LValToExpr(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ()); }
#line 1315 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 336 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIntExpr(yystack_[0].value.as< int > ());}
#line 1321 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 337 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcStringExpr(yystack_[0].value.as< std::string > ());}
#line 1327 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 121:
#line 338 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcCharExpr(yystack_[0].value.as< char > ());}
#line 1333 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 122:
#line 339 "parser.ypp" // lalr1.cc:847
    {/*todo*/}
#line 1339 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 123:
#line 341 "parser.ypp" // lalr1.cc:847
    {}
#line 1345 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 124:
#line 343 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1351 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 125:
#line 344 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1357 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;

  case 126:
#line 345 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = FC::GetLValForIdent(yystack_[0].value.as< std::string > ());}
#line 1363 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
    break;


#line 1367 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:847
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


  const short int Parser::yypact_ninf_ = -175;

  const signed char Parser::yytable_ninf_ = -73;

  const short int
  Parser::yypact_[] =
  {
      23,   -57,    12,    57,    43,    36,   -57,  -175,  -175,    -2,
      33,    37,    81,   112,  -175,    68,   112,    99,  -175,   112,
    -175,  -175,   100,   104,    -4,  -175,  -175,  -175,   121,  -175,
     156,   112,  -175,    -2,  -175,    17,  -175,  -175,  -175,  -175,
    -175,    -6,  -175,   115,    37,  -175,   105,  -175,   116,   122,
     130,   137,   112,   112,   112,  -175,  -175,   138,  -175,    76,
    -175,    16,   111,   296,   131,   296,   112,   112,  -175,    -2,
      -2,  -175,    -2,   296,   -18,   112,   112,   185,   133,   112,
     112,    -1,  -175,  -175,    58,   105,  -175,    80,   112,   112,
     112,   112,   328,   369,    97,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,  -175,   112,
     112,  -175,    51,    16,    53,   296,   142,   145,   296,  -175,
     146,   150,     3,   112,  -175,   296,   296,    -2,  -175,   141,
     296,   154,  -175,  -175,   148,  -175,  -175,  -175,   140,    -1,
    -175,   161,   176,  -175,   191,  -175,   206,   167,   188,   209,
     230,  -175,   205,   312,   328,   344,   353,   362,   369,   378,
     172,   193,   -11,   -20,    10,  -175,   296,   131,  -175,   112,
    -175,  -175,   112,  -175,  -175,   121,   112,   248,    -2,  -175,
     296,     5,  -175,   112,    -5,  -175,  -175,   210,   208,   211,
      38,    67,  -175,  -175,  -175,  -175,  -175,    16,   296,   296,
    -175,   296,  -175,   146,  -175,   251,  -175,  -175,    75,  -175,
      -7,    -7,   220,    43,   227,   228,   229,   112,    -1,  -175,
    -175,   231,   241,  -175,   105,   246,  -175,    81,  -175,  -175,
    -175,   272,   249,   232,    -3,    96,  -175,    57,   265,  -175,
      -1,  -175,    -1,  -175,    -1,  -175,  -175,  -175
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       5,     0,     0,     0,    31,     0,     4,     7,     1,    61,
       0,     0,    47,     0,     6,     0,     0,     0,    79,    86,
      84,    76,     0,   126,     0,    29,    51,    52,     0,    53,
       0,     0,    54,    61,    55,     0,    56,    57,    58,    59,
      60,     0,     2,     0,    30,    33,     0,    11,     0,     0,
       0,     0,     0,     0,     0,   121,   119,   126,   120,     0,
     122,   118,     0,    64,     0,    85,     0,    95,    27,    61,
      61,    67,    61,    75,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    44,     0,    46,    49,     3,     0,     0,
       0,     0,   112,   111,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,   126,     0,    89,     0,    92,     0,    94,    97,    28,
      65,    69,     0,     0,    77,    83,    82,    61,   124,     0,
      62,     0,    41,    38,     0,    35,    36,    37,     0,     0,
      48,     0,     0,     9,     0,    10,     0,     0,     0,     0,
       0,   113,     0,   106,   107,   109,   108,    99,    98,   100,
     101,   104,   102,   105,   103,   110,    81,     0,    87,     0,
      90,    93,     0,    73,    70,     0,     0,     0,    61,    74,
      78,     0,   125,     0,     0,    34,    43,     0,     0,     0,
       5,     5,   114,   115,   116,   117,   123,    88,    91,    96,
      66,    68,    63,    71,    80,     0,    39,    40,     0,    50,
      19,    19,     0,    31,     0,     0,     0,     0,     0,    24,
      23,     0,    18,    21,     0,     0,    12,    47,    13,    15,
      16,     0,     0,     0,    25,     0,    14,     0,     0,    42,
       0,    20,     0,    26,     0,    17,    22,    45
  };

  const short int
  Parser::yypgoto_[] =
  {
    -175,  -175,  -175,   303,  -175,   298,  -175,  -175,  -175,  -175,
    -175,    94,  -175,    72,  -175,   123,    84,   -28,   109,  -175,
     279,  -138,  -175,  -175,  -175,  -175,  -174,  -175,    98,  -175,
     239,   257,  -175,  -175,  -175,   152,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,   234,  -175,   -13,
    -175,     0
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,   213,     6,     7,    87,   143,   144,   145,
     146,   221,   222,   223,   224,   214,    10,    24,    12,    44,
      45,   134,   135,   136,   184,   207,    84,   137,    47,    85,
      86,    25,    26,    27,    28,    71,   121,   175,   176,   177,
     178,    29,    30,    31,    32,   124,    33,    34,    35,    77,
      36,    37,    38,   112,    39,   114,    40,   116,   117,   118,
      60,    61
  };

  const short int
  Parser::yytable_[] =
  {
      59,   187,   131,    63,     5,    74,    65,   206,    68,    41,
     208,    15,     8,   123,    16,   179,   219,   204,    73,    17,
     219,   132,    18,    19,    20,   220,    75,   -73,   107,   220,
       1,    21,    22,    41,    69,   -73,   106,   107,   109,    92,
      93,    94,   120,    78,   122,     1,    76,   109,    69,    79,
     235,    80,   212,   115,   -25,    69,    83,    69,   -73,    23,
     133,     9,   125,   126,   113,    78,   129,   130,   109,    41,
      41,    79,    41,    11,     1,   147,   148,   149,   150,    13,
     232,   215,    42,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   141,   165,   166,    43,   181,
     142,   167,   245,   169,   246,   168,   247,   170,   138,   139,
     180,    96,    97,    46,    98,    99,   100,   101,    48,   102,
     103,   104,   105,   106,   107,   138,   218,    41,   108,    62,
      49,    50,    96,    97,   109,    98,    99,   100,   101,    51,
     102,   103,   104,   105,   106,   107,   138,   242,    52,    70,
     203,   151,    64,    66,    53,   109,   198,    67,    81,   199,
     173,   174,   -72,   201,    72,    54,    83,   197,   110,    88,
     205,    55,    56,    57,    58,    89,    96,    97,    41,    98,
      99,   100,   101,    90,   102,   103,   104,   105,   106,   107,
      91,    95,   111,   127,   128,   172,   171,   182,    69,   109,
     185,   186,    96,    97,   231,    98,    99,   100,   101,   183,
     102,   103,   104,   105,   106,   107,   -73,   104,   105,   106,
     107,   192,   188,    96,    97,   109,    98,    99,   100,   101,
     109,   102,   103,   104,   105,   106,   107,   189,   -73,   105,
     106,   107,   193,   190,    96,    97,   109,    98,    99,   100,
     101,   109,   102,   103,   104,   105,   106,   107,   191,   196,
     202,   210,   209,   194,   211,    96,    97,   109,    98,    99,
     100,   101,   226,   102,   103,   104,   105,   106,   107,   228,
     229,   230,   244,   240,   195,   233,    96,    97,   109,    98,
      99,   100,   101,   234,   102,   103,   104,   105,   106,   107,
     236,   239,   217,     4,    14,   225,   241,    96,    97,   109,
      98,    99,   100,   101,   216,   102,   103,   104,   105,   106,
     107,   243,   227,    82,   140,   237,   119,   200,   238,   152,
     109,    96,    97,     0,    98,    99,   100,   101,     0,   102,
     103,   104,   105,   106,   107,     0,     0,     0,    97,     0,
      98,    99,   100,   101,   109,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     109,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   109,   102,   103,   104,
     105,   106,   107,   100,   101,     0,   102,   103,   104,   105,
     106,   107,   109,   101,     0,   102,   103,   104,   105,   106,
     107,   109,   102,   103,   104,   105,   106,   107,     0,     0,
     109,   -73,   103,   104,   105,   106,   107,   109,     0,     0,
       0,     0,     0,     0,     0,     0,   109
  };

  const short int
  Parser::yycheck_[] =
  {
      13,   139,     3,    16,    61,    33,    19,    12,    12,     9,
     184,    13,     0,    31,    16,    12,    23,    12,    31,    21,
      23,    22,    24,    25,    26,    32,     9,    47,    48,    32,
       7,    33,    34,    33,    52,    46,    47,    48,    58,    52,
      53,    54,    70,    49,    72,     7,    29,    58,    52,    55,
     224,    57,    14,    66,    61,    52,    61,    52,    48,    61,
      61,     4,    75,    76,    64,    49,    79,    80,    58,    69,
      70,    55,    72,    30,     7,    88,    89,    90,    91,    43,
     218,    14,    49,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    15,   109,   110,    61,   127,
      20,    50,   240,    50,   242,    54,   244,    54,    50,    51,
     123,    35,    36,    32,    38,    39,    40,    41,     6,    43,
      44,    45,    46,    47,    48,    50,    51,   127,    52,    61,
      18,    19,    35,    36,    58,    38,    39,    40,    41,    27,
      43,    44,    45,    46,    47,    48,    50,    51,    36,    28,
     178,    54,    53,    53,    42,    58,   169,    53,    43,   172,
      10,    11,    12,   176,     8,    53,    61,   167,    57,    53,
     183,    59,    60,    61,    62,    53,    35,    36,   178,    38,
      39,    40,    41,    53,    43,    44,    45,    46,    47,    48,
      53,    53,    61,     8,    61,    50,    54,    56,    52,    58,
      52,    61,    35,    36,   217,    38,    39,    40,    41,    55,
      43,    44,    45,    46,    47,    48,    44,    45,    46,    47,
      48,    54,    61,    35,    36,    58,    38,    39,    40,    41,
      58,    43,    44,    45,    46,    47,    48,    61,    45,    46,
      47,    48,    54,    52,    35,    36,    58,    38,    39,    40,
      41,    58,    43,    44,    45,    46,    47,    48,    52,    54,
      12,    53,    52,    54,    53,    35,    36,    58,    38,    39,
      40,    41,    52,    43,    44,    45,    46,    47,    48,    52,
      52,    52,    17,    51,    54,    54,    35,    36,    58,    38,
      39,    40,    41,    52,    43,    44,    45,    46,    47,    48,
      54,    52,    51,     0,     6,   211,   234,    35,    36,    58,
      38,    39,    40,    41,   191,    43,    44,    45,    46,    47,
      48,   237,   213,    44,    85,   227,    69,   175,    56,    95,
      58,    35,    36,    -1,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    58,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      58,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    58,    43,    44,    45,
      46,    47,    48,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    58,    41,    -1,    43,    44,    45,    46,    47,
      48,    58,    43,    44,    45,    46,    47,    48,    -1,    -1,
      58,    43,    44,    45,    46,    47,    48,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     7,    64,    65,    66,    61,    67,    68,     0,     4,
      79,    30,    81,    43,    68,    13,    16,    21,    24,    25,
      26,    33,    34,    61,    80,    94,    95,    96,    97,   104,
     105,   106,   107,   109,   110,   111,   113,   114,   115,   117,
     119,   124,    49,    61,    82,    83,    32,    91,     6,    18,
      19,    27,    36,    42,    53,    59,    60,    61,    62,   122,
     123,   124,    61,   122,    53,   122,    53,    53,    12,    52,
      28,    98,     8,   122,    80,     9,    29,   112,    49,    55,
      57,    43,    83,    61,    89,    92,    93,    69,    53,    53,
      53,    53,   122,   122,   122,    53,    35,    36,    38,    39,
      40,    41,    43,    44,    45,    46,    47,    48,    52,    58,
      57,    61,   116,   124,   118,   122,   120,   121,   122,    94,
      80,    99,    80,    31,   108,   122,   122,     8,    61,   122,
     122,     3,    22,    61,    84,    85,    86,    90,    50,    51,
      93,    15,    20,    70,    71,    72,    73,   122,   122,   122,
     122,    54,   120,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,    50,    54,    50,
      54,    54,    50,    10,    11,   100,   101,   102,   103,    12,
     122,    80,    56,    55,    87,    52,    61,    84,    61,    61,
      52,    52,    54,    54,    54,    54,    54,   124,   122,   122,
      98,   122,    12,    80,    12,   122,    12,    88,    89,    52,
      53,    53,    14,    66,    78,    14,    78,    51,    51,    23,
      32,    74,    75,    76,    77,    74,    52,    81,    52,    52,
      52,   122,    84,    54,    52,    89,    54,    91,    56,    52,
      51,    76,    51,    79,    17,    84,    84,    84
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
     101,   102,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   112,   113,   114,   114,   115,   116,   116,
     117,   118,   118,   119,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   124,   124,   124
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
       1,     2,     0,     1,     4,     2,     1,     3,     2,     1,
       5,     4,     2,     2,     1,     2,     1,     4,     3,     1,
       4,     3,     1,     4,     1,     0,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     4,     4,     4,     4,     1,     1,
       1,     1,     1,     4,     3,     4,     1
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
  "ThenPart", "ElseIfList", "ElseIfHead", "ElseIfSuperHead", "ElseClause",
  "ElseHead", "WhileStatement", "WhileHead", "WhileSuperHead",
  "RepeatStatement", "RepeatEnd", "RepeatHead", "ForStatement", "ForHead",
  "ToHead", "StopStatement", "ReturnStatement", "ReadStatement",
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
     266,   268,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   290,   292,   294,   295,   297,   299,   300,
     302,   304,   305,   307,   309,   310,   312,   313,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   341,   343,   344,   345
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
#line 1959 "/home/fabio/Desktop/UsuCS5300/HW4/parser.cpp" // lalr1.cc:1155
#line 347 "parser.ypp" // lalr1.cc:1156

void
yy::Parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
