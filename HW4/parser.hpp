// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file /home/fabio/Desktop/UsuCS5300/HW4/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_HOME_FABIO_DESKTOP_USUCS5300_HW4_PARSER_HPP_INCLUDED
# define YY_YY_HOME_FABIO_DESKTOP_USUCS5300_HW4_PARSER_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 17 "parser.ypp" // lalr1.cc:372

#include <string>
#include <iostream>
#include "CodeGen/CodeGenerator.hpp"
#include "CodeGen/Expr/Expr.hpp"
class Driver;

#line 52 "/home/fabio/Desktop/UsuCS5300/HW4/parser.hpp" // lalr1.cc:372

# include <cassert>
# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 128 "/home/fabio/Desktop/UsuCS5300/HW4/parser.hpp" // lalr1.cc:372



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytname_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytname_ (typeid (T).name ())
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytname_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytname_);
      YYASSERT (sizeof (T) <= S);
      yytname_ = typeid (T).name ();
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytname_);
      YYASSERT (sizeof (T) <= S);
      yytname_ = typeid (T).name ();
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (yytname_ == typeid (T).name ());
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (yytname_ == typeid (T).name ());
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytname_);
      YYASSERT (yytname_ == other.yytname_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytname_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const char *yytname_;
  };


  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // Type
      // SimpleType
      char dummy1[sizeof(FC::Type)];

      // CharTok
      char dummy2[sizeof(char)];

      // IntTok
      // PSignature
      // FSignature
      // OptFormalParameters
      // FormalParameters
      // FormalParameter
      // OptVar
      // Body
      // Block
      // RecordType
      // FieldDecls
      // FieldDecl
      // IdentList
      // ArrayType
      // Assignment
      // IfStatement
      // IfHead
      // ThenPart
      // ElseIfList
      // ElseIfHead
      // ElseClause
      // WhileStatement
      // RepeatStatement
      // ForStatement
      // ForHead
      // ToHead
      // StopStatement
      // ReturnStatement
      // ReadStatement
      // ReadArgs
      // WriteStatement
      // WriteArgs
      // ProcedureCall
      // OptArguments
      // Arguments
      // FunctionCall
      char dummy3[sizeof(int)];

      // WhileHead
      // WhileSuperHead
      // Expression
      char dummy4[sizeof(std::shared_ptr<FC::Expr>)];

      // LVal
      char dummy5[sizeof(std::shared_ptr<FC::LVal> )];

      // IdentifierTok
      // StringTok
      // StatementList
      // Statement
      char dummy6[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        ArrayTok = 258,
        BeginTok = 259,
        EndProgTok = 260,
        ChrTok = 261,
        ConstTok = 262,
        DoTok = 263,
        DowntoTok = 264,
        ElseTok = 265,
        ElseifTok = 266,
        EndTok = 267,
        ForTok = 268,
        ForwardTok = 269,
        FunctionTok = 270,
        IfTok = 271,
        OfTok = 272,
        OrdTok = 273,
        PredTok = 274,
        ProcedureTok = 275,
        ReadTok = 276,
        RecordTok = 277,
        RefTok = 278,
        RepeatTok = 279,
        ReturnTok = 280,
        StopTok = 281,
        SuccTok = 282,
        ThenTok = 283,
        ToTok = 284,
        TypeTok = 285,
        UntilTok = 286,
        VarTok = 287,
        WhileTok = 288,
        WriteTok = 289,
        PlusTok = 290,
        MinusTok = 291,
        UnaryMinusTok = 292,
        MultiplyTok = 293,
        DivideTok = 294,
        AndTok = 295,
        OrTok = 296,
        NotTok = 297,
        EqualsTok = 298,
        NotEqualTok = 299,
        LessThanTok = 300,
        LessEqualTok = 301,
        GreaterTok = 302,
        GreaterEqualTok = 303,
        DotTok = 304,
        CommaTok = 305,
        ColonTok = 306,
        SemicolonTok = 307,
        OpenParenTok = 308,
        CloseParenTok = 309,
        OpenBrktTok = 310,
        CloseBrktTok = 311,
        ColonEqualTok = 312,
        PercentTok = 313,
        CharTok = 314,
        IntTok = 315,
        IdentifierTok = 316,
        StringTok = 317
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Internal symbol number.
    typedef int symbol_number_type;

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const FC::Type v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const char v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const int v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<FC::Expr> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<FC::LVal>  v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      ~basic_symbol ();

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// -1 when this symbol is empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      enum { empty = 0 };

      /// The symbol type.
      /// -1 when this symbol is empty.
      token_number_type type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_ArrayTok (const location_type& l);

    static inline
    symbol_type
    make_BeginTok (const location_type& l);

    static inline
    symbol_type
    make_EndProgTok (const location_type& l);

    static inline
    symbol_type
    make_ChrTok (const location_type& l);

    static inline
    symbol_type
    make_ConstTok (const location_type& l);

    static inline
    symbol_type
    make_DoTok (const location_type& l);

    static inline
    symbol_type
    make_DowntoTok (const location_type& l);

    static inline
    symbol_type
    make_ElseTok (const location_type& l);

    static inline
    symbol_type
    make_ElseifTok (const location_type& l);

    static inline
    symbol_type
    make_EndTok (const location_type& l);

    static inline
    symbol_type
    make_ForTok (const location_type& l);

    static inline
    symbol_type
    make_ForwardTok (const location_type& l);

    static inline
    symbol_type
    make_FunctionTok (const location_type& l);

    static inline
    symbol_type
    make_IfTok (const location_type& l);

    static inline
    symbol_type
    make_OfTok (const location_type& l);

    static inline
    symbol_type
    make_OrdTok (const location_type& l);

    static inline
    symbol_type
    make_PredTok (const location_type& l);

    static inline
    symbol_type
    make_ProcedureTok (const location_type& l);

    static inline
    symbol_type
    make_ReadTok (const location_type& l);

    static inline
    symbol_type
    make_RecordTok (const location_type& l);

    static inline
    symbol_type
    make_RefTok (const location_type& l);

    static inline
    symbol_type
    make_RepeatTok (const location_type& l);

    static inline
    symbol_type
    make_ReturnTok (const location_type& l);

    static inline
    symbol_type
    make_StopTok (const location_type& l);

    static inline
    symbol_type
    make_SuccTok (const location_type& l);

    static inline
    symbol_type
    make_ThenTok (const location_type& l);

    static inline
    symbol_type
    make_ToTok (const location_type& l);

    static inline
    symbol_type
    make_TypeTok (const location_type& l);

    static inline
    symbol_type
    make_UntilTok (const location_type& l);

    static inline
    symbol_type
    make_VarTok (const location_type& l);

    static inline
    symbol_type
    make_WhileTok (const location_type& l);

    static inline
    symbol_type
    make_WriteTok (const location_type& l);

    static inline
    symbol_type
    make_PlusTok (const location_type& l);

    static inline
    symbol_type
    make_MinusTok (const location_type& l);

    static inline
    symbol_type
    make_UnaryMinusTok (const location_type& l);

    static inline
    symbol_type
    make_MultiplyTok (const location_type& l);

    static inline
    symbol_type
    make_DivideTok (const location_type& l);

    static inline
    symbol_type
    make_AndTok (const location_type& l);

    static inline
    symbol_type
    make_OrTok (const location_type& l);

    static inline
    symbol_type
    make_NotTok (const location_type& l);

    static inline
    symbol_type
    make_EqualsTok (const location_type& l);

    static inline
    symbol_type
    make_NotEqualTok (const location_type& l);

    static inline
    symbol_type
    make_LessThanTok (const location_type& l);

    static inline
    symbol_type
    make_LessEqualTok (const location_type& l);

    static inline
    symbol_type
    make_GreaterTok (const location_type& l);

    static inline
    symbol_type
    make_GreaterEqualTok (const location_type& l);

    static inline
    symbol_type
    make_DotTok (const location_type& l);

    static inline
    symbol_type
    make_CommaTok (const location_type& l);

    static inline
    symbol_type
    make_ColonTok (const location_type& l);

    static inline
    symbol_type
    make_SemicolonTok (const location_type& l);

    static inline
    symbol_type
    make_OpenParenTok (const location_type& l);

    static inline
    symbol_type
    make_CloseParenTok (const location_type& l);

    static inline
    symbol_type
    make_OpenBrktTok (const location_type& l);

    static inline
    symbol_type
    make_CloseBrktTok (const location_type& l);

    static inline
    symbol_type
    make_ColonEqualTok (const location_type& l);

    static inline
    symbol_type
    make_PercentTok (const location_type& l);

    static inline
    symbol_type
    make_CharTok (const char& v, const location_type& l);

    static inline
    symbol_type
    make_IntTok (const int& v, const location_type& l);

    static inline
    symbol_type
    make_IdentifierTok (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_StringTok (const std::string& v, const location_type& l);


    /// Build a parser object.
    Parser (Driver& driver_yyarg);
    virtual ~Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    Parser (const Parser&);
    Parser& operator= (const Parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yytoken   the lookahead token type, or yyempty_.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         symbol_number_type yytoken) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// "empty" when empty.
      symbol_number_type type_get () const;

      enum { empty = 0 };

      /// The state.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    // Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 458,     ///< Last index in yytable_.
      yynnts_ = 58,  ///< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 8, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 63  ///< Number of tokens.
    };


    // User arguments.
    Driver& driver;
  };

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (token_type t)
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
      switch (other.type_get ())
    {
      case 84: // Type
      case 85: // SimpleType
        value.copy< FC::Type > (other.value);
        break;

      case 59: // CharTok
        value.copy< char > (other.value);
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
        value.copy< int > (other.value);
        break;

      case 103: // WhileHead
      case 104: // WhileSuperHead
      case 118: // Expression
        value.copy< std::shared_ptr<FC::Expr> > (other.value);
        break;

      case 120: // LVal
        value.copy< std::shared_ptr<FC::LVal>  > (other.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 80: // StatementList
      case 94: // Statement
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 84: // Type
      case 85: // SimpleType
        value.copy< FC::Type > (v);
        break;

      case 59: // CharTok
        value.copy< char > (v);
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
        value.copy< int > (v);
        break;

      case 103: // WhileHead
      case 104: // WhileSuperHead
      case 118: // Expression
        value.copy< std::shared_ptr<FC::Expr> > (v);
        break;

      case 120: // LVal
        value.copy< std::shared_ptr<FC::LVal>  > (v);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 80: // StatementList
      case 94: // Statement
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const FC::Type v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const char v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<FC::Expr> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<FC::LVal>  v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 84: // Type
      case 85: // SimpleType
        value.template destroy< FC::Type > ();
        break;

      case 59: // CharTok
        value.template destroy< char > ();
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
        value.template destroy< int > ();
        break;

      case 103: // WhileHead
      case 104: // WhileSuperHead
      case 118: // Expression
        value.template destroy< std::shared_ptr<FC::Expr> > ();
        break;

      case 120: // LVal
        value.template destroy< std::shared_ptr<FC::LVal>  > ();
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 80: // StatementList
      case 94: // Statement
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 84: // Type
      case 85: // SimpleType
        value.move< FC::Type > (s.value);
        break;

      case 59: // CharTok
        value.move< char > (s.value);
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
        value.move< int > (s.value);
        break;

      case 103: // WhileHead
      case 104: // WhileSuperHead
      case 118: // Expression
        value.move< std::shared_ptr<FC::Expr> > (s.value);
        break;

      case 120: // LVal
        value.move< std::shared_ptr<FC::LVal>  > (s.value);
        break;

      case 61: // IdentifierTok
      case 62: // StringTok
      case 80: // StatementList
      case 94: // Statement
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

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

  inline
  Parser::token_type
  Parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  Parser::symbol_type
  Parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  Parser::symbol_type
  Parser::make_ArrayTok (const location_type& l)
  {
    return symbol_type (token::ArrayTok, l);
  }

  Parser::symbol_type
  Parser::make_BeginTok (const location_type& l)
  {
    return symbol_type (token::BeginTok, l);
  }

  Parser::symbol_type
  Parser::make_EndProgTok (const location_type& l)
  {
    return symbol_type (token::EndProgTok, l);
  }

  Parser::symbol_type
  Parser::make_ChrTok (const location_type& l)
  {
    return symbol_type (token::ChrTok, l);
  }

  Parser::symbol_type
  Parser::make_ConstTok (const location_type& l)
  {
    return symbol_type (token::ConstTok, l);
  }

  Parser::symbol_type
  Parser::make_DoTok (const location_type& l)
  {
    return symbol_type (token::DoTok, l);
  }

  Parser::symbol_type
  Parser::make_DowntoTok (const location_type& l)
  {
    return symbol_type (token::DowntoTok, l);
  }

  Parser::symbol_type
  Parser::make_ElseTok (const location_type& l)
  {
    return symbol_type (token::ElseTok, l);
  }

  Parser::symbol_type
  Parser::make_ElseifTok (const location_type& l)
  {
    return symbol_type (token::ElseifTok, l);
  }

  Parser::symbol_type
  Parser::make_EndTok (const location_type& l)
  {
    return symbol_type (token::EndTok, l);
  }

  Parser::symbol_type
  Parser::make_ForTok (const location_type& l)
  {
    return symbol_type (token::ForTok, l);
  }

  Parser::symbol_type
  Parser::make_ForwardTok (const location_type& l)
  {
    return symbol_type (token::ForwardTok, l);
  }

  Parser::symbol_type
  Parser::make_FunctionTok (const location_type& l)
  {
    return symbol_type (token::FunctionTok, l);
  }

  Parser::symbol_type
  Parser::make_IfTok (const location_type& l)
  {
    return symbol_type (token::IfTok, l);
  }

  Parser::symbol_type
  Parser::make_OfTok (const location_type& l)
  {
    return symbol_type (token::OfTok, l);
  }

  Parser::symbol_type
  Parser::make_OrdTok (const location_type& l)
  {
    return symbol_type (token::OrdTok, l);
  }

  Parser::symbol_type
  Parser::make_PredTok (const location_type& l)
  {
    return symbol_type (token::PredTok, l);
  }

  Parser::symbol_type
  Parser::make_ProcedureTok (const location_type& l)
  {
    return symbol_type (token::ProcedureTok, l);
  }

  Parser::symbol_type
  Parser::make_ReadTok (const location_type& l)
  {
    return symbol_type (token::ReadTok, l);
  }

  Parser::symbol_type
  Parser::make_RecordTok (const location_type& l)
  {
    return symbol_type (token::RecordTok, l);
  }

  Parser::symbol_type
  Parser::make_RefTok (const location_type& l)
  {
    return symbol_type (token::RefTok, l);
  }

  Parser::symbol_type
  Parser::make_RepeatTok (const location_type& l)
  {
    return symbol_type (token::RepeatTok, l);
  }

  Parser::symbol_type
  Parser::make_ReturnTok (const location_type& l)
  {
    return symbol_type (token::ReturnTok, l);
  }

  Parser::symbol_type
  Parser::make_StopTok (const location_type& l)
  {
    return symbol_type (token::StopTok, l);
  }

  Parser::symbol_type
  Parser::make_SuccTok (const location_type& l)
  {
    return symbol_type (token::SuccTok, l);
  }

  Parser::symbol_type
  Parser::make_ThenTok (const location_type& l)
  {
    return symbol_type (token::ThenTok, l);
  }

  Parser::symbol_type
  Parser::make_ToTok (const location_type& l)
  {
    return symbol_type (token::ToTok, l);
  }

  Parser::symbol_type
  Parser::make_TypeTok (const location_type& l)
  {
    return symbol_type (token::TypeTok, l);
  }

  Parser::symbol_type
  Parser::make_UntilTok (const location_type& l)
  {
    return symbol_type (token::UntilTok, l);
  }

  Parser::symbol_type
  Parser::make_VarTok (const location_type& l)
  {
    return symbol_type (token::VarTok, l);
  }

  Parser::symbol_type
  Parser::make_WhileTok (const location_type& l)
  {
    return symbol_type (token::WhileTok, l);
  }

  Parser::symbol_type
  Parser::make_WriteTok (const location_type& l)
  {
    return symbol_type (token::WriteTok, l);
  }

  Parser::symbol_type
  Parser::make_PlusTok (const location_type& l)
  {
    return symbol_type (token::PlusTok, l);
  }

  Parser::symbol_type
  Parser::make_MinusTok (const location_type& l)
  {
    return symbol_type (token::MinusTok, l);
  }

  Parser::symbol_type
  Parser::make_UnaryMinusTok (const location_type& l)
  {
    return symbol_type (token::UnaryMinusTok, l);
  }

  Parser::symbol_type
  Parser::make_MultiplyTok (const location_type& l)
  {
    return symbol_type (token::MultiplyTok, l);
  }

  Parser::symbol_type
  Parser::make_DivideTok (const location_type& l)
  {
    return symbol_type (token::DivideTok, l);
  }

  Parser::symbol_type
  Parser::make_AndTok (const location_type& l)
  {
    return symbol_type (token::AndTok, l);
  }

  Parser::symbol_type
  Parser::make_OrTok (const location_type& l)
  {
    return symbol_type (token::OrTok, l);
  }

  Parser::symbol_type
  Parser::make_NotTok (const location_type& l)
  {
    return symbol_type (token::NotTok, l);
  }

  Parser::symbol_type
  Parser::make_EqualsTok (const location_type& l)
  {
    return symbol_type (token::EqualsTok, l);
  }

  Parser::symbol_type
  Parser::make_NotEqualTok (const location_type& l)
  {
    return symbol_type (token::NotEqualTok, l);
  }

  Parser::symbol_type
  Parser::make_LessThanTok (const location_type& l)
  {
    return symbol_type (token::LessThanTok, l);
  }

  Parser::symbol_type
  Parser::make_LessEqualTok (const location_type& l)
  {
    return symbol_type (token::LessEqualTok, l);
  }

  Parser::symbol_type
  Parser::make_GreaterTok (const location_type& l)
  {
    return symbol_type (token::GreaterTok, l);
  }

  Parser::symbol_type
  Parser::make_GreaterEqualTok (const location_type& l)
  {
    return symbol_type (token::GreaterEqualTok, l);
  }

  Parser::symbol_type
  Parser::make_DotTok (const location_type& l)
  {
    return symbol_type (token::DotTok, l);
  }

  Parser::symbol_type
  Parser::make_CommaTok (const location_type& l)
  {
    return symbol_type (token::CommaTok, l);
  }

  Parser::symbol_type
  Parser::make_ColonTok (const location_type& l)
  {
    return symbol_type (token::ColonTok, l);
  }

  Parser::symbol_type
  Parser::make_SemicolonTok (const location_type& l)
  {
    return symbol_type (token::SemicolonTok, l);
  }

  Parser::symbol_type
  Parser::make_OpenParenTok (const location_type& l)
  {
    return symbol_type (token::OpenParenTok, l);
  }

  Parser::symbol_type
  Parser::make_CloseParenTok (const location_type& l)
  {
    return symbol_type (token::CloseParenTok, l);
  }

  Parser::symbol_type
  Parser::make_OpenBrktTok (const location_type& l)
  {
    return symbol_type (token::OpenBrktTok, l);
  }

  Parser::symbol_type
  Parser::make_CloseBrktTok (const location_type& l)
  {
    return symbol_type (token::CloseBrktTok, l);
  }

  Parser::symbol_type
  Parser::make_ColonEqualTok (const location_type& l)
  {
    return symbol_type (token::ColonEqualTok, l);
  }

  Parser::symbol_type
  Parser::make_PercentTok (const location_type& l)
  {
    return symbol_type (token::PercentTok, l);
  }

  Parser::symbol_type
  Parser::make_CharTok (const char& v, const location_type& l)
  {
    return symbol_type (token::CharTok, v, l);
  }

  Parser::symbol_type
  Parser::make_IntTok (const int& v, const location_type& l)
  {
    return symbol_type (token::IntTok, v, l);
  }

  Parser::symbol_type
  Parser::make_IdentifierTok (const std::string& v, const location_type& l)
  {
    return symbol_type (token::IdentifierTok, v, l);
  }

  Parser::symbol_type
  Parser::make_StringTok (const std::string& v, const location_type& l)
  {
    return symbol_type (token::StringTok, v, l);
  }



} // yy
#line 1865 "/home/fabio/Desktop/UsuCS5300/HW4/parser.hpp" // lalr1.cc:372




#endif // !YY_YY_HOME_FABIO_DESKTOP_USUCS5300_HW4_PARSER_HPP_INCLUDED
