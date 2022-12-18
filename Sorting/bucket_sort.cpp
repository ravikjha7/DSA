#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
    public :
    int data;
    Node *link;
    Node(int data)
    {
        this->data = data;
        link = NULL;  
    }
};

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Bucket Sort Algorithm
// Very similar to Count Sort
// Stores list of elements rather than freqeuncy
// Time Complexity : O(N)
// Space Complexity : O(M+N)
void bucketSort(int arr[],int n) {
    int maxm = 0;
    for(int i = 0; i < n; i++) maxm = max(maxm,arr[i]);
    Node* bucket[maxm+1] = {NULL};
    for(int i = 0; i < n; i++) {
        Node* temp = new Node(arr[i]);
        if(bucket[arr[i]] == NULL) {
            bucket[arr[i]] = temp;
        } else {
            Node* p = bucket[arr[i]];
            while(p->link != NULL) p = p->link;
            p->link = temp;
        }
    }
    int j = 0;
    for(int i = 0; i < maxm+1; i++) {
        if(bucket[i] != NULL) {
            Node* p = bucket[i];
            while(p!=NULL) {
                arr[j++] = p->data;
                p = p->link;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArray(arr, n);
    bucketSort(arr,n);
    printArray(arr, n);
    return 0;
}