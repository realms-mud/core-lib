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
        addSpecification("name", "Boon of Dhuras");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge to express their raw magical energy as a magical shield. "
            "This form enhances the scion's mana shield.");

        addPrerequisite("level", ([
            "type":"level",
            "guild": "Scion of Dhuras",
            "value": 11 
        ]));

        addPrerequisite("lib/guilds/scion/common/mana-shield/gift-of-dhuras.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", (["Mana Shield":2]));
    }
}
