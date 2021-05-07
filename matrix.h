void matrixScanChar(FILE *in, char matrix[ROWS][COLS]) {
    for ( int row = 0; row < ROWS; row++ ) {
        for ( int col = 0; col < COLS; col++ ) {
            fscanf(in, "%c", &matrix[row][col]);
        }
    }
}
