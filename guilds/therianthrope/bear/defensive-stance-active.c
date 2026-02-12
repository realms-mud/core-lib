//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Unyielding Guard Active");
    addSpecification("root", "defensive stance");
    addSpecification("description", "You have hunkered down into an immovable "
        "posture, sacrificing offensive power for greatly increased defense.");

    addSpecification("triggering research",
        "/guilds/therianthrope/bear/defensive-stance.c");
}
