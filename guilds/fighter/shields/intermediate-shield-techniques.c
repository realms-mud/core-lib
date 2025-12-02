//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Intermediate Shield Techniques");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively use a shield.");

    addSpecification("limited by", (["equipment":({ "shield" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 13 ]));

    addPrerequisite("/guilds/fighter/shields/shield-bearing.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus shield", 4);
    addSpecification("bonus dodge", 2);
    addSpecification("bonus defense", 2);
    addSpecification("bonus soak", 2);
}
