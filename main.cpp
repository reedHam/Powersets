#include <iostream>
#include <vector>
#include <stack>


using namespace std;

vector<vector<int>> powerSet(vector<int> setOrg){
    int currentElement;
    stack<int> elements;
    vector<vector<int>> setStream;
    vector<vector<int>> setStreamCpy;
    vector<int> currentSet;

    //sets the elements in the stack to the elements in the vector in reverse order
    for(int i = 0; i < setOrg.size(); i++){
        elements.push(setOrg[i]);
    }

    //fill queue with the empty set
    setStream.push_back(currentSet);

    //set a copy of current stack
    //pop off element from stack
    //pop off first element from queue
    //union with the int from the stack
    //add to copy of queue
    //LOOP
    while(!elements.empty()){
        setStreamCpy = setStream; //copy current queue

        currentElement = elements.top();
        elements.pop();// remove the element from the stack

        while(!setStream.empty()){ //while the queue is not empty
            currentSet = setStream.front(); //get the first element from the queue
            setStream.erase(setStream.begin());

            currentSet.push_back(currentElement); //add the current element to the set

            setStreamCpy.push_back(currentSet); //add the set to the queue
        }

        setStream = setStreamCpy;
    }

    return setStream;

}

void print(vector<vector<int>> result){
    for (int i = 0; i < result.size(); i++){
        cout << "{";
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j];
            if (j != result[i].size() - 1){
                cout << ", ";
            }
        }
        if (i == result.size() - 1){
            cout << "}";
        } else {
            cout << "}, ";
        }
    }
}

int main()
{
    vector<int> test;
    for (int i = 1; i <= 10; i++){ test.push_back(i * 10); } //change the length of the for loop to test for different values

    vector<vector<int>> result;

    print(powerSet(test));
}
