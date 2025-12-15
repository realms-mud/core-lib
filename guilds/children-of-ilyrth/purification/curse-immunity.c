//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Curse Immunity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with near "
        "immunity to curses. The caster's spirit is so thoroughly blessed "
        "that dark magic slides off like water.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 41 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/remove-curse.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist evil", 15);
    addSpecification("bonus resist magical", 8);

    addSpecification("affected research", ([
        "Remove Curse": 30,
        "Absolute Purification": 20
    ]));
    addSpecification("affected research type", "percentage");
}
