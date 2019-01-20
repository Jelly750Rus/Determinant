#include <iostream>
#include <math.h>
using namespace std;
int determinant(int *newMatrix, int NewSize){
    if (NewSize == 2){
        return (*(newMatrix))*(*(newMatrix+3))-(*(newMatrix+1))*(*(newMatrix+2));
    }else{
        int det = 0;
        int parametr = 0;
        for (int k = 0; k<NewSize; k++){ //count det using the firsl line
            int SecondMatrix[NewSize-1][NewSize-1]; //create a matrix that is smaller than current

            for (int i = 0; i<NewSize-1; i++){ //add elements to the new matrix
                for (int j = 0; j<NewSize; j++){
                    if (j!=k){
                        SecondMatrix[i][j-parametr]=*(newMatrix+(i+1)*NewSize+j);//we don`t use the first line and we remove column that is equal to current number
                    }else{
                        parametr=1;
                    }
                }
                parametr = 0;
            }

            det = det + *(newMatrix+k)*pow(-1,k+2)*determinant(&SecondMatrix[0][0], NewSize-1);
        }
        return det;
    }
}int main()
{
    int sizeOfMatrica = 0;
    cout << "Input the size of matrix: " << endl;
    cin >> sizeOfMatrica;
    if (sizeOfMatrica <= 0){
        cout << "Wrond size! "<<endl;
        return 0x1;
    }
    int matrica[sizeOfMatrica][sizeOfMatrica];
    for (int i = 0; i<sizeOfMatrica; i++){ //input the first matrix
        cout << "Input " << i+1 << " line: " << endl;
        for (int j = 0; j<sizeOfMatrica; j++){
            cin >> matrica[i][j];
        }
    }
    cout << "Determinant is "<< determinant(&matrica[0][0], sizeOfMatrica);
    return 0;
}
