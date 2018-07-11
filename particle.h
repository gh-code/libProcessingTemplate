#ifndef PARTICLE_H
#define PARTICLE_H

#include <Processing>

using namespace processing;

const float gravity = -0.098;

class Particle
{
public:
    Particle(float x, float y) : r(16), vx(0), vy(0), x(x), y(y) {}

    void setPosition(float x_, float y_) { x = x_; y = y_; }
    void setVelocity(float vx_, float vy_) { vx = vx_; vy = vy_; }
    void applyForce(float fy) { vy -= fy; }
    void update() { x += vx; y += vy; }
    void show() {
        ellipse(x, y, 2 * r, 2 * r);
    }
    void boundary() {
        if (x < r) {
            x = r;
            vx *= -0.9;
        }
        if (x > width - r) {
            x = width - r;
            vx *= -0.9;
        }
        if (y < r) {
            y = r;
            vy *= -1.0;
        }
        if (y > height - r) {
            y = height - r;
            vy *= -0.8;
        }
        if (y == height -r)
            vx *= 0.9;
    }

    float r;
    float vx;
    float vy;
    float x;
    float y;
};

#endif // PARTICLE_H
