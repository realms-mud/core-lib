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
        addSpecification("name", "Boon of Lyndros");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge to express their raw magical energy as a magical shield. "
            "This form enhances the scion's mana shield.");

        addSpecification("limited by", (["research active": ({
            "guilds/scion/common/mana-shield/root.c" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 11 ]));

        addPrerequisite("guilds/scion/common/mana-shield/gift-of-dhuras.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus heal hit points", 3);
        addSpecification("bonus heal spell points", 3);
    }
}
