      # Deletive Editing

          #include<bits/stdc++.h>
          using namespace std;
     
          int main(){
          int t;
          cin>>t;
          while (t--){
     string s,t,temp="";
     cin>>s>>t;
     
          vector<int>v(26,0);
          for(auto f:t){
              v[f-'A']++;
          }
          for(int i=s.size()-1;i>=0;i--){
              if(v[s[i]-'A']>0){
                  temp+=s[i];
                  v[s[i]-'A']--;
              }
     
          }
          reverse(temp.begin(),temp.end());
     
          if(temp==t)cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
     
     
     
          }
          }

      The code checks if it's possible to obtain string t from string s by removing characters from left to right.

      Key algorithm:

      - For each character in target string t, count its frequency
      - Scan original string s from right to left
      - When finding a character that exists in t's frequency count, add it to result and decrease its count
      - Finally check if constructed string equals target t

      Let's break down the example "DETERMINED" → "TRME":

          Original: DETERMINED
          For target TRME:
          T(1), R(1), M(1), E(1)

          Scanning right to left:
          D -> skip
          E -> keep (matches)
          N -> skip  
          I -> skip
          M -> keep (matches)
          R -> keep (matches)
          E -> skip
          T -> keep (matches)
          E -> skip
          D -> skip

          Result after reversing: TRME

      The code returns YES because we can obtain "TRME" by removing characters while preserving relative order of required characters.

      It returns NO for "DETERMINED" → "TERM" because 'E' appears before 'R' in "TERM" but after 'R' in "DETERMINED", making it impossible to obtain through left-to-right deletions.