//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Eledhel palace");
    setFloorPlanType("palace");
    addAdjectives(({ "white-stone", "plain", "guarded", "old" }));

    addDescriptionTemplate(
        "a modest royal compound of white stone, its separate wings "
        "gathered around a central hall"
    );
    addTimeOfDayDescription("morning", ({
        " as clerks, guards, and petitioners pass through the west gate"
    }));
    addTimeOfDayDescription("evening", ({
        " as household lamps appear behind the narrow upper windows"
    }));
    addTimeOfDayDescription("night", ({
        " with the gate watched and only a few upper rooms lit"
    }));
    addItemTemplate(
        "The palace is a guarded compound rather than a single grand block. "
        "Its central hall joins smaller court, household, and service wings; "
        "a west gate opens toward the old city's streets."
    );
    addSourceOfLight(3);
}
