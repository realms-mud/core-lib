//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Paralysis Immunity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with near "
        "immunity to paralysis. The caster's body flows like water, "
        "impossible to bind or freeze.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 29 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/corruption-ward.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist paralysis", 15);

    addSpecification("affected research", ([
        "Remove Paralysis": 25,
        "Remove Curse": 20
    ]));
    addSpecification("affected research type", "percentage");
}
