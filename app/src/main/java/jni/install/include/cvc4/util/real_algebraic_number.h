/*********************                                                        */
/*! \file real_algebraic_number.h.in
 ** \verbatim
 ** Top contributors (to current version):
 **   Gereon Kremer
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
 ** in the top-level source directory and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief A real algebraic number constant
 **
 ** A real algebraic number constant.
 **/

// these gestures are used to avoid a public header dependence on cvc4autoconfig.h

#if /* use libpoly */ 0
#  define CVC4_POLY_IMP
#endif /* 0 */

#ifdef CVC4_POLY_IMP
#  include <cvc4/util/real_algebraic_number_poly_imp.h>
#endif /* CVC4_POLY_IMP */
