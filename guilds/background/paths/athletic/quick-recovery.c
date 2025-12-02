//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quick Recovery");
    addSpecification("source", "background");
    addSpecification("description",
        "You recover from exertion and injury faster than most.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 1);
    addSpecification("bonus heal stamina rate", 1);
    addSpecification("bonus constitution", 1);

    addPrerequisite("/guilds/background/paths/athletic/fleet-footed.c",
        (["type":"research"]));
}
