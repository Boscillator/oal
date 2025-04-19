.. OAL documentation master file, created by

Open Aerospace Library Documentation
====================================

Unopinionated, open source, and correct utilities for aerospace applications.

.. caution::
   This library is a work in progress. The API may not be stable. If you plan to
   use the library, please contact me so I can begin working toward API stability.

Table of Contents
-----------------
.. toctree::
  :maxdepth: 1

  manual/index.rst
  api/index.rst

Goals
-----
* **Unopinionated:** Do not impose constraints on conventions and code
  architecture. Allow integration with legacy code. Provide sensible defaults.
* **Text-book grade documentation:** You should be able to understand the
  algorithms provided, and there limitations, simply by reading the docs.
* **Correct:** Provide sufficient testing to demonstrate trust in the
  correctness of the routines.
* **C++ and Python as first class citizens:** The same algorithms should be
  useable between a trade study script and flight code.