#include "particle.h"
#include <Processing>
#include <vector>

using namespace processing;
using namespace std;

std::vector<Particle *> particles;

void reset_particle(Particle *p)
{
    float x = random(width);
    float y = random(height);
    float vx = random(-5, 5);
    float vy = random(-5, 5);
    float h = random(0, 255);
    float s = random(0, 255);
    color c(h, s, 255);
    p->setColor(c);
    p->setPosition(x, y);
    p->setVelocity(vx, vy);
}

void mousePressed()
{
    for (auto p : particles)
        reset_particle(p);
}

void setup()
{
    size(400, 300);
    setFrameRate(60);

    for (int i = 0; i < 100; i++)
    {
        Particle *p = new Particle(0, 0);
        reset_particle(p);
        particles.push_back(p);
    }

}

void draw()
{
    colorMode(RGB);
    background(204);
    colorMode(HSB);
    for (auto p : particles)
    {
        p->boundary();
        p->applyForce(gravity);
        p->update();
        p->show();
    }
}

void leave()
{
    for (auto p : particles)
        delete p;
}
