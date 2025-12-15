//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ocean Omniscience");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "omniscient awareness of their surroundings. The caster perceives "
        "everything within their vicinity as if through the all-seeing "
        "waters of Ilyrth.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/trench-sight.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 6);
    addSpecification("bonus spot", 5);
    addSpecification("bonus listen", 5);
    addSpecification("bonus search", 4);
}
