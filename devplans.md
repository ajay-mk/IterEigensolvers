#### Datatypes to be supported
- Eigen::Matrix
- TA::DistArray (both dense and sparse)
- TA::Tensor
- std::vector<MatrixType>

Operations like `axpy()`, `inner_product()`, `norm()` should be defined for all these datatypes.

#### Backends for subspace diagonalization
- LAPACKPP
- Eigen

##### Cases to test
- Real and complex symmetric matrices
- Real and complex non-symmetric matrices
- A Hamiltonian like matrix

### Design Ideas
- Generic `IterSolver` class as a base class.
  - Should provide (at least) the following methods:
    - `solve(guess_vectors, preconditioner, max_iter, tol)`
    - `set_n_roots(n_roots)`
    - `eigenvalues()`
    - `eigenvectors()`
  - Nothing is implemented in the base class, throws exceptions if invoked. 
  - These functions should only act as an interface. 
