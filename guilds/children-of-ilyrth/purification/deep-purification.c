//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Deep Purification");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of deep purification. The caster's cleansing magic reaches "
        "into the very depths of affliction.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 21 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/sacred-cleansing.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist poison", 5);
    addSpecification("bonus resist disease", 5);
    addSpecification("bonus resist paralysis", 5);

    addSpecification("affected research", ([
        "Cure Poison": 25,
        "Cure Disease": 25,
        "Remove Paralysis": 20
    ]));
    addSpecification("affected research type", "percentage");
}
