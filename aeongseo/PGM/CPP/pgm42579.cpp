/*** 베스트앨범 (L3) ***/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genreTotal; // 총 조회수 저장
    unordered_map<string, vector<pair<int, int>>> genreSongs; // 장르별 곡 정보 저장 (play수, 인덱스)
    
    for(int i=0; i<genres.size(); i++){
        genreTotal[genres[i]] += plays[i];
        genreSongs[genres[i]].push_back({plays[i], i});
    }
    
    // 총 플레이수 순으로 장르 정렬
    vector<pair<string, int>> genrePlay(genreTotal.begin(), genreTotal.end());
    sort(genrePlay.begin(), genrePlay.end(), [](const auto& a, const auto& b){return a.second > b.second;});
    
    // 총 플레이수 순으로 장르 정렬된 것을 순회
    for(const auto& [genre, total] : genrePlay){
        auto& songs = genreSongs[genre];
        // 장르별 곡을 조회수 내림차순, 인덱스 오름차순으로 정렬
        sort(songs.begin(), songs.end(), [](const auto& a, const auto& b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        
        // 장르별 곡을 2개씩 answer에 추가
        for(int i=0; i<min((int)songs.size(), 2); i++){
            answer.push_back(songs[i].second);
        }
    }
    
    return answer;
}