/*********************                                                        */
/*! \file unsat_core.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Andrew Reynolds, Morgan Deters, Mathias Preiner
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2020 by the authors listed in the file AUTHORS
 ** in the top-level source directory and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief Representation of unsat cores.
 **/

#include <cvc4/cvc4_private.h>

#ifndef CVC4__UNSAT_CORE_H
#define CVC4__UNSAT_CORE_H

#include <iosfwd>
#include <vector>

#include <cvc4/expr/node.h>

namespace CVC4 {

/**
 * An unsat core, which can optionally be initialized as a list of names
 * or as a list of formulas.
 */
class UnsatCore
{
 public:
  UnsatCore() {}
  /** Initialize using assertions */
  UnsatCore(const std::vector<Node>& core);
  /** Initialize using assertion names */
  UnsatCore(std::vector<std::string>& names);
  ~UnsatCore() {}

  /** Whether we are using names for this unsat core */
  bool useNames() const { return d_useNames; }
  /** Get the assertions in the unsat core */
  const std::vector<Node>& getCore() const;
  /** Get their names */
  const std::vector<std::string>& getCoreNames() const;

  typedef std::vector<Node>::const_iterator iterator;
  typedef std::vector<Node>::const_iterator const_iterator;

  const_iterator begin() const;
  const_iterator end() const;

  /**
   * prints this UnsatCore object to the stream out.
   */
  void toStream(std::ostream& out) const;

 private:
  /** Whether we are using names for this unsat core */
  bool d_useNames;
  /** The unsat core */
  std::vector<Node> d_core;
  /** The names of assertions in the above core */
  std::vector<std::string> d_names;
};/* class UnsatCore */

/** Print the unsat core to stream out */
std::ostream& operator<<(std::ostream& out, const UnsatCore& core);

}/* CVC4 namespace */

#endif /* CVC4__UNSAT_CORE_H */
