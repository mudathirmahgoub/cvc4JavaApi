/*********************                                                        */
/** expr.h
 **
 ** Copyright 2010-2014  New York University and The University of Iowa,
 ** and as below.
 **
 ** This file automatically generated by:
 **
 **     ../../../src/expr/mkexpr /home/mudathir/Desktop/CVC4/java/src/expr/expr_template.h /home/mudathir/Desktop/CVC4/java/src/theory/builtin/kinds /home/mudathir/Desktop/CVC4/java/src/theory/booleans/kinds /home/mudathir/Desktop/CVC4/java/src/theory/uf/kinds /home/mudathir/Desktop/CVC4/java/src/theory/arith/kinds /home/mudathir/Desktop/CVC4/java/src/theory/bv/kinds /home/mudathir/Desktop/CVC4/java/src/theory/fp/kinds /home/mudathir/Desktop/CVC4/java/src/theory/arrays/kinds /home/mudathir/Desktop/CVC4/java/src/theory/datatypes/kinds /home/mudathir/Desktop/CVC4/java/src/theory/sep/kinds /home/mudathir/Desktop/CVC4/java/src/theory/sets/kinds /home/mudathir/Desktop/CVC4/java/src/theory/bags/kinds /home/mudathir/Desktop/CVC4/java/src/theory/strings/kinds /home/mudathir/Desktop/CVC4/java/src/theory/quantifiers/kinds
 **
 ** for the CVC4 project.
 **/

/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */

/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */

/* Edit the template file instead:                     */
/* /home/mudathir/Desktop/CVC4/java/src/expr/expr_template.h */

/*********************                                                        */
/*! \file expr_template.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Morgan Deters, Dejan Jovanovic, Aina Niemetz
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2020 by the authors listed in the file AUTHORS
 ** in the top-level source directory and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief Public-facing expression interface.
 **
 ** Public-facing expression interface.
 **/

#include <cvc4/cvc4_public.h>

// putting the constant-payload #includes up here allows circularity
// (some of them may require a completely-defined Expr type).  This
// way, those #includes can forward-declare some stuff to get Expr's
// getConst<> template instantiations correct, and then #include
// "expr.h" safely, then go on to completely declare their own stuff.

#include <cvc4/expr/uninterpreted_constant.h>
#include <cvc4/util/abstract_value.h>
#include <cvc4/expr/kind.h>
#include <cvc4/util/bool.h>
#include <cvc4/util/divisible.h>
#include <cvc4/util/rational.h>
#include <cvc4/util/indexed_root_predicate.h>
#include <cvc4/util/iand.h>
#include <cvc4/util/bitvector.h>
#include <cvc4/util/floatingpoint.h>
#include <cvc4/expr/array_store_all.h>
#include <cvc4/expr/datatype_index.h>
#include <cvc4/expr/ascription_type.h>
#include <cvc4/util/tuple.h>
#include <cvc4/expr/record.h>
#include <cvc4/expr/emptyset.h>
#include <cvc4/theory/sets/singleton_op.h>
#include <cvc4/expr/emptybag.h>
#include <cvc4/theory/bags/make_bag_op.h>
#include <cvc4/util/string.h>
#include <cvc4/expr/sequence.h>
#include <cvc4/util/regexp.h>

#ifndef CVC4__EXPR_H
#define CVC4__EXPR_H

#include <iosfwd>
#include <iterator>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <cvc4/base/exception.h>
#include <cvc4/options/language.h>
#include <cvc4/util/hash.h>

namespace CVC4 {

// The internal expression representation
template <bool ref_count>
class NodeTemplate;

class NodeManager;

class Expr;
class ExprManager;
class SmtEngine;
class Type;
class TypeCheckingException;
class TypeCheckingExceptionPrivate;

namespace api {
class Solver;
}

namespace prop {
  class TheoryProxy;
}/* CVC4::prop namespace */

struct ExprManagerMapCollection;

struct ExprHashFunction;

namespace smt {
  class SmtEnginePrivate;
}/* CVC4::smt namespace */

namespace expr {
  class ExportPrivate;
}/* CVC4::expr namespace */

/**
 * Exception thrown in the case of type-checking errors.
 */
class CVC4_PUBLIC TypeCheckingException : public Exception {
 private:
  friend class SmtEngine;
  friend class smt::SmtEnginePrivate;

  /** The expression responsible for the error */
  Expr* d_expr;

 protected:
  TypeCheckingException() : Exception() {}
  TypeCheckingException(ExprManager* em,
                        const TypeCheckingExceptionPrivate* exc);

 public:
  TypeCheckingException(const Expr& expr, std::string message);

  /** Copy constructor */
  TypeCheckingException(const TypeCheckingException& t);

  /** Destructor */
  ~TypeCheckingException() override;

  /**
   * Get the Expr that caused the type-checking to fail.
   *
   * @return the expr
   */
  Expr getExpression() const;

  /**
   * Returns the message corresponding to the type-checking failure.
   * We prefer toStream() to toString() because that keeps the expr-depth
   * and expr-language settings present in the stream.
   */
  void toStream(std::ostream& out) const override;

  friend class ExprManager;
};/* class TypeCheckingException */

/**
 * Exception thrown in case of failure to export
 */
class CVC4_PUBLIC ExportUnsupportedException : public Exception {
 public:
  ExportUnsupportedException() : Exception("export unsupported") {}
  ExportUnsupportedException(const char* msg) : Exception(msg) {}
};/* class DatatypeExportUnsupportedException */

std::ostream& operator<<(std::ostream& out,
                         const TypeCheckingException& e) CVC4_PUBLIC;

/**
 * Output operator for expressions
 * @param out the stream to output to
 * @param e the expression to output
 * @return the stream
 */
std::ostream& operator<<(std::ostream& out, const Expr& e) CVC4_PUBLIC;

/**
 * Serialize a vector of expressions to given stream.
 *
 * @param out the output stream to use
 * @param container the vector of expressions to output to the stream
 * @return the stream
 */
std::ostream& operator<<(std::ostream& out,
                         const std::vector<Expr>& container) CVC4_PUBLIC;

/**
 * Serialize a set of expressions to the given stream.
 *
 * @param out the output stream to use
 * @param container the set of expressions to output to the stream
 * @return the stream
 */
std::ostream& operator<<(std::ostream& out,
                         const std::set<Expr>& container) CVC4_PUBLIC;

/**
 * Serialize an unordered_set of expressions to the given stream.
 *
 * @param out the output stream to use
 * @param container the unordered_set of expressions to output to the stream
 * @return the stream
 */
std::ostream& operator<<(
    std::ostream& out,
    const std::unordered_set<Expr, ExprHashFunction>& container) CVC4_PUBLIC;

/**
 * Serialize a map of expressions to the given stream.
 *
 * @param out the output stream to use
 * @param container the map of expressions to output to the stream
 * @return the stream
 */
template <typename V>
std::ostream& operator<<(std::ostream& out,
                         const std::map<Expr, V>& container) CVC4_PUBLIC;

/**
 * Serialize an unordered_map of expressions to the given stream.
 *
 * @param out the output stream to use
 * @param container the unordered_map of expressions to output to the stream
 * @return the stream
 */
template <typename V>
std::ostream& operator<<(
    std::ostream& out,
    const std::unordered_map<Expr, V, ExprHashFunction>& container) CVC4_PUBLIC;

// for hash_maps, hash_sets..
struct ExprHashFunction {
  size_t operator()(CVC4::Expr e) const;
};/* struct ExprHashFunction */

/**
 * Class encapsulating CVC4 expressions and methods for constructing new
 * expressions.
 */
class CVC4_PUBLIC Expr {
  friend class ExprManager;
  friend class NodeManager;
  friend class SmtEngine;
  friend class TypeCheckingException;
  friend class api::Solver;
  friend class expr::ExportPrivate;
  friend class prop::TheoryProxy;
  friend class smt::SmtEnginePrivate;
  friend std::ostream& CVC4::operator<<(std::ostream& out, const Expr& e);

  /** The internal expression representation */
  NodeTemplate<true>* d_node;

  /** The responsible expression manager */
  ExprManager* d_exprManager;

  /**
   * Constructor for internal purposes.
   *
   * @param em the expression manager that handles this expression
   * @param node the actual expression node pointer
   */
  Expr(ExprManager* em, NodeTemplate<true>* node);

public:

  /** Default constructor, makes a null expression. */
  Expr();

  /**
   * Copy constructor, makes a copy of a given expression
   *
   * @param e the expression to copy
   */
  Expr(const Expr& e);

  /** Destructor */
  ~Expr();

  /**
   * Assignment operator, makes a copy of the given expression. If the
   * expression managers of the two expressions differ, the expression of
   * the given expression will be used.
   *
   * @param e the expression to assign
   * @return the reference to this expression after assignment
   */
  Expr& operator=(const Expr& e);

  /**
   * Syntactic comparison operator. Returns true if expressions belong to the
   * same expression manager and are syntactically identical.
   *
   * @param e the expression to compare to
   * @return true if expressions are syntactically the same, false otherwise
   */
  bool operator==(const Expr& e) const;

  /**
   * Syntactic disequality operator.
   *
   * @param e the expression to compare to
   * @return true if expressions differ syntactically, false otherwise
   */
  bool operator!=(const Expr& e) const;

  /**
   * Order comparison operator. The only invariant on the order of expressions
   * is that the expressions that were created sooner will be smaller in the
   * ordering than all the expressions created later. Null expression is the
   * smallest element of the ordering. The behavior of the operator is
   * undefined if the expressions come from two different expression managers.
   *
   * @param e the expression to compare to
   * @return true if this expression is smaller than the given one
   */
  bool operator<(const Expr& e) const;

  /**
   * Order comparison operator. The only invariant on the order of expressions
   * is that the expressions that were created sooner will be smaller in the
   * ordering than all the expressions created later. Null expression is the
   * smallest element of the ordering. The behavior of the operator is
   * undefined if the expressions come from two different expression managers.
   *
   * @param e the expression to compare to
   * @return true if this expression is greater than the given one
   */
  bool operator>(const Expr& e) const;

  /**
   * Order comparison operator. The only invariant on the order of expressions
   * is that the expressions that were created sooner will be smaller in the
   * ordering than all the expressions created later. Null expression is the
   * smallest element of the ordering. The behavior of the operator is
   * undefined if the expressions come from two different expression managers.
   *
   * @param e the expression to compare to
   * @return true if this expression is smaller or equal to the given one
   */
  bool operator<=(const Expr& e) const { return !(*this > e); }

  /**
   * Order comparison operator. The only invariant on the order of expressions
   * is that the expressions that were created sooner will be smaller in the
   * ordering than all the expressions created later. Null expression is the
   * smallest element of the ordering. The behavior of the operator is
   * undefined if the expressions come from two different expression managers.
   *
   * @param e the expression to compare to
   * @return true if this expression is greater or equal to the given one
   */
  bool operator>=(const Expr& e) const { return !(*this < e); }

  /**
   * Get the ID of this expression (used for the comparison operators).
   *
   * @return an identifier uniquely identifying the value this
   * expression holds.
   */
  uint64_t getId() const;

  /**
   * Returns the kind of the expression (AND, PLUS ...).
   *
   * @return the kind of the expression
   */
  Kind getKind() const;

  /**
   * Returns the number of children of this expression.
   *
   * @return the number of children
   */
  size_t getNumChildren() const;

  /**
   * Returns the i'th child of this expression.
   *
   * @param i the index of the child to retrieve
   * @return the child
   */
  Expr operator[](unsigned i) const;

  /**
   * Returns the children of this Expr.
   */
  std::vector<Expr> getChildren() const {
    return std::vector<Expr>(begin(), end());
  }

  /**
   * Returns the Boolean negation of this Expr.
   */
  Expr notExpr() const;

  /**
   * Returns the conjunction of this expression and
   * the given expression.
   */
  Expr andExpr(const Expr& e) const;

  /**
   * Returns the disjunction of this expression and
   * the given expression.
   */
  Expr orExpr(const Expr& e) const;

  /**
   * Returns the exclusive disjunction of this expression and
   * the given expression.
   */
  Expr xorExpr(const Expr& e) const;

  /**
   * Returns the Boolean equivalence of this expression and
   * the given expression.
   */
  Expr eqExpr(const Expr& e) const;

  /**
   * Returns the implication of this expression and
   * the given expression.
   */
  Expr impExpr(const Expr& e) const;

  /**
   * Returns the if-then-else expression with this expression
   * as the Boolean condition and the given expressions as
   * the "then" and "else" expressions.
   */
  Expr iteExpr(const Expr& then_e, const Expr& else_e) const;

  /**
   * Iterator type for the children of an Expr.
   */
  class const_iterator : public std::iterator<std::input_iterator_tag, Expr> {
    ExprManager* d_exprManager;
    void* d_iterator;

    explicit const_iterator(ExprManager*, void*);

    friend class Expr;// to access void* constructor

  public:
    const_iterator();
    const_iterator(const const_iterator& it);
    const_iterator& operator=(const const_iterator& it);
    ~const_iterator();
    bool operator==(const const_iterator& it) const;
    bool operator!=(const const_iterator& it) const {
      return !(*this == it);
    }
    const_iterator& operator++();
    const_iterator operator++(int);
    Expr operator*() const;
  };/* class Expr::const_iterator */

  /**
   * Returns an iterator to the first child of this Expr.
   */
  const_iterator begin() const;

  /**
   * Returns an iterator to one-off-the-last child of this Expr.
   */
  const_iterator end() const;

  /**
   * Check if this is an expression that has an operator.
   *
   * @return true if this expression has an operator
   */
  bool hasOperator() const;

  /**
   * Get the operator of this expression.
   *
   * @throws IllegalArgumentException if it has no operator
   * @return the operator of this expression
   */
  Expr getOperator() const;

  /**
   * Check if this is an expression is parameterized.
   *
   * @return true if this expression is parameterized.
   *
   * In detail, an expression that is parameterized is one that has an operator
   * that must be provided in addition to its kind to construct it. For example,
   * say we want to re-construct an Expr e where its children a1, ..., an are
   * replaced by b1 ... bn. Then there are two cases:
   * (1) If e is parametric, call:
   *   ExprManager::mkExpr(e.getKind(), e.getOperator(), b1, ..., bn )
   * (2) If e is not parametric, call:
   *   ExprManager::mkExpr(e.getKind(), b1, ..., bn )
   */
  bool isParameterized() const;

  /**
   * Get the type for this Expr and optionally do type checking.
   *
   * Initial type computation will be near-constant time if
   * type checking is not requested. Results are memoized, so that
   * subsequent calls to getType() without type checking will be
   * constant time.
   *
   * Initial type checking is linear in the size of the expression.
   * Again, the results are memoized, so that subsequent calls to
   * getType(), with or without type checking, will be constant
   * time.
   *
   * NOTE: A TypeCheckingException can be thrown even when type
   * checking is not requested. getType() will always return a
   * valid and correct type and, thus, an exception will be thrown
   * when no valid or correct type can be computed (e.g., if the
   * arguments to a bit-vector operation aren't bit-vectors). When
   * type checking is not requested, getType() will do the minimum
   * amount of checking required to return a valid result.
   *
   * @param check whether we should check the type as we compute it
   * (default: false)
   */
  Type getType(bool check = false) const;

  /**
   * Substitute "replacement" in for "e".
   */
  Expr substitute(Expr e, Expr replacement) const;

  /**
   * Substitute "replacements" in for "exes".
   */
  Expr substitute(const std::vector<Expr> exes,
                  const std::vector<Expr>& replacements) const;

  /**
   * Substitute pairs of (ex,replacement) from the given map.
   */
  Expr substitute(const std::unordered_map<Expr, Expr, ExprHashFunction> map) const;

  /**
   * Returns the string representation of the expression.
   * @return a string representation of the expression
   */
  std::string toString() const;

  /**
   * Outputs the string representation of the expression to the stream.
   *
   * @param out the stream to serialize this expression to
   * @param toDepth the depth to which to print this expression, or -1
   * to print it fully
   * @param dag the dagification threshold to use (0 == off)
   * @param language the language in which to output
   */
  void toStream(std::ostream& out,
                int toDepth = -1,
                size_t dag = 1,
                OutputLanguage language = language::output::LANG_AUTO) const;

  /**
   * Check if this is a null expression.
   *
   * @return true if a null expression
   */
  bool isNull() const;

  /**
   * Check if this is an expression representing a variable.
   *
   * @return true if a variable expression
   */
  bool isVariable() const;

  /**
   * Check if this is an expression representing a constant.
   *
   * @return true if a constant expression
   */
  bool isConst() const;

  /**
   * Check if this expression contains a free variable.
   *
   * @return true if this node contains a free variable.
   */
  bool hasFreeVariable() const;

  /* A note on isAtomic() and isAtomicFormula() (in CVC3 parlance)..
   *
   * It has been decided for now to hold off on implementations of
   * these functions, as they may only be needed in CNF conversion,
   * where it's pointless to do a lazy isAtomic determination by
   * searching through the DAG, and storing it, since the result will
   * only be used once.  For more details see the 4/27/2010 CVC4
   * developer's meeting notes at:
   *
   * http://cvc4.cs.stanford.edu/wiki/Meeting_Minutes_-_April_27,_2010#isAtomic.28.29_and_isAtomicFormula.28.29
   */
  // bool containsDecision(); // is "atomic"
  // bool properlyContainsDecision(); // maybe not atomic but all children are

  /** Extract a constant of type T */
  template <class T>
  const T& getConst() const;

  /**
   * Returns the expression reponsible for this expression.
   */
  ExprManager* getExprManager() const;

  /**
   * Maps this Expr into one for a different ExprManager, using
   * variableMap for the translation and extending it with any new
   * mappings.
   */
  Expr exportTo(ExprManager* exprManager, ExprManagerMapCollection& variableMap, uint32_t flags = 0) const;

  /**
   * Very basic pretty printer for Expr.
   * This is equivalent to calling e.getNode().printAst(...)
   * @param out output stream to print to.
   * @param indent number of spaces to indent the formula by.
   */
  void printAst(std::ostream& out, int indent = 0) const;

private:

  /**
   * Pretty printer for use within gdb
   * This is not intended to be used outside of gdb.
   * This writes to the ostream Warning() and immediately flushes
   * the ostream.
   */
  void debugPrint();

  /**
   * Returns the actual internal node.
   * @return the internal node
   */
  NodeTemplate<true> getNode() const;

  /**
   * Returns the actual internal node as a TNode.
   * @return the internal node
   */
  NodeTemplate<false> getTNode() const;
  template <bool ref_count> friend class NodeTemplate;

};/* class Expr */


template <> ::CVC4::UninterpretedConstant const & Expr::getConst< ::CVC4::UninterpretedConstant >() const;

template <> ::CVC4::AbstractValue const & Expr::getConst< ::CVC4::AbstractValue >() const;

template <> ::CVC4::Kind const & Expr::getConst< ::CVC4::Kind >() const;

template <> ::CVC4::TypeConstant const & Expr::getConst< ::CVC4::TypeConstant >() const;

template <> bool const & Expr::getConst< bool >() const;

template <> ::CVC4::Divisible const & Expr::getConst< ::CVC4::Divisible >() const;

template <> ::CVC4::Rational const & Expr::getConst< ::CVC4::Rational >() const;

template <> ::CVC4::IndexedRootPredicate const & Expr::getConst< ::CVC4::IndexedRootPredicate >() const;

template <> ::CVC4::IntAnd const & Expr::getConst< ::CVC4::IntAnd >() const;

template <> ::CVC4::BitVectorSize const & Expr::getConst< ::CVC4::BitVectorSize >() const;

template <> ::CVC4::BitVector const & Expr::getConst< ::CVC4::BitVector >() const;

template <> ::CVC4::BitVectorBitOf const & Expr::getConst< ::CVC4::BitVectorBitOf >() const;

template <> ::CVC4::BitVectorExtract const & Expr::getConst< ::CVC4::BitVectorExtract >() const;

template <> ::CVC4::BitVectorRepeat const & Expr::getConst< ::CVC4::BitVectorRepeat >() const;

template <> ::CVC4::BitVectorRotateLeft const & Expr::getConst< ::CVC4::BitVectorRotateLeft >() const;

template <> ::CVC4::BitVectorRotateRight const & Expr::getConst< ::CVC4::BitVectorRotateRight >() const;

template <> ::CVC4::BitVectorSignExtend const & Expr::getConst< ::CVC4::BitVectorSignExtend >() const;

template <> ::CVC4::BitVectorZeroExtend const & Expr::getConst< ::CVC4::BitVectorZeroExtend >() const;

template <> ::CVC4::IntToBitVector const & Expr::getConst< ::CVC4::IntToBitVector >() const;

template <> ::CVC4::FloatingPoint const & Expr::getConst< ::CVC4::FloatingPoint >() const;

template <> ::CVC4::RoundingMode const & Expr::getConst< ::CVC4::RoundingMode >() const;

template <> ::CVC4::FloatingPointSize const & Expr::getConst< ::CVC4::FloatingPointSize >() const;

template <> ::CVC4::FloatingPointToFPIEEEBitVector const & Expr::getConst< ::CVC4::FloatingPointToFPIEEEBitVector >() const;

template <> ::CVC4::FloatingPointToFPFloatingPoint const & Expr::getConst< ::CVC4::FloatingPointToFPFloatingPoint >() const;

template <> ::CVC4::FloatingPointToFPReal const & Expr::getConst< ::CVC4::FloatingPointToFPReal >() const;

template <> ::CVC4::FloatingPointToFPSignedBitVector const & Expr::getConst< ::CVC4::FloatingPointToFPSignedBitVector >() const;

template <> ::CVC4::FloatingPointToFPUnsignedBitVector const & Expr::getConst< ::CVC4::FloatingPointToFPUnsignedBitVector >() const;

template <> ::CVC4::FloatingPointToFPGeneric const & Expr::getConst< ::CVC4::FloatingPointToFPGeneric >() const;

template <> ::CVC4::FloatingPointToUBV const & Expr::getConst< ::CVC4::FloatingPointToUBV >() const;

template <> ::CVC4::FloatingPointToUBVTotal const & Expr::getConst< ::CVC4::FloatingPointToUBVTotal >() const;

template <> ::CVC4::FloatingPointToSBV const & Expr::getConst< ::CVC4::FloatingPointToSBV >() const;

template <> ::CVC4::FloatingPointToSBVTotal const & Expr::getConst< ::CVC4::FloatingPointToSBVTotal >() const;

template <> ::CVC4::ArrayStoreAll const & Expr::getConst< ::CVC4::ArrayStoreAll >() const;

template <> ::CVC4::DatatypeIndexConstant const & Expr::getConst< ::CVC4::DatatypeIndexConstant >() const;

template <> ::CVC4::AscriptionType const & Expr::getConst< ::CVC4::AscriptionType >() const;

template <> ::CVC4::TupleUpdate const & Expr::getConst< ::CVC4::TupleUpdate >() const;

template <> ::CVC4::RecordUpdate const & Expr::getConst< ::CVC4::RecordUpdate >() const;

template <> ::CVC4::EmptySet const & Expr::getConst< ::CVC4::EmptySet >() const;

template <> ::CVC4::SingletonOp const & Expr::getConst< ::CVC4::SingletonOp >() const;

template <> ::CVC4::EmptyBag const & Expr::getConst< ::CVC4::EmptyBag >() const;

template <> ::CVC4::MakeBagOp const & Expr::getConst< ::CVC4::MakeBagOp >() const;

template <> ::CVC4::String const & Expr::getConst< ::CVC4::String >() const;

template <> ::CVC4::Sequence const & Expr::getConst< ::CVC4::Sequence >() const;

template <> ::CVC4::RegExpRepeat const & Expr::getConst< ::CVC4::RegExpRepeat >() const;

template <> ::CVC4::RegExpLoop const & Expr::getConst< ::CVC4::RegExpLoop >() const;


inline size_t ExprHashFunction::operator()(CVC4::Expr e) const {
  return (size_t) e.getId();
}

}/* CVC4 namespace */

#endif /* CVC4__EXPR_H */