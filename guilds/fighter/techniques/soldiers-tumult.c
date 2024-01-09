//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soldier's Tumult");
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
          "value": 27 ]));

    addPrerequisite("/guilds/fighter/techniques/skirmish-tactics.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 2);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 2);
    addSpecification("equivalence", "soldiers tumult");
}
