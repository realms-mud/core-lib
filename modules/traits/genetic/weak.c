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
        addSpecification("type", "genetic");
        addSpecification("name", "weak");
        addSpecification("description", "You are a rather wimpy person.");
        addSpecification("root", "weak");
        addSpecification("opposing root", "strong");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -5);
        addSpecification("penalty to strength", 2);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}

