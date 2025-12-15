//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pressure Ward");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to use the crushing pressure of the deep as protection. "
        "Enemies who strike the caster feel the weight of the ocean depths.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 7 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/tidal-barrier.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage reflection", 1);
    addSpecification("bonus elemental water", 2);

    addSpecification("affected research", ([
        "Tidal Barrier": 15,
        "Maelstrom Barrier": 10
    ]));
    addSpecification("affected research type", "percentage");
}
