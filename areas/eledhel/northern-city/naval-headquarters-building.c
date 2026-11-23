//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("naval headquarters");
    setFloorPlanType("military");
    addDescriptionTemplate(
        "a low stone naval headquarters overlooking the northern docks");
    addTimeOfDayDescription("dawn", ({
        ". The watch changes as the first harbor bells sound",
        ". The water brightens below the quiet stone facade"
        }));
    addTimeOfDayDescription("morning", ({
        ". Officers and porters cross the quay with the day's orders",
        ". Sunlight catches the signal lamps above the harbor entrance"
        }));
    addTimeOfDayDescription("evening", ({
        ". Lanterns mark the guarded passage from the headquarters to the pier",
        ". The last cargo crews leave beneath the watchful upper windows"
        }));
    addTimeOfDayDescription("night", ({
        ". A small watch remains while the northern docks settle into quiet",
        ". The harbor lamps gleam against the dark stone and water"
        }));
}
