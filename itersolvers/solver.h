//
// Created by Ajay Melekamburath on 11/22/24.
//

#ifndef SOLVER_H_H
#define SOLVER_H_H

#include <exception>
#include <iostream>

namespace itersolvers {

/// @brief Base class for iterative eigensolvers
///
/// This class is the base class for the Davidson eigensolver. It provides the
/// interface for eigensolver and the necessary functions.
/// All derived classes must implement the pure virtual functions.
class IterSolver {
 public:
  IterSolver() = default;
  virtual ~IterSolver() = default;

  /// @brief Set the number of roots to be computed
  virtual void set_n_roots(const size_t n_roots) {
    throw std::runtime_error("Not implemented");
  }

  /// @brief return eigenvalues
  virtual void eigenvalues() const {
    throw std::runtime_error("Not implemented");
  }

  /// @brief return eigenvectors
  virtual void eigenvectors() const {
    throw std::runtime_error("Not implemented");
  }
};

/// @brief Base class for preconditioners
class Preconditioner {
 public:
  Preconditioner() = default;
  virtual ~Preconditioner() = default;
};

}  // namespace itersolvers

#endif  // SOLVER_H_H
