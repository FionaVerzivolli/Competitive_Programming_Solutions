class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Steps:
        // - Iterate through each element and check if it is a 0, keep track
        // of row number
        // - If it is a zero replace every element in that row to a 0
        // - Keep track of the index i and then iterate through the array
        // - and change the ith element of every row to a 0. need to keep track
        // first and then make the changes to avoid loops

        std::vector<int> rows;
        std::vector<int> columns; // vertical
            int width = matrix[0].size();
            int height = matrix.size();
        
        // get the indeces
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        for(int i = 0; i < rows.size(); i++){ // replace all rows with 0
            for(int j = 0; j < width; j++){
                matrix[rows[i]][j] = 0;
            }
        }
        for(int i = 0; i < columns.size(); i++){
            for(int j = 0; j < height; j++){
                matrix[j][columns[i]] = 0;
            }
        }
    }
};
