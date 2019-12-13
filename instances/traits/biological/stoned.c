//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "stoned");
        addSpecification("description", "You are completely stoned on psychedelic drugs.");
        addSpecification("root", "biological");
        addSpecification("opinion", -15);
        addSpecification("duration", 300);
        addSpecification("expire message", "You are no longer stoned.");
        "baseTrait"::reset(arg);
    }
}
