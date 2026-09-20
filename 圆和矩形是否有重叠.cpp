#include <cmath>
#include <cstdlib>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        // 圆心在矩形内时，两者一定重叠
        if (xCenter >= x1 && xCenter <= x2 &&
            yCenter >= y1 && yCenter <= y2) {
            return true;
        }

        // x = x1 这条边
        if (yCenter >= y2) {
            double d = std::sqrt(1.0 * (xCenter - x1) * (xCenter - x1) +
                                  1.0 * (yCenter - y2) * (yCenter - y2));
            if (d <= radius) return true;
        } else if (yCenter <= y1) {
            double d = std::sqrt(1.0 * (xCenter - x1) * (xCenter - x1) +
                                  1.0 * (yCenter - y1) * (yCenter - y1));
            if (d <= radius) return true;
        } else if (std::abs(xCenter - x1) <= radius) {
            return true;
        }

        // x = x2 这条边
        if (yCenter >= y2) {
            double d = std::sqrt(1.0 * (xCenter - x2) * (xCenter - x2) +
                                  1.0 * (yCenter - y2) * (yCenter - y2));
            if (d <= radius) return true;
        } else if (yCenter <= y1) {
            double d = std::sqrt(1.0 * (xCenter - x2) * (xCenter - x2) +
                                  1.0 * (yCenter - y1) * (yCenter - y1));
            if (d <= radius) return true;
        } else if (std::abs(xCenter - x2) <= radius) {
            return true;
        }

        // y = y1 这条边
        if (xCenter >= x2) {
            double d = std::sqrt(1.0 * (xCenter - x2) * (xCenter - x2) +
                                  1.0 * (yCenter - y1) * (yCenter - y1));
            if (d <= radius) return true;
        } else if (xCenter <= x1) {
            double d = std::sqrt(1.0 * (xCenter - x1) * (xCenter - x1) +
                                  1.0 * (yCenter - y1) * (yCenter - y1));
            if (d <= radius) return true;
        } else if (std::abs(yCenter - y1) <= radius) {
            return true;
        }

        // y = y2 这条边
        if (xCenter >= x2) {
            double d = std::sqrt(1.0 * (xCenter - x2) * (xCenter - x2) +
                                  1.0 * (yCenter - y2) * (yCenter - y2));
            if (d <= radius) return true;
        } else if (xCenter <= x1) {
            double d = std::sqrt(1.0 * (xCenter - x1) * (xCenter - x1) +
                                  1.0 * (yCenter - y2) * (yCenter - y2));
            if (d <= radius) return true;
        } else if (std::abs(yCenter - y2) <= radius) {
            return true;
        }

        return false;
    }
};
