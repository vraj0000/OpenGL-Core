#ifndef RAY_H
#define RAY_H

#include "../glm/glm.hpp"
#include "precision.h"

class ray {
    public:
        ray() {}
        ray(const glm::vec3& origin, const glm::vec3& direction)
            : orig(origin), dir(direction)
        {}

        glm::vec3 origin() const  { return orig; }
        glm::vec3 direction() const { return dir; }

        void set_direction(const glm::vec3& direc)
        {
            dir = direc;
        }

        glm::vec3 at(real t) const {
            return orig + dir*t;
        }

    public:
        glm::vec3 orig;
        glm::vec3 dir;
};


#endif