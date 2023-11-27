#include <array>
#include <cmath>
#include <thread>
#include <numbers>
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Window.h"

// mp_roundtime_defuse 60; mp_autoteambalance 0; mp_restartgame 1; mp_limitteams 0;
// sv_cheats 1; mp_drop_knife_enable 1; mp_items_prohibited 0; give weapon_knife_m9_bayonet; ent_fire weapon_knife addoutput "classname weapon_knifegg"
// sv_cheats 1; mp_drop_knife_enable 1; mp_items_prohibited 0; give weapon_knife_karambit; ent_fire weapon_knife addoutput "classname weapon_knifegg"
// sv_cheats 1; mp_drop_knife_enable 1; mp_items_prohibited 0; give weapon_knife_stiletto; ent_fire weapon_knife addoutput "classname weapon_knifegg"

// sv_cheats 1; mp_roundtime_defuse 60; bot_zombie 1; mp_restartgame 1;

class Main {
    GLFWwindow* glfwwindow;
    GLFWmonitor* glfwPrimaryMonitor;

public:
    void setupImGui();
    void setup();
    void loop();
    bool ShouldClose();
    void Terminate();
    void ImguiNewFrame();
    void ImguiRender();
};

void Main::setupImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(glfwwindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void Main::setup() {
    glfwInit();

    glfwPrimaryMonitor = glfwGetPrimaryMonitor();

    int window_width = glfwGetVideoMode(glfwPrimaryMonitor)->width;
    int window_height = glfwGetVideoMode(glfwPrimaryMonitor)->height;

    glfwWindowHint(GLFW_FLOATING, true);
    glfwWindowHint(GLFW_RESIZABLE, false);
    // glfwWindowHint(GLFW_MAXIMIZED, true);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, true);

    // glfwwindow = glfwCreateWindow(window_width, window_height, "RetroWare.cc", NULL, NULL);
    glfwwindow = glfwCreateWindow(1176, 664, "RetroWare", NULL, NULL);

    glfwMakeContextCurrent(glfwwindow);

    glfwSetWindowAttrib(glfwwindow, GLFW_DECORATED, false);
    // glfwSetWindowAttrib(glfwwindow, GLFW_MOUSE_PASSTHROUGH, true);

    glfwSetWindowPos(glfwwindow, 745, 376);

    setupImGui();
    window->setup();
}

void Main::ImguiNewFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Main::ImguiRender() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Main::loop() {
    glClear(GL_COLOR_BUFFER_BIT);
    ImguiNewFrame();

    window->loop(glfwwindow);
    
    ImguiRender();

    window->Cheatloop();

    glfwSwapBuffers(glfwwindow);
    glfwPollEvents();
    glfwSwapInterval(0);
}

bool Main::ShouldClose() {
    return glfwWindowShouldClose(glfwwindow);
}

void Main::Terminate() {
    glfwTerminate();
}

int main() {
    Main* main = new Main();

    main->setup();
    
    while (!main->ShouldClose()) {
        main->loop();
    }
    
    main->Terminate();
    return 0;
}