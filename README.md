Fast Input and Output programs for competitive programming.

In C++ the cin is considerably slower than scanf or other means

The programs are to reduce the read and write time of the program.

The methods get progressively faster as you move down

1.    Simplest Approach if you r using cin:

            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            
2.    fastAtoi
            
             Standard Atoi simple to replicate, useful in contests where you cant have a code template.
             the given code works for only 32 bit integers, though can easily be changed to integers of other sizes

3.     fasterAtoi (Recommended)
             This is a lot faster than the previous ones, the main reason for them being slow is frequent calls to inbuilt functions
             this is detoured by caching input stream as a character array, this works only if the input is passed through external files as stdin,
             can be used for the competetive reliably
             
             This program can handle :
                integers of any size
                character
                character array
                string
                
             There is also an obfuscated and compressed source for the cases when there is a source code size limit in that round
                
4.     fastIO
             Same input speed as 3. but also has a fast output
                The input part can handle everything what 3. can
                
                The output can only handle 32 bit integers and character
                
             Beware use this only if the the number of integers to print is at least 200000 if so its more than 10 times faster than cout
             
 5.    multiThreadedAtoi
             This is an experimental method the source code only works for 32 bit integers and the input is not  a proper sequence
             it need to be merged from different array. It works best if the system is multi threaded,It works only on the linux distribution
             Only the core of the functionality is implemented since it fits a very small niche. 
             
             But when the conditions meet it is lot faster than any of the above
             
