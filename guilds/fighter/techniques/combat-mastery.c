//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Combat Mastery");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of an advanced combat technique.");

    addSpecification("limited by", (["equipment":({ "long sword",
        "hand and a half sword", "two-handed sword", "axe",
        "dagger", "short sword", "hammer", "mace", "flail",
        "staff", "pole arm" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 33 ]));

    addPrerequisite("/guilds/fighter/techniques/soldiers-tumult.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 3);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 2);
    addSpecification("equivalence", "combat mastery");
}
