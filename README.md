# O.A.L.
https://boscillator.github.io/oal

Open Aerospace Library. Unopinionated, open source, and correct utilities for aerospace applications.


> **THIS SOFTWARE IS CURRENTLY IN ALPHA.** If you plan on using it, please
> contact me so I can begin stabilizing the API. The software is provided
> without warrantee.

## Goals
- **Unopinionated:** Do not impose constraints on conventions and code
  architecture. Allow integration with legacy code. Provide sensible defaults.
- **Text-book grade documentation:** You should be able to understand the
  algorithms provided, and there limitations, simply by reading the docs.
- **Correct:** Provide sufficient testing to demonstrate trust in the
  correctness of the routines.
- **C++ and Python as first class citizens:** The same algorithms should be
  useable between a trade study script and flight code.

## Non-Goals
- **Being a monte-carlo framework:** O.A.L. will never contain code that
  requires a certain structure for your codebase, and instead provides
  utility routines that can be used a-la-cart with your existing
  monte-carlo or <abbr title="Operational Flight Software">OFS</abbr> framework.
- **DO-178B Certification:** This software is not ready for use in
  safety-of-life critical applications. Perhaps this will become a goal in the
  future.
- **Accepting source code contributions:** While I appreciate enthusiasm to
  contribute, I wish to remain the sole contributor to the redistributable
  source of this library as I hope to provide commercial licensing and
  simplify security auditing in the future. I am more than happy to
  accept contributions in the form of bug reports, feature requests,
  improve testing and documentation changes.
