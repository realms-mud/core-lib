//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Escape Artist");
    addSpecification("source", "background");
    addSpecification("description",
        "You are adept at slipping bonds, wriggling free from danger, "
        "and escaping tight situations.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus acrobatics", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus move silently", 1);

    addPrerequisite("/guilds/background/paths/miscreant/quick-hands.c", 
        (["type":"research"]));
}
