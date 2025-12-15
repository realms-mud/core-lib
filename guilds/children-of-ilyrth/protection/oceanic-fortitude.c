//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oceanic Fortitude");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "fortitude of the eternal ocean. The caster's body and spirit become "
        "as resilient as the sea itself.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 13 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/shell-of-the-deep.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 20);
    addSpecification("bonus soak", 3);

    addSpecification("affected research", ([
        "Shell of the Deep": 20,
        "Maelstrom Barrier": 15,
        "Ilryth's Aegis": 15
    ]));
    addSpecification("affected research type", "percentage");
}
