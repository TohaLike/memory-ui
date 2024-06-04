#pragma once
#include <vector>
#include <cstdint>
#include <Windows.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class MemoryUsageGraph {
private:
    std::vector<int> memoryUsageData;
    static const int maxMemoryUsagePoints = 60;

public:
    MemoryUsageGraph() {
        memoryUsageData = std::vector<int>(maxMemoryUsagePoints, 0);
    }

    void UpdateMemoryUsageData(int newValue) {
        memoryUsageData.erase(memoryUsageData.begin());
        memoryUsageData.push_back(newValue);
    }

    void DrawGraph(PaintEventArgs^ e) {
        Graphics^ g = e->Graphics;
        Pen^ pen = gcnew Pen(Color::Purple);

        int width = e->ClipRectangle.Width;
        int height = e->ClipRectangle.Height;
        int pointWidth = width / (memoryUsageData.size() - 1);

        for (int i = 1; i < memoryUsageData.size(); i++) {
            int x1 = (i - 1) * pointWidth;
            int y1 = height - (memoryUsageData[i - 1] * height / 100);
            int x2 = i * pointWidth;
            int y2 = height - (memoryUsageData[i] * height / 100);
            g->DrawLine(pen, x1, y1, x2, y2);
        }
    }
};

