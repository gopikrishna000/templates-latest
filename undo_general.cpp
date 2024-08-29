<snippet>
	<content><![CDATA[


//any undo feature
std::vector<std::pair<int &, int>> his;//history
void change(int &x, int y) {
	his.emplace_back(x, x);
	x = y;
}
void undo(int mark) {
	while (int(his.size()) > mark) {
		auto [x,y] = his.back();
		his.pop_back();
		x = y;
	}
}
// whenever assignment operation happens, insteads of doing a = b, call change(a,b);
// using size of "his" as timeline, one can go back to any state.


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>any undo </tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
