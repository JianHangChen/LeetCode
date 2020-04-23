
//https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/


// sol6, random fixed lenth encoding + double map
// 1. shorte 62^6 link
// 2. key length fixed to 6 char
// 3. less conflict
// 4. tradeoff between length of key and number of links
// 5. security: not predicatable
// 6. avoid repeated url
class Solution {
private:
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    map<string, string> short2long, long2short;
public:
    string getKey(){
        int code = rand();
        string key;
        for(int i = 0; i < 6; i++){
            key.push_back(chars[code % 62]);
            code /= 62;
        }
        return key;
    }
    
    string encode(string longUrl){
        if(long2short.count(longUrl) > 0) return long2short[longUrl];
        string key = getKey();
        if(short2long.count(key) > 0){
            key = getKey();
        }
        short2long[key] = longUrl;
        return "http://tinyurl.com/" + key; 
    }
    
    string decode(string shortUrl){
        auto pos = shortUrl.find_last_of("/") + 1;
        string key = shortUrl.substr(pos);
        return short2long[key];
    }
};

// sol5, random fixed lenth encoding
// 1. store 62^6 link
// 2. key length fixed to 6 characters
// 3. less probability of conflict
// 4. there is a trade of between the length of key and number of links
// 5. security: not predicatable
// 6. if there are many the same url, it will generate many keys
// class Solution {
// private:
//     string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//     map<string, string> m;
// public:
//     string getKey(){
//         int code = rand();
//         string key;
//         for(int i = 0; i < 6; i++){
//             key.push_back(chars[code % 62]);
//             code /= 62;
//         }
//         return key;
//     }
    
//     string encode(string longUrl){
//         string key = getKey();
//         if(m.count(key) > 0){
//             key = getKey();
//         }
//         m[key] = longUrl;
//         return "http://tinyurl.com/" + key; 
//     }
    
//     string decode(string shortUrl){
//         auto pos = shortUrl.find_last_of("/") + 1;
//         string key = shortUrl.substr(pos);
//         return m[key];
//     }
// };
    
// sol4, random code and hashmap, from sol4
// 1. limit by int
// 2. the key will not duplicate
// 3. key independent of length of longUrl
// 4. collision of random number will degrade performance
// 5. we cannot determin the encoded url from the key

// class Solution {
// private:
//     map<int, string> m;
// public:
//     string encode(string longUrl){
//         int code = rand();
//         while(m.count(code) > 0){
//             code = rand();
//         }
//         m[code] =longUrl;
//         return "http://tinyurl.com/" + to_string(code);
//     }

//     string decode(string shortUrl){
//         string key = shortUrl.substr(shortUrl.find_last_of("/") + 1);
//         int code = stoi(key);
//         return m[code];
//     }  
// };

// sol3, hash code, from sol3
// 1. hashcode may collision, cause failure
// 2. security: predicting url is not easy


// sol1, from gy1 and sol1
// 1. limit to the size of int, overflow will degrade the performance
// 2. security concern, others know how many url stored
// 3. the length is no always shorter
// 4. repeated url will generate several different short url
// class Solution {
// private:
//     int count = 0;
//     vector<string> v;
// public:
//     string encode(string longUrl){
//         v.push_back(longUrl);
//         return "http://tinyurl.com/" + to_string(count++);
//     }
//     string decode(string shortUrl){
//         auto pos = shortUrl.find_last_of("/");
//         return v[stoi(shortUrl.substr(pos+1))];
//     }  
// };

// sol2, my, same as sol2, variable-length encoding 
// count and change to string

// 1. depend on int, overflow
// 2. short url will have some pattern, lexicographically, it's good for performance, bad for secrurity
// 3. repeated url will generate several different short url

// class Solution {
// private:
//     int count = 0;
//     unordered_map<string, string> m;
//     string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
// public:
    
//     string getShortUrl(){
//         string key;
//         while(count){
//             key.push_back(chars[count%62]);
//             count /= 62;
//         }
//         return key;
        
//     }
    
//     // Encodes a URL to a shortened URL.
//     string encode(string longUrl) {        
//         count++;
//         string key = getShortUrl();
//         m[key] = longUrl;
//         return "http://tinyurl.com/" + key;
//     }

//     // Decodes a shortened URL to its original URL.
//     string decode(string shortUrl) {
//         string key = shortUrl.substr(19);
//         return m[key];
//     }
// };

