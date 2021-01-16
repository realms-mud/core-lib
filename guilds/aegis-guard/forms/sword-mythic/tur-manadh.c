//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Tur Manadh");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge to decrease the cost for which they can use their "
            "mythic magic skills.");

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 43
            ]));
        addPrerequisite("guilds/aegis-guard/forms/sword-mythic/tur-edlothia.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", ([
            "Auth": 10,
            "Sereg": 10,
            "Guruthos": 10,
            "Lhutha": 10,
            "Angolo": 10,
        ]));
        addSpecification("affected research type", "decrease cost");
    }
}
