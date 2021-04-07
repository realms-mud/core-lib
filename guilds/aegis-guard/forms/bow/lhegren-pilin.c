//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Lhegren Pilin");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with "
        "mystic knowledge that enhances mundane archery attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 25
        ]));
    addPrerequisite("guilds/aegis-guard/forms/bow/megor-pilin.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Bregol Adleg": 15,
        "Umba ai Adleg": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
