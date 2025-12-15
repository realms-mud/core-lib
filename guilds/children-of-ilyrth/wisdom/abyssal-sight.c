//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Abyssal Sight");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "sight of creatures from the abyss. The caster can see in the darkest "
        "depths and perceive things hidden from normal vision.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 13 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/pressure-sense.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spot", 5);
    addSpecification("bonus blind fighting", 4);
    addSpecification("bonus perception", 3);
}
