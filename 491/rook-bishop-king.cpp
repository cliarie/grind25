#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    std::cin.tie(nullptr); // Break the tie between cin and cout

    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    int r = r1 - r2;
    int c = c1 - c2;

    int rook, bishop, king;
    // rook can go anywhere, max 2 moves
    if (!r && !c) rook = 0;
    else if (r1 == r2 || c1 == c2) rook = 1;
    else rook = 2;

    // bishop can only go their color square, max 2 moves
    if ((r + c) % 2 != 0 || !r && !c) bishop = 0;
    else if (abs(r) == abs(c)) bishop = 1;
    else bishop = 2;

    // king
    if (!r && !c) king = 0;
    else king = min(abs(r), abs(c)) + max(abs(r), abs(c)) - min(abs(r), abs(c));

    cout << rook << " " << bishop << " " << king << endl;
}
