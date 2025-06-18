//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Haste");
    addSpecification("description", "This is a persona research item.");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 10);
    addSpecification("bonus haste", 1);
    addSpecification("duration", 20);
    addSpecification("cooldown", 12);
    addSpecification("command template", "haste ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::trace## a sigil in the air, and time quickens "
        "around ##TargetName##.");
}
