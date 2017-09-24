/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "RageJavaCore.hpp"

bool RageJavaCore::initialize(rage::IMultiplayer *mp) {
    this->mp = mp;
    if (!JVM::VM::create()) {
        return false;
    }
    try {
        mp->AddEventHandler(new PlayerEventHandler);
        mp->AddEventHandler(new VehicleEventHandler);
        mp->AddEventHandler(new ColshapeEventHandler);
        mp->AddEventHandler(new CheckpointEventHandler);
    } catch (ClassNotFoundException &e) {
        std::cout << "ClassNotFoundException: " << e.what() << std::endl;
        return false;
    } catch (MethodNotFoundException &e) {
        std::cout << "MethodNotFoundException: " << e.what() << std::endl;
        return false;
    }
    return true;
}
