class Solution {
public:
    unordered_map<string, string>map;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        if(map.find(longUrl)!=map.end()){
            return map[longUrl];
        }else{
            hash<string> mystdhash;
            string hashed = to_string(mystdhash(longUrl));
            map[longUrl]=hashed;
            map[hashed]=longUrl;
            return hashed;
        }
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));