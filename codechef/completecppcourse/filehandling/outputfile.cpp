void userFunction() {
    
    // Open files in respective modes
    string inputFilename = "/mnt/himu23/input.txt";
    string outputFilename = "/mnt/himu23/output.txt";
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);
    
    // Read and write the numbers from the file
    int number;
    while(inputFile >> number) {
        outputFile << number << "\n";
    }
    
    // Close the file
    inputFile.close();
    outputFile.close();

    // Display the contents of output.txt    
    system("cat /mnt/himu23/output.txt");
}    
 void function(){
    char *inputfilename = "/home/sample_input.txt";
    FILE *inputfile = fopen(inputfilename, "r");
    char *outputfilename = "/home/sample_output.txt";
    FILE *outputfile = fopen(outputfilename, "w");
    
    int number;
    
    // Read and write the numbers from the file
    while (fscanf(inputfile, "%d", &number) != EOF) {
        fprintf(outputfile, "%d\n", number);
    }
    
    fclose(inputfile);
    fclose(outputfile);

 }
 /*
 
    char *inputfilename and char *outputfilename: These lines declares a character pointer and initializes it with the path to the input text and the output file.
    FILE *outputfile = fopen(outputfilename, "w");: This line uses the fopen() function to open the output file specified by outputfilename in write mode ("w").
    It returns a pointer to a FILE structure that represents the opened output file.
    fprintf(outputfile, "%d\n", number * number);: This function writes the read integer to the output file represented by the outputfile pointer.
    The %d format specifier is used to format the integer, followed by \n to write a newline character.

 */