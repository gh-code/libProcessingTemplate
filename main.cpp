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
    size(800, 600);
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
    background(204);
    fill(0, 100, 255);
    stroke(0, 40, 200);
    strokeWeight(4);
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
