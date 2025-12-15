//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Tides");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "perception of the eternal tides. The caster sees past, present, "
        "and future as one continuous flow, granting profound insight.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 33 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/ocean-omniscience.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 7);
    addSpecification("bonus divination", 6);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus defense", 3);
}
