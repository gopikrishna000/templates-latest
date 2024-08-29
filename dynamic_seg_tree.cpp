<snippet>
	<content><![CDATA[

struct Vertex {
	int left, right;
	int sum = 0;
	int lazy = 0;
	int neutral = 0;
	Vertex *left_child = nullptr, *right_child = nullptr;

	Vertex(int lb, int rb) {
		left = lb;
		right = rb;
	}

	int joinDeltas(int oldDelta, int newDelta) {
		return oldDelta + newDelta;
	}

	int joinValueWithDelta(int value, int delta, int length) {
		return value + length * delta;
	}

	void push() { //own
		int tm = (left + right) / 2;
		left_child->sum = joinValueWithDelta(left_child->sum, lazy , tm - left);
		left_child->lazy = joinDeltas(left_child->lazy, lazy);
		right_child->sum = joinValueWithDelta(right_child->sum, lazy, right-tm);
		right_child->lazy = joinDeltas(right_child->lazy, lazy);
		lazy = 0;
	}

	void extend() {
		if (!left_child && left + 1 < right) {
			int t = (left + right) / 2;
			left_child = new Vertex(left, t);
			right_child = new Vertex(t, right);
		}
	}

	void add(int k, int x) {
		extend();
		sum += x;
		if (left_child) {
			push();
			if (k < left_child->right)
				left_child->add(k, x);
			else
				right_child->add(k, x);
		}
	}

	int get_sum2(int lq, int rq) {
		if (lq >= rq) return neutral;
		if (lq <= left && right <= rq)
			return sum;
		if (max(left, lq) >= min(right, rq))
			return neutral;
		extend();
		push();
		return left_child->get_sum2(lq, rq) + right_child->get_sum2(lq, rq);
	}

	void update2(int lq, int rq, auto addend) { //own
		if (lq >= rq) return;
		extend();
		if (!left_child) {assert((lq <= left && right <= rq ) || max(left, lq) >= min(right, rq));}
		if (lq <= left && right <= rq) {
			sum += (right - left) * addend;
			lazy += addend;
		}
		else if (max(left, lq) >= min(right, rq)) {
			//do ntg
		}
		else {
			push();
			sum += (min(right, rq) - max(left, lq)) * addend;
			left_child->update2(lq, rq, addend);
			right_child->update2(lq, rq, addend);
		}
	}
	int query(int lq, int rq) {return get_sum2(lq, rq + 1);}
	void update(int lq, int rq, auto addend) {update2(lq, rq + 1, addend);}
};
/* [lb,rb)
*dont forget to intilaise lb,rb;
* get_sum2&update2 => [); but query&update => [inclusive]
* ~lb and rb can be any range, like 1-based or 2-based index;~
*/
/* Avoid initial range as [a,b] but rather keep [0,N]
cause keeping former and updating or querying out of range cause undefined behaviour
also no use of keeping former, as it just mean consering subset/subrange of later range
*/



]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>dynamic segment tree</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
