class StoryFromTCO {
public:
	int minimumChanges(vector <int> places, vector <int> cutoff) {
		n = places.size();
		For(i,1,n) A[i] = MP(cutoff[i - 1], places[i - 1]);
		sort(A + 1, A + n + 1);
		multiset<int> S;
		int ans = 0;
		For(i,1,n) if (A[i].FI < A[i].SE) {
			++ans;
			if (!S.empty()) {
				int have_best = *S.begin();
				if (have_best <= A[i].FI) {
					S.erase(S.begin());
					S.insert(A[i].SE);
					continue ;
				}
			}
			bool solved = false ;
			Cor(j,n,i + 1) if (A[j].SE <= A[i].FI) {
				A[j].SE = INF;
				S.insert(A[i].SE);
				solved = true; 
				break ;
			}
			if (!solved) return -1;
		}
		return ans;
	}
};
