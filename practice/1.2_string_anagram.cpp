// read from file
// creat map
// print map
// write to file (log?)

#include <iostream>    //which to be include in c?
#include <fstream>     //which to be include in c?
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	char *dictname = argv[1];
	ifstream dict;
	string str;
	set<string> dict_set;
	multimap<string, string> dict_map;
	
	dict.open(dictname, ifstream::in);
	if(!dictname) {
		cerr << "can't open file;" << endl;
		return -1;
	}
	while(getline(dict, str)) {
		string sort_str = str;
		sort(sort_str.begin(), sort_str.end());
		dict_map.insert(make_pair(sort_str, str));
		dict_set.insert(sort_str);
	}
	dict.close();
	dict.clear();
	
	ofstream ret_dict("sort_dict");
	if(!ret_dict) {
		cerr <<"ERROR happen;" << endl;
		return -2;
	}
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> ret_pair;
	for(set<string>::iterator s_iter = dict_set.begin(); s_iter != dict_set.end(); ++s_iter) {
		if(dict_map.count(*s_iter) > 1) {
			ret_pair = dict_map.equal_range(*s_iter);
			for(multimap<string, string>::iterator iter = ret_pair.first;  iter != ret_pair.second; ++iter)
				ret_dict << iter->second << ' ' << endl;
        }
	}
	ret_dict.close();
	ret_dict.clear();
	
	return 0;
}
//test
