//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("source", "guild");
    addSpecification("name", "Sustained research");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("cooldown", 4);
    addSpecification("spell point cost", 10);
    addSpecification("command template", "throw turnip at ##Target##");
    addSpecification("trait", "/lib/tests/support/traits/testTraitForSustainedResearch.c");
}
