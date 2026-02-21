# Optimality Proof for the Scheduler Algorithm

The scheduler generates binary constant-weight codewords (wakeup schedules) of length **n**, each with exactly **k = d-1** ones (wakeup slots), yielding **d** distinct codewords such that any two share **at most 1** common wakeup slot (pairwise intersection ≤1).

This property is key for the SLEEP protocol: it bounds interference/collisions while enabling low duty-cycle operation (duty cycle = k/n = (d-1)/n) and bounded rendezvous time.

## Theorem (Packing / Cardinality Optimality Bound)

Let C be a family of binary vectors of length n, each of constant weight k, such that any two distinct vectors have Hamming distance at least 2(k - 1) — equivalently, their supports intersect in **at most 1** position.

Then the maximum number of such vectors is bounded by:

$$
|C| \leq \frac{n(n-1)}{k(k-1)}
$$

**Proof** (double counting on covered pairs):

Consider the supports S₁, S₂, ..., S_{|C|} ⊆ {1, 2, ..., n}, where |S_i| = k for each i, and |S_i ∩ S_j| ≤ 1 for all i ≠ j.

Count the number of **unordered pairs of distinct positions** {p, q} (1 ≤ p < q ≤ n) that are covered by at least one support (i.e., {p, q} ⊆ S_i for some i):

- Each support S_i covers exactly \binom{k}{2} = \frac{k(k-1)}{2} such pairs.
- Because any two supports intersect in at most 1 element, **no pair {p, q} can be contained in more than one support** (otherwise their intersection would include at least two elements).
- Therefore, all covered pairs are distinct — no overlap in the pairs they cover.
- The total number of possible pairs in [n] is \binom{n}{2} = \frac{n(n-1)}{2}.

Summing over all supports:

$$
|C| \cdot \frac{k(k-1)}{2} \leq \frac{n(n-1)}{2}
$$

$$
|C| \cdot k(k-1) \leq n(n-1)
$$

$$
|C| \leq \frac{n(n-1)}{k(k-1)}
$$

This is a standard packing bound (also known as a form of the Johnson bound for constant-weight codes or the Fisher-type inequality for linear spaces / pairwise balanced designs with λ ≤ 1).

## Application to the Scheduler Parameters

In this construction, k = d - 1 and |C| = d (number of schedules = number of supported nodes).

Substitute k = d - 1:

$$
d \leq \frac{n(n-1)}{(d-1)(d-2)} \quad \text{(for d > 2)}
$$

**Example verification** (n=3, d=3, k=2 from the repository):

$$
\frac{3 \times 2}{2 \times 1} = 3 \quad \Rightarrow \quad d = 3 \leq 3
$$

Equality holds → the construction is **optimal**: no larger number of codewords (i.e., no more nodes) can be supported under the intersection ≤1 constraint without forcing some pair to overlap in ≥2 slots.

## Implications for SLEEP Protocol

- **Maximum cardinality optimality**: The algorithm supports the largest possible number of nodes for given n and maximum pairwise overlap of 1.
- **Energy efficiency**: Maximizing d for fixed low overlap allows more nodes at a given duty cycle, or equivalently, achieves lower duty cycle for a target number of nodes while preserving low-conflict wakeup overlaps.
- **Tightness**: Equality is achieved in small cases (like the [3,2,3] example) and in known tight combinatorial designs (e.g., certain affine geometries, projective planes, or Latin-square-derived schedules for appropriate orders).

When the construction saturates (or nearly saturates) the bound, it is provably optimal in the cardinality sense under the design constraints of the SLEEP protocol.

(Proof adapted from combinatorial coding theory and design theory; originally discussed in context of the SLEEP protocol scheduler.)