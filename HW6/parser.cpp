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

#line 37 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 51 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 41 "parser.ypp" // lalr1.cc:408

# include "driver.hpp"

#line 57 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:408


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
#line 143 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:474

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
      case 90: // Type
      case 91: // SimpleType
      case 92: // RecordType
      case 96: // ArrayType
        value.move< FC::Type > (that.value);
        break;

      case 74: // PBody
      case 77: // FBody
        value.move< bool > (that.value);
        break;

      case 59: // CharTok
        value.move< char > (that.value);
        break;

      case 60: // IntTok
      case 83: // OptVar
      case 84: // Body
      case 85: // Block
      case 95: // IdentList
      case 101: // Assignment
      case 102: // IfStatement
      case 103: // IfHead
      case 104: // ThenPart
      case 105: // ElseIfList
      case 106: // ElseIfHead
      case 108: // ElseClause
      case 110: // WhileStatement
      case 113: // RepeatStatement
      case 116: // ForStatement
      case 117: // ForHead
      case 118: // ToHead
      case 119: // StopStatement
      case 120: // ReturnStatement
      case 121: // ReadStatement
      case 122: // ReadArgs
      case 123: // WriteStatement
      case 124: // WriteArgs
      case 125: // ProcedureCall
        value.move< int > (that.value);
        break;

      case 94: // FieldDecl
        value.move< std::pair<std::vector<std::string>,FC::Type> > (that.value);
        break;

      case 111: // WhileHead
      case 112: // WhileSuperHead
      case 128: // Expression
      case 129: // FunctionCall
        value.move< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 75: // PSignature
      case 78: // FSignature
        value.move< std::shared_ptr<FC::Func>  > (that.value);
        break;

      case 130: // LVal
        value.move< std::shared_ptr<FC::LVal>  > (that.value);
        break;

      case 79: // OptFormalParameters
      case 80: // FormalParameters
      case 81: // FormalParameter
        value.move< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (that.value);
        break;

      case 126: // OptArguments
      case 127: // Arguments
        value.move< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > (that.value);
        break;

      case 82: // ParamIdentList
        value.move< std::shared_ptr<std::vector<std::string> >  > (that.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 86: // StatementList
      case 100: // Statement
        value.move< std::string > (that.value);
        break;

      case 93: // FieldDecls
        value.move< std::vector<std::pair<std::vector<std::string>,FC::Type>> > (that.value);
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
      case 90: // Type
      case 91: // SimpleType
      case 92: // RecordType
      case 96: // ArrayType
        value.copy< FC::Type > (that.value);
        break;

      case 74: // PBody
      case 77: // FBody
        value.copy< bool > (that.value);
        break;

      case 59: // CharTok
        value.copy< char > (that.value);
        break;

      case 60: // IntTok
      case 83: // OptVar
      case 84: // Body
      case 85: // Block
      case 95: // IdentList
      case 101: // Assignment
      case 102: // IfStatement
      case 103: // IfHead
      case 104: // ThenPart
      case 105: // ElseIfList
      case 106: // ElseIfHead
      case 108: // ElseClause
      case 110: // WhileStatement
      case 113: // RepeatStatement
      case 116: // ForStatement
      case 117: // ForHead
      case 118: // ToHead
      case 119: // StopStatement
      case 120: // ReturnStatement
      case 121: // ReadStatement
      case 122: // ReadArgs
      case 123: // WriteStatement
      case 124: // WriteArgs
      case 125: // ProcedureCall
        value.copy< int > (that.value);
        break;

      case 94: // FieldDecl
        value.copy< std::pair<std::vector<std::string>,FC::Type> > (that.value);
        break;

      case 111: // WhileHead
      case 112: // WhileSuperHead
      case 128: // Expression
      case 129: // FunctionCall
        value.copy< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 75: // PSignature
      case 78: // FSignature
        value.copy< std::shared_ptr<FC::Func>  > (that.value);
        break;

      case 130: // LVal
        value.copy< std::shared_ptr<FC::LVal>  > (that.value);
        break;

      case 79: // OptFormalParameters
      case 80: // FormalParameters
      case 81: // FormalParameter
        value.copy< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (that.value);
        break;

      case 126: // OptArguments
      case 127: // Arguments
        value.copy< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > (that.value);
        break;

      case 82: // ParamIdentList
        value.copy< std::shared_ptr<std::vector<std::string> >  > (that.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 86: // StatementList
      case 100: // Statement
        value.copy< std::string > (that.value);
        break;

      case 93: // FieldDecls
        value.copy< std::vector<std::pair<std::vector<std::string>,FC::Type>> > (that.value);
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
    #line 32 "parser.ypp" // lalr1.cc:725
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 584 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:725

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
      case 90: // Type
      case 91: // SimpleType
      case 92: // RecordType
      case 96: // ArrayType
        yylhs.value.build< FC::Type > ();
        break;

      case 74: // PBody
      case 77: // FBody
        yylhs.value.build< bool > ();
        break;

      case 59: // CharTok
        yylhs.value.build< char > ();
        break;

      case 60: // IntTok
      case 83: // OptVar
      case 84: // Body
      case 85: // Block
      case 95: // IdentList
      case 101: // Assignment
      case 102: // IfStatement
      case 103: // IfHead
      case 104: // ThenPart
      case 105: // ElseIfList
      case 106: // ElseIfHead
      case 108: // ElseClause
      case 110: // WhileStatement
      case 113: // RepeatStatement
      case 116: // ForStatement
      case 117: // ForHead
      case 118: // ToHead
      case 119: // StopStatement
      case 120: // ReturnStatement
      case 121: // ReadStatement
      case 122: // ReadArgs
      case 123: // WriteStatement
      case 124: // WriteArgs
      case 125: // ProcedureCall
        yylhs.value.build< int > ();
        break;

      case 94: // FieldDecl
        yylhs.value.build< std::pair<std::vector<std::string>,FC::Type> > ();
        break;

      case 111: // WhileHead
      case 112: // WhileSuperHead
      case 128: // Expression
      case 129: // FunctionCall
        yylhs.value.build< std::shared_ptr<FC::Expr> > ();
        break;

      case 75: // PSignature
      case 78: // FSignature
        yylhs.value.build< std::shared_ptr<FC::Func>  > ();
        break;

      case 130: // LVal
        yylhs.value.build< std::shared_ptr<FC::LVal>  > ();
        break;

      case 79: // OptFormalParameters
      case 80: // FormalParameters
      case 81: // FormalParameter
        yylhs.value.build< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ();
        break;

      case 126: // OptArguments
      case 127: // Arguments
        yylhs.value.build< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ();
        break;

      case 82: // ParamIdentList
        yylhs.value.build< std::shared_ptr<std::vector<std::string> >  > ();
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 86: // StatementList
      case 100: // Statement
        yylhs.value.build< std::string > ();
        break;

      case 93: // FieldDecls
        yylhs.value.build< std::vector<std::pair<std::vector<std::string>,FC::Type>> > ();
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
#line 164 "parser.ypp" // lalr1.cc:847
    {FC::AddMain();}
#line 787 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 168 "parser.ypp" // lalr1.cc:847
    {FC::MainBlock();FC::WriteStatement();}
#line 793 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 170 "parser.ypp" // lalr1.cc:847
    {FC::FuncBlock();}
#line 799 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 6:
#line 170 "parser.ypp" // lalr1.cc:847
    { FC::CheckForwardDecls();}
#line 805 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 178 "parser.ypp" // lalr1.cc:847
    {FC::AddConst(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 811 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 184 "parser.ypp" // lalr1.cc:847
    {yystack_[3].value.as< std::shared_ptr<FC::Func>  > ()->isForwardDeclared = yystack_[1].value.as< bool > ();FC::AddFunction(yystack_[3].value.as< std::shared_ptr<FC::Func>  > ());}
#line 817 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 186 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< bool > () = false;}
#line 823 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 187 "parser.ypp" // lalr1.cc:847
    { yylhs.value.as< bool > () = true;}
#line 829 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 189 "parser.ypp" // lalr1.cc:847
    {FC::AddLocalParams(yystack_[1].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (),FC::VoidType()); yylhs.value.as< std::shared_ptr<FC::Func>  > () = std::make_shared<FC::Func>(nullptr, yystack_[1].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (), yystack_[3].value.as< std::string > ());}
#line 835 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 191 "parser.ypp" // lalr1.cc:847
    {yystack_[3].value.as< std::shared_ptr<FC::Func>  > ()->isForwardDeclared = yystack_[1].value.as< bool > ();FC::AddFunction(yystack_[3].value.as< std::shared_ptr<FC::Func>  > ());}
#line 841 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 193 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< bool > () = false;}
#line 847 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 194 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< bool > () = true;}
#line 853 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 196 "parser.ypp" // lalr1.cc:847
    {FC::AddLocalParams(yystack_[3].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (),yystack_[0].value.as< FC::Type > ()); yylhs.value.as< std::shared_ptr<FC::Func>  > () = std::make_shared<FC::Func>(std::make_shared<FC::Type>(yystack_[0].value.as< FC::Type > ()), yystack_[3].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (), yystack_[5].value.as< std::string > ());}
#line 859 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 198 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () = yystack_[0].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ();}
#line 865 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 199 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () = nullptr;}
#line 871 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 202 "parser.ypp" // lalr1.cc:847
    {
        //$1->insert($3->end(),$3->begin(),$3->end());
        for(auto s : (*yystack_[0].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ()))
        {
            yystack_[2].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ()->push_back(s);
        }
        yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () =yystack_[2].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ();}
#line 883 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 209 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () = yystack_[0].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ();}
#line 889 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 212 "parser.ypp" // lalr1.cc:847
    {   //TODO VAR/REF
                auto a = std::make_shared<std::vector<std::pair<std::string,FC::Type> >>();
                for(int i = 0; i < yystack_[2].value.as< std::shared_ptr<std::vector<std::string> >  > ()->size();i++)
                {
                    a->push_back(std::pair<std::string,FC::Type>((*yystack_[2].value.as< std::shared_ptr<std::vector<std::string> >  > ())[i],yystack_[0].value.as< FC::Type > ()));
                }
                yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () = a;
            }
#line 902 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 221 "parser.ypp" // lalr1.cc:847
    {yystack_[2].value.as< std::shared_ptr<std::vector<std::string> >  > ()->push_back(yystack_[0].value.as< std::string > ()); yylhs.value.as< std::shared_ptr<std::vector<std::string> >  > () = yystack_[2].value.as< std::shared_ptr<std::vector<std::string> >  > ();}
#line 908 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 222 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::string> >  > () = std::make_shared<std::vector<std::string> >(1,yystack_[0].value.as< std::string > ());}
#line 914 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 224 "parser.ypp" // lalr1.cc:847
    {}
#line 920 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 31:
#line 225 "parser.ypp" // lalr1.cc:847
    {std::cout << "Unfortunately, passing by reference is not supported, passing by value instead" << std::endl;}
#line 926 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 226 "parser.ypp" // lalr1.cc:847
    {}
#line 932 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 228 "parser.ypp" // lalr1.cc:847
    {}
#line 938 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 230 "parser.ypp" // lalr1.cc:847
    {}
#line 944 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 232 "parser.ypp" // lalr1.cc:847
    {}
#line 950 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 36:
#line 233 "parser.ypp" // lalr1.cc:847
    {}
#line 956 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 241 "parser.ypp" // lalr1.cc:847
    {FC::DeclareType(yystack_[3].value.as< std::string > (),yystack_[1].value.as< FC::Type > ());}
#line 962 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 243 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = yystack_[0].value.as< FC::Type > ();}
#line 968 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 244 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = yystack_[0].value.as< FC::Type > ();}
#line 974 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 245 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = yystack_[0].value.as< FC::Type > ();}
#line 980 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 247 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = FC::SimpleTypeLookup(yystack_[0].value.as< std::string > ());}
#line 986 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 249 "parser.ypp" // lalr1.cc:847
    {FC::GetRecordType(yystack_[1].value.as< std::vector<std::pair<std::vector<std::string>,FC::Type>> > ());}
#line 992 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 251 "parser.ypp" // lalr1.cc:847
    {yystack_[1].value.as< std::vector<std::pair<std::vector<std::string>,FC::Type>> > ().push_back(yystack_[0].value.as< std::pair<std::vector<std::string>,FC::Type> > ());yylhs.value.as< std::vector<std::pair<std::vector<std::string>,FC::Type>> > ()=yystack_[1].value.as< std::vector<std::pair<std::vector<std::string>,FC::Type>> > ();}
#line 998 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 253 "parser.ypp" // lalr1.cc:847
    {
            auto a = std::vector<std::pair<std::vector<std::string>,FC::Type>>();
            a.push_back(yystack_[0].value.as< std::pair<std::vector<std::string>,FC::Type> > ());
            yylhs.value.as< std::vector<std::pair<std::vector<std::string>,FC::Type>> > () = a;
        }
#line 1008 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 259 "parser.ypp" // lalr1.cc:847
    {FC::GetRecordFields(yystack_[1].value.as< FC::Type > ());}
#line 1014 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 261 "parser.ypp" // lalr1.cc:847
    {FC::AddIdent(yystack_[0].value.as< std::string > ());}
#line 1020 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 262 "parser.ypp" // lalr1.cc:847
    {FC::AddIdent(yystack_[0].value.as< std::string > ());}
#line 1026 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 264 "parser.ypp" // lalr1.cc:847
    {GetArrayType(yystack_[5].value.as< std::shared_ptr<FC::Expr> > (),yystack_[3].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< FC::Type > ());}
#line 1032 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 272 "parser.ypp" // lalr1.cc:847
    {AddVariables(yystack_[1].value.as< FC::Type > ());}
#line 1038 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 274 "parser.ypp" // lalr1.cc:847
    {}
#line 1044 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 275 "parser.ypp" // lalr1.cc:847
    {}
#line 1050 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 276 "parser.ypp" // lalr1.cc:847
    {}
#line 1056 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 277 "parser.ypp" // lalr1.cc:847
    {}
#line 1062 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 278 "parser.ypp" // lalr1.cc:847
    {}
#line 1068 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 279 "parser.ypp" // lalr1.cc:847
    {}
#line 1074 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 280 "parser.ypp" // lalr1.cc:847
    {}
#line 1080 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 281 "parser.ypp" // lalr1.cc:847
    {}
#line 1086 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 282 "parser.ypp" // lalr1.cc:847
    {}
#line 1092 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 283 "parser.ypp" // lalr1.cc:847
    {}
#line 1098 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 284 "parser.ypp" // lalr1.cc:847
    {}
#line 1104 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 286 "parser.ypp" // lalr1.cc:847
    {FC::Assignment(yystack_[2].value.as< std::shared_ptr<FC::LVal>  > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1110 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 288 "parser.ypp" // lalr1.cc:847
    {FC::IfEnd();}
#line 1116 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 290 "parser.ypp" // lalr1.cc:847
    {FC::IfHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1122 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 292 "parser.ypp" // lalr1.cc:847
    {}
#line 1128 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 294 "parser.ypp" // lalr1.cc:847
    {}
#line 1134 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 295 "parser.ypp" // lalr1.cc:847
    {}
#line 1140 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 297 "parser.ypp" // lalr1.cc:847
    {FC::ElseIfHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1146 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 298 "parser.ypp" // lalr1.cc:847
    {}
#line 1152 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 300 "parser.ypp" // lalr1.cc:847
    {FC::ElseIfSuperHead();}
#line 1158 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 302 "parser.ypp" // lalr1.cc:847
    {}
#line 1164 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 303 "parser.ypp" // lalr1.cc:847
    {FC::ElseHead();}
#line 1170 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 305 "parser.ypp" // lalr1.cc:847
    {FC::ElseHead();}
#line 1176 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 307 "parser.ypp" // lalr1.cc:847
    {FC::WhileEnd();}
#line 1182 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 309 "parser.ypp" // lalr1.cc:847
    {FC::WhileHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1188 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 311 "parser.ypp" // lalr1.cc:847
    {FC::WhileSuperHead();}
#line 1194 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 313 "parser.ypp" // lalr1.cc:847
    {}
#line 1200 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 315 "parser.ypp" // lalr1.cc:847
    {FC::RepeatEnd(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1206 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 317 "parser.ypp" // lalr1.cc:847
    {FC::RepeatHead();}
#line 1212 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 319 "parser.ypp" // lalr1.cc:847
    {FC::ForEnd();}
#line 1218 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 321 "parser.ypp" // lalr1.cc:847
    {FC::ForHead(yystack_[2].value.as< std::string > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1224 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 323 "parser.ypp" // lalr1.cc:847
    {FC::ToHead(true,yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1230 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 324 "parser.ypp" // lalr1.cc:847
    {FC::ToHead(false,yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1236 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 326 "parser.ypp" // lalr1.cc:847
    {FC::Stop();}
#line 1242 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 328 "parser.ypp" // lalr1.cc:847
    {FC::AddReturn(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1248 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 329 "parser.ypp" // lalr1.cc:847
    {FC::AddReturn(nullptr);}
#line 1254 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 331 "parser.ypp" // lalr1.cc:847
    {}
#line 1260 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 333 "parser.ypp" // lalr1.cc:847
    {FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1266 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 334 "parser.ypp" // lalr1.cc:847
    {std::cout << "dafuq" << std::endl;FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1272 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 336 "parser.ypp" // lalr1.cc:847
    {}
#line 1278 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 338 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1284 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 339 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1290 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 341 "parser.ypp" // lalr1.cc:847
    {FC::CallFunction(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ());}
#line 1296 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 343 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > () = yystack_[0].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ();}
#line 1302 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 344 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > () = nullptr;}
#line 1308 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 346 "parser.ypp" // lalr1.cc:847
    {yystack_[2].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ()->push_back(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());yylhs.value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > () = yystack_[2].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ();}
#line 1314 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 347 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > () = std::make_shared<std::vector<std::shared_ptr<FC::Expr> > >(1,yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1320 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 349 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcOrExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1326 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 350 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcAndExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1332 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 351 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1338 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 352 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1344 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 353 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1350 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 354 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1356 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 355 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1362 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 356 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1368 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 357 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcPlusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1374 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 358 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMinusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1380 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 359 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcDivideExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1386 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 360 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMultiplyExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1392 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 361 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcModExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1398 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 362 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1404 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 363 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcUnaryMinusExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1410 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 364 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = yystack_[1].value.as< std::shared_ptr<FC::Expr> > ();}
#line 1416 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 121:
#line 365 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToChar(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1422 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 122:
#line 366 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToInt(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1428 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 123:
#line 367 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcDecrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1434 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 124:
#line 368 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIncrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1440 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 125:
#line 369 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::LValToExpr(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ()); }
#line 1446 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 126:
#line 370 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIntExpr(yystack_[0].value.as< int > ());}
#line 1452 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 127:
#line 371 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcStringExpr(yystack_[0].value.as< std::string > ());}
#line 1458 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 128:
#line 372 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcCharExpr(yystack_[0].value.as< char > ());}
#line 1464 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 129:
#line 373 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = yystack_[0].value.as< std::shared_ptr<FC::Expr> > ();}
#line 1470 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 130:
#line 375 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::CallFunction(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ());}
#line 1476 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 131:
#line 377 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = FC::GetRecordField(yystack_[2].value.as< std::shared_ptr<FC::LVal>  > (),yystack_[0].value.as< std::string > ());}
#line 1482 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 132:
#line 378 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1488 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;

  case 133:
#line 379 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = FC::GetLValForIdent(yystack_[0].value.as< std::string > ());}
#line 1494 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
    break;


#line 1498 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:847
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


  const signed char Parser::yypact_ninf_ = -118;

  const signed char Parser::yytable_ninf_ = -80;

  const short int
  Parser::yypact_[] =
  {
      27,   -53,    44,  -118,    15,    11,   -53,  -118,  -118,    -1,
      78,    29,    68,    95,  -118,  -118,    -4,  -118,    69,    29,
    -118,    75,  -118,    85,    86,    88,    89,    95,    95,    95,
    -118,  -118,    90,  -118,   146,  -118,   -36,    91,    95,    92,
    -118,    95,  -118,  -118,    93,    96,    -5,  -118,  -118,  -118,
     123,  -118,   145,    95,  -118,    -4,  -118,     9,  -118,  -118,
    -118,  -118,  -118,   -18,     1,  -118,  -118,    55,    75,  -118,
    -118,    95,    95,    95,    95,   376,    72,   170,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,  -118,    95,   100,    95,   112,   344,   110,   344,    95,
      95,  -118,    -4,    -4,  -118,    -4,   344,   -20,    95,    95,
     164,    95,   120,    75,  -118,   122,  -118,  -118,  -118,   115,
       1,  -118,    82,   191,   212,   233,   254,  -118,   124,   133,
     344,   360,   376,   119,   385,   394,    72,   401,   175,    63,
      46,     5,   -15,  -118,  -118,   275,    95,  -118,    -8,   -36,
      49,   344,   134,  -118,   143,   113,    -2,    95,  -118,   344,
     344,    -4,   344,    95,    -6,  -118,    76,  -118,  -118,   144,
     136,   138,  -118,   148,  -118,   149,  -118,  -118,  -118,  -118,
    -118,    95,  -118,   344,   110,  -118,    95,  -118,  -118,  -118,
    -118,   123,    95,   195,    -4,  -118,   344,    12,   299,  -118,
    -118,     1,  -118,   150,   159,    71,    73,   344,   -36,   344,
    -118,   344,  -118,   143,  -118,    95,   173,     4,     4,  -118,
      15,   188,  -118,  -118,   189,  -118,   320,  -118,  -118,  -118,
     190,   194,  -118,   181,   200,    68,  -118,  -118,   226,   210,
       3,  -118,    84,  -118,    78,     1,     1,  -118,   201,     1,
    -118,  -118,  -118,  -118,  -118
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       8,     0,     0,     4,    38,     0,     7,    10,     1,     0,
       0,     0,    54,     0,     9,     2,    68,     3,     0,    37,
      40,     0,     5,     0,     0,     0,     0,     0,     0,     0,
     128,   126,   133,   127,     0,   129,   125,     0,     0,     0,
      86,    93,    91,    83,     0,   133,     0,    36,    58,    59,
       0,    60,     0,     0,    61,    68,    62,     0,    63,    64,
      65,    66,    67,     0,     0,    39,    51,     0,    53,    56,
      14,     0,     0,     0,     0,   119,   118,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,    71,     0,    92,     0,
     102,    34,    68,    68,    74,    68,    82,     0,     0,     0,
       0,     0,     0,     0,    45,     0,    42,    43,    44,     0,
       0,    55,     6,     0,     0,     0,     0,   120,     0,   101,
     104,   113,   114,   116,   115,   106,   105,   107,   108,   111,
     109,   112,   110,   117,   131,     0,     0,   133,     0,    96,
       0,    99,     0,    35,    72,    76,     0,     0,    84,    90,
      89,    68,    69,     0,     0,    48,     0,    41,    50,     0,
       0,     0,    12,     0,    13,     0,   121,   122,   123,   124,
     130,     0,   132,    88,     0,    94,     0,    97,   100,    80,
      77,     0,     0,     0,    68,    81,    85,     0,     0,    46,
      47,     0,    57,     0,     0,     8,     8,   103,    95,    98,
      73,    75,    70,    78,    87,     0,     0,    24,    24,    17,
      38,     0,    16,    21,     0,    20,     0,    49,    31,    30,
       0,    23,    26,     0,     0,    54,    15,    19,     0,     0,
      32,    29,     0,    18,     0,     0,     0,    25,     0,     0,
      33,    52,    22,    28,    27
  };

  const short int
  Parser::yypgoto_[] =
  {
    -118,  -118,  -118,  -118,  -118,  -118,   263,  -118,   258,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,    47,  -118,    35,  -118,
    -118,    61,    38,   -54,    64,  -118,   264,  -117,  -118,  -118,
    -118,   121,  -108,  -118,    51,  -118,   220,   202,  -118,  -118,
    -118,   105,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,   203,  -118,   -13,  -118,   -14
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     9,    10,     3,    70,   220,     6,     7,   122,
     172,   221,   173,   174,   224,   175,   230,   231,   232,   242,
     233,   222,    17,    46,    12,    19,    20,   115,   116,   117,
     164,   165,    67,   118,    22,    68,    69,    47,    48,    49,
      50,   104,   155,   191,   192,   193,   194,    51,    52,    53,
      54,   158,    55,    56,    57,   110,    58,    59,    60,   148,
      61,   150,    62,   128,   129,   130,    35,    36
  };

  const short int
  Parser::yytable_[] =
  {
      34,   107,    63,   169,   112,   166,   199,   101,     5,    37,
     195,   157,    38,    93,    75,    76,    77,    39,   108,    94,
      40,    41,    42,   113,   214,    96,   228,   228,    98,    43,
      44,    93,   102,   -80,     1,   229,   229,    94,   109,   111,
     106,    63,   184,    92,     8,    11,   185,   102,    15,   154,
     102,   156,   -80,    90,    13,    66,   166,    45,   123,   124,
     125,   126,   114,    92,   102,   -32,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     1,   143,
       1,   145,    16,   149,   216,   219,   151,   223,    63,    63,
      18,    63,   -80,    89,    90,   159,   160,   170,   162,   186,
      21,    23,   171,   187,    92,   119,   120,   197,   -80,    88,
      89,    90,    64,    24,    25,    85,    86,    87,    88,    89,
      90,    92,    26,   189,   190,   -79,   119,   201,   251,   252,
      92,    27,   254,   183,   248,   249,    66,    28,    71,    72,
     213,    73,    74,    78,   196,    97,    99,    63,    29,   100,
     198,   103,    95,   105,    30,    31,    32,    33,    82,    83,
      84,   144,    85,    86,    87,    88,    89,    90,   207,   146,
     208,   147,   161,   209,   167,   163,   168,    92,   180,   211,
      63,    79,    80,   181,    81,    82,    83,    84,   188,    85,
      86,    87,    88,    89,    90,   102,   202,   203,    91,   204,
     205,   206,   226,   217,    92,    79,    80,   212,    81,    82,
      83,    84,   218,    85,    86,    87,    88,    89,    90,   -80,
      87,    88,    89,    90,   127,   227,    79,    80,    92,    81,
      82,    83,    84,    92,    85,    86,    87,    88,    89,    90,
     236,   237,   241,   245,   239,   176,   240,    79,    80,    92,
      81,    82,    83,    84,   243,    85,    86,    87,    88,    89,
      90,   246,   253,     4,    14,   234,   177,   225,    79,    80,
      92,    81,    82,    83,    84,   247,    85,    86,    87,    88,
      89,    90,   250,    65,   235,   200,   244,   178,   121,    79,
      80,    92,    81,    82,    83,    84,   210,    85,    86,    87,
      88,    89,    90,   152,   153,     0,     0,     0,   179,     0,
      79,    80,    92,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,   182,     0,    92,    79,    80,     0,    81,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,     0,     0,
     215,     0,     0,     0,     0,    79,    80,    92,    81,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,   238,     0,    92,    79,
      80,     0,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,     0,     0,     0,    80,     0,    81,    82,
      83,    84,    92,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    92,    85,
      86,    87,    88,    89,    90,    83,    84,     0,    85,    86,
      87,    88,    89,    90,    92,    84,     0,    85,    86,    87,
      88,    89,    90,    92,   -80,    86,    87,    88,    89,    90,
       0,     0,    92,     0,     0,     0,     0,     0,     0,    92
  };

  const short int
  Parser::yycheck_[] =
  {
      13,    55,    16,   120,     3,   113,    12,    12,    61,    13,
      12,    31,    16,    49,    27,    28,    29,    21,     9,    55,
      24,    25,    26,    22,    12,    38,    23,    23,    41,    33,
      34,    49,    52,    48,     7,    32,    32,    55,    29,    57,
      53,    55,    50,    58,     0,    30,    54,    52,    49,   103,
      52,   105,    47,    48,    43,    61,   164,    61,    71,    72,
      73,    74,    61,    58,    52,    61,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     7,    92,
       7,    94,     4,    97,   201,    14,    99,    14,   102,   103,
      61,   105,    46,    47,    48,   108,   109,    15,   111,    50,
      32,     6,    20,    54,    58,    50,    51,   161,    45,    46,
      47,    48,    43,    18,    19,    43,    44,    45,    46,    47,
      48,    58,    27,    10,    11,    12,    50,    51,   245,   246,
      58,    36,   249,   146,    50,    51,    61,    42,    53,    53,
     194,    53,    53,    53,   157,    53,    53,   161,    53,    53,
     163,    28,    61,     8,    59,    60,    61,    62,    39,    40,
      41,    61,    43,    44,    45,    46,    47,    48,   181,    57,
     184,    61,     8,   186,    52,    55,    61,    58,    54,   192,
     194,    35,    36,    50,    38,    39,    40,    41,    54,    43,
      44,    45,    46,    47,    48,    52,    52,    61,    52,    61,
      52,    52,   215,    53,    58,    35,    36,    12,    38,    39,
      40,    41,    53,    43,    44,    45,    46,    47,    48,    44,
      45,    46,    47,    48,    54,    52,    35,    36,    58,    38,
      39,    40,    41,    58,    43,    44,    45,    46,    47,    48,
      52,    52,    61,    17,    54,    54,    52,    35,    36,    58,
      38,    39,    40,    41,    54,    43,    44,    45,    46,    47,
      48,    51,    61,     0,     6,   218,    54,   206,    35,    36,
      58,    38,    39,    40,    41,   240,    43,    44,    45,    46,
      47,    48,   244,    19,   220,   164,   235,    54,    68,    35,
      36,    58,    38,    39,    40,    41,   191,    43,    44,    45,
      46,    47,    48,   100,   102,    -1,    -1,    -1,    54,    -1,
      35,    36,    58,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    35,    36,    -1,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    35,    36,    58,    38,    39,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    35,
      36,    -1,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    58,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    58,    43,
      44,    45,    46,    47,    48,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    58,    41,    -1,    43,    44,    45,
      46,    47,    48,    58,    43,    44,    45,    46,    47,    48,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    58
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     7,    64,    67,    69,    61,    70,    71,     0,    65,
      66,    30,    87,    43,    71,    49,     4,    85,    61,    88,
      89,    32,    97,     6,    18,    19,    27,    36,    42,    53,
      59,    60,    61,    62,   128,   129,   130,    13,    16,    21,
      24,    25,    26,    33,    34,    61,    86,   100,   101,   102,
     103,   110,   111,   112,   113,   115,   116,   117,   119,   120,
     121,   123,   125,   130,    43,    89,    61,    95,    98,    99,
      68,    53,    53,    53,    53,   128,   128,   128,    53,    35,
      36,    38,    39,    40,    41,    43,    44,    45,    46,    47,
      48,    52,    58,    49,    55,    61,   128,    53,   128,    53,
      53,    12,    52,    28,   104,     8,   128,    86,     9,    29,
     118,    57,     3,    22,    61,    90,    91,    92,    96,    50,
      51,    99,    72,   128,   128,   128,   128,    54,   126,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,    61,   128,    57,    61,   122,   130,
     124,   128,   126,   100,    86,   105,    86,    31,   114,   128,
     128,     8,   128,    55,    93,    94,    95,    52,    61,    90,
      15,    20,    73,    75,    76,    78,    54,    54,    54,    54,
      54,    50,    56,   128,    50,    54,    50,    54,    54,    10,
      11,   106,   107,   108,   109,    12,   128,    86,   128,    12,
      94,    51,    52,    61,    61,    52,    52,   128,   130,   128,
     104,   128,    12,    86,    12,    51,    90,    53,    53,    14,
      69,    74,    84,    14,    77,    84,   128,    52,    23,    32,
      79,    80,    81,    83,    79,    87,    52,    52,    56,    54,
      52,    61,    82,    54,    97,    17,    51,    81,    50,    51,
      85,    90,    90,    61,    90
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    63,    64,    65,    66,    68,    67,    69,    69,    70,
      70,    71,    72,    72,    72,    73,    74,    74,    75,    76,
      77,    77,    78,    79,    79,    80,    80,    81,    82,    82,
      83,    83,    83,    84,    85,    86,    86,    87,    87,    88,
      88,    89,    90,    90,    90,    91,    92,    93,    93,    94,
      95,    95,    96,    97,    97,    98,    98,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     102,   103,   104,   105,   105,   106,   106,   107,   108,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     118,   119,   120,   120,   121,   122,   122,   123,   124,   124,
     125,   126,   126,   127,   127,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     129,   130,   130,   130
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     3,     2,     0,     0,     5,     2,     0,     2,
       1,     4,     2,     2,     0,     4,     1,     1,     5,     4,
       1,     1,     7,     1,     0,     3,     1,     4,     3,     1,
       1,     1,     0,     4,     3,     3,     1,     2,     0,     2,
       1,     4,     1,     1,     1,     1,     3,     2,     1,     4,
       3,     1,     8,     2,     0,     2,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       5,     2,     2,     3,     0,     2,     0,     1,     2,     0,
       1,     4,     2,     1,     3,     2,     1,     5,     4,     2,
       2,     1,     2,     1,     4,     3,     1,     4,     3,     1,
       4,     1,     0,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       4,     3,     4,     1
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
  "MainBlock", "MainHead", "ProgramHead", "$@1", "OptConstDecls",
  "ConstDecls", "ConstDecl", "PFDecls", "ProcedureDecl", "PBody",
  "PSignature", "FunctionDecl", "FBody", "FSignature",
  "OptFormalParameters", "FormalParameters", "FormalParameter",
  "ParamIdentList", "OptVar", "Body", "Block", "StatementList",
  "OptTypeDecls", "TypeDecls", "TypeDecl", "Type", "SimpleType",
  "RecordType", "FieldDecls", "FieldDecl", "IdentList", "ArrayType",
  "OptVarDecls", "VarDecls", "VarDecl", "Statement", "Assignment",
  "IfStatement", "IfHead", "ThenPart", "ElseIfList", "ElseIfHead",
  "ElseIfSuperHead", "ElseClause", "ElseHead", "WhileStatement",
  "WhileHead", "WhileSuperHead", "RepeatStatement", "RepeatEnd",
  "RepeatHead", "ForStatement", "ForHead", "ToHead", "StopStatement",
  "ReturnStatement", "ReadStatement", "ReadArgs", "WriteStatement",
  "WriteArgs", "ProcedureCall", "OptArguments", "Arguments", "Expression",
  "FunctionCall", "LVal", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   164,   164,   166,   168,   170,   170,   172,   173,   175,
     176,   178,   180,   181,   182,   184,   186,   187,   189,   191,
     193,   194,   196,   198,   199,   201,   209,   211,   221,   222,
     224,   225,   226,   228,   230,   232,   233,   235,   236,   238,
     239,   241,   243,   244,   245,   247,   249,   251,   252,   259,
     261,   262,   264,   266,   267,   269,   270,   272,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   286,
     288,   290,   292,   294,   295,   297,   298,   300,   302,   303,
     305,   307,   309,   311,   313,   315,   317,   319,   321,   323,
     324,   326,   328,   329,   331,   333,   334,   336,   338,   339,
     341,   343,   344,   346,   347,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     375,   377,   378,   379
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
#line 2102 "/home/fabio/Desktop/UsuCS5300/HW6/parser.cpp" // lalr1.cc:1155
#line 381 "parser.ypp" // lalr1.cc:1156

void
yy::Parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
