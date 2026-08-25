#include <deque>
#include <vector>

std::vector<int> next_greater_index(const std::vector<int>& values) {
    std::vector<int> answer(values.size(), -1), st;
    for (int i = 0; i < (int)values.size(); ++i) {
        while (!st.empty() && values[st.back()] < values[i]) answer[st.back()] = i, st.pop_back();
        st.push_back(i);
    }
    return answer;
}

std::vector<int> sliding_window_maximum(const std::vector<int>& values, int k) {
    std::deque<int> q; std::vector<int> answer;
    for (int i = 0; i < (int)values.size(); ++i) {
        while (!q.empty() && q.front() <= i - k) q.pop_front();
        while (!q.empty() && values[q.back()] <= values[i]) q.pop_back();
        q.push_back(i); if (i >= k - 1) answer.push_back(values[q.front()]);
    }
    return answer;
}
