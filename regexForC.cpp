#include <iostream>
#include <utility>
#include <vector>
#include <regex>
using namespace std;

void regexForC(vector<pair<string, vector<string> > >* matchAndGroups, string str, string regexExpression, int groupAmount = 0){
	regex exp(regexExpression);
	smatch res;
	// Find the number of group in regex expression if it's not being specified
	if (groupAmount == 0){
		regex groupMatchRe("[(].*?[)]");
		string tmpRegexExpression = regexExpression;
		while (regex_search(tmpRegexExpression, res, groupMatchRe)) {
	        groupAmount++;
	        tmpRegexExpression = res.suffix();;
	    }
    }
    // Find all the matches result together with corresponding groups
    while (regex_search(str, res, exp)) {
    	vector<string> groupsVector;
    	(*matchAndGroups).push_back(make_pair(res[0], groupsVector));
        for (int i = 1; i <= groupAmount; i++){
        	(*matchAndGroups)[(*matchAndGroups).size() - 1].second.push_back(res[i]);
        }
        str = res.suffix();;
    }
}

//Sample test for regexForC function
int main(){
	string str = "<tag4 name = \"Name4\" text = \"Super\">";
	string regexExpression = " (.*?) = \"(.*?)\"";
	vector<pair<string, vector<string> > > matchAndGroups;
	regexForC(&matchAndGroups, str, regexExpression, 2);
    for (const auto &p : matchAndGroups) {
	    cout << "MATCH:" << p.first << endl;
	    cout << "GROUPS:" << endl;
	    for (int i = 0; i < p.second.size(); i++){
	    	cout << i;
	    	cout << "\t" << p.second.at(i) << endl;
	    }
	    cout << endl;
	}
}