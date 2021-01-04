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
        addSpecification("name", "Quenching - Armor");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of quenching metal for use in armor - a rapid cooling "
            "of the metal in water or oil. This treatment results in a very hard,"
            "brittle, amorphous metal.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/armor/common/slack-quenching.c",
            (["type":"research"]));
        addPrerequisite("chemistry", (["type":"skill", "value" : 5]));
        addPrerequisite("blacksmithing", (["type":"skill", "value" : 1]));

        addSpecification("limited by", (["crafting type":({ "chainmail",
            "plate armor", "splint armor", "scale armor", "helmet" })]));

        addSpecification("bonus crafting armor class", 2);
    }
}
