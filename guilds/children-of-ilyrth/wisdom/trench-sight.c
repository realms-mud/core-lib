//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Trench Sight");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "sight of the deepest trenches. The caster can perceive what lies "
        "in the most profound darkness, seeing truths hidden from all others.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 21 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/prophetic-tides.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spot", 5);
    addSpecification("bonus perception", 5);
    addSpecification("bonus blind fighting", 5);
}
