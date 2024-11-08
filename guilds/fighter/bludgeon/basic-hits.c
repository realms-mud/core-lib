//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basic Hits");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to more effectively connect with the haft of a weapon.");

    addSpecification("limited by", (["equipment":({ "mace", "hammer",
        "flail", "staff" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "fighter",
          "value": 5 ]));

    addPrerequisite("/guilds/fighter/bludgeon/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 2);
    addSpecification("bonus attack", 3);
}
