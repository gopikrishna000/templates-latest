<snippet>
	<content><![CDATA[


//order_of_key(k) :Number of items strictly smaller than k.
//find_by_order : K-th smallest element. (0-index)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int,int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>


/*very very imp error/bug in ordered_multiset:
 * find() method always return set.end();
 * so to erase, use: set.erase(set.upper_bound(x)); 
 * lower_bound works as upper_bound and vice versa.
*/
typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// cout << (o_set.find_by_order(0)) ->first<<" "<<(o_set.find_by_order(0)) ->second<<"\n";
// cout << o_set.order_of_key({4,3})<<"\n";
struct comp { //for ordered_set, sorts based on only first element & uniqueness also based on only first element
	bool operator() (const pair <int , int> &a, const pair <int , int> &b) const {
		return a.first < b.first;
	}
};



]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>ordered set</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
