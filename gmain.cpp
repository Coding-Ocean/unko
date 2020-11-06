#include"libOne.h"
#include"../title/title.h"
struct UNKO {
    float px, py, vy,flag=0;
};
const int NUM = 150;
struct UNKO unkos[NUM];
int img;
int addIdx = 0;
int drawIdx = 0;
float rad = 0;
void launch() {
    if (isPress(KEY_SPACE)) {
        angleMode(RADIANS);
        unkos[addIdx].flag = 1;
        unkos[addIdx].px = width / 2 + sin(rad) * 10;
        unkos[addIdx].py = -100;
        unkos[addIdx].vy = 10;
        ++addIdx %= NUM;
    }
    rad += 0.1f;
}
void move() {
    int idx = drawIdx;
    for (int i = 0; i < NUM; i++) {
        if (unkos[idx].flag) {
            unkos[idx].py += unkos[idx].vy;
            if (unkos[idx].py > height) {
                unkos[idx].flag = 0;
                drawIdx = (idx + 1) % NUM;
            }
        }
        ++idx %= NUM;
    }
}
void draw() {
    int idx = drawIdx;
    for (int i = 0; i < NUM; i++) {
        if (unkos[idx].flag) {
            image(img, unkos[idx].px, unkos[idx].py);
        }
        ++idx %= NUM;
    }
}

void gmain() {
    window(1920, 1080, 1);
    img = loadImage("assets/unchi.png");
    rectMode(CENTER);
    repeat() {
        launch();
        move();
        clear(220, 220, 0);
        draw();
        fill(0);
        textSize(50);
        text((float)addIdx, 0, 50);
        text((float)drawIdx, 0, 100);
        //title();
    }
}