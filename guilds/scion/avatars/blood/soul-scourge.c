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
        addSpecification("name", "Soul Scourge");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research gives your "
            "avatar the `Soul Scourge' spell.");

        addPrerequisite("level", ([  
            "type":"level",
            "guild": "Scion of Dhuras Guild",
            "value": 13
        ]));

        addPrerequisite("guilds/scion/avatars/blood/touch-of-the-damned.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("related research", ({
            "guilds/scion/avatars/blood/root.c",
        }));
    }
}
