//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shield Bearing");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively use a shield.");

    addSpecification("limited by", (["equipment":({ "shield" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 7 ]));

    addPrerequisite("/guilds/fighter/shields/basic-shield-techniques.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus shield", 3);
    addSpecification("bonus defense", 1);
    addSpecification("bonus soak", 1);
}
