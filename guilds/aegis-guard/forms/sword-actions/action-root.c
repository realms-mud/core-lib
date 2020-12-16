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
        addSpecification("name", "Hur ai Megil");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of advanced actions for swordplay.");

        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" }) ]));

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus dagger", 1);
        addSpecification("bonus short sword", 1);
        addSpecification("bonus long sword", 1);
        addSpecification("bonus hand and a half sword", 1);
        addSpecification("bonus two-handed sword", 1);
    }
}
