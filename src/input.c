#include "input.h"

char *concat (char *str1, char *str2) {
    char *str;
    if (str1 == NULL || strlen(str1) == 0) {
        str = strdup(str2);
    }
    else { 
        asprintf(&str, "%s%s", str1, str2);
        free(str1);
    }
    return str;
}

char *read_enum(char *file, int *res_len, char **name, bool flag) {
    char slash[2] = "/";
    char *temp_file = strdup(file);
    char *prev_ptr = strtok(temp_file, slash);
    char *temp_file_name;
    while (prev_ptr) {
        temp_file_name = prev_ptr;
        prev_ptr = strtok(NULL, slash);
    }
    char *file_name = strtok(temp_file_name, ".");
    for (int i = 0; i < strlen(file_name); i++) {
        if (file_name[i] == '-') file_name[i] = '_';
    }
    *name = file_name;

    FILE* fp = fopen(file, "r");
    char *buf = malloc(BUF);
    char *res = ""; 
    int i = 0;
    while (fgets(buf, BUF, fp)) {
        if (i != 0) {
            res = concat(res, ",\n  ");
        }
        if (buf[strlen(buf)-1] == '\n') {
            buf[strlen(buf)-1] = '\0';
        } 
        res = concat(res, buf);
        if (flag) {
            res = concat(res, " = ");
            char num[10];
            sprintf(num, "%d", 1 << i);
            res = concat(res, num);
        }
        i++;
    }
    fclose(fp);
    free(buf);
    if (res_len) *res_len = i;
    return res;
}

void write_enum(char *file, char *mode, char *name, char *res) {
    if (strlen(name) == 0) return;

    char *code = "";
    code = concat(code, "typedef enum ");
    code = concat(code, name);
    code = concat(code, " {\n  ");
    code = concat(code, res);
    code = concat(code, "\n} ");
    code = concat(code, name);
    code = concat(code, ";\n\n");

    if (!mode) mode = "w";
    FILE *fp = fopen(file, mode);
    fprintf(fp, "%s", code);
    fclose(fp);
    free(res);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    bool flag = strcmp(argv[1], "t") == 0;

    struct dirent *entry;
    char *dest_path = "./inputs/all.c";
    
    FILE *fp = fopen(dest_path, "w");
    fclose(fp);

    DIR *dp;

    dp = opendir("inputs");

    while((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
        
        char dot[2] = ".";
        char *temp_file_name = strdup(entry->d_name);
        char *file_name = strtok(temp_file_name, dot);

        char *file_ext = strtok(NULL, dot);
        if (!file_ext) continue;
        if (strcmp(file_ext, "txt") == 0) {
            char *name;
            char *path = "";
            path = concat(path, "inputs/");
            path = concat(path, entry->d_name);
            char *data = read_enum(path, NULL, &name, flag);
            write_enum(dest_path, "a", name, data);
        }
    }
    closedir(dp);
}