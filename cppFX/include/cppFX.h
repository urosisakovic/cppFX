#pragma once

// This file should be included by client applications.
// It should not be included anywhere in cppFX implementation.

// Entry point class-----------------------------------------------------------
#include "../src/application.h"
//-----------------------------------------------------------------------------

// OpenGL abstractions
#include "../src/node.h"
#include "../src/cube.h"
#include "../src/group.h"
#include "../src/stage.h"

// Event system
#include "../src/events/event.h"
#include "../src/events/eventDispatcher.h"
#include "../src/events/keyEvent.h"
#include "../src/events/mouseEvent.h"
#include "../src/events/applicationEvent.h"

