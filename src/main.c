#include "rayfork/rayfork.h"
#include "glad/glad.h"
#include "glfw/include/GLFW/glfw3.h"

#ifndef ASSETS_PATH
#define ASSETS_PATH
#endif

int main()
{
    // Init glfw and opengl
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 450, "rayfork simple glfw example", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    gladLoadGL();

    // Init rayfork
    rf_context rf_ctx = {0};
    rf_render_batch batch;

    // Initialize rayfork
    rf_init_context(&rf_ctx);
    rf_init_gfx(800, 450, RF_DEFAULT_GFX_BACKEND_INIT_DATA);

    // Initialize the rendering batch
    batch = rf_create_default_render_batch(RF_DEFAULT_ALLOCATOR);
    rf_set_active_render_batch(&batch);

    // Load a texture with the default libc allocator and io callbacks.
    rf_texture2d texture = rf_load_texture_from_file_ez(ASSETS_PATH"test.png");

    // Main game loop
    while (!glfwWindowShouldClose(window))
    {
        // Render the image and clear the background to some nice shade of white
        rf_begin();
        rf_clear(RF_RAYWHITE);
        rf_draw_rectangle(0, 0, 100, 100, RF_RED);
        rf_draw_texture(texture, 0, 0, RF_WHITE);
        rf_end();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}