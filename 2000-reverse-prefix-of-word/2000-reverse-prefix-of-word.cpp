class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        for(i = 0; i<word.length(); i++){
            if(word[i]==ch){
                break;    
            }
        }
        if(i == word.length()) return word;
        int j = 0;
        while(j<i){
            swap(word[i], word[j]);
            i--;
            j++;
        }
        return word;
    }
};