#include <iostream>

#include <Windows.h>

#pragma comment(lib,"winmm.lib")

using namespace std;



enum Scale

{

Rest = 0, C8 = 108, B7 = 107, A7s = 106, A7 = 105, G7s = 104, G7 = 103, F7s = 102, F7 = 101, E7 = 100,

D7s = 99, D7 = 98, C7s = 97, C7 = 96, B6 = 95, A6s = 94, A6 = 93, G6s = 92, G6 = 91, F6s = 90, F6 = 89,

E6 = 88, D6s = 87, D6 = 86, C6s = 85, C6 = 84, B5 = 83, A5s = 82, A5 = 81, G5s = 80, G5 = 79, F5s = 78,

F5 = 77, E5 = 76, D5s = 75, D5 = 74, C5s = 73, C5 = 72, B4 = 71, A4s = 70, A4 = 69, G4s = 68, G4 = 67,

F4s = 66, F4 = 65, E4 = 64, D4s = 63, D4 = 62, C4s = 61, C4 = 60, B3 = 59, A3s = 58, A3 = 57, G3s = 56,

G3 = 55, F3s = 54, F3 = 53, E3 = 52, D3s = 51, D3 = 50, C3s = 49, C3 = 48, B2 = 47, A2s = 46, A2 = 45,

G2s = 44, G2 = 43, F2s = 42, F2 = 41, E2 = 40, D2s = 39, D2 = 38, C2s = 37, C2 = 36, B1 = 35, A1s = 34,

A1 = 33, G1s = 32, G1 = 31, F1s = 30, F1 = 29, E1 = 28, D1s = 27, D1 = 26, C1s = 25, C1 = 24, B0 = 23,

A0s = 22, A0 = 21

};

enum Voice

{

X1 = C2, X2 = D2, X3 = E2, X4 = F2, X5 = G2, X6 = A2, X7 = B2,

L1 = C3, L2 = D3, L3 = E3, L4 = F3, L5 = G3, L6 = A3, L7 = B3,

M1 = C4, M2 = D4, M3 = E4, M4 = F4, M5 = G4, M6 = A4, M7 = B4,

H1 = C5, H2 = D5, H3 = E5, H4 = F5, H5 = G5, H6 = A5, H7 = B5,

_ = 0XFF

};

void TH()

{

HMIDIOUT handle;

midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);

int volume = 0x7f;

int voice = 0x0;

int sleep = 300;int tmp =5;

int th[] =

{

H3,_,_,_,_,_,H3,700,0,H2,300,H2,700,0,H1,300,H1,_,_,_,H1,700,0,M7,300,M7,700,0,M6,300,M6,_,_,_,M6,700,0,M5,300,M5,_,_,_,_,L5,M1,L7,M1,700,0,L5,300,L5,_,

_,L5,M1,L7,M1,700,0,L5,300,L5,_,_,L5,M1,L7,M1,_,_,M1,M1,L6,L6,L5,L5,_,_,_,_,L5,M1,L7,M1,L5,L5,_,_,L5,M3,700,0,M2,300,M2,M1,M1,_,_,L5,M1,L7,M1,L6,_,L6,L6,M1,M6,M5,M5,_,_,_,_,

M2,M2,M4,M4,M3,M3,_,_,

M3,M2,L7,M2,700,0,M1,300,M1,0,L7,M1,300,_,

M1,L7,M1,M4,_,_,L5,M5,M4,M3,M2,M2,_,_,_,_,

M2,M2,M4,M4,M3,M3,_,_,M3,M3,M7,M7,M6,M7,H1,_,H1,M2,M1,M6,_,_,M6,M6,M5,M5,M5,M5,_,_,_,_,

L5,M5,M4,M3,_,M3,0,M4,M3,300,_,_,M3,M4,M3,M4,M3,0,M2,M1,300,_,M1,M3,M5,M6,_,M6,0,M6,M5,300,M5,M2,M2,0,M4,M3,300,M3,_,_,_,_,

M1,M3,M5,M6,_,M6,0,M6,M5,300,M5,M2,M2,M4,M3,M4,M3,0,M2,M1,300,M1,_,M2,0,M2,M3,300,L6,_,L6,M1,M1,_,L7,_,M1,_,_,_,

_,M3,M4,M5,M6,_,_,M5,M5,_,M6,_,M5,_,M5,_,

M5,M2,M2,M4,M4,M3,M3,_,_,

M3,M2,L7,M2,700,0,M1,300,M1,0,L7,M1,300,_,

M1,L7,M1,M4,_,_,L5,M5,M4,M3,M2,M2,_,_,_,_,

M2,M2,M4,M4,M3,M3,_,_,M3,M3,M7,M7,M6,M7,H1,_,H1,M2,M1,M6,_,_,M6,M6,M5,M5,M5,M5,_,_,_,_,

L5,M5,M4,M3,_,M3,0,M4,M3,300,_,_,M3,M4,M3,M4,M3,0,M2,M1,300,_,M1,M3,M5,M6,_,M6,0,M6,M5,300,M5,M2,M2,0,M4,M3,300,M3,_,_,_,_,

M1,M3,M5,M6,_,M6,0,M6,M5,300,M5,M2,M2,M4,M3,M4,M3,0,M2,M1,300,M1,_,M2,0,M2,M3,300,L6,_,L6,M1,M1,_,L7,_,M1,_,_,_,

L5,M5,M4,M3,_,M3,0,M4,M3,300,_,_,M3,M4,M3,M4,M3,0,M2,M1,300,_,M1,M3,M5,M6,_,M6,0,M6,M5,300,M5,M2,M2,0,M4,M3,300,M3,_,_,_,_,

M1,M3,M5,M6,_,M6,0,M6,M5,300,M5,M2,M2,M4,M3,M4,M3,0,M2,M1,300,M1,_,M2,0,M2,M3,300,L6,_,L6,M1,M1,_,L7,_,M1,_,_,_,

L5,M5,M4,M3,_,M3,0,M4,M3,300,_,_,M3,M4,M3,M4,M3,0,M2,M1,300,_,M1,M3,M5,M6,_,M6,0,M6,M5,300,M5,M2,M2,0,M4,M3,300,M3,_,_,_,_,

M1,M3,M5,M6,_,M6,0,M6,M7,300,M7,M6,M5,M4,M3,M4,M3,0,M2,M1,300,M1,_,M2,0,M2,M3,300,L6,_,L6,M1,M1,L7,L7,M1,M1,_,_,_,_,_,M2,0,M2,M3,300,0,M3,M2,M3,M2,M1,M2,300,M1,M1,_,M2,0,M2,M3,300,L6,_,L6,M1,M1,L7,L7,M1,M1,_,_,_,_,_,_,_,M1,_,_,_,_,_,_,_,M1,_,_,_,_,_,_,_,



};

for (auto i : th) {

if (i == 300) { sleep = 300;continue; }

if (i == 0) { sleep =150;continue; }

if (i == 700) { Sleep(150);continue; }

if (i == _) {

Sleep(300);

continue;

}



if (i == 1000) { tmp = +5;continue; }

voice = (volume << 16) + ((i + tmp) << 8) + 0x90;

midiOutShortMsg(handle, voice);

cout << voice << endl;

Sleep(sleep);

}

midiOutClose(handle);

}



int main()

{



TH();

return 0;

}
