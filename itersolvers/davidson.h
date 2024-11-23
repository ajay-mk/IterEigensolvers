//
// Created by Ajay Melekamburath on 11/22/24.
//

#ifndef DAVIDSON_H
#define DAVIDSON_H

#include <itersolvers/solver.h>

namespace itersolvers {

/// @brief Davidson eigensolver
///
/// Implements the Davidson-Liu eigensolver for computing the lowest eigenvalues
template <typename MatrixType>
class DavidsonLiu : public IterSolver {
 public:
  DavidsonLiu() = delete;
  ~DavidsonLiu() override = default;

 private:
  size_t n_roots_;
};
}  // namespace itersolvers

#endif  // DAVIDSON_H
