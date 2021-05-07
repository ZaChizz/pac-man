bool moove(char key, char matrix[ROWS][COLS], int i, int j) {
    if ( key == 'w' ) {
        if ( i > 0 ) {
            i -= 1;
            if ( matrix[i][j] == '*' || matrix[i][j] == '.' ) {
                return true;
            }
        }
    }
    if ( key == 's' ) {
        if ( i < ROWS - 1 ) {
            i += 1;
            if ( matrix[i][j] == '*' || matrix[i][j] == '.' ) {
                return true;
            }
        }
    }
    if ( key == 'a' ) {
        if ( j > 0 ) {
            j -= 1;
            if ( matrix[i][j] == '*' || matrix[i][j] == '.' ) {
                return true;
            }
        }
    }
    if ( key == 'd' ) {
        if ( j < ROWS - 1 ) {
            j += 1;
            if ( matrix[i][j] == '*' || matrix[i][j] == '.' ) {
                return true;
            }
        }
    }
    return false;
}
