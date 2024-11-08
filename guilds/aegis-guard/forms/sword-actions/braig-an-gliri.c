//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Braig an Gliri");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of an aggressive hewing technique for Gliri and Hwinio.");

    addPrerequisite("/guilds/aegis-guard/forms/sword-actions/delu-an-gliri.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 33
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Gliri": 25,
        "Hwinio": 25
    ]));
    addSpecification("affected research type", "percentage");
}
