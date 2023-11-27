#pragma once
#include "Offsets.h"

HWND hWnd;
DWORD PID;
HANDLE hProcess;

uintptr_t client_DLL;
uintptr_t engine_DLL;

// ---------------------- CSGO -----------------------------

class Localplayer {
    uintptr_t addresses = 0;

public:
    void GetLocalplayer() {
        ReadProcessMemory(hProcess, (void*)(client_DLL + offsets->dwLocalPlayer), &addresses, sizeof(addresses), 0);
    }

    int m_iHealth() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_iHealth), &value, sizeof(value), 0);
        return value;
    }

    int m_iTeamNum() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_iTeamNum), &value, sizeof(value), 0);
        return value;
    }

    float m_vecOriginX() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_vecOrigin), &value, sizeof(value), 0);
        return value;
    }

    float m_vecOriginY() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_vecOrigin + 0x4), &value, sizeof(value), 0);
        return value;
    }

    float m_vecOriginZ() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_vecOrigin + 0x8), &value, sizeof(value), 0);
        return value;
    }

    int m_fFlags() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_fFlags), &value, sizeof(value), 0);
        return value;
    }

    int m_iCrosshairId() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_iCrosshairId), &value, sizeof(value), 0);
        return value;
    }

    float m_angEyeAnglesX() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_angEyeAnglesX), &value, sizeof(value), 0);
        return value;
    }

    float m_angEyeAnglesY() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_angEyeAnglesY), &value, sizeof(value), 0);
        return value;
    }

    int m_bSpottedByMask() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_bSpottedByMask), &value, sizeof(value), 0);
        return value;
    }
};
Localplayer* localplayer = new Localplayer();

class EntityList {
    uintptr_t addresses = 0;

public:
    void GetEntityList(int i) {
        ReadProcessMemory(hProcess, (void*)(client_DLL + offsets->dwEntityList + i * 0x10), &addresses, sizeof(addresses), 0);
    }

    int m_iHealth() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_iHealth), &value, sizeof(value), 0);
        return value;
    }

    int m_iTeamNum() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_iTeamNum), &value, sizeof(value), 0);
        return value;
    }

    float m_vecOriginX() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_vecOrigin), &value, sizeof(value), 0);
        return value;
    }

    float m_vecOriginY() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_vecOrigin + 0x4), &value, sizeof(value), 0);
        return value;
    }

    float m_vecOriginZ() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_vecOrigin + 0x8), &value, sizeof(value), 0);
        return value;
    }

    int m_fFlags() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_fFlags), &value, sizeof(value), 0);
        return value;
    }

    void ForceJump(int value) {
        WriteProcessMemory(hProcess, (void*)(client_DLL + offsets->dwForceJump), &value, sizeof(value), 0);
    }

    int m_bSpottedByMask() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_bSpottedByMask), &value, sizeof(value), 0);
        return value;
    }

    int m_iGlowIndex() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->m_iGlowIndex), &value, sizeof(value), 0);
        return value;
    }
};
EntityList* entitylist = new EntityList();

class Force {
public:
    void dwForceAttack(int value) {
        WriteProcessMemory(hProcess, (void*)(client_DLL + offsets->dwForceAttack), &value, sizeof(value), 0);
    }

    void dwForceAttack2(int value) {
        WriteProcessMemory(hProcess, (void*)(client_DLL + offsets->dwForceAttack2), &value, sizeof(value), 0);
    }

    void dwForceBackward(int value) {
        WriteProcessMemory(hProcess, (void*)(client_DLL + offsets->dwForceBackward), &value, sizeof(value), 0);
    }

    void dwForceForward(int value) {
        WriteProcessMemory(hProcess, (void*)(client_DLL + offsets->dwForceForward), &value, sizeof(value), 0);
    }

    void dwForceJump(int value) {
        WriteProcessMemory(hProcess, (void*)(client_DLL + offsets->dwForceJump), &value, sizeof(value), 0);
    }

    void dwForceLeft(int value) {
        WriteProcessMemory(hProcess, (void*)(client_DLL + offsets->dwForceLeft), &value, sizeof(value), 0);
    }

    void dwForceRight(int value) {
        WriteProcessMemory(hProcess, (void*)(client_DLL + offsets->dwForceRight), &value, sizeof(value), 0);
    }
};
Force* force = new Force();

class ClientState {
    uintptr_t addresses = 0;

public:
    void GetClientState() {
        ReadProcessMemory(hProcess, (void*)(engine_DLL + offsets->dwClientState), &addresses, sizeof(addresses), 0);
    }

    float dwClientState_ViewAnglesX() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->dwClientState_ViewAngles), &value, sizeof(value), 0);
        return value;
    }

    float dwClientState_ViewAnglesY() {
        float value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->dwClientState_ViewAngles + 0x4), &value, sizeof(value), 0);
        return value;
    }

    void SetdwClientState_ViewAnglesX(float value) {
        WriteProcessMemory(hProcess, (void*)(addresses + offsets->dwClientState_ViewAngles), &value, sizeof(value), 0);
    }

    void SetdwClientState_ViewAnglesY(float value) {
        WriteProcessMemory(hProcess, (void*)(addresses + offsets->dwClientState_ViewAngles + 0x4), &value, sizeof(value), 0);
    }

    int dwClientState_GetLocalPlayer() {
        int value;
        ReadProcessMemory(hProcess, (void*)(addresses + offsets->dwClientState_GetLocalPlayer), &value, sizeof(value), 0);
        return value;
    }
};
ClientState* clientstate = new ClientState();

class GlowObjectManager {
    uintptr_t addresses = 0;

public:
    void GetdwGlowObjectManager() {
        uintptr_t value;
        ReadProcessMemory(hProcess, (LPCVOID)(client_DLL + offsets->dwGlowObjectManager), &value, sizeof(value), NULL);
        addresses = value;
    }

    void SetColorR(uintptr_t glowIndex, float v) {
        WriteProcessMemory(hProcess, (void*)(addresses + (glowIndex * 0x38) + 0x8), &v, sizeof(v), NULL);
    }

    void SetColorG(uintptr_t glowIndex, float v) {
        WriteProcessMemory(hProcess, (void*)(addresses + (glowIndex * 0x38) + 0xC), &v, sizeof(v), NULL);
    }

    void SetColorB(uintptr_t glowIndex, float v) {
        WriteProcessMemory(hProcess, (void*)(addresses + (glowIndex * 0x38) + 0x10), &v, sizeof(v), NULL);
    }

    void SetColorA(uintptr_t glowIndex, float v) {
        WriteProcessMemory(hProcess, (void*)(addresses + (glowIndex * 0x38) + 0x14), &v, sizeof(v), NULL);
    }

    void SetColor1(uintptr_t glowIndex, bool v) {
        WriteProcessMemory(hProcess, (void*)(addresses + (glowIndex * 0x38) + 0x27), &v, sizeof(v), NULL);
    }

    void SetColor2(uintptr_t glowIndex, bool v) {
        WriteProcessMemory(hProcess, (void*)(addresses + (glowIndex * 0x38) + 0x28), &v, sizeof(v), NULL);
    }
};
GlowObjectManager* glowObjectManager = new GlowObjectManager();

// ---------------------- cheats ---------------------------

class Bhop {
public:
    bool Enable = false;

    void loop() {
        int flags = localplayer->m_fFlags();

        int buffer;
        if (flags & 1) {
            buffer = 5;
        }
        else {
            buffer = 4;
        }

        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            force->dwForceJump(buffer);
        }
    }
};
Bhop* bhop = new Bhop();

class AutoStrafe {
    float rot = 0;
    float rot_new = 0;

    bool one = false;

public:
    bool Enable = false;

    void loop() {
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (rot_new > rot) {
                rot = rot_new;
                // std::cout << "right" << std::endl;

                force->dwForceRight(0);
                force->dwForceLeft(1);

            }
            else if (rot_new < rot) {
                rot = rot_new;
                // std::cout << "left" << std::endl;

                force->dwForceLeft(0);
                force->dwForceRight(1);
            }

            rot_new = clientstate->dwClientState_ViewAnglesY();

            one = true;
        } else {
            rot = rot_new;

            if (one) {
                one = false;
                force->dwForceLeft(0);
                force->dwForceRight(0);
            }
        }
    }
};
AutoStrafe* autostrafe = new AutoStrafe();

class TriggerBot {
    bool one = true;

public:
    bool Enable = false;

    void loop() {
        int crosshair = localplayer->m_iCrosshairId();
        int localTeam = localplayer->m_iTeamNum();

        if (crosshair > 0 && crosshair < 64) {
            entitylist->GetEntityList(crosshair - 1);

            int health = entitylist->m_iHealth();

            if ((entitylist->m_iTeamNum() != localTeam && health > 0 && health < 101)) {
                if (one) {
                    force->dwForceAttack(1);
                    one = false;
                } else {
                    force->dwForceAttack(0);
                    one = true;
                }
            }
           
        } else {
            if (!one) {
                one = false;
                force->dwForceAttack(0);
            }
        }
    }
};
TriggerBot* triggerbot = new TriggerBot();

class AimBot {
    float map(float x, float in_min, float in_max, float out_min, float out_max) {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    void DrawFovCircle() {
        if (DrawFov) {
            float dis = map(Fov, 0, 35, 0, 0.5);

            glBegin(GL_LINES);
            glColor3f(1, 1, 1);

            float r = 0;

            for (int i = 0; i < 70; i++) {
                glVertex2f(0 + sin(r) * dis, 0 + cos(r) * (dis * 1.7));
                glVertex2f(0 + sin(r + 0.1) * dis, 0 + cos(r + 0.1) * (dis * 1.7));

                r += 0.1;
            }

            glEnd();
        }
    }

    void Shoot() {
        if (AutoShoot) {
            triggerbot->loop();
        }
    }

    void autoAim() {
        for (int i = 1; i < 64; i++) {
            entitylist->GetEntityList(i);

            if (SpottedByMask) {
                if (!(entitylist->m_bSpottedByMask() & (1 << clientstate->dwClientState_GetLocalPlayer()))) {
                    continue;
                }
            }

            int Health = entitylist->m_iHealth();

            if (Health > 0 && Health < 101) {
                if (entitylist->m_iTeamNum() != localplayer->m_iTeamNum()) {
                    float pos_x = entitylist->m_vecOriginX() - localplayer->m_vecOriginX();
                    float pos_y = entitylist->m_vecOriginY() - localplayer->m_vecOriginY();
                    float pos_z = entitylist->m_vecOriginZ() - localplayer->m_vecOriginZ() - 20;

                    float rot_x = atan2(pos_y, pos_x);
                    float rot_y = atan2(-pos_z, hypot(pos_x, pos_y));

                    float rot_x_new = map(rot_x, -3.1415, 3.1415, -180, 180);
                    float rot_y_new = map(rot_y, -1.57, 1.57, -89, 89);

                    float old_rot_x = clientstate->dwClientState_ViewAnglesX();
                    float old_rot_y = clientstate->dwClientState_ViewAnglesY();

                    if (
                        rot_x_new < clientstate->dwClientState_ViewAnglesY() + Fov &&
                        rot_x_new > clientstate->dwClientState_ViewAnglesY() - Fov &&

                        rot_y_new < clientstate->dwClientState_ViewAnglesX() + Fov &&
                        rot_y_new > clientstate->dwClientState_ViewAnglesX() - Fov
                    ) {
                        clientstate->SetdwClientState_ViewAnglesX(rot_y_new);
                        clientstate->SetdwClientState_ViewAnglesY(rot_x_new);

                        // clientstate->SetdwClientState_ViewAnglesX(old_rot_y + 0.5 * (rot_y_new - old_rot_y));
                        // clientstate->SetdwClientState_ViewAnglesY(old_rot_x + 0.5 * (rot_x_new - old_rot_x));
                    }
                }
            }
        }
    }

public:
    bool Enable = false;
    bool DrawFov = false;
    bool SpottedByMask = false;
    bool AutoShoot = false;
    bool ClickToAim = false;

    float Fov = 10;
    float smoothing = 1;

    void loop() {
        Shoot();
        DrawFovCircle();

        if (!ClickToAim || GetAsyncKeyState(VK_LBUTTON)) {
            autoAim();
        }
    }
};
AimBot* aimbot = new AimBot();

class Glow {
public:
    bool Enable = false;
    bool SpottedByMask = false;
    float Color[4] = {1, 0, 0, 1};
    float SpottedByMask_Color[4] = {1, 0, 0, 1};

    void loop() {
        glowObjectManager->GetdwGlowObjectManager();

        for (int i = 0; i < 64; i++) {
            entitylist->GetEntityList(i);

            if (entitylist->m_iTeamNum() == localplayer->m_iTeamNum()) {
                continue;
            }

            int glowIndex = entitylist->m_iGlowIndex();

            bool s = entitylist->m_bSpottedByMask() & (1 << clientstate->dwClientState_GetLocalPlayer());

            if (SpottedByMask && s) {
                glowObjectManager->SetColorR(glowIndex, SpottedByMask_Color[0]);
                glowObjectManager->SetColorG(glowIndex, SpottedByMask_Color[1]);
                glowObjectManager->SetColorB(glowIndex, SpottedByMask_Color[2]);
                glowObjectManager->SetColorA(glowIndex, SpottedByMask_Color[3]);

            } else {
                glowObjectManager->SetColorR(glowIndex, Color[0]);
                glowObjectManager->SetColorG(glowIndex, Color[1]);
                glowObjectManager->SetColorB(glowIndex, Color[2]);
                glowObjectManager->SetColorA(glowIndex, Color[3]);

            }

            glowObjectManager->SetColor1(glowIndex, true);
            glowObjectManager->SetColor2(glowIndex, true);
        }
    }
};
Glow* glow = new Glow();

// ---------------------- menu -----------------------------

class Window {
    bool insert = false;
    bool menu_open = true;

public:
	void setup();
	void loop(GLFWwindow* window);
	void WaterMark();
	void Style();
    void OpenClose(GLFWwindow* window);
    void Menu();
    void Cheatloop();
    void CheatSetup();
    void Tabs();
    void Tab1_Visuals();
    void Tab2_Legit();
    void Tab3_Misc();
    void Tab4_Skins();
    uintptr_t GetModuleBaseAddress(const char* modName);
};

void Window::Style() {
    ImVec4* colors = ImGui::GetStyle().Colors;

    colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
    colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
    colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
    colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
    colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_TableHeaderBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
    colors[ImGuiCol_TableBorderStrong] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
    colors[ImGuiCol_TableBorderLight] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
    colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
    colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

    ImGuiStyle& style = ImGui::GetStyle();

    style.WindowPadding = ImVec2(8.00f, 8.00f);
    style.FramePadding = ImVec2(5.00f, 2.00f);
    style.CellPadding = ImVec2(6.00f, 6.00f);
    style.ItemSpacing = ImVec2(6.00f, 6.00f);
    style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
    style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
    style.IndentSpacing = 25;
    style.ScrollbarSize = 15;
    style.GrabMinSize = 10;
    style.WindowBorderSize = 1;
    style.ChildBorderSize = 1;
    style.PopupBorderSize = 1;
    style.FrameBorderSize = 1;
    style.TabBorderSize = 3;
    style.WindowRounding = 7;
    style.ChildRounding = 4;
    style.FrameRounding = 3;
    style.PopupRounding = 4;
    style.ScrollbarRounding = 9;
    style.GrabRounding = 3;
    style.LogSliderDeadzone = 4;
    style.TabRounding = 3;
}

uintptr_t Window::GetModuleBaseAddress(const char* modName) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, PID);
    if (hSnap != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(hSnap, &modEntry)) {
            do {
                if (!strcmp(modEntry.szModule, modName)) {
                    CloseHandle(hSnap);
                    return (uintptr_t)modEntry.modBaseAddr;
                }
            } while (Module32Next(hSnap, &modEntry));
        }
    }
}

void Window::CheatSetup() {
    hWnd = FindWindowA(NULL, "Counter-Strike: Global Offensive - Direct3D 9");
    GetWindowThreadProcessId(hWnd, &PID);
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, PID);

    client_DLL = GetModuleBaseAddress("client.dll");
    engine_DLL = GetModuleBaseAddress("engine.dll");
    
    std::cout << "hWnd: " << hWnd << std::endl;
    std::cout << "PID: " << PID << std::endl;
    std::cout << "hProcess: " << hProcess << std::endl;

    std::cout << "client_DLL: " << client_DLL << std::endl;
    std::cout << "engine_DLL: " << engine_DLL << std::endl;
}

void Window::setup() {
    Style();
    CheatSetup();
}

void Window::WaterMark() {
	ImGui::SetNextWindowPos(ImVec2(10, 10));
	ImGui::SetNextWindowSize(ImVec2(80, 15));
	ImGui::Begin("WaterMark", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
	ImGui::Text("RetroWare");
	ImGui::End();
}

void Window::Tab1_Visuals() {
    ImGui::SetCursorPos(ImVec2(10, 50));
    ImGui::BeginChildFrame('1', ImVec2(310, 392), 0);

    ImGui::Checkbox("Glow  ", &glow->Enable);
    ImGui::SameLine();
    ImGui::SetCursorPosX(285);
    ImGui::ColorEdit4("##Glow Color", glow->Color, ImGuiColorEditFlags_NoInputs);

    ImGui::Checkbox("Glow SpottedByMask", &glow->SpottedByMask);
    ImGui::SameLine();
    ImGui::SetCursorPosX(285);
    ImGui::ColorEdit4("##Glow SpottedByMask Color", glow->SpottedByMask_Color, ImGuiColorEditFlags_NoInputs);


    ImGui::EndChild();

    ImGui::SetCursorPos(ImVec2(310 + 20, 50));
    ImGui::BeginChildFrame('2', ImVec2(310, 392), 0);

    ImGui::Checkbox("Draw AimBotFov", &aimbot->DrawFov);

    ImGui::EndChild();
}

void Window::Tab2_Legit() {
    ImGui::SetCursorPos(ImVec2(10, 50));
    ImGui::BeginChildFrame('1', ImVec2(310, 392), 0);

    ImGui::Checkbox("AimBot", &aimbot->Enable);
    ImGui::Checkbox("SpottedByMask", &aimbot->SpottedByMask);
    ImGui::Checkbox("AutoShoot", &aimbot->AutoShoot);
    ImGui::Checkbox("ClickToAim", &aimbot->ClickToAim);
    // ImGui::SliderFloat("Smoothing", &aimbot->smoothing, 0, 1000);
    ImGui::SliderFloat("Fov", &aimbot->Fov, 0, 30);

    ImGui::EndChild();

    ImGui::SetCursorPos(ImVec2(310 + 20, 50));
    ImGui::BeginChildFrame('2', ImVec2(310, 392), 0);

    ImGui::Checkbox("TriggerBot", &triggerbot->Enable);

    ImGui::EndChild();
}

void Window::Tab3_Misc() {
    ImGui::SetCursorPos(ImVec2(10, 50));
    ImGui::BeginChildFrame('1', ImVec2(310, 392), 0);

    ImGui::Checkbox("Bhop", &bhop->Enable);
    ImGui::Checkbox("AutoStrafe", &autostrafe->Enable);

    ImGui::EndChild();

    ImGui::SetCursorPos(ImVec2(310 + 20, 50));
    ImGui::BeginChildFrame('2', ImVec2(310, 392), 0);

    ImGui::EndChild();
}

void Window::Tab4_Skins() {
    ImGui::SetCursorPos(ImVec2(10, 50));
    ImGui::BeginChildFrame('1', ImVec2(310, 392), 0);

    ImGui::EndChild();

    ImGui::SetCursorPos(ImVec2(310 + 20, 50));
    ImGui::BeginChildFrame('2', ImVec2(310, 392), 0);

    ImGui::EndChild();
}

void Window::Tabs() {
    ImGui::BeginTabBar("Tabs");

    if (ImGui::BeginTabItem("Visuals")) {
        Tab1_Visuals();
        ImGui::EndTabItem();
    }

    if (ImGui::BeginTabItem("Legit")) {
        Tab2_Legit();
        ImGui::EndTabItem();
    }

    if (ImGui::BeginTabItem("Misc")) {
        Tab3_Misc();
        ImGui::EndTabItem();
    }

    if (ImGui::BeginTabItem("Skins")) {
        Tab4_Skins();
        ImGui::EndTabItem();
    }

    ImGui::EndTabBar();
}

void Window::Menu() {
    ImGui::SetNextWindowSize(ImVec2(650, 450));
	ImGui::Begin("RetroWare V1.0", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    Tabs();

	ImGui::End();
}

void Window::OpenClose(GLFWwindow* window) {
    if (insert && (GetKeyState(VK_INSERT) & 0x8000)) {
        insert = false;
        menu_open = !menu_open;
    }

    if (!(GetKeyState(VK_INSERT) & 0x8000)) {
        insert = true;
    }

    if (menu_open) {
        glfwSetWindowAttrib(window, GLFW_MOUSE_PASSTHROUGH, false);
        Menu();
    } else {
        glfwSetWindowAttrib(window, GLFW_MOUSE_PASSTHROUGH, true);

    }
}

void Window::loop(GLFWwindow* window) {
    OpenClose(window);

	WaterMark();
}

void Window::Cheatloop() {
    localplayer->GetLocalplayer();
    clientstate->GetClientState();

    if (bhop->Enable) {
        bhop->loop();
    }

    if (triggerbot->Enable) {
        triggerbot->loop();
    }

    if (autostrafe->Enable) {
        autostrafe->loop();
    }

    if (aimbot->Enable) {
        aimbot->loop();
    }

    if (glow->Enable) {
        glow->loop();
    }
}

Window* window = new Window();