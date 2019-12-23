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
        addSpecification("type", "effect");
        addSpecification("name", "Temporary Jerk");
        addSpecification("description", "blah blah blah");
        addSpecification("root", "mean");
        addSpecification("opposing root", "nice");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        addSpecification("cost", 1);
        addSpecification("duration", 10);
        addSpecification("expire message", "This is an expire message.");
        "baseTrait"::reset(arg);
    }
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}

