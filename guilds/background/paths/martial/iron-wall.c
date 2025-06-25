//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Iron Wall");
    addSpecification("source", "background");
    addSpecification("description",
        "You are a bulwark against harm, able to withstand heavy attacks.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus resist physical", 2);
    addSpecification("bonus parry", 1);

    addPrerequisite("/guilds/background/paths/martial/unyielding.c",
        (["type":"research"]));
}
