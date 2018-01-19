//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "sustained effect");
        addSpecification("name", "Sustained Jerk");
        addSpecification("description", "blah blah blah");
        addSpecification("root", "mean");
        addSpecification("opposing root", "nice");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        addSpecification("cost", 1);
        addSpecification("triggering research", "lib/tests/support/research/testSustainedTraitResearch.c");
        addSpecification("expire message", "This is an expire message.");
        "baseTrait"::reset(arg);
    }
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}

