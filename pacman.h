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
        if ( j < COLS - 2 ) {
            j += 1;
            if ( matrix[i][j] == '*' || matrix[i][j] == '.' ) {
                return true;
            }
        }
    }
    return false;
}

bool moove(char key, char matrix[ROWS][COLS], Point coord) {
    if ( key == 'w' ) {
        if ( coord.getX() > 0 ) {
            coord.decreaseX();
            if ( matrix[coord.getX()][coord.getY()] == '*' || matrix[coord.getX()][coord.getY()] == '.' ) {
                return true;
            }
        }
    }
    if ( key == 's' ) {
        if ( coord.getX() < ROWS - 1 ) {
            coord.increaseX();
            if ( matrix[coord.getX()][coord.getY()] == '*' || matrix[coord.getX()][coord.getY()] == '.' ) {
                return true;
            }
        }
    }
    if ( key == 'a' ) {
        if ( coord.getY() > 0 ) {
            coord.decreaseY();
            if ( matrix[coord.getX()][coord.getY()] == '*' || matrix[coord.getX()][coord.getY()] == '.' ) {
                return true;
            }
        }
    }
    if ( key == 'd' ) {
        if ( coord.getY() < COLS - 2 ) {
            coord.increaseY();
            if ( matrix[coord.getX()][coord.getY()] == '*' || matrix[coord.getX()][coord.getY()] == '.' ) {
                return true;
            }
        }
    }
    return false;
}

void goBack(char* forward, char* backward) {
    char buffer;
    buffer = *forward;
    *forward = *backward;
    *backward = buffer;
}

void goTwist(char* forward, char* backward, char* left, char* right, char direction) {
    if ( direction == 'l') {
        goBack(forward, left);
        goBack(backward, right);
    }
    if ( direction == 'r' ) {
        goBack(forward, right);
        goBack(backward, left);
    }
}
