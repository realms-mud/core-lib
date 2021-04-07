//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hope's Embrace");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to express their raw magical energy as a magical shield. "
        "This form enhances the scion's mana shield.");

    addPrerequisite("level", ([
        "type":"level",
        "guild": "Scion of Dhuras",
        "value": 21 
    ]));

    addPrerequisite("guilds/scion/common/mana-shield/mana-shroud.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", (["Mana Shield":2]));
    addSpecification("affected research type", "bonus");
}
