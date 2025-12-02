//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Slow");
    addSpecification("description", "This is a persona research item.");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 10);
    addSpecification("bonus slow", 1);
    addSpecification("duration", 20);
    addSpecification("cooldown", 12);
    addSpecification("command template", "slow ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::gesture## and the flow of time drags for "
        "##TargetName##.");
}
