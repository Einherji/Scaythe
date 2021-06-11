//
// Created by matthiaso on 6/11/21.
//

#ifndef SCAYTHE_RENDERINGSTRUCTS_H
#define SCAYTHE_RENDERINGSTRUCTS_H


namespace Scaythe {
    struct vertex{
        float x, y, z;
    };
    struct textureCoords
    {
        float a,b;
    };
    struct polygon{
        int a, b, c;
    };
}


#endif //SCAYTHE_RENDERINGSTRUCTS_H
