//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Intuition");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "powerful intuition guided by the tides. The caster gains an "
        "instinctive understanding of people and situations.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 21 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/seas-memory.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 5);
    addSpecification("bonus persuasion", 3);
    addSpecification("bonus diplomacy", 3);
    addSpecification("bonus wisdom", 1);
}
