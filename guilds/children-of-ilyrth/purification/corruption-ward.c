//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Corruption Ward");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "protection against magical corruption and curses. The caster's "
        "spirit is shielded by Ilyrth's sacred waters.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/remove-paralysis.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist evil", 8);
    addSpecification("bonus resist magical", 5);

    addSpecification("affected research", ([
        "Remove Paralysis": 20,
        "Remove Curse": 15
    ]));
    addSpecification("affected research type", "percentage");
}
