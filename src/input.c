#ifndef INPUT_H
#define INPUT_H
#include "input.h"
#endif

/**
 * @brief Concatenates two string.
 * It should be used as a string builder function.
 * char *x = "";
 * x = builder(x, <your_input_1>)
 * x = builder(x, <your_input_2>)
 * 
 * @param str1 Pre-built string
 * @param str2 Input string
 * @return char* Built string
 */
char *builder (char *str1, char *str2) {
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

/**
 * @brief Handles the inputs of main file.
 * If there is two or one argument(s) given,
 * sets working directory to "."
 * If there is one argument given, sets flag to true.
 * 
 * @param argc Argument count
 * @param argv Argument values
 * @param dest_wdir Destination working directory
 * @param flag The feature is_flag
 * @return int Return for error handling
 */
int _enum_handle_input (int argc, char **argv, char **dest_wdir, bool *flag) {
    if (argc > 3) return 1;
    if (argc == 3) {
        *flag = strcmp(argv[1], "t") == 0;
        *dest_wdir = builder(*dest_wdir, argv[2]);
    }
    if (argc < 3) *dest_wdir = builder(*dest_wdir, ".");
    if (argc < 2) *flag = false;
    return 0;
}

/**
 * @brief Appends the file content of entry to dest_dir
 * 
 * @param entry Child node of directory
 * @param dest_dir Destination directory
 * @param flag The feature is_flag
 * @return int Return for error handling
 */
int _enum_write_to_all (struct dirent *entry, char *dest_dir, bool flag) {
    char *d_name = strdup(entry->d_name);
    char *d_name_ext = strdup(d_name);

    if (strcmp(d_name, ".") == 0) return 1;
    if (strcmp(d_name, "..") == 0) return 1;
        
    char dot[2] = ".";
    char *file_name = strtok(d_name, dot);
    char *file_ext = strtok(NULL, dot);
    if (!file_ext) return 1;

    if (strcmp(file_ext, "txt") == 0) {
        char *path = "";
        path = builder(path, dest_dir);
        path = builder(path, "/");
        path = builder(path, d_name_ext);

        char *dest_path = strdup(dest_dir);
        dest_path = builder(dest_path, "/all.h");
        _enum_write_file(path, dest_path, flag);
        free(dest_path);

        free(path);
    }

    free(d_name_ext);
    free(d_name);
    return 0;
}

/**
 * @brief Enum type is set to file name
 * 
 * @param file File 
 * @return char* Name
 */
char *_enum_set_name(char *file) {
    char *file_name;
    char *temp_file_name;

    char slash[2] = "/";
    char *prev_ptr = strtok(file, slash);
    while (prev_ptr) {
        temp_file_name = prev_ptr;
        prev_ptr = strtok(NULL, slash);
    }
    file_name = strtok(temp_file_name, ".");  

    for (int i = 0; i < strlen(file_name); i++) {
        if (file_name[i] == '-') file_name[i] = '_';
    }

    return file_name;
}

/**
 * @brief Saves file content as a string
 * 
 * @param file File
 * @param flag The feature is_flag
 * @return char* String
 */
char *_enum_set_data(char *file, bool flag) {
    char *res = "";
    
    int i = 0;

    char *buf = malloc(BUF);
    FILE* fp = fopen(file, "r");
    while (fgets(buf, BUF, fp)) {
        res = _enum_set_data_step(res, buf, i, flag);
        i++;
    }
    fclose(fp);
    free(buf);

    return res;
}

/**
 * @brief Line-by-line iteration internal to 
 * _enum_set_data(...)
 * 
 * @param res Result
 * @param buf Buffer
 * @param i Iteration step
 * @param flag The feature is_flag
 * @return char* Enum variable
 */
char *_enum_set_data_step (char *res, char *buf, uint32_t i, bool flag) {
    if (i != 0) {
        res = builder(res, ",\n  ");
    }
    if (buf[strlen(buf)-1] == '\n') {
        buf[strlen(buf)-1] = '\0';
    } 
    res = builder(res, buf);
    if (flag) {
        res = builder(res, " = ");
        char num[10];
        sprintf(num, "%d", 1 << i);
        res = builder(res, num);
    }
    return res;
}

/**
 * @brief Creates the code for writing inside a .c file
 * 
 * @param name Type name of enum
 * @param data Content of enum as a string
 * @return char* 
 */
char *_enum_set_code(char *name, char *data) {
    char *code = "";
    code = builder(code, "typedef enum ");
    code = builder(code, name);
    code = builder(code, " {\n  ");
    code = builder(code, data);
    code = builder(code, "\n} ");
    code = builder(code, name);
    code = builder(code, ";\n\n");
    return code;
}

/**
 * @brief Writes code to a specified file path
 * 
 * @param file File path
 * @param mode Mode of writing
 * @param code Code created
 */
void _enum_write_code(char *file, char *mode, char *code) {
    if (!mode) mode = "w";

    FILE *fp = fopen(file, mode);
    fprintf(fp, "%s", code);
    fclose(fp);
}

/**
 * @brief Appends the content of file specified in 
 * path to dest_path in expected format
 * 
 * @param path Source path
 * @param dest_path Destination path
 * @param flag The feature is_flag
 */
void _enum_write_file(char *path, char *dest_path, bool flag) {
    char *temp_file = strdup(path);
    char *name = _enum_set_name(temp_file);
    free(temp_file);

    char *temp_name = strdup(name);
    char *data = _enum_set_data(path, flag);
    char *code = _enum_set_code(temp_name, data);
    free(temp_name);
            
    _enum_write_code(dest_path, "a", code);
    free(code);
}

/**
 * @brief Reads the inputs from a given working directory,
 * converts to a header file and appends to the main application
 * Working directory should have a folder structure:
 * It should have a child directory "input".
 * "input" should contain "all.h" and
 * and "<your-input1>.txt", "<your-input2>.txt", …
 * 
 * @param argc
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv) {
    char *dest_wdir;
    bool flag;
    if (_enum_handle_input(argc, argv, &dest_wdir, &flag) == 1) 
        return 1;

    struct dirent *entry;

    char *dest_dir = strdup(dest_wdir); 
    free(dest_wdir);

    dest_dir = builder(dest_dir, "/input");
    
    char *dest_path = strdup(dest_dir);
    dest_path = builder(dest_path, "/all.h");
    
    FILE *fp = fopen(dest_path, "w");
    free(dest_path);
    fclose(fp);

    DIR *dp;
    dp = opendir(dest_dir);

    while((entry = readdir(dp))) {
        if (_enum_write_to_all(entry, dest_dir, flag) == 1)
            continue;
    }
    closedir(dp);
    free(dest_dir);
}