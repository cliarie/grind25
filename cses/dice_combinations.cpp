#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ll n;
    ll mod = 1e9 + 7;
    cin >> n;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    // 1:1; 2:2; 3:4; 4:8; 5:16; 6:32; 7:63; 8:125; 9:248; 10:492; 11:976; 12:1936; 13:3848; 14:7648; 15:15296; 16:30416; 17:60504; 18:120096; 19:238816; 20:476096; 21:946880; 22:1883136; 23:3749184; 24:7463168; 25:14852096; 26:29533568; 27:58720256; 28:116932864; 29:232452736; 30:462535168; 31:920724992; 32:1836480216; 33:3652966912; 34:7273643920; 35:14474011136; 36:28869841312; 37:57552571392; 38:114465131264; 39:228930662144; 40:456483973376; 41:908007228160; 42:1808548327424; 43:3600914251776; 44:7171439379456; 45:14294967290880; 46:28488289461760; 47:56790717115392; 48:113134732290816; 49:225234018775808; 50:448947907781120; 51:894784853130752; 52:1782321657755136; 53:3545516145872896; 54:7052774766025728; 55:14079294023459840; 56:28057766158701568; 57:55960743312312320; 58:111921486624624128; 59:223842973249248256; 60:446678161972177152; 61:892498220394541312; 62:1778385366167072768; 63:3556770732334145536; 64:7113541464668291072; 65:14227082929336582144; 66:28454165858673164288; 67:56908331717346328576; 68:113816663434692657152; 69:227633326869385
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            dp[i] = (i - j >= 0) ? (dp[i] + dp[i - j]) % mod : dp[i];
        }
    }
    cout << dp[n];
}