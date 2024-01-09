//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "impaired");
    addSpecification("description", "You are impaired from the effects of barbituates.");
    addSpecification("root", "biological");
    addSpecification("opinion", -15);
    addSpecification("duration", 300);
    addSpecification("expire message", "You are no longer impaired from barbituates.");
}
