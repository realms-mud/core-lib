//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Edwen Idh");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of an archer's release form.");
    addSpecification("limited by", (["equipment":({ "bow" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 13 ]));

    addPrerequisite("guilds/aegis-guard/forms/bow/adleg.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus bow", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
}
