//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "delirious");
        addSpecification("description", "You are under the influence of drugs "
            "causing overwhelming delirium.");
        addSpecification("root", "biological");
        addSpecification("opinion", -75);
        addSpecification("duration", 300);
        addSpecification("expire message", "You are no longer delirious.");
        "baseTrait"::reset(arg);
    }
}
