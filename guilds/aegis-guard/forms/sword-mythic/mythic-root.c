//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Manadh ai Megil");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of the mystic actions for swordplay.");

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus spellcraft", 2);
}
