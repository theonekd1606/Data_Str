#include <iostream>
using namespace std;

// --- FUNCTION PROTOTYPES ---
void displayArray(int arr[], int size);
void displayMatrix(int mat[2][2]);

int main() {
    int choice;
    
    // 1D Array Variables
    int arr[100], size = 0;
    
    // 2D Matrix Variables
    int A[2][2], B[2][2], res[2][2];

    do {
        cout << "\n1.  Insert Element ";
        cout << "\n2.  Display Array ";
        cout << "\n3.  Search Element ";
        cout << "\n4.  Delete Element ";
        cout << "\n5.  Find Max & Min ";
        cout << "\n6.  Update Element ";
        cout << "\n7.  Matrix Addition (2x2)";
        cout << "\n8.  Matrix Multiplication (2x2)";
        cout << "\n9.  Matrix Transpose (A)";
        cout << "\n10. Generate Identity Matrix";
        cout << "\n0.  Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> choice;
                cout << "Enter position: "; int pos; cin >> pos;
                if (pos < 0 || pos > size) cout << "Invalid pos!";
                else {
                    for (int i = size; i > pos; i--) arr[i] = arr[i-1];
                    arr[pos] = choice;
                    size++;
                }
                break;
            case 2: 
                displayArray(arr, size);
                break;
            case 3: 
                cout << "Search value: "; cin >> choice;
                for (int i = 0; i < size; i++) {
                    if (arr[i] == choice) { cout << "Found at index " << i << endl; break; }
                }
                break;
            case 4: 
                cout << "Enter index to delete: "; cin >> pos;
                if (pos >= 0 && pos < size) {
                    for (int i = pos; i < size - 1; i++) arr[i] = arr[i+1];
                    size--;
                }
                break;
            case 5: 
                if (size > 0) {
                    int ma = arr[0], mi = arr[0];
                    for(int i=1; i<size; i++) {
                        if(arr[i] > ma) ma = arr[i];
                        if(arr[i] < mi) mi = arr[i];
                    }
                    cout << "Max: " << ma << " Min: " << mi << endl;
                }
                break;
            case 6: 
                cout << "Enter index: "; cin >> pos;
                if (pos >= 0 && pos < size) {
                    cout << "New value: "; cin >> arr[pos];
                }
                break;
            case 7: 
                cout << "Enter Matrix A (2x2):\n";
                for(int i=0; i<2; i++) for(int j=0; j<2; j++) cin >> A[i][j];
                cout << "Enter Matrix B (2x2):\n";
                for(int i=0; i<2; i++) for(int j=0; j<2; j++) cin >> B[i][j];
                for(int i=0; i<2; i++)
                    for(int j=0; j<2; j++) res[i][j] = A[i][j] + B[i][j];
                cout << "Result:\n"; displayMatrix(res);
                break;
            case 8: 
                cout << "Enter Matrix A (2x2):\n";
                for(int i=0; i<2; i++) for(int j=0; j<2; j++) cin >> A[i][j];
                cout << "Enter Matrix B (2x2):\n";
                for(int i=0; i<2; i++) for(int j=0; j<2; j++) cin >> B[i][j];
                for(int i=0; i<2; i++) {
                    for(int j=0; j<2; j++) {
                        res[i][j] = 0;
                        for(int k=0; k<2; k++) res[i][j] += A[i][k] * B[k][j];
                    }
                }
                cout << "Multiplication Result:\n"; displayMatrix(res);
                break;

            case 9:
                cout << "Enter Matrix A (2x2):\n";
                for(int i=0; i<2; i++) for(int j=0; j<2; j++) cin >> A[i][j];
                for(int i=0; i<2; i++)
                    for(int j=0; j<2; j++) res[j][i] = A[i][j];
                cout << "Transpose:\n"; displayMatrix(res);
                break;
            case 10: 
                for(int i=0; i<2; i++)
                    for(int j=0; j<2; j++) res[i][j] = (i == j) ? 1 : 0;
                displayMatrix(res);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}
void displayMatrix(int mat[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
