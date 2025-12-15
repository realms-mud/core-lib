//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Resilience");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "the resilience of the eternal tides. Like the sea that cannot be "
        "conquered, the caster endures all attacks.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 17 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/oceanic-fortitude.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 4);
    addSpecification("bonus resist magical", 4);

    addSpecification("affected research", ([
        "Shell of the Deep": 25,
        "Maelstrom Barrier": 20,
        "Ilryth's Aegis": 20
    ]));
    addSpecification("affected research type", "percentage");
}
