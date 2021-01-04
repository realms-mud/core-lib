//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "on salycilates");
        addSpecification("description", "You have salycilates in your blood stream.");
        addSpecification("root", "biological");
        addSpecification("duration", 600);
        "baseTrait"::reset(arg);
    }
}
