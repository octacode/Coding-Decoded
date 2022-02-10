Brief note about Question-

We have to return the letter that was added to t.

In simple words, we are given two stringssand t, andtcontains one more extra letter which is not present in s, so we have to return that particular letter.
Let's take an example other than the given in question-
suppose s : "xyzat"
and  t as : "axztyg"
& if we observe then we find out that 'g' was an extra letter that is not present in s. 
So, we have to return letter "g".
Solution - I ( Accepted)-

The most basic thing we can think of is after reading the statement is, String t is generated by random shuffling string s and then add one more letter at a random position.
We know that string t contains n (n is size of string s) letters same as ofstring sand their is only particular charater in t which is different from s.
So, why not try to do something with the frequency.
For every characer of string s, we make it's frequency as negative so that when we traverse the string t, then add every character.
And at last the character whose frequency is 1, that is our answer.
How will I code that-

We create an frequency array,freq of size 26 as the English Alphabet contains only 26 letters.
First we start traversing the string s, and for every character we decrease the its frequency.
After that, we start traversing string t, and add frequency.
At last, their is only character left whose frequency is1, and that should be our answer.
A question arises, why freq array?
See, since freq array is of size 26, so every index of the array repersents a character i.e 0 index represents character 'a', index 1 reprsents character 'b' and so on..
See Dry run on first example -

Let's take first example-
suppose s : "abcd"
and  t as : "abcde"

so, intially our freq array looks like
index->   0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11, 12, 13, 14, 15, 16, 17, 18,19, 20, 21, 22, 23, 24, 25
 freq[]: [0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
 
 so on traversing s, our freq array looks like:
 index :   0,  1,  2,  3
 freq[]: [-1, -1, -1, -1,  0, 0, ...........]
 
 and after that traversing t, our freq looks like:
  index : 0, 1, 2, 3, 4
 freq[]: [0, 0, 0, 0, 1,  0, 0, ...........]
 
 so, we can see that at index 4 its frequency is '1' so it is different.
 and 4 represents which character, if 0 represents character 'a' then, 
 a -> 0
 b -> 1
 c -> 2
 d -> 3
 e -> 4
 therefore, e is our answer.
Time Complexity --> O(n) // as we are traversing strings single time
Space Complexity --> O(26) i.e nothing but O(1)  // we use frequency array of size 26
It paases [ 54 / 54] in built test cases
Code (C++)

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length(); // size of string s
        vector<int> freq(26, 0); // making a frequency array of size 26
        
        // decreasse frequency of every character
        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']--;
        }
        
        // now increase frequency of every character
        for(int i = 0; i < n + 1; i++)
        {
            freq[t[i] - 'a']++;
        }
        
        char ans = '#'; // for storing answer
        
        // traverse the frequency array
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] == 1) // character whose frequency is 1
            {
                ans = (char) i + 'a'; //extract that character and stores in answer
                break; // we got our answer now, so break the loop
            }
        }
        
        return ans; // return answer
    }
};
Solution - II ( Accepted)-

Can we do it anthor way?
Yess, we are going to use the property of xor.
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0

we can see that, if we xor 0 with 0 or 1 with 1, we get our result as 0
therefore we can say that 

* if we are going to xor two same characters then our result is zero.
One more thing which we have to kept in mind related to xor is-
If we do xor of a number with zero, we get the same number as itself.
1 ^ 0 = 1
0 ^ 1 = 1
Time Complexity --> O(n) // as we are traversing strings single time
Space Complexity --> O(1)  // we are not using extra space
It paases [ 54 / 54] in built test cases
Code (C++)

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length(); // extracting length
        char ans = 0; // set intially answer as zero
        
        for(int i = 0; i < n; i++) // traverse string s
        {
            ans = ans ^ s[i];
        }
        
        for(int i = 0; i < n + 1; i++) // traverse string t
        {
            ans = ans ^ t[i];
        }
        
        return ans; // return answer
    }
};