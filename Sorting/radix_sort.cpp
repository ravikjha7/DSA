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

// Radix Sort Algorithm
// Very similar to Bucket Sort
// Just makes an array of 10 size
// Performs no of digits times operation
// Time Complexity : O(N)
// Space Complexity : O(N)
void radixSort(int arr[],int n) {
    int maxm = 0;
    for(int i = 0; i < n; i++) maxm = max(maxm,arr[i]);
    int count = 0;
    int temp2 = maxm;
    while(maxm > 0) {
        maxm /= 10;
        count++;
    }

    int power = 0;
    while(count--) {
        Node* bucket[10] = {NULL};
        for(int i = 0; i < n; i++) {
            Node* temp = new Node(arr[i]);
            int index = (arr[i]/pow(10,power));
            index %= 10;
            if(bucket[index] == NULL) {
                bucket[index] = temp;
            } else {
                Node* p = bucket[index];
                while(p->link != NULL) p = p->link;
                p->link = temp;
            }
        }
        int j = 0;
        for(int i = 0; i < 10; i++) {
            if(bucket[i] != NULL) {
                Node* p = bucket[i];
                while(p!=NULL) {
                    arr[j++] = p->data;
                    p = p->link;
                }
            }
        }
        power++;
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
    radixSort(arr,n);
    printArray(arr, n);
    return 0;
}