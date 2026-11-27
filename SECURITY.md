# Security policy

Report suspected vulnerabilities privately to the repository maintainers
through GitHub's security reporting feature. Include the affected API, input
conditions, impact and a minimal reproducer when possible. Avoid publishing
exploit details before maintainers have had a reasonable opportunity to
investigate.

Vectrava performs deterministic caller-provided integer and fixed-point
calculations. Applications remain responsible for validating external data,
checking function status results and managing buffer lifetimes.
