//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Mana Bulwark");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge to express their raw magical energy as a magical shield. "
            "This form enhances the scion's mana shield.");

        addSpecification("limited by", (["traits": ({
            "guilds/scion/common/mana-shield/shield-trait.c" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 23 ]));

        addPrerequisite("guilds/scion/common/mana-shield/mana-screen.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus soak", 5);
        addSpecification("bonus defense", 2);
    }
}
