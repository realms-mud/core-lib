//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "stoned");
    addSpecification("description", "You are completely stoned on psychedelic drugs.");
    addSpecification("root", "biological");
    addSpecification("opinion", -15);
    addSpecification("duration", 300);
    addSpecification("expire message", "You are no longer stoned.");
}
