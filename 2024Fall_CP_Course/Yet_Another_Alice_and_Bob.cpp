#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef pair<long long, long long> Position; // Define type for position as a pair of long long integers

// Directions (right, down, left, up)
int dx[4] = {1, 0, -1, 0}; // Change in x-axis
int dy[4] = {0, 1, 0, -1}; // Change in y-axis

int main() {
    long long k; // Total seconds
    int n, m;    // Number of turns for Alice and Bob
    cin >> k >> n >> m;
    
    vector<long long> alice_turns(n), bob_turns(m);
    
    // Read the times Alice makes her turns
    for (int i = 0; i < n; ++i) {
        cin >> alice_turns[i];
    }
    
    // Read the times Bob makes his turns
    for (int i = 0; i < m; ++i) {
        cin >> bob_turns[i];
    }
    
    // Initialize positions for Alice and Bob
    Position alice_pos = {1, 1}, bob_pos = {1, 1};
    int alice_dir = 0, bob_dir = 1; // Alice starts facing right, Bob starts facing down
    int alice_turn_idx = 0, bob_turn_idx = 0;
    
    set<Position> alice_visited, bob_visited; // Track cells visited by Alice and Bob
    
    // Iterate through each second of the game
    for (long long t = 1; t <= k; ++t) {
        // Alice turns if necessary
        if (alice_turn_idx < n && t == alice_turns[alice_turn_idx]) {
            alice_dir = 1-alice_dir; // Turn right
            alice_turn_idx++;
        }
        
        // Bob turns if necessary
        if (bob_turn_idx < m && t == bob_turns[bob_turn_idx]) {
            bob_dir = 1-bob_dir; // Turn right
            bob_turn_idx++;
        }
        
        // Move Alice
        alice_pos.first += dx[alice_dir];
        alice_pos.second += dy[alice_dir];
        alice_visited.insert(alice_pos); // Paint the cell Alice visits
        
        // Move Bob
        bob_pos.first += dx[bob_dir];
        bob_pos.second += dy[bob_dir];
        bob_visited.insert(bob_pos); // Paint the cell Bob visits
    }
    
    // Calculate red, blue, and purple cells
    int red = 0, blue = 0, purple = 0;
    
    // Count red and purple cells (visited by Alice)
    for (auto cell : alice_visited) {
        if (bob_visited.count(cell)) {
            purple++;
        } else {
            red++;
        }
    }
    
    // Count blue cells (visited only by Bob)
    for (auto cell : bob_visited) {
        if (!alice_visited.count(cell)) {
            blue++;
        }
    }
    
    // Output the result
    cout << red << " " << blue << " " << purple << endl;
    
    return 0;
}
