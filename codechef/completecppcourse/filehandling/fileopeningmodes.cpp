/*

    Read Mode ("r"): Opens the file for reading.
    If the file does not exist, the operation will fail.

FILE *file = fopen("filename.txt", "r");

    Write Mode ("w"): Opens the file for writing.
    If the file already exists, its content is truncated (deleted). If the file does not exist, a new file is created.

FILE *file = fopen("filename.txt", "w");

    Append Mode ("a"): Opens the file for writing.
    If the file already exists, new data is appended to the end. If the file does not exist, a new file is created.

FILE *file = fopen("filename.txt", "a");

    Read-Write Mode ("r+"): Opens the file for both reading and writing.
    The file must exist, and both reading and writing operations can be performed on it.

FILE *file = fopen("filename.txt", "r+");

    Write-Read Mode ("w+"): Opens the file for both reading and writing.
    If the file already exists, its content is truncated. If the file doesn't exist, a new file is created.

FILE *file = fopen("filename.txt", "w+");

    Append-Read Mode ("a+"): Opens the file for both reading and writing.
    Data can be appended at the end of the file, and existing data can be read.

FILE *file = fopen("filename.txt", "a+");

*/