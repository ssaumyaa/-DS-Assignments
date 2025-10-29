#include <iostream>
#include <queue>
using namespace std;

int countStudents(int students[], int sandwiches[], int n) {
    queue<int> q;

    // put all students in queue
    for (int i = 0; i < n; i++)
        q.push(students[i]);

    int i = 0;       // index for sandwiches
    int count = 0;   // how many students in a row didn't eat

    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[i]) {
            // student takes sandwich
            q.pop();
            i++;
            count = 0; // reset failed attempts
        } else {
            // student goes to back
            int temp = q.front();
            q.pop();
            q.push(temp);
            count++;
        }
    }

    return q.size();  // remaining students who couldn't eat
}

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;

    cout << countStudents(students, sandwiches, n);
    return 0;
}
