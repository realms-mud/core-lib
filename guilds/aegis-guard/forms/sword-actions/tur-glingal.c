//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tur Glingal");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a master hewing technique for Gling.");

    addPrerequisite("/guilds/aegis-guard/forms/sword-actions/braig-an-gling.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 37
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Gling": 25
    ]));
    addSpecification("affected research type", "percentage");
}
