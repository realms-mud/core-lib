//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Infinite Depths");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "perception as infinite as the ocean depths. The caster's awareness "
        "expands to encompass vast distances, perceiving what others cannot.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 41 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/eternal-tides.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 8);
    addSpecification("bonus spot", 6);
    addSpecification("bonus listen", 6);
    addSpecification("bonus senses", 5);
}
