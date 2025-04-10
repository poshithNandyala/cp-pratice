// B. Balanced Tunnel - Traffic enforcement in a one-way tunnel
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Read number of cars
    int n;
    cin >> n;
    
    // Arrays to store entrance and exit order
    vector<int> a(n), b(n); // a: entrance order, b: exit order
    
    // Read entrance order and convert to 0-based indexing
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        --a[i]; // Convert to 0-based indexing
    }
    
    // Read exit order and convert to 0-based indexing
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        --b[i]; // Convert to 0-based indexing
    }
    
    // Store exit positions for each car
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
    {
        pos[b[i]] = i; // pos[car_id] = exit_position
    }
    
    // Convert entrance order to exit positions
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        c[i] = pos[a[i]]; // c[i] = exit position of i-th car that entered
    }
     
    for(auto item : a){
        cout << item << " ";
    }
    cout << "\n";
    
    for(auto item : b){
        cout << item << " ";
    }
    cout << "\n";
    for(auto item : pos){
        cout << item << " ";
    }
    cout << "\n";
    
    for(auto item : c){
        cout << item << " ";
    }
    cout << "\n";
    // Count cars that need to be fined
    int mx = -1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] > mx)
        {
            mx = c[i]; // Update maximum exit position seen so far
        }
        else
        {
            // If current car exits before any previous car,
            // it means it overtook someone and must be fined
            ++ans;
        }
    }
    
    // Output number of cars to be fined
    cout << ans << '\n';
    return 0;
}