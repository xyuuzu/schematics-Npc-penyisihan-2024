#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Task {
    int id;    
    int T;    
    int S;    
    bool operator<(const Task& other) const {
        if (S == other.S) {
            return id > other.id; 
        }
        return S < other.S;  
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Task> tasks(N);
    bool isAllTEqual = true;
    bool isAllSZero = true;
    int firstT;


    for (int i = 0; i < N; ++i) {
        tasks[i].id = i + 1;
        cin >> tasks[i].T >> tasks[i].S;
        if (i == 0) {
            firstT = tasks[i].T;  
        } else if (tasks[i].T != firstT) {
            isAllTEqual = false; 
        }
        if (tasks[i].S == 1) {
            isAllSZero = false;   
        }
    }

    if (isAllTEqual) {

        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            if (a.S == b.S) {
                return a.id < b.id; 
            }
            return a.S > b.S;  
        });

        int currentTime = firstT;
        for (const Task& task : tasks) {
            currentTime += M;
            cout << currentTime << " ";
        }
        cout << endl;
        return 0;
    }


    if (isAllSZero) {
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            if (a.T == b.T) {
                return a.id < b.id; 
            }
            return a.T < b.T; 
        });

    
        int currentTime = 0;
        for (const Task& task : tasks) {
            currentTime = max(currentTime, task.T);
            currentTime += M;
            cout << currentTime << " ";
        }
        cout << endl;
        return 0;
    }

 
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.T < b.T; 
    });

    priority_queue<Task> pq;
    int currentTime = 0;  
    int taskIdx = 0;     
    vector<int> finishTimes(N);  

    while (taskIdx < N || !pq.empty()) {
        while (taskIdx < N && tasks[taskIdx].T <= currentTime) {
            pq.push(tasks[taskIdx]);
            ++taskIdx;
        }

        if (!pq.empty()) {
            Task currentTask = pq.top();
            pq.pop();

            currentTime = max(currentTime, currentTask.T);

            currentTime += M;
            finishTimes[currentTask.id - 1] = currentTime;
        } else {
            currentTime = tasks[taskIdx].T;
        }
    }

    for (int time : finishTimes) {
        cout << time << " ";
    }
    cout << endl;

    return 0;
}
