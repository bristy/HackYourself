
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define mp make_pair

using namespace std;
typedef pair<int, int > PII;
// }}}

class PalindromeMatrix{
public:
	int minChange(vector <string> A, int rowCount, int columnCount){
		
        int ret = 1e9;
        int n = A.size();
        int m = A[0].size();

        int pcol[m];
        int prow[n];

        REP(i, m){
            pcol[i] = (m-i-1 < columnCount);
        }

        do{
            REP(j, n){
                prow[j] = (n-j-1 < rowCount);
            }

            do{
                int cost = 0;
                int visited[15][15] = {{0}};
                REP(i, n){
                    REP(j, m){
                        if(visited[i][j] == 0){
                            // not visited
                            int o = 0;
                            int z = 0;

                            stack<PII> stack;
                            stack.push(mp(i, j));
                            while(!stack.empty()){
                                PII curr = stack.top();
                                stack.pop();
                                int x = curr.first;
                                int y = curr.second;
                                if(visited[x][y] == 0){
                                    visited[x][y] = 1;
                                    z += (A[x][y] == '0');
                                    o += (A[x][y] == '1');

                                    if(pcol[y]){
                                        stack.push(mp(n-x-1, y));
                                    }

                                    if(prow[x]){
                                        stack.push(mp(x, m - y - 1));
                                    }
                                }


                            }

                            cost += min(o,z);
                        }
                    }
                }

                ret = min(ret, cost);
            
            } while(next_permutation(prow, prow+n));
        }while(next_permutation(pcol, pcol+m));
        return ret;
	}
};

