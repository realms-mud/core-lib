//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sea Hardened");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with a "
        "body hardened by the sea. The caster's flesh becomes as tough as "
        "barnacle-encrusted rock, resistant to all forms of damage.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 21 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/crushing-depths.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 25);
    addSpecification("bonus soak", 3);
    addSpecification("apply damage reflection", 10);

    addSpecification("affected research", ([
        "Shell of the Deep": 25,
        "Maelstrom Barrier": 20,
        "Ilyryth's Aegis": 20,
        "Sanctuary of Waves": 15
    ]));
    addSpecification("affected research type", "percentage");
}
