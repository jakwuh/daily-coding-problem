"""
Task:
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.
"""

LINE_END = '\n'
TAB = '\t'
DOT = '.'
SEPARATOR = '/'

def solve(str):
    longest_path = ""
    current_path = ""
    current_path_parts = []
    i = 0

    while i < len(str):
        is_file = False
        current_word = ""
        
        while i < len(str) and str[i] != LINE_END:
            is_file = is_file or (str[i] == DOT)
            current_word += str[i]
            i += 1

        current_path_parts.append(current_word)
        current_path = SEPARATOR.join(current_path_parts)

        if not is_file:
            current_path += SEPARATOR

        longest_path = max([longest_path, current_path])

        tabs_count = 0
        i += 1
        while i < len(str) and str[i] == TAB:
            i += 1
            tabs_count += 1        

        current_path_parts = current_path_parts[0:tabs_count]
    
    return longest_path


print solve("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext")