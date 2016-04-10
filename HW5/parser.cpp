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

#line 37 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 51 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 41 "parser.ypp" // lalr1.cc:408

# include "driver.hpp"

#line 57 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:408


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
#line 143 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:474

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
      case 89: // Type
      case 90: // SimpleType
        value.move< FC::Type > (that.value);
        break;

      case 73: // PBody
      case 76: // FBody
        value.move< bool > (that.value);
        break;

      case 59: // CharTok
        value.move< char > (that.value);
        break;

      case 60: // IntTok
      case 82: // OptVar
      case 83: // Body
      case 84: // Block
      case 91: // RecordType
      case 92: // FieldDecls
      case 93: // FieldDecl
      case 94: // IdentList
      case 95: // ArrayType
      case 100: // Assignment
      case 101: // IfStatement
      case 102: // IfHead
      case 103: // ThenPart
      case 104: // ElseIfList
      case 105: // ElseIfHead
      case 107: // ElseClause
      case 109: // WhileStatement
      case 112: // RepeatStatement
      case 115: // ForStatement
      case 116: // ForHead
      case 117: // ToHead
      case 118: // StopStatement
      case 119: // ReturnStatement
      case 120: // ReadStatement
      case 121: // ReadArgs
      case 122: // WriteStatement
      case 123: // WriteArgs
      case 124: // ProcedureCall
        value.move< int > (that.value);
        break;

      case 110: // WhileHead
      case 111: // WhileSuperHead
      case 127: // Expression
      case 128: // FunctionCall
        value.move< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 74: // PSignature
      case 77: // FSignature
        value.move< std::shared_ptr<FC::Func>  > (that.value);
        break;

      case 129: // LVal
        value.move< std::shared_ptr<FC::LVal>  > (that.value);
        break;

      case 78: // OptFormalParameters
      case 79: // FormalParameters
      case 80: // FormalParameter
        value.move< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (that.value);
        break;

      case 125: // OptArguments
      case 126: // Arguments
        value.move< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > (that.value);
        break;

      case 81: // ParamIdentList
        value.move< std::shared_ptr<std::vector<std::string> >  > (that.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 85: // StatementList
      case 99: // Statement
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
      case 89: // Type
      case 90: // SimpleType
        value.copy< FC::Type > (that.value);
        break;

      case 73: // PBody
      case 76: // FBody
        value.copy< bool > (that.value);
        break;

      case 59: // CharTok
        value.copy< char > (that.value);
        break;

      case 60: // IntTok
      case 82: // OptVar
      case 83: // Body
      case 84: // Block
      case 91: // RecordType
      case 92: // FieldDecls
      case 93: // FieldDecl
      case 94: // IdentList
      case 95: // ArrayType
      case 100: // Assignment
      case 101: // IfStatement
      case 102: // IfHead
      case 103: // ThenPart
      case 104: // ElseIfList
      case 105: // ElseIfHead
      case 107: // ElseClause
      case 109: // WhileStatement
      case 112: // RepeatStatement
      case 115: // ForStatement
      case 116: // ForHead
      case 117: // ToHead
      case 118: // StopStatement
      case 119: // ReturnStatement
      case 120: // ReadStatement
      case 121: // ReadArgs
      case 122: // WriteStatement
      case 123: // WriteArgs
      case 124: // ProcedureCall
        value.copy< int > (that.value);
        break;

      case 110: // WhileHead
      case 111: // WhileSuperHead
      case 127: // Expression
      case 128: // FunctionCall
        value.copy< std::shared_ptr<FC::Expr> > (that.value);
        break;

      case 74: // PSignature
      case 77: // FSignature
        value.copy< std::shared_ptr<FC::Func>  > (that.value);
        break;

      case 129: // LVal
        value.copy< std::shared_ptr<FC::LVal>  > (that.value);
        break;

      case 78: // OptFormalParameters
      case 79: // FormalParameters
      case 80: // FormalParameter
        value.copy< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (that.value);
        break;

      case 125: // OptArguments
      case 126: // Arguments
        value.copy< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > (that.value);
        break;

      case 81: // ParamIdentList
        value.copy< std::shared_ptr<std::vector<std::string> >  > (that.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 85: // StatementList
      case 99: // Statement
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
    #line 32 "parser.ypp" // lalr1.cc:725
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 572 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:725

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
      case 89: // Type
      case 90: // SimpleType
        yylhs.value.build< FC::Type > ();
        break;

      case 73: // PBody
      case 76: // FBody
        yylhs.value.build< bool > ();
        break;

      case 59: // CharTok
        yylhs.value.build< char > ();
        break;

      case 60: // IntTok
      case 82: // OptVar
      case 83: // Body
      case 84: // Block
      case 91: // RecordType
      case 92: // FieldDecls
      case 93: // FieldDecl
      case 94: // IdentList
      case 95: // ArrayType
      case 100: // Assignment
      case 101: // IfStatement
      case 102: // IfHead
      case 103: // ThenPart
      case 104: // ElseIfList
      case 105: // ElseIfHead
      case 107: // ElseClause
      case 109: // WhileStatement
      case 112: // RepeatStatement
      case 115: // ForStatement
      case 116: // ForHead
      case 117: // ToHead
      case 118: // StopStatement
      case 119: // ReturnStatement
      case 120: // ReadStatement
      case 121: // ReadArgs
      case 122: // WriteStatement
      case 123: // WriteArgs
      case 124: // ProcedureCall
        yylhs.value.build< int > ();
        break;

      case 110: // WhileHead
      case 111: // WhileSuperHead
      case 127: // Expression
      case 128: // FunctionCall
        yylhs.value.build< std::shared_ptr<FC::Expr> > ();
        break;

      case 74: // PSignature
      case 77: // FSignature
        yylhs.value.build< std::shared_ptr<FC::Func>  > ();
        break;

      case 129: // LVal
        yylhs.value.build< std::shared_ptr<FC::LVal>  > ();
        break;

      case 78: // OptFormalParameters
      case 79: // FormalParameters
      case 80: // FormalParameter
        yylhs.value.build< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ();
        break;

      case 125: // OptArguments
      case 126: // Arguments
        yylhs.value.build< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ();
        break;

      case 81: // ParamIdentList
        yylhs.value.build< std::shared_ptr<std::vector<std::string> >  > ();
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 85: // StatementList
      case 99: // Statement
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
#line 164 "parser.ypp" // lalr1.cc:847
    {FC::AddMain();}
#line 769 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 168 "parser.ypp" // lalr1.cc:847
    {FC::MainBlock();FC::WriteStatement();}
#line 775 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 170 "parser.ypp" // lalr1.cc:847
    { FC::CheckForwardDecls();}
#line 781 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 178 "parser.ypp" // lalr1.cc:847
    {FC::AddConst(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 787 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 184 "parser.ypp" // lalr1.cc:847
    {yystack_[3].value.as< std::shared_ptr<FC::Func>  > ()->isForwardDeclared = yystack_[1].value.as< bool > ();FC::AddFunction(yystack_[3].value.as< std::shared_ptr<FC::Func>  > ());}
#line 793 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 186 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< bool > () = false;}
#line 799 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 187 "parser.ypp" // lalr1.cc:847
    { yylhs.value.as< bool > () = true;}
#line 805 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 189 "parser.ypp" // lalr1.cc:847
    {FC::AddLocalParams(yystack_[1].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (),FC::VoidType()); yylhs.value.as< std::shared_ptr<FC::Func>  > () = std::make_shared<FC::Func>(nullptr, yystack_[1].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (), yystack_[3].value.as< std::string > ());}
#line 811 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 191 "parser.ypp" // lalr1.cc:847
    {yystack_[3].value.as< std::shared_ptr<FC::Func>  > ()->isForwardDeclared = yystack_[1].value.as< bool > ();FC::AddFunction(yystack_[3].value.as< std::shared_ptr<FC::Func>  > ());}
#line 817 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 193 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< bool > () = false;}
#line 823 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 194 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< bool > () = true;}
#line 829 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 196 "parser.ypp" // lalr1.cc:847
    {FC::AddLocalParams(yystack_[3].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (),yystack_[0].value.as< FC::Type > ()); yylhs.value.as< std::shared_ptr<FC::Func>  > () = std::make_shared<FC::Func>(std::make_shared<FC::Type>(yystack_[0].value.as< FC::Type > ()), yystack_[3].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > (), yystack_[5].value.as< std::string > ());}
#line 835 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 198 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () = yystack_[0].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ();}
#line 841 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 199 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () = nullptr;}
#line 847 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 202 "parser.ypp" // lalr1.cc:847
    {
        //$1->insert($3->end(),$3->begin(),$3->end());
        for(auto s : (*yystack_[0].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ()))
        {
            yystack_[2].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ()->push_back(s);
        }
        yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () =yystack_[2].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ();}
#line 859 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 209 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () = yystack_[0].value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > ();}
#line 865 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 212 "parser.ypp" // lalr1.cc:847
    {   //TODO VAR/REF
                auto a = std::make_shared<std::vector<std::pair<std::string,FC::Type> >>();
                for(int i = 0; i < yystack_[2].value.as< std::shared_ptr<std::vector<std::string> >  > ()->size();i++)
                {
                    a->push_back(std::pair<std::string,FC::Type>((*yystack_[2].value.as< std::shared_ptr<std::vector<std::string> >  > ())[i],yystack_[0].value.as< FC::Type > ()));
                }
                yylhs.value.as< std::shared_ptr<std::vector<std::pair<std::string,FC::Type> > >  > () = a;
            }
#line 878 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 221 "parser.ypp" // lalr1.cc:847
    {yystack_[2].value.as< std::shared_ptr<std::vector<std::string> >  > ()->push_back(yystack_[0].value.as< std::string > ()); yylhs.value.as< std::shared_ptr<std::vector<std::string> >  > () = yystack_[2].value.as< std::shared_ptr<std::vector<std::string> >  > ();}
#line 884 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 222 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::string> >  > () = std::make_shared<std::vector<std::string> >(1,yystack_[0].value.as< std::string > ());}
#line 890 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 224 "parser.ypp" // lalr1.cc:847
    {}
#line 896 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 225 "parser.ypp" // lalr1.cc:847
    {std::cout << "Unfortunately, passing by reference is not supported, passing by value instead" << std::endl;}
#line 902 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 31:
#line 226 "parser.ypp" // lalr1.cc:847
    {}
#line 908 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 228 "parser.ypp" // lalr1.cc:847
    {}
#line 914 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 33:
#line 230 "parser.ypp" // lalr1.cc:847
    {}
#line 920 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 34:
#line 232 "parser.ypp" // lalr1.cc:847
    {}
#line 926 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 35:
#line 233 "parser.ypp" // lalr1.cc:847
    {}
#line 932 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 40:
#line 241 "parser.ypp" // lalr1.cc:847
    {}
#line 938 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 41:
#line 243 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = yystack_[0].value.as< FC::Type > ();}
#line 944 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 42:
#line 244 "parser.ypp" // lalr1.cc:847
    {}
#line 950 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 245 "parser.ypp" // lalr1.cc:847
    {}
#line 956 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 247 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< FC::Type > () = FC::SimpleTypeLookup(yystack_[0].value.as< std::string > ());}
#line 962 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 249 "parser.ypp" // lalr1.cc:847
    {}
#line 968 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 251 "parser.ypp" // lalr1.cc:847
    {}
#line 974 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 252 "parser.ypp" // lalr1.cc:847
    {}
#line 980 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 254 "parser.ypp" // lalr1.cc:847
    {}
#line 986 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 256 "parser.ypp" // lalr1.cc:847
    {FC::AddIdent(yystack_[0].value.as< std::string > ());}
#line 992 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 257 "parser.ypp" // lalr1.cc:847
    {FC::AddIdent(yystack_[0].value.as< std::string > ());}
#line 998 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 259 "parser.ypp" // lalr1.cc:847
    {}
#line 1004 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 267 "parser.ypp" // lalr1.cc:847
    {AddVariables(yystack_[1].value.as< FC::Type > ());}
#line 1010 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 269 "parser.ypp" // lalr1.cc:847
    {}
#line 1016 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 270 "parser.ypp" // lalr1.cc:847
    {}
#line 1022 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 271 "parser.ypp" // lalr1.cc:847
    {}
#line 1028 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 272 "parser.ypp" // lalr1.cc:847
    {}
#line 1034 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 273 "parser.ypp" // lalr1.cc:847
    {}
#line 1040 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 274 "parser.ypp" // lalr1.cc:847
    {}
#line 1046 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 275 "parser.ypp" // lalr1.cc:847
    {}
#line 1052 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 276 "parser.ypp" // lalr1.cc:847
    {}
#line 1058 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 277 "parser.ypp" // lalr1.cc:847
    {}
#line 1064 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 278 "parser.ypp" // lalr1.cc:847
    {}
#line 1070 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 279 "parser.ypp" // lalr1.cc:847
    {}
#line 1076 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 281 "parser.ypp" // lalr1.cc:847
    {FC::Assignment(yystack_[2].value.as< std::shared_ptr<FC::LVal>  > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1082 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 283 "parser.ypp" // lalr1.cc:847
    {FC::IfEnd();}
#line 1088 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 285 "parser.ypp" // lalr1.cc:847
    {FC::IfHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1094 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 287 "parser.ypp" // lalr1.cc:847
    {}
#line 1100 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 289 "parser.ypp" // lalr1.cc:847
    {}
#line 1106 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 290 "parser.ypp" // lalr1.cc:847
    {}
#line 1112 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 292 "parser.ypp" // lalr1.cc:847
    {FC::ElseIfHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1118 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 293 "parser.ypp" // lalr1.cc:847
    {}
#line 1124 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 295 "parser.ypp" // lalr1.cc:847
    {FC::ElseIfSuperHead();}
#line 1130 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 297 "parser.ypp" // lalr1.cc:847
    {}
#line 1136 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 298 "parser.ypp" // lalr1.cc:847
    {FC::ElseHead();}
#line 1142 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 300 "parser.ypp" // lalr1.cc:847
    {FC::ElseHead();}
#line 1148 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 302 "parser.ypp" // lalr1.cc:847
    {FC::WhileEnd();}
#line 1154 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 304 "parser.ypp" // lalr1.cc:847
    {FC::WhileHead(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1160 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 306 "parser.ypp" // lalr1.cc:847
    {FC::WhileSuperHead();}
#line 1166 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 308 "parser.ypp" // lalr1.cc:847
    {}
#line 1172 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 310 "parser.ypp" // lalr1.cc:847
    {FC::RepeatEnd(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1178 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 312 "parser.ypp" // lalr1.cc:847
    {FC::RepeatHead();}
#line 1184 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 314 "parser.ypp" // lalr1.cc:847
    {FC::ForEnd();}
#line 1190 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 316 "parser.ypp" // lalr1.cc:847
    {FC::ForHead(yystack_[2].value.as< std::string > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1196 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 318 "parser.ypp" // lalr1.cc:847
    {FC::ToHead(true,yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1202 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 319 "parser.ypp" // lalr1.cc:847
    {FC::ToHead(false,yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1208 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 321 "parser.ypp" // lalr1.cc:847
    {FC::Stop();}
#line 1214 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 323 "parser.ypp" // lalr1.cc:847
    {FC::AddReturn(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1220 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 324 "parser.ypp" // lalr1.cc:847
    {FC::AddReturn(nullptr);}
#line 1226 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 326 "parser.ypp" // lalr1.cc:847
    {}
#line 1232 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 328 "parser.ypp" // lalr1.cc:847
    {FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1238 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 329 "parser.ypp" // lalr1.cc:847
    {std::cout << "dafuq" << std::endl;FC::ReadToLVal(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ());}
#line 1244 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 331 "parser.ypp" // lalr1.cc:847
    {}
#line 1250 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 333 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1256 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 334 "parser.ypp" // lalr1.cc:847
    {FC::WriteExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1262 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 336 "parser.ypp" // lalr1.cc:847
    {FC::CallFunction(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ());}
#line 1268 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 338 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > () = yystack_[0].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ();}
#line 1274 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 339 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > () = nullptr;}
#line 1280 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 341 "parser.ypp" // lalr1.cc:847
    {yystack_[2].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ()->push_back(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());yylhs.value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > () = yystack_[2].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ();}
#line 1286 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 342 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > () = std::make_shared<std::vector<std::shared_ptr<FC::Expr> > >(1,yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1292 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 344 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcOrExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1298 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 345 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcAndExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1304 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 346 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1310 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 347 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1316 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 348 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1322 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 349 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterEqualExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1328 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 350 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcLessThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1334 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 351 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcGreaterThanExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1340 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 352 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcPlusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1346 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 353 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMinusExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1352 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 354 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcDivideExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1358 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 355 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcMultiplyExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1364 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 356 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcModExpr(yystack_[2].value.as< std::shared_ptr<FC::Expr> > (),yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1370 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 357 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcNotExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1376 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 358 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = ProcUnaryMinusExpr(yystack_[0].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1382 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 359 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = yystack_[1].value.as< std::shared_ptr<FC::Expr> > ();}
#line 1388 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 360 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToChar(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1394 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 121:
#line 361 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ToInt(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1400 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 122:
#line 362 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcDecrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1406 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 123:
#line 363 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIncrement(yystack_[1].value.as< std::shared_ptr<FC::Expr> > ());}
#line 1412 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 124:
#line 364 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::LValToExpr(yystack_[0].value.as< std::shared_ptr<FC::LVal>  > ()); }
#line 1418 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 125:
#line 365 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcIntExpr(yystack_[0].value.as< int > ());}
#line 1424 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 126:
#line 366 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcStringExpr(yystack_[0].value.as< std::string > ());}
#line 1430 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 127:
#line 367 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::ProcCharExpr(yystack_[0].value.as< char > ());}
#line 1436 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 128:
#line 368 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = yystack_[0].value.as< std::shared_ptr<FC::Expr> > ();}
#line 1442 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 129:
#line 370 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::Expr> > () = FC::CallFunction(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::shared_ptr<std::vector<std::shared_ptr<FC::Expr> > >  > ());}
#line 1448 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 130:
#line 372 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1454 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 131:
#line 373 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = nullptr;}
#line 1460 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;

  case 132:
#line 374 "parser.ypp" // lalr1.cc:847
    {yylhs.value.as< std::shared_ptr<FC::LVal>  > () = FC::GetLValForIdent(yystack_[0].value.as< std::string > ());}
#line 1466 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
    break;


#line 1470 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:847
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

  const signed char Parser::yytable_ninf_ = -79;

  const short int
  Parser::yypact_[] =
  {
      12,   -22,    85,  -118,    60,    66,   -22,  -118,  -118,    48,
     107,    61,    91,    74,  -118,  -118,    -4,  -118,    81,    61,
    -118,    64,  -118,    75,    77,    79,    84,    74,    74,    74,
    -118,  -118,    86,  -118,   118,  -118,    29,    82,    74,    87,
    -118,    74,  -118,  -118,    89,    92,    -6,  -118,  -118,  -118,
     116,  -118,   109,    74,  -118,    -4,  -118,     4,  -118,  -118,
    -118,  -118,  -118,    45,     1,  -118,  -118,    56,    64,  -118,
      67,    74,    74,    74,    74,   356,   397,   147,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,  -118,    74,    90,    74,    93,   324,    99,   324,    74,
      74,  -118,    -4,    -4,  -118,    -4,   324,   -20,    74,    74,
     138,    74,   112,  -118,  -118,    95,  -118,  -118,  -118,   111,
       1,  -118,   114,   117,  -118,    96,  -118,   121,   171,   192,
     213,   234,  -118,   123,   129,   324,   340,   356,   372,   381,
     390,   397,   406,   176,    -3,   -10,     5,   -40,  -118,  -118,
     255,    74,  -118,    49,    29,    54,   324,   130,  -118,   137,
     103,    -5,    74,  -118,   324,   324,    -4,   324,    74,    -7,
    -118,  -118,   144,   115,   145,    17,    20,  -118,  -118,  -118,
    -118,  -118,    74,  -118,   324,    99,  -118,    74,  -118,  -118,
    -118,  -118,   116,    74,   185,    -4,  -118,   324,    -2,   279,
    -118,  -118,    68,  -118,     3,     3,  -118,    60,   148,  -118,
    -118,   150,  -118,   324,    29,   324,  -118,   324,  -118,   137,
    -118,    74,     1,  -118,  -118,   149,   152,  -118,   165,   159,
      91,  -118,  -118,   300,   189,   191,    33,  -118,    70,  -118,
     107,   182,  -118,     1,  -118,   183,     1,  -118,     1,  -118,
    -118,  -118,  -118
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       7,     0,     0,     4,    37,     0,     6,     9,     1,     0,
       0,     0,    53,     0,     8,     2,    67,     3,     0,    36,
      39,     0,    13,     0,     0,     0,     0,     0,     0,     0,
     127,   125,   132,   126,     0,   128,   124,     0,     0,     0,
      85,    92,    90,    82,     0,   132,     0,    35,    57,    58,
       0,    59,     0,     0,    60,    67,    61,     0,    62,    63,
      64,    65,    66,     0,     0,    38,    50,     0,    52,    55,
       5,     0,     0,     0,     0,   118,   117,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,    70,     0,    91,     0,
     101,    33,    67,    67,    73,    67,    81,     0,     0,     0,
       0,     0,     0,    47,    44,     0,    41,    42,    43,     0,
       0,    54,     0,     0,    11,     0,    12,     0,     0,     0,
       0,     0,   119,     0,   100,   103,   112,   113,   115,   114,
     105,   104,   106,   107,   110,   108,   111,   109,   116,   130,
       0,     0,   132,     0,    95,     0,    98,     0,    34,    71,
      75,     0,     0,    83,    89,    88,    67,    68,     0,     0,
      40,    49,     0,     0,     0,     7,     7,   120,   121,   122,
     123,   129,     0,   131,    87,     0,    93,     0,    96,    99,
      79,    76,     0,     0,     0,    67,    80,    84,     0,     0,
      45,    46,     0,    56,    23,    23,    16,    37,     0,    15,
      20,     0,    19,   102,    94,    97,    72,    74,    69,    77,
      86,     0,     0,    30,    29,     0,    22,    25,     0,     0,
      53,    14,    18,     0,     0,     0,    31,    28,     0,    17,
       0,     0,    48,     0,    24,     0,     0,    32,     0,    21,
      27,    26,    51
  };

  const short int
  Parser::yypgoto_[] =
  {
    -118,  -118,  -118,  -118,  -118,   243,  -118,   239,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,    42,  -118,    19,  -118,  -118,
      88,    22,   -54,    58,  -118,   244,  -117,  -118,  -118,  -118,
    -118,    97,  -118,    38,  -118,   208,   181,  -118,  -118,  -118,
      94,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,   184,  -118,   -13,  -118,   -14
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     2,     9,    10,     3,   207,     6,     7,    70,   124,
     208,   125,   126,   211,   127,   225,   226,   227,   238,   228,
     209,    17,    46,    12,    19,    20,   115,   116,   117,   169,
     201,    67,   118,    22,    68,    69,    47,    48,    49,    50,
     104,   160,   192,   193,   194,   195,    51,    52,    53,    54,
     163,    55,    56,    57,   110,    58,    59,    60,   153,    61,
     155,    62,   133,   134,   135,    35,    36
  };

  const short int
  Parser::yytable_[] =
  {
      34,   107,    63,   172,   112,   200,   101,   196,   -79,    37,
     220,   162,    38,   108,    75,    76,    77,    39,    92,     1,
      40,    41,    42,   113,     1,    96,   223,     1,    98,    43,
      44,   206,   102,   109,   210,   224,   -79,    89,    90,     5,
     106,    63,   -79,    88,    89,    90,   102,   102,    92,   159,
     102,   161,   -79,    90,    66,    92,   223,    45,   128,   129,
     130,   131,   114,    92,   -31,   224,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    93,   148,
      23,   150,   122,   154,    94,     8,   156,   123,    63,    63,
      11,    63,    24,    25,    93,   164,   165,    15,   167,   185,
      94,    26,   111,   186,   187,   234,   119,   120,   188,    13,
      27,    16,   198,   190,   191,   -78,    28,   105,   119,   222,
     245,   246,    18,    21,    64,    66,   249,    29,    71,   251,
      72,   252,    73,    30,    31,    32,    33,    74,   184,    78,
      97,   219,    99,    95,   103,   100,   166,   170,   175,   197,
     151,   149,    63,    79,    80,   199,    81,    82,    83,    84,
     152,    85,    86,    87,    88,    89,    90,   168,   204,   213,
      91,   214,   171,   176,   215,   173,    92,   181,   174,   182,
     217,    63,    79,    80,   189,    81,    82,    83,    84,   102,
      85,    86,    87,    88,    89,    90,   203,   218,   205,   248,
     231,   132,   232,   235,   236,    92,    79,    80,   233,    81,
      82,    83,    84,   239,    85,    86,    87,    88,    89,    90,
     -79,    87,    88,    89,    90,   177,   237,    79,    80,    92,
      81,    82,    83,    84,    92,    85,    86,    87,    88,    89,
      90,   242,   243,     4,   250,    14,   178,   229,    79,    80,
      92,    81,    82,    83,    84,   244,    85,    86,    87,    88,
      89,    90,   247,    65,   212,   230,   202,   179,   240,    79,
      80,    92,    81,    82,    83,    84,   121,    85,    86,    87,
      88,    89,    90,   158,   157,     0,   216,     0,   180,     0,
      79,    80,    92,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,   183,     0,    92,    79,    80,     0,    81,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,     0,     0,
     221,     0,     0,     0,     0,    79,    80,    92,    81,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,   241,     0,    92,    79,
      80,     0,    81,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,     0,     0,     0,    80,     0,    81,    82,
      83,    84,    92,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    92,    85,
      86,    87,    88,    89,    90,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    92,    85,    86,    87,    88,    89,
      90,    83,    84,     0,    85,    86,    87,    88,    89,    90,
      92,    84,     0,    85,    86,    87,    88,    89,    90,    92,
      85,    86,    87,    88,    89,    90,     0,     0,    92,   -79,
      86,    87,    88,    89,    90,    92,     0,     0,     0,     0,
       0,     0,     0,     0,    92
  };

  const short int
  Parser::yycheck_[] =
  {
      13,    55,    16,   120,     3,    12,    12,    12,    48,    13,
      12,    31,    16,     9,    27,    28,    29,    21,    58,     7,
      24,    25,    26,    22,     7,    38,    23,     7,    41,    33,
      34,    14,    52,    29,    14,    32,    46,    47,    48,    61,
      53,    55,    45,    46,    47,    48,    52,    52,    58,   103,
      52,   105,    47,    48,    61,    58,    23,    61,    71,    72,
      73,    74,    61,    58,    61,    32,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    49,    92,
       6,    94,    15,    97,    55,     0,    99,    20,   102,   103,
      30,   105,    18,    19,    49,   108,   109,    49,   111,    50,
      55,    27,    57,    54,    50,   222,    50,    51,    54,    43,
      36,     4,   166,    10,    11,    12,    42,     8,    50,    51,
      50,    51,    61,    32,    43,    61,   243,    53,    53,   246,
      53,   248,    53,    59,    60,    61,    62,    53,   151,    53,
      53,   195,    53,    61,    28,    53,     8,    52,    52,   162,
      57,    61,   166,    35,    36,   168,    38,    39,    40,    41,
      61,    43,    44,    45,    46,    47,    48,    55,    53,   182,
      52,   185,    61,    52,   187,    61,    58,    54,    61,    50,
     193,   195,    35,    36,    54,    38,    39,    40,    41,    52,
      43,    44,    45,    46,    47,    48,    52,    12,    53,    17,
      52,    54,    52,    54,    52,    58,    35,    36,   221,    38,
      39,    40,    41,    54,    43,    44,    45,    46,    47,    48,
      44,    45,    46,    47,    48,    54,    61,    35,    36,    58,
      38,    39,    40,    41,    58,    43,    44,    45,    46,    47,
      48,    52,    51,     0,    61,     6,    54,   205,    35,    36,
      58,    38,    39,    40,    41,   236,    43,    44,    45,    46,
      47,    48,   240,    19,   176,   207,   169,    54,   230,    35,
      36,    58,    38,    39,    40,    41,    68,    43,    44,    45,
      46,    47,    48,   102,   100,    -1,   192,    -1,    54,    -1,
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
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    58,    43,    44,    45,    46,    47,
      48,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      58,    41,    -1,    43,    44,    45,    46,    47,    48,    58,
      43,    44,    45,    46,    47,    48,    -1,    -1,    58,    43,
      44,    45,    46,    47,    48,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     7,    64,    67,    68,    61,    69,    70,     0,    65,
      66,    30,    86,    43,    70,    49,     4,    84,    61,    87,
      88,    32,    96,     6,    18,    19,    27,    36,    42,    53,
      59,    60,    61,    62,   127,   128,   129,    13,    16,    21,
      24,    25,    26,    33,    34,    61,    85,    99,   100,   101,
     102,   109,   110,   111,   112,   114,   115,   116,   118,   119,
     120,   122,   124,   129,    43,    88,    61,    94,    97,    98,
      71,    53,    53,    53,    53,   127,   127,   127,    53,    35,
      36,    38,    39,    40,    41,    43,    44,    45,    46,    47,
      48,    52,    58,    49,    55,    61,   127,    53,   127,    53,
      53,    12,    52,    28,   103,     8,   127,    85,     9,    29,
     117,    57,     3,    22,    61,    89,    90,    91,    95,    50,
      51,    98,    15,    20,    72,    74,    75,    77,   127,   127,
     127,   127,    54,   125,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,    61,
     127,    57,    61,   121,   129,   123,   127,   125,    99,    85,
     104,    85,    31,   113,   127,   127,     8,   127,    55,    92,
      52,    61,    89,    61,    61,    52,    52,    54,    54,    54,
      54,    54,    50,    56,   127,    50,    54,    50,    54,    54,
      10,    11,   105,   106,   107,   108,    12,   127,    85,   127,
      12,    93,    94,    52,    53,    53,    14,    68,    73,    83,
      14,    76,    83,   127,   129,   127,   103,   127,    12,    85,
      12,    51,    51,    23,    32,    78,    79,    80,    82,    78,
      86,    52,    52,   127,    89,    54,    52,    61,    81,    54,
      96,    56,    52,    51,    80,    50,    51,    84,    17,    89,
      61,    89,    89
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    63,    64,    65,    66,    67,    68,    68,    69,    69,
      70,    71,    71,    71,    72,    73,    73,    74,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    81,    81,    82,
      82,    82,    83,    84,    85,    85,    86,    86,    87,    87,
      88,    89,    89,    89,    90,    91,    92,    92,    93,    94,
      94,    95,    96,    96,    97,    97,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   101,
     102,   103,   104,   104,   105,   105,   106,   107,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   117,
     118,   119,   119,   120,   121,   121,   122,   123,   123,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   128,
     129,   129,   129
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     3,     2,     0,     4,     2,     0,     2,     1,
       4,     2,     2,     0,     4,     1,     1,     5,     4,     1,
       1,     7,     1,     0,     3,     1,     4,     3,     1,     1,
       1,     0,     4,     3,     3,     1,     2,     0,     2,     1,
       4,     1,     1,     1,     1,     3,     2,     0,     4,     3,
       1,     8,     2,     0,     2,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     5,
       2,     2,     3,     0,     2,     0,     1,     2,     0,     1,
       4,     2,     1,     3,     2,     1,     5,     4,     2,     2,
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
  "MainBlock", "MainHead", "ProgramHead", "OptConstDecls", "ConstDecls",
  "ConstDecl", "PFDecls", "ProcedureDecl", "PBody", "PSignature",
  "FunctionDecl", "FBody", "FSignature", "OptFormalParameters",
  "FormalParameters", "FormalParameter", "ParamIdentList", "OptVar",
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
       0,   164,   164,   166,   168,   170,   172,   173,   175,   176,
     178,   180,   181,   182,   184,   186,   187,   189,   191,   193,
     194,   196,   198,   199,   201,   209,   211,   221,   222,   224,
     225,   226,   228,   230,   232,   233,   235,   236,   238,   239,
     241,   243,   244,   245,   247,   249,   251,   252,   254,   256,
     257,   259,   261,   262,   264,   265,   267,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   281,   283,
     285,   287,   289,   290,   292,   293,   295,   297,   298,   300,
     302,   304,   306,   308,   310,   312,   314,   316,   318,   319,
     321,   323,   324,   326,   328,   329,   331,   333,   334,   336,
     338,   339,   341,   342,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   370,
     372,   373,   374
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
#line 2075 "/home/fabio/Desktop/UsuCS5300/HW5/parser.cpp" // lalr1.cc:1155
#line 376 "parser.ypp" // lalr1.cc:1156

void
yy::Parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
