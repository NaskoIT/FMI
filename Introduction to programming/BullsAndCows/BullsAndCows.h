const int SECRET_NUMBER_MAX_LENGTH = 4;
const int RESULT_LENGTH = 2;
const int SECRET = 5819;

void localGetScore(int *currentSuggestion, int *secret, int *result) {
    result[0] = 0;
    result[1] = 0;

    for (unsigned int i = 0; i < SECRET_NUMBER_MAX_LENGTH; i++) {
        if (currentSuggestion[i] == secret[i]) {
            result[0]++;
        } else {
            for (unsigned int j = 0; j < SECRET_NUMBER_MAX_LENGTH; j++)
                if (currentSuggestion[i] == secret[j]) {
                    result[1]++;
                }
        }
    }
}

int *localToArray(int number) {
    int *array = new int[SECRET_NUMBER_MAX_LENGTH];

    for (int i = 3; i >= 0; i--) {
        array[i] = number % 10;
        number /= 10;
    }

    return array;
}

int *tryGuess(int number) {
    int *result = new int[RESULT_LENGTH];
    localGetScore(localToArray(number), localToArray(SECRET), result);
    return result;
}