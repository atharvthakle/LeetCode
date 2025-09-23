int compareVersion(char* version1, char* version2) {
    int i = 0, j = 0;
    int n1 = strlen(version1), n2 = strlen(version2);

    while (i < n1 || j < n2) {
        long rev1 = 0, rev2 = 0;

        // Parse revision from version1
        while (i < n1 && version1[i] != '.') {
            rev1 = rev1 * 10 + (version1[i] - '0');
            i++;
        }

        // Parse revision from version2
        while (j < n2 && version2[j] != '.') {
            rev2 = rev2 * 10 + (version2[j] - '0');
            j++;
        }

        if (rev1 < rev2) return -1;
        if (rev1 > rev2) return 1;

        // Move past '.'
        i++;
        j++;
    }

    return 0;
}
