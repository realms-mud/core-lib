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
        addSpecification("name", "Extra Attack");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research attunes the "
            "scion's avatar to have an extra attack.");

        addPrerequisite("level", ([  
            "type":"level",
            "guild": "Scion of Dhuras Guild",
            "value": 15
        ]));

        addPrerequisite("guilds/scion/avatars/common/attack-ii.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("related research", ({
            "guilds/scion/avatars/blood/root.c",
            "guilds/scion/avatars/electricity/root.c",
            "guilds/scion/avatars/evocation/root.c",
            "guilds/scion/avatars/flame/root.c",
            "guilds/scion/avatars/ice/root.c",
            "guilds/scion/avatars/spirit/root.c",
        }));
    }
}
