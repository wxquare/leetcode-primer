#!/usr/bin/env bash
set -euo pipefail

root_dir=$(cd "$(dirname "$0")/../.." && pwd)
templates=(
  union_find.cc
  graph_bridges.cc
  graph_zero_one_bfs.cc
  heavy_light_decomposition.cc
  tree_rerooting_dp.cc
  sparse_table.cc
  monotonic_structures.cc
  manacher.cc
  z_function.cc
  min_cost_max_flow.cc
  persistent_segment_tree.cc
  linear_basis.cc
  matrix_exponentiation.cc
  coordinate_compression.cc
  fast_io_and_debug.hpp
)

for template in "${templates[@]}"; do
  if [[ "$template" == *.hpp ]]; then
    c++ -std=c++17 -include "$root_dir/template/$template" -x c++ -fsyntax-only /dev/null
  else
    c++ -std=c++17 -x c++ -fsyntax-only "$root_dir/template/$template"
  fi
done

c++ -std=c++17 "$root_dir/template/tests/template_smoke.cc" -o /tmp/leetcode_primer_template_smoke
/tmp/leetcode_primer_template_smoke
