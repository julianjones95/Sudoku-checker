#include <iostream>
using namespace std;

bool checkValidity(int row, int column, bool input[10], string board[9][9]) {

    if(board[row][column] == ".") {
        return true;
    }
    int numberCheck = stoi(board[row][column]);
    if(input[numberCheck] ==false) {
        input[numberCheck] = true;
//        cout << "row Num (valid): " << row << " ";
//        cout << "numCheck: " << numberCheck << " ";
//        cout << "entryCheck: " << input[numberCheck] << endl;
        return true;
    }
    else if (input[numberCheck]==true) {                
        cout << "row Num (invalid): " << row << " ";
        cout << "numCheck: " << numberCheck << " ";
        cout << "entryCheck: " << input[numberCheck] << endl;
        return false;
    }
    return true;
}

bool isValidSudoku(string board[9][9]) {
    for (int l = 0; l < 9; l=l+3) {
        for (int m = 0; m < 9; m=m+3) {
            bool entryCheck[10] = {0,0,0,0,0,0,0,0,0,0};
            for (int i =0+l; i< 3+l; i++) {
                for (int j=0+m; j<3+m; j++) {
                    if(!checkValidity(i,j, entryCheck, board)){
                        cout << "box check error: " << endl; 
                        return false;
                    }

                }

            }
            
        }

    }


    //Checks if the rows and columns are valid
    for (int i =0; i< 9; i++) {
        bool rowEntryCheck[10] = {0,0,0,0,0,0,0,0,0,0};
        bool colEntryCheck[10] = {0,0,0,0,0,0,0,0,0,0};
        for (int j=0; j<9; j++) {
           
            //Check rows
            if(!checkValidity(i,j, rowEntryCheck, board)){
                return false;
            }

            //Check columns
            if(!checkValidity(j,i, colEntryCheck, board)){
                return false;
            }

        }

    }

}

int main() {

 
    string board1[9][9] = 
{{"5","3",".",".","7",".",".",".","."}
,{"6",".",".","1","9","5",".",".","."}
,{".","9","8",".",".",".",".","6","."}
,{"8",".",".",".","6",".",".",".","3"}
,{"4",".",".","8",".","3",".",".","1"}
,{"7",".",".",".","2",".",".",".","6"}
,{".","6",".",".",".",".","2","8","."}
,{".",".",".","4","1","9",".",".","5"}
,{".",".",".",".","8",".",".","7","9"}};

    string board2[9][9] = 
{{"8","3",".",".","7",".",".",".","."}
,{"6",".",".","1","9","5",".",".","."}
,{".","9","8",".",".",".",".","6","."}
,{"8",".",".",".","6",".",".",".","3"}
,{"4",".",".","8",".","3",".",".","1"}
,{"7",".",".",".","2",".",".",".","6"}
,{".","6",".",".",".",".","2","8","."}
,{".",".",".","4","1","9",".",".","5"}
,{".",".",".",".","8",".",".","7","9"}};

    
    string board3[9][9] = 
{{"5","3",".",".","7",".",".",".","."}
,{"6",".",".","1","9","5",".",".","."}
,{".","9","8",".",".",".",".","6","."}
,{"8",".",".",".","6",".",".",".","3"}
,{"4",".",".","8",".","3",".",".","1"}
,{"7","4",".",".","2",".",".",".","6"}
,{".","6",".",".",".",".","2","8","."}
,{".",".",".","4","1","9",".",".","5"}
,{".",".",".",".","8",".",".","7","9"}};

    // Test 1
    cout << "test 1 start: " << endl;
    bool test1 = isValidSudoku(board1);
    
    
    // Test 2
    cout << "test 2 start: " << endl;
    bool test2 = isValidSudoku(board2);


    // Test 3
    cout << "test 3 start: " << endl;
    bool test3 = isValidSudoku(board3);
    
    return 0;
}
