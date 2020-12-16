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
        addSpecification("name", "Pelthaes ai Megil");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of advanced evasion for swordplay.");

        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" }) ]));

        addSpecification("scope", "self");
        addSpecification("research type", "tree root");
        addSpecification("bonus dodge", 1);
    }
}
