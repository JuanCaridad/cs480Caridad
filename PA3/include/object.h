#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"

class Object
{
  public:
    Object(bool moon, float scale, float orbitSpeed, float spinSpeed, Object *p);
    ~Object();
    void Update(unsigned int dt, glm::mat4 origin);
    void Render();

    glm::mat4 GetModel();
    glm::mat4 GetPosition();
    
    Object *parent;
    
    void Scale(bool scalar);
    void OrbitSpeed(bool speed);
    void SpinSpeed(bool speed);
    
    bool rev_Orbit;
    bool pauseOrbit;
    bool rev_Spin;
    bool pauseSpin;

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;
    
    glm::mat4 position;//position of object
    float rot_angle;
    float spin_angle;
    
    bool Moon;
    
    //variables used for scaling
    float defaultScale, scaleMultiplier, maxScale, minScale;
    
    //variables for object orbit and spin
    float defaultOrbSpeed, defaultSpinSpeed, orbSpeedMultiplier,spinSpeedMultiplier, maxSpeed, minSpeed;
    
    
};

#endif /* OBJECT_H */
