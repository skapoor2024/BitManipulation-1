/*
// Time Complexity : O(N)
// Space Complexity : O(N)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :


// Your code here along with comments explaining your approach
Create a hashmap of the window and store the frequency of the substring.
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int window_len{10};
        unordered_map<string,int> umap{};
        vector<string> res{};
        int s_len = s.size();
        //cout<<s_len<<endl;
        if(s_len<=window_len) return res;
        for(int i{};i<s_len-window_len+1;++i){
            string temp = s.substr(i,window_len);
            if(umap.find(temp)==umap.end()){
                umap[temp]=0;
            }
            else{
                umap[temp]++;
            }
        }
        for(const auto& pair:umap){
            if(pair.second>0){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};

//optimized version 

#include <iostream>
#include <vector>
#include <unordered_map>

int encode(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: return -1;
    }
    return -1;
}

int encodeSequence(const std::string& seq) {
    int encoded = 0;
    for (char c : seq) {
        encoded = (encoded << 2) | encode(c);
    }
    return encoded;
}

std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> result;
    std::unordered_map<int, int> sequenceCount;
    std::unordered_map<int, int> seen;

    int n = s.length();
    if (n <= 10) return result;

    int mask = 0xFFFFF; // Represents 20 bits for 10-letter sequence


    for (int i = 0; i < n - 9; ++i) {
        int encodedSeq = encodeSequence(s.substr(i, 10));
        if (++sequenceCount[encodedSeq] == 2 && seen[encodedSeq]++ == 0) {
            result.push_back(s.substr(i, 10));
        }
    }

    return result;
};