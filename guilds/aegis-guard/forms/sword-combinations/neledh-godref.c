//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Neledh-Godref");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge to chain an additional attack to their combinations.");

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 31
            ]));
        addPrerequisite("guilds/aegis-guard/forms/sword-combinations/tad-godref.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", ([
            "Godrebh ai Megil": 1
        ]));
        addSpecification("affected research type", "max combination chain");
    }
}
