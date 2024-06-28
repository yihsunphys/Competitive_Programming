#include <bits/stdc++.h>

int w[9][9];
int d[9];
int parent[9];
int source;
void bellman_ford() {
    for(int i = 0; i < 9; i++) 
      d[i] = 1e9;
    d[source] = 0;
    parent[source] = source;

    for(int i = 0; i < 9; i++) {
        for(int a = 0; a < 9; a++) {
            for(int b = 0; b < 9; b++) {
                if(d[a] != 1e9 && w[a][b] != 1e9) {
                    if(d[a] + w[a][b] < d[b]){
                        d[b] = d[a] + w[a][b];
                        parent[b] = a;
                    }    
                }
            }
        }
    }
}

bool negative_cycle(){
	for (int a=0; a<9; ++a)
		for (int b=0; b<9; ++b)
			if (d[a] != 1e9 && w[a][b] != 1e9)
				if (d[a] + w[a][b] < d[b])
					return true;
	return false;
}