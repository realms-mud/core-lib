//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Purification");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "power of divine purification. The caster channels Ilyrth's purest "
        "essence in all cleansing magic.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 41 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/ilryths-cleansing.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus magical essence", 6);
    addSpecification("bonus resist poison", 8);
    addSpecification("bonus resist disease", 8);
    addSpecification("bonus resist paralysis", 8);

    addSpecification("affected research", ([
        "Ocean Purge": 25,
        "Remove Curse": 25,
        "Absolute Purification": 20
    ]));
    addSpecification("affected research type", "percentage");
}
