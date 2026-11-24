//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/investigationRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addItem("/areas/tol-dhurath/items/chapel-register.c", "north");
    addInvestigationClue("chapel register",
        "/areas/minlach/quests/safe-seam.c", "readChapelRegister",
        "The carved record says the spring and cave path were maintained "
        "by local foresters and miners in rotation. It names no house as "
        "owner and records the closure of the adit after a roof fall.");

    addExit("east", "/areas/tol-dhurath/forest-5/14x7.c");
}
