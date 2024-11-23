#### Datatypes of Support
- Eigen::Matrix
- TA::DistArray (both dense and sparse)
- TA::Tensor
- std::vector<MatrixType> (or any mutable container)

#### Backends for subspace diagonalization
- LAPACKPP
- Eigen
- ScalaPACKPP (Only for symmetric real matrices)

##### Cases to test
- Real and complex symmetric matrices
- Real and complex non-symmetric matrices
- A Hamiltonian like matrix

### Design Ideas
- Generic `DavidsonSolver` class as a base class.
  - Should provide the following methods:
    - `solve(guess_vectors, preconditioner, max_iter, tol)`
    - `set_n_roots(n_roots)`
    - `compute_subspace(...)` could be a private method
    - `eigenvalues()`
    - `eigenvectors()`
  - Nothing is implemented in the base class, throws exceptions if invoked. 
  - These functions should only act as a interface. 
