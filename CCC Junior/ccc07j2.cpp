#include <bits/stdc++.h>
using namespace std;

string s;

int main () {
  while(true) {
    cin >> s;
    if(s.compare("TTYL") == 0) {
      printf("%s\n", "talk to you later");
      break;
    }
    else if(s.compare("CU") == 0) printf("%s\n", "see you");
    else if(s.compare(":-)") == 0) printf("%s\n", "I'm happy");
    else if(s.compare(":-(") == 0) printf("%s\n", "I'm unhappy");
    else if(s.compare(";-)") == 0) printf("%s\n", "wink");
    else if(s.compare(":-P") == 0) printf("%s\n", "stick out my tongue");
    else if(s.compare("(~.~)") == 0) printf("%s\n", "sleepy");
    else if(s.compare("TA") == 0) printf("%s\n", "totally awesome");
    else if(s.compare("CCC") == 0) printf("%s\n", "Canadian Computing Competition");
    else if(s.compare("CUZ") == 0) printf("%s\n", "because");
    else if(s.compare("TY") == 0) printf("%s\n", "thank-you");
    else if(s.compare("YW") == 0) printf("%s\n", "you're welcome");
    else if(s.compare("LOL") == 0) printf("%s\n", "laughing out loud");
    else cout << s << endl;
  }
}
