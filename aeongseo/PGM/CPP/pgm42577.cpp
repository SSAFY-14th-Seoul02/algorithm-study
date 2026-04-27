/*** 전화번호 목록 ***/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++){
        int l = min(phone_book[i].length(), phone_book[i+1].length());
        int cnt = 0;
        for(int j = 0; j<l; j++){
            if(phone_book[i][j] == phone_book[i+1][j]) cnt++;
        }
        if(cnt == l){
            answer = false;
            break;
        }
    }
    
    return answer;
}