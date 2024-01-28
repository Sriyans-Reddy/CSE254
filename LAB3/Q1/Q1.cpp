#include <bits/stdc++.h>
using namespace std;



void displayMatrix(ofstream& outputFile, string label, vector<vector<long long>> matrix,
                   long long startRow, long long startColumn,
                   long long endRow, long long endColumn) {
    outputFile << endl << label << " =>" << endl;
    for (long long i = startRow; i <= endRow; i++) {
        for (long long j = startColumn; j <= endColumn; j++) {
            outputFile<< matrix[i][j]<<" ";
        }
        outputFile << endl;
    }
    outputFile << endl;
    return;
}

void addMatrices(vector<vector<long long>> matrixA,
                 vector<vector<long long>> matrixB,
                 vector<vector<long long>>& resultMatrix,
                 long long splitIndex) {
    for (auto i = 0; i < splitIndex; i++)
        for (auto j = 0; j < splitIndex; j++)
            resultMatrix[i][j]
                = matrixA[i][j] + matrixB[i][j];
}

vector<vector<long long>> multiplyMatrices(vector<vector<long long>> matrixA,
                                     vector<vector<long long>> matrixB) {
    long long colsA = matrixA[0].size();
    long long rowsA = matrixA.size();
    long long colsB = matrixB[0].size();
    long long rowsB = matrixB.size();

    if (colsA != rowsB) {
        cout << "\nError: The number of columns in Matrix "
                "A must be equal to the number of rows in "
                "Matrix B\n";
        return {};
    }

    vector<long long> resultMatrixRow(colsB, 0);
    vector<vector<long long>> resultMatrix(rowsA, resultMatrixRow);

    if (colsA == 1)
        resultMatrix[0][0] = matrixA[0][0] * matrixB[0][0];
    else {
        long long splitIndex = colsA / 2;

        vector<long long> rowVector(splitIndex, 0);
        vector<vector<long long>> resultMatrix00(splitIndex, rowVector);
        vector<vector<long long>> resultMatrix01(splitIndex, rowVector);
        vector<vector<long long>> resultMatrix10(splitIndex, rowVector);
        vector<vector<long long>> resultMatrix11(splitIndex, rowVector);

        vector<vector<long long>> a00(splitIndex, rowVector);
        vector<vector<long long>> a01(splitIndex, rowVector);
        vector<vector<long long>> a10(splitIndex, rowVector);
        vector<vector<long long>> a11(splitIndex, rowVector);
        vector<vector<long long>> b00(splitIndex, rowVector);
        vector<vector<long long>> b01(splitIndex, rowVector);
        vector<vector<long long>> b10(splitIndex, rowVector);
        vector<vector<long long>> b11(splitIndex, rowVector);

        for (auto i = 0; i < splitIndex; i++)
            for (auto j = 0; j < splitIndex; j++) {
                a00[i][j] = matrixA[i][j];
                a01[i][j] = matrixA[i][j + splitIndex];
                a10[i][j] = matrixA[splitIndex + i][j];
                a11[i][j] = matrixA[i + splitIndex][j + splitIndex];
                b00[i][j] = matrixB[i][j];
                b01[i][j] = matrixB[i][j + splitIndex];
                b10[i][j] = matrixB[splitIndex + i][j];
                b11[i][j] = matrixB[i + splitIndex][j + splitIndex];
            }

        addMatrices(multiplyMatrices(a00, b00),
                    multiplyMatrices(a01, b10),
                    resultMatrix00, splitIndex);
        addMatrices(multiplyMatrices(a00, b01),
                    multiplyMatrices(a01, b11),
                    resultMatrix01, splitIndex);
        addMatrices(multiplyMatrices(a10, b00),
                    multiplyMatrices(a11, b10),
                    resultMatrix10, splitIndex);
        addMatrices(multiplyMatrices(a10, b01),
                    multiplyMatrices(a11, b11),
                    resultMatrix11, splitIndex);

        for (auto i = 0; i < splitIndex; i++)
            for (auto j = 0; j < splitIndex; j++) {
                resultMatrix[i][j] = resultMatrix00[i][j];
                resultMatrix[i][j + splitIndex] = resultMatrix01[i][j];
                resultMatrix[splitIndex + i][j] = resultMatrix10[i][j];
                resultMatrix[i + splitIndex][j + splitIndex] = resultMatrix11[i][j];
            }

        resultMatrix00.clear();
        resultMatrix01.clear();
        resultMatrix10.clear();
        resultMatrix11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return resultMatrix;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the input file" << endl;
        return 1;
    }
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening the output file" << endl;
        return 1;
    }
    long long n;
    inputFile >> n;

    vector<vector<long long>> matrixA, matrixB;
    long long value;
    for (long long i = 0; i < n; i++) {
        vector<long long> row;
        for (long long j = 0; j < n; j++) {
            inputFile >> value;
            row.push_back(value);
        }
        matrixA.push_back(row);
    }

    for (long long i = 0; i < n; i++) {
        vector<long long> row;
        for (long long j = 0; j < n; j++) {
            inputFile >> value;
            row.push_back(value);
        }
        matrixB.push_back(row);
    }
    inputFile.close();

    // displayMatrix(outputFile, "Array A", matrixA, 0, 0, n - 1, n - 1);
    // displayMatrix(outputFile, "Array B", matrixB, 0, 0, n - 1, n - 1);

    vector<vector<long long>> resultMatrix(multiplyMatrices(matrixA, matrixB));

    displayMatrix(outputFile, "Result Array", resultMatrix, 0, 0, n - 1, n - 1);

    outputFile.close();
    return 0;
}