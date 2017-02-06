//
//  eulerian_circuit.cpp
//  Eulerian_circuit
//
//  Created by Kyle Stumpff.
//  Copyright (c) 2014 Kyle Stumpff. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;



class Tour {
public:
    stack<int> st;
    struct node
    {
        node *prev;
        node *next;
        int A;
        int B;
    };
    node *head;
    node *tail;
    Tour() {
        head=tail=NULL;
    }
    ~Tour() {
        node *temp;
        while(head != tail) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
    void addEdge(int A, int B) {
        if (head == NULL) {
//            cout << "Adding head node\n";
            head = new node;
            head->A = A;
            head->B = B;
            tail = head;
            tail->prev = head;
            head->next = tail;
        } else {
//            cout << "Adding next node\n";
            tail->next = new node;
            // set new tail's prev to current tail
            tail->next->prev = tail;
            // set tail to the new node
            tail = tail->next;
            tail->next = NULL;
            tail->A = A;
            tail->B = B;
        }
    }
    void printList() {
        //cout << "The tour: ";
        node *current = head;
        int counter = 0;
        while (current->next != NULL) {
            //cout << current->A << "-" << current->B << " ";
            st.push(current->A + 1);
            st.push(current->B + 1);
            current = current->next;
            counter++;
        }

        while(st.size() > 0){
            cout<<st.top()<<" ";
            st.pop();
            cout<<st.top()<<endl;
            st.pop();
        }
        //cout << endl << endl;
//        cout << endl << "counter: " << counter << endl;;
    }
};

void printStartScreen() {
    cout << "/////////////////////////////////////////////////////////////\n";
    cout << "// Welcome to the Eulerian Tour!\n";
    cout << "//\n";
    cout << "// You will be asked to input the number of verticies\n";
    cout << "// in the graph and also the edges that connect the verticies.\n";
    cout << "//\n";
    cout << "// All verticies must have an even degree.\n";
    cout << "/////////////////////////////////////////////////////////////\n\n";
}

void printMatrix(int matrix[], int verticies, int size) {
    cout << "|";
    for (int i = 0 ; i < size ; i++) {
        cout << matrix[i] << "|";
        if ((i%verticies == verticies-1) && (i != size-1))
            cout << endl << "|";
    }
    cout << endl << endl;
}

int numUnusedEdges(int U[], int verticies) {
    int count = 0;
    for ( int i = 0 ; i <= verticies ; i++) {
        count += U[i];
    }
    return count;
}

int findPath(int matrix[], int U[], int verticies, int startNode) {
    int endNode = -1;
    int value = 0;
    // int unusedEdges = numUnusedEdges(U, verticies);
    for ( int i = verticies-1 ; i > 0 ; i--) {
        if (matrix[(verticies*startNode)+i] > value) {
            value = matrix[(verticies*startNode)+i];
            endNode = i;
        }

    }
    return endNode;
}

void findTour(int matrix[], int U[], int verticies) {
    Tour tour;
    int startNode = 0;
    int endNode = 0;
    bool finished = false;
    while (!finished) {
        // Start at node 0 and find a path to a different node
        endNode = findPath(matrix, U, verticies, startNode);
//        cout << "Start: " << startNode << " End: " << endNode << endl;
        if (endNode == -1) {
            finished = true;
            endNode = 0;
        }
        // Add node to linked list
        tour.addEdge(startNode, endNode);
        if (startNode != endNode) {
            // Decrement A's B
            matrix[(verticies*startNode)+endNode]--;
            // Decrement B's A
            matrix[(verticies*endNode)+startNode]--;
            // Revise U
            U[startNode]--;
            U[endNode]--;
            // repeat until we return to node 0
            startNode = endNode;
        }
    }

    tour.addEdge(endNode, 0);

    // print path
    tour.printList();
    // print remaining matrix

    // cout << "Remaining Matrix:\n\n";
    // printMatrix(matrix, verticies, verticies*verticies);
}

int main()
{

    //printStartScreen();

    int verticies = 0;
    //cout << "Enter number of vertices: ";
    cin >> verticies;
    set<int> myset[verticies];

    // if (verticies < 2) {
    //     cout << "What in the I don't even! Invalid input...\n\n";
    //     return 0;
    // }
    int matrix_size = verticies*verticies;
    int *matrix = new int[matrix_size];
    int *U = new int[verticies];

    // Initialize matrix to 0
    for (int i = 0 ; i < verticies ; i++) {
        matrix[i] = 0;
    }

    int A = 0;
    int B = 0;
    int edge_num = 0;
    cin>>edge_num;
    //cout << "Enter two numbers to create an edge between two vertices (0-" << verticies-1 << ")\n";
    //cout << "Enter -1 to finish\n";
    // while (true) {
    //     while (true) {
            //cout << "1: ";
            // cin >> A;
            // if (A == -1) {
            //     if (edge_num < verticies) {
            //         cout << "You need to add more verticies...\n";
            //     }
            //     break;
            // }
            //cout << "2: ";
            //cin >> B;\

    for (int i = 0; i < edge_num; ++i)
    {
        cin>>A;
        cin>>B;
        myset[A-1].insert(B);
        myset[B-1].insert(A);
        A--;
        B--;    

    
            if (A >= 0 && A < verticies) {
                if (B >= 0 && B < verticies) {
                    // Increment both values in adjacency matrix

                    // Increment A's B
                    matrix[(verticies*A)+B]++;
                    U[A]++;
                    // Increment B's A
                    matrix[(verticies*B)+A]++;
                    U[B]++;

                    //edge_num++;
                } //else {cout << "Vertex 2 was invalid\n";}
            } //else {cout << "Vertex 1 was invalid\n";}
        //}
    }
    //     if (A == -1 && edge_num >= verticies) { break; }
    // }

    // cout << "\nAdjacency Matrix:\n\n";
    // printMatrix(matrix, verticies, verticies*verticies);

    // cout << "Starting U[i]: ";
    // printMatrix(U, verticies, verticies);

    int ans = 1;
    for (int i = 0; i < edge_num; ++i)
    {
        if(myset[i].size() == 0 || myset[i].size() % 2 != 0)
            ans = 0;
    }
    
    if(ans == 0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        findTour(matrix, U, verticies);
    }


    
    
    // cout << "Ending U[i]: ";
    // printMatrix(U, verticies, verticies);

    return 0;
}