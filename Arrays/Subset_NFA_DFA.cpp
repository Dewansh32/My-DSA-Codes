#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {
    // NFA definition
    int n = 3;
    int startState = 0;
    set<int> finalStates = {2};
    set<char> alphabet = {'a', 'b'};
    map<int, vector<pair<char, int>>> nfa;

    // Transitions
    nfa[0] = {{'e', 1}, {'e', 2}};
    nfa[1] = {{'a', 1}, {'b', 2}};
    nfa[2] = {{'b', 2}};

    // Functions for epsilon closure and move
    auto epsilonClosure = [&](set<int> states) {
        set<int> closure = states;
        queue<int> q;
        for (int s : states)
            q.push(s);
        while (!q.empty()) {
            int state = q.front();
            q.pop();
            for (auto &trans : nfa[state]) {
                if (trans.first == 'e' && closure.find(trans.second) == closure.end()) {
                    closure.insert(trans.second);
                    q.push(trans.second);
                }
            }
        }
        return closure;
    };

    auto moveFunc = [&](set<int> states, char symbol) {
        set<int> result;
        for (int s : states) {
            for (auto &trans : nfa[s]) {
                if (trans.first == symbol)
                    result.insert(trans.second);
            }
        }
        return result;
    };

    // DFA construction
    map<set<int>, int> dfaStateIds;
    vector<set<int>> dfaStates;
    map<pair<int, char>, int> dfaTrans;
    set<int> dfaFinals;

    set<int> startClosure = epsilonClosure({startState});
    dfaStates.push_back(startClosure);
    dfaStateIds[startClosure] = 0;

    queue<set<int>> q;
    q.push(startClosure);

    while (!q.empty()) {
        set<int> current = q.front();
        q.pop();
        int currentId = dfaStateIds[current];

        for (char symbol : alphabet) {
            set<int> moveSet = moveFunc(current, symbol);
            set<int> closure = epsilonClosure(moveSet);
            if (closure.empty()) continue;
            if (dfaStateIds.find(closure) == dfaStateIds.end()) {
                int newId = dfaStates.size();
                dfaStates.push_back(closure);
                dfaStateIds[closure] = newId;
                q.push(closure);
            }
            dfaTrans[{currentId, symbol}] = dfaStateIds[closure];
        }
    }

    for (int i = 0; i < dfaStates.size(); i++) {
        for (int fs : finalStates) {
            if (dfaStates[i].find(fs) != dfaStates[i].end()) {
                dfaFinals.insert(i);
                break;
            }
        }
    }

    // DFA output
    cout << "DFA States:\n";
    for (int i = 0; i < dfaStates.size(); i++) {
        cout << "D" << i << " = { ";
        for (int state : dfaStates[i])
            cout << state << " ";
        cout << "}\n";
    }

    cout << "\nDFA Transitions:\n";
    for (auto &t : dfaTrans) {
        cout << "D" << t.first.first << " --" << t.first.second << "--> D" << t.second << "\n";
    }

    cout << "\nStart state: D0\nFinal states: ";
    for (int f : dfaFinals)
        cout << "D" << f << " ";
    cout << "\n";

    // Test input string
    string test = "ab";
    cout << "\nTesting string: " << test << "\n";
    int current = 0;
    for (char c : test) {
        if (dfaTrans.find({current, c}) == dfaTrans.end()) {
            cout << "Not Accepted\n";
            return 0;
        }
        current = dfaTrans[{current, c}];
    }
    if (dfaFinals.find(current) != dfaFinals.end())
        cout << "Accepted\n";
    else
        cout << "Not Accepted\n";

    return 0;
}
