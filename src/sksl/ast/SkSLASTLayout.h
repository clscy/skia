/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
 
#ifndef SKSL_ASTLAYOUT
#define SKSL_ASTLAYOUT

#include "SkSLASTNode.h"
#include "SkSLUtil.h"

namespace SkSL {

/**
 * Represents a layout block appearing before a variable declaration, as in:
 *
 * layout (location = 0) int x;
 */
struct ASTLayout : public ASTNode {
    // For int parameters, a -1 means no value
    ASTLayout(int location, int binding, int index, int set, int builtin, bool originUpperLeft,
              bool overrideCoverage, bool blendSupportAllEquations, bool pushConstant)
    : fLocation(location)
    , fBinding(binding)
    , fIndex(index)
    , fSet(set)
    , fBuiltin(builtin)
    , fOriginUpperLeft(originUpperLeft)
    , fOverrideCoverage(overrideCoverage)
    , fBlendSupportAllEquations(blendSupportAllEquations)
    , fPushConstant(pushConstant) {}

    std::string description() const {
        std::string result;
        std::string separator;
        if (fLocation >= 0) {
            result += separator + "location = " + to_string(fLocation);
            separator = ", ";
        }
        if (fBinding >= 0) {
            result += separator + "binding = " + to_string(fBinding);
            separator = ", ";
        }
        if (fIndex >= 0) {
            result += separator + "index = " + to_string(fIndex);
            separator = ", ";
        }
        if (fSet >= 0) {
            result += separator + "set = " + to_string(fSet);
            separator = ", ";
        }
        if (fBuiltin >= 0) {
            result += separator + "builtin = " + to_string(fBuiltin);
            separator = ", ";
        }
        if (fOriginUpperLeft) {
            result += separator + "origin_upper_left";
            separator = ", ";
        }
        if (fOverrideCoverage) {
            result += separator + "override_coverage";
            separator = ", ";
        }
        if (fBlendSupportAllEquations) {
            result += separator + "blend_support_all_equations";
            separator = ", ";
        }
        if (fPushConstant) {
            result += separator + "push_constant";
            separator = ", ";
        }
        if (result.length() > 0) {
            result = "layout (" + result + ")";
        }
        return result;
    }

    const int fLocation;
    const int fBinding;
    const int fIndex;
    const int fSet;
    const int fBuiltin;
    const bool fOriginUpperLeft;
    const bool fOverrideCoverage;
    const bool fBlendSupportAllEquations;
    const bool fPushConstant;
};

} // namespace

#endif
