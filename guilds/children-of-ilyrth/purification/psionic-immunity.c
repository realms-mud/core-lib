//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psionic Immunity");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with near "
        "immunity to mental attacks. The caster's mind is as vast and deep "
        "as the ocean itself, drowning all attempts at intrusion.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 51 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/mental-clarity.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist psionic", 20);

    addSpecification("affected research", ([
        "Absolute Purification": 25
    ]));
    addSpecification("affected research type", "percentage");
}
