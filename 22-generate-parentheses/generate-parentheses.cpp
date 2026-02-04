class Solution {
public:
void generate(string curr,vector<string>& result,int open,int close){
 if(open==0 && close==0){
    result.emplace_back(curr);
    return;
 }
 if(open>0){
  generate(curr+"(",result,open-1,close);
 }
  if( open<close && close>0){
    generate(curr +")",result,open,close-1);
  }

}
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        vector<string> result;
        generate("",result,open,close);
        return result;
    }
};