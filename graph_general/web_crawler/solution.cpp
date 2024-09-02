/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    unordered_set<string> seen;
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string host = get_hostname(startUrl);
        dfs(startUrl, htmlParser, host);
        return vector<string>(seen.begin(), seen.end());
    }

    string get_hostname(string url){
        int slash_count = 0;
        string result;
        for(auto& c : url){
            if(slash_count == 2 && c=='/') break;
            result.push_back(c);
            if(c=='/') slash_count++;
        }
        return result;
    }

    void dfs(string url, HtmlParser& parser, string hostname){
        seen.insert(url);
        vector<string> child_urls = parser.getUrls(url);
        for(auto& c : child_urls){
            if(!seen.count(c) && c.find(hostname)==0) dfs(c, parser, hostname);
        }
    }
};