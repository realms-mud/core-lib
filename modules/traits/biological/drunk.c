//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "drunk");
        addSpecification("description", "You are drunk.");
        addSpecification("root", "biological");
        addSpecification("opinion", -25);
        addSpecification("duration", 300);
        addSpecification("expire message", "You are no longer drunk.");
        "baseTrait"::reset(arg);
    }
}
