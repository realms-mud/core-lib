//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Offensive Shield Techniques");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively use a shield.");

    addSpecification("limited by", (["equipment":({ "shield" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 23 ]));

    addPrerequisite("/guilds/fighter/shields/shield-bearing.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus shield", 4);
    addSpecification("bonus physical enchantment", 2);
    addSpecification("bonus damage", 1);
}
