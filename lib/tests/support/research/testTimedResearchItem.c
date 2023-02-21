//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Timed research");
    addSpecification("scope", "targeted");
    addSpecification("research type", "timed");
    addSpecification("research cost", 10);
    addSpecification("cooldown", 4);
    addSpecification("event handler", "usedResearchEvent");
    addSpecification("command template", "throw turnip at ##Target##");
    addSpecification("bonus strength", 2);
    addSpecification("bonus long sword", 5);
    addSpecification("bonus fire attack", 15);
    addSpecification("bonus weapon attack", 1);
}
