#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

struct player {
    int index;
    int score;
};


int calculateScore(const string &toss) {
    unordered_map<string, int> colorMap = {
        {"A", 1}, {"R", 1}, {"O", 3}, {"G", 3}, {"B", 6},
        {"AO", 5}, {"OA", 5}, {"OB", 10}, {"BO", 10},
        {"BG", 10}, {"GB", 10}, {"GR", 5}, {"RG", 5}
    };
    
    int score = 0;
    string ring = toss;
    if (ring[ring.size() - 1] == '+') {
        score += 2;
        ring.pop_back();
    }
    
    score += colorMap[ring];
    return score;
}

int calculatePlayerScore(const string &tosses) {
    istringstream iss(tosses);
    string toss;
    int totalScore = 0;
    while (iss >> toss) {
        totalScore += calculateScore(toss);
    }
    
    return totalScore;
}
/*
 * Complete the 'scoreTosses' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER numPlayers
 *  2. STRING_ARRAY tosses
 */

string scoreTosses(int numPlayers, vector<string> tosses) {
    vector<player> playerScores;
    for (int i = 0; i < numPlayers; i++) {
        int score = calculatePlayerScore(tosses[i]);
        playerScores.push_back({i + 1, score});
    }
    
    auto compare = [&] (const player &a, const player &b) {
        if (a.score != b.score) return a.score > b.score; // Descending score
        return tosses[a.index - 1].size() < tosses[b.index - 1].size();
    };
    
    sort(playerScores.begin(), playerScores.end(), compare);
    
    string result;
    for (const auto &p : playerScores) {
        result += to_string(p.index) + "-" + to_string(p.score) + " ";
    }
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string numPlayers_temp;
    getline(cin, numPlayers_temp);

    int numPlayers = stoi(ltrim(rtrim(numPlayers_temp)));

    string tosses_count_temp;
    getline(cin, tosses_count_temp);

    int tosses_count = stoi(ltrim(rtrim(tosses_count_temp)));

    vector<string> tosses(tosses_count);

    for (int i = 0; i < tosses_count; i++) {
        string tosses_item;
        getline(cin, tosses_item);

        tosses[i] = tosses_item;
    }

    string result = scoreTosses(numPlayers, tosses);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

