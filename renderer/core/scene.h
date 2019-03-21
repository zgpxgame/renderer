#ifndef SCENE_H
#define SCENE_H

#include "geometry.h"
#include "graphics.h"
#include "mesh.h"
#include "skeleton.h"
#include "texture.h"

typedef struct {
    float frame_time;
    float delta_time;
    vec3_t light_dir;
    vec3_t camera_pos;
    mat4_t light_view_matrix;
    mat4_t light_proj_matrix;
    mat4_t camera_view_matrix;
    mat4_t camera_proj_matrix;
    texture_t *shadow_map;
} perframe_t;

typedef struct model {
    mesh_t *mesh;
    mat4_t transform;
    program_t *program;
    skeleton_t *skeleton;
    /* generic functions */
    void (*draw)(struct model *model, framebuffer_t *fbuffer, int shadow_pass);
    void (*update)(struct model *model, perframe_t *perframe);
    void (*release)(struct model *model);
    /* for model sorting */
    int opaque;
    float distance;
} model_t;

typedef struct scene {
    vec4_t background;
    model_t *skybox;
    model_t **models;
    /* for shadow mapping */
    int with_shadow;
    framebuffer_t *shadow_fb;
    texture_t *shadow_map;
} scene_t;

#endif
