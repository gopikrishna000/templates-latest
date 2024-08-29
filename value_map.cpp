<snippet>
	<content><![CDATA[
	

//Same complexity as map, with some constant factor
//sort based on value, and access based on key
template<typename K, typename V>
struct vmp { //value based map
	set<pair<V, K>> vk; // {val,key}
	map<K, V> kv; //{key,val}
	vmp() {}

	void update(K key, V newval) {
		V oldval = kv[key];
		auto pos = vk.find({oldval, key});
		if (pos != vk.end()) {
			vk.erase(pos);
		}
		vk.insert({newval, key});
		kv[key] = newval;
	}
	V operator[](const K &key) {
		auto it = kv.find(key);
		if (it == kv.end()) return 0;
		return it->second;
	}
	auto begin() {
		return vk.begin();//{val,key}
	}
	auto end() {
		return vk.end();//{val,key}
	}
	void erase(const K key) {
		V val = kv[key];
		kv.erase(key);
		vk.erase({val, key});
	}
	void pop_front() {
		if (!vk.empty()) {
			auto it = vk.begin();
			K key = it->second;
			vk.erase(it);
			kv.erase(key);
		}
	}
	void pop_back() {
		if (!vk.empty()) {
			auto it = prev(vk.end());
			K key = it->second;
			vk.erase(it);
			kv.erase(key);
		}
	}
	unsigned int size(){
		return vk.size();
	}
};
/* Extras:
* if need lower bound value, do it on vk
* if need index based acess, use ordered_pii for vk
* printing just wd(kv,vk);
*/
//warning: for(auto [x,y]:m.vk){//using m.update()} may result in infinite loop in GNUg++20WIN...
//but m.kv works fine... and also first extracting pairs from m.vk and then using m.update() works fine..
// OR just using g++17 works fine

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>value based map</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
