# regexForC
A simple function implemented for regex using in C++
## Properties
* Really short, handy and easy to use!
* No need to use any additional C++ library, just C++11 STD
* Support catching multiple groups in regex
* Not support group in group regex type. For ex: `abc ((.*) 123) 456` (I actually never use this type of regular expression)
* Result of regex matching is a `vector<pair<string, vector<string> > >` contain pairs in which:
 * The first element in pair is the matching value, the second element is a vector contain groups of the matching value.
 * For example:  
   Regex expression: ` (.*?) = "(.*?)"`  
   String to apply the regex: `<tag4 name = "Name4" text = "Super">`  
   The result will be a vector contains 2 pair:
     1. Pair 1: <` name = "Name4"`, `[name, Name4]`>
     2. Pair 2: <` text = "Super"`, `[text, Super]`>

There is a sample test in the source code file that denotes how to use regexForC function.
