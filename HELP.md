# HELP – Simple Line Editor

## How to Start
Compile and run the C program using GCC.

## Menu Options

**1. Insert Line**  
Enter the position and text to add a new line.

**2. Display Document**  
Displays all the lines stored in the document.

**3. Delete Line**  
Enter the line number to delete that line.

**4. Save Document**  
Saves the document content into `document.txt`.

**5. Load Document**  
Loads previously saved content from `document.txt`.

**6. Search Word**  
Enter a word to search for it in the document. The program displays the matching line number.

**7. Count Lines and Words**  
Displays the total number of lines and words in the document.

**8. Exit**  
Closes the program.

## Important Notes
- Enter a valid menu option.
- Enter a valid line position when inserting or deleting.
- Save the document before exiting to keep your changes.
- The file `document.txt` is created in the project folder.

## Troubleshooting
- If compilation fails, check whether GCC is installed.
- Make sure the terminal is opened in the project folder.
- Check that `line_editor.c` and `document.txt` are in the correct folder.