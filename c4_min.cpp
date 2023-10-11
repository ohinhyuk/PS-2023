#include <iostream>
using namespace std;

#define MAX_SIZE 51

//각 인덱스는 disk의 종류이며 disk배열에는 어느 rod에 disk가 있는 지를 나타낸다.
int disk[MAX_SIZE]; 
int result = 0;

void hanoi_default(int disk_idx, int from, int by, int to){
	if(disk_idx == 1){
		if(from != to){
			disk[disk_idx] = to;
			result++;
		}
	}else{
		if(from != to){
			hanoi_default(disk_idx-1, disk[disk_idx-1], 6-(disk[disk_idx-1] + by), by);
            cout << disk_idx-1 << disk[disk_idx-1] << "//" << to << 6-(disk[disk_idx-1] + by) << "//"<< by << endl;
			disk[disk_idx] = to;
			result++;
		}
		hanoi_default(disk_idx-1, disk[disk_idx-1], 6-(disk[disk_idx-1] + to), to);
        cout << disk_idx-1 << disk[disk_idx-1] << "//" << 6-(disk[disk_idx-1] + to) << by  << "//" << to << endl;
	}
}

void hanoi(int disk_idx, int from, int by, int to){
	if(disk_idx == 1){
		disk[disk_idx] = to;
		result++;
	}else{
		hanoi(disk_idx - 1, from, to, by);
		disk[disk_idx] = to;
		result++;
		hanoi(disk_idx - 1, by, from, to); 
	}
}

int main(){
	int n, k;
	int start_disk;
	cin >> n >> k;
	// n은 dist 수, k 는 도착 rod;

	for(int i=1; i<=3; i++){
		int cnt_disk;
		cin >> cnt_disk;
		for(int j=0; j<cnt_disk; j++){
			int w;
			cin >> w;
			disk[w] = i;
		}
	}

	for(start_disk=n; start_disk>0; start_disk--){
		if(disk[start_disk] != k) break;
	}

	//start_disk-1 거를 목적지와, start_disk 있는 rod 말고 다른 곳에 나열되어 있어야함.
	int from = disk[start_disk-1];
	int to = 6-(disk[start_disk]+k);
	int by = 6-(from + to);
    cout << "ㅇㅇㅇ"<<start_disk-1 << from << by << to << "dd"<<endl;

	hanoi_default(start_disk-1, from, by, to);
	disk[start_disk] = k;
	result++;

	hanoi(start_disk-1, disk[start_disk-1], 6-(disk[start_disk-1]+k),k);

	cout << result << endl;

	return 0;
}