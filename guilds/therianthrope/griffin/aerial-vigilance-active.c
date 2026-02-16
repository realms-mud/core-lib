//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Aerial Vigilance Active");
    addSpecification("root", "defensive stance");
    addSpecification("description", "You have taken to a watchful aerial "
        "posture, sacrificing offensive power for greatly increased "
        "evasion.");

    addSpecification("triggering research",
        "/guilds/therianthrope/griffin/aerial-vigilance.c");
}
