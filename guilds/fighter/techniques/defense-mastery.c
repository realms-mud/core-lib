//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Defense Mastery");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively defend an attack whilst "
        "using a weapon.");
    addSpecification("limited by", (["equipment":({ "long sword",
        "hand and a half sword", "two-handed sword", "axe",
        "dagger", "short sword", "hammer", "mace", "flail",
        "staff", "pole arm" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 37 ]));

    addPrerequisite("/guilds/fighter/techniques/advanced-defense-tactics.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus parry", 4);
    addSpecification("bonus soak", 2);
    addSpecification("bonus defense", 4);
    addSpecification("equivalence", "defense tactics");
}
