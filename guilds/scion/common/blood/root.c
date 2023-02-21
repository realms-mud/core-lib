//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "The Wounded");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with "
        "the knowledge to express their raw magical energy as blood "
        "magic.");
    SetupResearch();

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus blood", 1);
}
