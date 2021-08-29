int read_text(char str[], int size, int flag);

int main() {
    char str[100], key[26];
    int i, j, len, found;
    printf("enter text : ");
    len = read_text(str, sizeof(str), 1);

    do {
        printf("enter key (%d different characters):  ", 26);
        read_text(key, sizeof(key), 1);
        found = 0;
        for (i = 0; i < 26; i++) {
            for (j = i + 1; j < 26; j++) {
                if (key[i] == key[j])//sto key[j] apothikevwntai ta apokriptografimena grammata
                {
                    found = 1;
                    printf("enter characters should be different\n");
                    break;
                }
            }
            if (found == 1) {
                break;
            }
        }
    } while (found != 0);
    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = key[str[i] - 'a'];//afaireis ton xarakthra apo to str[i]
            // gia na pareis to stoixeio stwn pinaka key[j]
        }
    }
    printf("encrypted text : %s\n", str);
    for (i = 0; i < len; i++) {
        for (j = 0; j < 26; j++) {
            if (str[i] == key[j]) {
                str[i] = 'a' + j;
                break;
            }
        }
    }
    printf("original text : %s\n", str);
    return 0;
}

int read_text(char string[], int size, int flag) {
    int len;
    if (fgets(string, size, stdin) == NULL) {
        printf("error : fgets() failed\n");
        exit(EXIT_FAILURE);
    }
    len = strlen(string);
    if (len > 0) {
        if (flag && (string[len - 1] == '\n')) {
            string[len - 1] = '\0';
            len--;
        }
    } else {
        printf("error : no input\n");
        exit(EXIT_FAILURE);
    }
    return len;
}
