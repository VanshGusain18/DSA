// Brute Approch

double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<int> howmany(n - 1, 0);
    for (int i = 1; i <= k; i++)
    {
        double maxlen = -1;
        int maxind = -1;
        for (int j = 0; j < n - 1; j++)
        {
            double seclen = (arr[j + 1] - arr[j]) / (howmany[j] + 1.0);
            if (seclen > maxlen)
            {
                maxlen = seclen;
                maxind = j;
            }
        }
        howmany[maxind]++;
    }
    double maxans = -1;
    for (int i = 0; i < n - 1; i++)
    {
        double seclen = (arr[i + 1] - arr[i]) / (howmany[i] + 1.0);
        maxans = max(seclen, maxans);
    }
    return maxans;
}

// Better Approch

#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<int> howmany(n - 1, 0);
    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        double seclen = arr[i + 1] - arr[i];
        pq.push({seclen, i});
    }
    for (int i = 0; i < k; i++)
    {
        auto tp = pq.top();
        pq.pop();
        int ind = tp.second;
        howmany[ind]++;
        double seclen = (arr[ind + 1] - arr[ind]) / (howmany[ind] + 1.0);
        pq.push({seclen, ind});
    }
    return pq.top().first;
}

//Optimal Solution

#include <bits/stdc++.h>

int placestation(double dist, vector<int>& arr)
{
	int n=arr.size();
	int cnt=0;
	for(int i=0; i<n-1; i++)
	{
		int inbtw=(arr[i+1]-arr[i])/dist;
		if((inbtw * dist)==arr[i+1]-arr[i])
		{
			inbtw--;
		}
		cnt+=inbtw;
	}
	return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	int n=arr.size();
	double low=0,high=0;
	for(int i=0; i<n-1; i++)
	{
		high=max((double)arr[i+1]-arr[i],high);
	}
	double diff=1e-6;
	while(high-low>diff)
	{
		double mid=(high+low)/2.0;
		int station=placestation(mid, arr);
		if(station>k)
			low=mid;
		else high=mid;
	}
	return high;
}
