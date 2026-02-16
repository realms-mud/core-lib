//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Hypnotic Gaze Active");
    addSpecification("root", "mesmerize");
    addSpecification("description", "You are fixing your prey with an "
        "unblinking, mesmerizing stare that weakens their defenses.");

    addSpecification("triggering research",
        "/guilds/therianthrope/serpent/hypnotic-gaze.c");
}
