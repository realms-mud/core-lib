//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Beria an Cu");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to use a bow as a defensive weapon without "
        "damaging the bow.");
    addSpecification("limited by", (["equipment":({ "bow" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 1 ]));

    addPrerequisite("guilds/aegis-guard/forms/bow/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus bow", 1);
    addSpecification("bonus defense", 1);
    addSpecification("bonus dodge", 1);
    addSpecification("bonus parry", 1);
}
