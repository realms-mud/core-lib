//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Eithagos");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of how to more effectively stab with swords.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("guilds/aegis-guard/forms/sword-attacks/attack-root.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus attack", 1);
        addSpecification("bonus damage", 1);
        addSpecification("equivalence", "stabbing");
    }
}
