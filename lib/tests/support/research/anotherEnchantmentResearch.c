//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enchantment research");
    addSpecification("source", "mage guild");
    addSpecification("description", "This is enchantment research");
    addSpecification("scope", "self");
    addSpecification("research type", "granted");
    addSpecification("bonus fire enchantment", 3);
}
