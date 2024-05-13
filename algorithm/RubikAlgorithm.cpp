//
// Created by KOSTJA on 25.02.2024.
//

#include "RubikAlgorithm.h"

void RubikAlgorithm::solve() {
    while (!FirstLayer::isWhiteCrossCorrect()) {
        FirstLayer::buildWhiteEdges(7);
        FirstLayer::buildWhiteEdges(15);
        FirstLayer::buildWhiteEdges(17);
        FirstLayer::buildWhiteEdges(25);
    }

    FirstLayer::buildWhiteCorners(6);
    FirstLayer::buildWhiteCorners(8);
    FirstLayer::buildWhiteCorners(24);
    FirstLayer::buildWhiteCorners(26);

    BuildSecondLayer::buildSecondEdges(3);
    BuildSecondLayer::buildSecondEdges(5);
    BuildSecondLayer::buildSecondEdges(21);
    BuildSecondLayer::buildSecondEdges(23);

    ThirdLayer::yellowEdgesFlips();
    ThirdLayer::moveYellowEdges();
    ThirdLayer::moveYellowCorners();
    ThirdLayer::rotateYellowCorners();
}
