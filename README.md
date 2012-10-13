This is messy as hell at the moment, but here are things.
 
/getwords.cpp
 
Source for the core of the server - pulls the appropriate
length word file and returns a handful of similar words.

/index.html

Contains the core of everything else. HTML, CSS and JS currently all in this one file, probably going to separate those soon for clarity's sake.

/server.php

Called via Ajax request from index.html, calls getwords.exe and returns its result as JSON.

/words/[2 - 19].txt

Words from "/words/crossword.txt" sorted by length.

/words/crossword.txt

Original word file, courtesy of the Gutenberg project.

/words/parsedictionary.cpp

Used to sort the dictionary by length. Not used at runtime.