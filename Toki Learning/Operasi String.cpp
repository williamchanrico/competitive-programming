#include <iostream>
using namespace std;

int main(){
	string s1, s2, s3, s4;
	getline(cin, s1);
	getline(cin, s2);
	s1.erase(s1.find(s2), s2.size());
	getline(cin, s3);
	getline(cin, s4);
	s1.insert(s1.find(s3)+s3.size(), s4);
	cout << s1 << "\n";
}

/*
#include <iostream>
using namespace std;

int main(){
	string s1, mwhapus, mulaidari, sisipkan, temp="", ans;
	
	cin >> s1 >> mwhapus >> mulaidari >> sisipkan;
	for(int a=0, len=s1.size();a<len;a++){
		int ind=0;
		for(int b=a, len2=mwhapus.size();b<(len2+a);b++){
			if(s1[b]==mwhapus[ind]){
				ind++;
				if(ind==len2){
					temp+=s1.substr(0, a);
					temp+=s1.substr((b+1), (len-1));
					a=len;
					b=len2+a;
				}
			}else{
				b=len2+a;
			}
		}
	}
	for(int a=0, len=temp.size(), len2=mulaidari.size();a<len;a++){
		if(temp[a]==mulaidari[0]){
			int ind=0;
			for(int b=a, lenn=a+len2;b<lenn;b++){
				if(temp[b]==mulaidari[ind]){
					ind++;
					if(ind==len2){
						ans+=temp.substr(0, b+1);
						ans+=sisipkan;
						ans+=temp.substr(b+1, len-1);
						a=len;
					}
				}else{
					b=lenn;
				}
			}
		}
	}
	cout << ans << endl;
}
*/

/*
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	char S1[500],
		 S2[500],
		 S3[500],
		 S4[500],
		 S5[500];
	int n, m, temp;
	
	scanf("%s%s%s%s", S1, S2, S3, S4);
	
	for(int a=0;a<strlen(S1);a++){
		if(S1[a]==S2[0]){
			n=a;
			for(int b=0;b<strlen(S2);b++){
				if(S1[n]==S2[b]){
					if(b==strlen(S2)-1){
						n-=strlen(S2);
						a=strlen(S1);
					}
					n++;
				}
			}
		}
	}
	for(int a=0;a<n;a++){
		S5[a]=S1[a];
	}
	temp=n;
	for(int a=n;a<strlen(S1);a++){
		S5[a]=S1[temp+strlen(S2)];
		temp++;
	}
	
	for(int a=0;a<strlen(S5);a++){
		if(S5[a]==S3[0]){
			m=a;
			for(int b=0;b<strlen(S3);b++){
				if(S5[m]==S3[b]){
					if(b==(strlen(S3)-1)){
						m-=strlen(S3);
						a=strlen(S5);
					}
					m++;
				}
			}
		}
	}
	
	for(int a=0;a<m+strlen(S3);a++){
		printf("%c", S5[a]);
	}
	
	printf("%s", S4);
	
	for(int a=m+strlen(S3);a<strlen(S5);a++){
		printf("%c", S5[a]);
	}
	printf("\n");
	
}
*/