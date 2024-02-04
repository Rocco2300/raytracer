#include "Image.hpp"

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <iostream>

const int Width  = 1280;
const int Height = 720;

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW init failed!\n";
        glfwTerminate();
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    GLFWwindow* window = glfwCreateWindow(Width, Height, "Raytracer", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (gl3wInit()) {
        std::cerr << "GL3W init failed!\n";
        glfwTerminate();
        return -1;
    }

    const uint32_t imageWidth  = 256;
    const uint32_t imageHeight = 256;
    Image image(imageWidth, imageHeight);
    for (size_t y = 0; y < imageHeight; y++) {
        for (size_t x = 0; x < imageWidth; x++) {
            image.setPixel(x, y, Color(x, y, 32));
        }
    }

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
    auto* data = image.getPixelData();
    for (size_t y = 0; y < imageHeight; y++) {
        for (size_t x = 0; x < imageWidth; x++) {
            const int index  = y * imageWidth + x;
            const auto pixel = data[index];

            std::cout << static_cast<uint16_t>(pixel.r) << ' ' << static_cast<uint16_t>(pixel.g)
                      << ' ' << static_cast<uint16_t>(pixel.b) << '\n';
        }
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClearColor(160.f / 255.f, 202.f / 255.f, 146.f / 255.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos({0.f, 0.f});
        ImGui::SetNextWindowSize({io.DisplaySize});
        ImGui::Begin("App", nullptr,
                     ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize |
                             ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
                             ImGuiWindowFlags_NoNavFocus);
        auto id = ImGui::GetID("dockspace");
        ImGui::DockSpace(id);
        ImGui::End();

        ImGui::Begin("Viewport");
        //ImGui::Image()
        ImGui::End();

        ImGui::Begin("Inspector");
        ImGui::End();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}