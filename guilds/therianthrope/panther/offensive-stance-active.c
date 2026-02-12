//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Hunter's Crouch Active");
    addSpecification("root", "offensive stance");
    addSpecification("description", "You are coiled low to the ground, every "
        "muscle tensed for the kill, sacrificing defensive awareness for "
        "lethal aggression.");

    addSpecification("triggering research",
        "/guilds/therianthrope/panther/offensive-stance.c");
}
