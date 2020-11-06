#include"libOne.h"
struct UNKO {
    float px = 0, py = 0, vy = 0;
    int flag = 0;
};
//äOïîïœêîÇ≈çsÇ´Ç‹Ç∑
const int NUM = 300;
struct UNKO Unkos[NUM];
int UnkoImg = 0;
int CurIdx = 0;
int DrawIdx = 0;
float Radian = 0;
void load() {
    UnkoImg = loadImage("assets/unchi.png");
}
void launch() {
    angleMode(RADIANS);
    Unkos[CurIdx].flag = 1;
    Unkos[CurIdx].px = width / 2 + sin(Radian) * 10;
    Unkos[CurIdx].py = -100;
    Unkos[CurIdx].vy = 5;
    ++CurIdx %= NUM;
    Radian += 0.1f;
}
void move() {
    int idx = DrawIdx;
    for (int i = 0; i < NUM; i++) {
        if (Unkos[idx].flag) {
            Unkos[idx].py += Unkos[idx].vy;
            if (Unkos[idx].py > height) {
                Unkos[idx].flag = 0;
                DrawIdx = (idx + 1) % NUM;
            }
        }
        ++idx %= NUM;
    }
}
void draw() {
    rectMode(CENTER);
    int idx = DrawIdx;
    for (int i = 0; i < NUM; i++) {
        if (Unkos[idx].flag) {
            image(UnkoImg, Unkos[idx].px, Unkos[idx].py);
        }
        ++idx %= NUM;
    }
}

void gmain() {
    window(1920, 1080, 1);
    load();
    repeat() {
        if (isPress(KEY_SPACE)) {
            launch();
        }
        move();
        clear(220, 220, 0);
        draw();
#ifdef _DEBUG
        fill(0);
        textSize(50);
        text((float)CurIdx, 0, 50);
        text((float)DrawIdx, 0, 100);
#endif
    }
}