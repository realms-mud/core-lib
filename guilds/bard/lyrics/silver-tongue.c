//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Silver Tongue");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with "
        "knowledge on how to make their lyrical content more poignant "
        "and therefore, more powerful.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 9
        ]));
    addPrerequisite("guilds/bard/lyrics/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Inspiring Lyrics": 100,
        "Demoralizing Lyrics": 100,
    ]));
    addSpecification("affected research type", "percentage");
}
