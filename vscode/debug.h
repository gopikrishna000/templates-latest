void dbg_print(int x) { cerr << x; }
void dbg_print(long x) { cerr << x; }
void dbg_print(long long x) { cerr << x; }
void dbg_print(unsigned x) { cerr << x; }
void dbg_print(unsigned long x) { cerr << x; }
void dbg_print(unsigned long long x) { cerr << x; }
void dbg_print(float x) { cerr << x; }
void dbg_print(double x) { cerr << x; }
void dbg_print(long double x) { cerr << x; }
void dbg_print(char x) { cerr << '\'' << x << '\''; }
void dbg_print(const char *x) { cerr << '\"' << x << '\"'; }
void dbg_print(const string &x) { cerr << '\"' << x << '\"'; }
void dbg_print(bool x) { cerr << (x ? "true" : "false"); }
void dbg_print(const vector<int> &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), dbg_print(i);
  cerr << "}";
}

template <typename T, typename V> void dbg_print(const pair<T, V> &x) {
  cerr << '{';
  dbg_print(x.first);
  cerr << ',';
  dbg_print(x.second);
  cerr << '}';
}
template <typename T> void dbg_print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), dbg_print(i);
  cerr << "}";
}

template <typename T> void dbg_print(stack<T> st) {
  while (!st.empty()) {
    cerr << st.top() << " ";
    st.pop();
  };
}
template <typename T> void dbg_print(queue<T> st) {
  while (!st.empty()) {
    cerr << st.front() << " ";
    st.pop();
  };
}
template <typename T> void dbg_print(deque<T> st) {
  while (!st.empty()) {
    cerr << st.front() << " ";
    st.pop_front();
  };
}

void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  dbg_print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

/*------------time--------------*/
double __start_time = 0;
void __stime() {
#pragma GCC diagnostic ignored "-Wconversion"
  __start_time = 1.0 * clock() / CLOCKS_PER_SEC;
}

void __etime() {
#ifndef ONLINE_JUDGE
#pragma GCC diagnostic ignored "-Wconversion"
  cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC - __start_time)
       << " s.\n";
#endif
}
/*------------time--------------*/

#define wd(x...)                                                               \
  cerr << "[" << #x << "] = [";                                                \
  _print(x)
