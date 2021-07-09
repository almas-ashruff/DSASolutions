// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], 
// obtaining a profit of profit[i]. You're given the startTime, endTime and profit arrays, 
// return the maximum profit you can take such that there are no two jobs in the subset with 
// overlapping time range.
// If you choose a job that ends at time X you will be able to start another job that starts at time X.


// https://leetcode.com/problems/maximum-profit-in-job-scheduling/


#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& a, int target)
{
	int left = 0;
	int right = a.size() - 1;
	while (left + 1 < right)
	{
		int mid = (left + right) / 2;
		if (a[mid] < target)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	if (a[left] == target)
	{
		return left;
	}
	return right;
}
void preSort(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
	struct Job
	{
		int startTime;
		int endTime;
		int profit;
	};
	int n = startTime.size();
	vector<Job> jobs(n, Job());
	// copy to struct
	for (int i = 0; i < n; ++i)
	{
		jobs[i].startTime = startTime[i];
		jobs[i].endTime = endTime[i];
		jobs[i].profit = profit[i];
	}
	// sort based on startTime
	sort(jobs.begin(), jobs.end(), [](const Job& lhs, const Job& rhs)->bool
	{
		return lhs.startTime < rhs.startTime;
	});
	// copy back to array
	for (int i = 0; i < n; ++i)
	{
		startTime[i] = jobs[i].startTime;
		endTime[i] = jobs[i].endTime;
		profit[i] = jobs[i].profit;
	}
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
	int n = startTime.size();
	// sort based on startTime
	preSort(startTime, endTime, profit);
	// max profit we can get for now, if we take job from last to first
	vector<int> p(n, 0);
	// only take the last one
	p[n - 1] = profit[n - 1];
	for (int i = n - 2; i >= 0; --i)
	{
		int currentEndTime = endTime[i];
		// if we take the current job, the max profit we can get after the endTime of the current job
		int profitAfterEnd = 0;
		if (currentEndTime <= startTime[n - 1])
		{
			int idx = binarySearch(startTime, currentEndTime);
			profitAfterEnd = p[idx];
		}
		// Try to maximize the current profit
		// Profit if take the current job = combine the max profit after the current job's end with the current profit
		// Profit if not take the current job = last profit
		if (profitAfterEnd + profit[i] > p[i + 1])
		{
			// take
			p[i] = profitAfterEnd + profit[i];
		}
		else
		{
			// not take
			p[i] = p[i + 1];
		}
	}
	return p[0];
}