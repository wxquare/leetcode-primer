#include <cassert>
#include <string>
#include <tuple>
#include <vector>

#include "data_structure_union_find_template.cc"
#include "graph_bridges.cc"
#include "graph_zero_one_bfs.cc"
#include "heavy_light_decomposition.cc"
#include "tree_rerooting_dp.cc"
#include "sparse_table.cc"
#include "monotonic_structures.cc"
#include "manacher.cc"
#include "z_function.cc"
#include "min_cost_max_flow.cc"
#include "persistent_segment_tree.cc"
#include "linear_basis.cc"
#include "matrix_exponentiation.cc"
#include "coordinate_compression.cc"
#include "fast_io_and_debug.hpp"

int main() {
    UnionFind uf(3); assert(uf.unite(0, 1) && uf.connected(0, 1) && uf.count() == 2);
    BridgeAndCutVertex bridge(3); bridge.add_edge(0, 1); bridge.add_edge(1, 2); bridge.build(); assert(bridge.bridges().size() == 2);
    assert(zero_one_bfs(3, {{0, 1, 0}, {1, 2, 1}}, 0)[2] == 1);
    HeavyLightDecomposition hld(3); hld.add_edge(0, 1); hld.add_edge(1, 2); hld.build(); assert(!hld.path_segments(0, 2).empty());
    std::vector<std::vector<int>> tree{{1}, {0, 2}, {1}}; assert(sum_of_distances_in_tree(3, tree) == std::vector<long long>({3, 2, 3}));
    assert(SparseTableMin({3, 1, 2}).query(0, 2) == 1);
    assert(next_greater_index({2, 1, 3}) == std::vector<int>({2, 2, -1}));
    assert(sliding_window_maximum({1, 3, 2}, 2) == std::vector<int>({3, 3}));
    assert(longest_palindromic_substring("babad").size() == 3);
    assert(z_function("aaaa") == std::vector<int>({4, 3, 2, 1}));
    MinCostMaxFlow flow(2); flow.add_edge(0, 1, 2, 3); auto flow_result = flow.flow(0, 1); assert(flow_result.first == 2 && flow_result.second == 6);
    PersistentSegmentTree pst(5); pst.append(2); pst.append(1); assert(pst.kth(0, 2, 1) == 1);
    LinearBasis basis; basis.insert(3); basis.insert(5); assert(basis.max_xor() == 6 && basis.representable(6));
    Matrix fibonacci{{1, 1}, {1, 0}}; assert(matrix_power(fibonacci, 5, 1000000007LL)[0][1] == 5);
    CoordinateCompression<int> compression({30, 10, 30, 20}); assert(compression.size() == 3 && compression.index(20) == 1);
    fast_io(); debug(0);
}
