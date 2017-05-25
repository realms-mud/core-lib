//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    addSpecification("type", "sustained effect");
    addSpecification("name", "Temporary Jerk");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "mean");
    addSpecification("opposing root", "nice");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
    addSpecification("cost", 1);
    addSpecification("triggering research", "lib/tests/support/research/testSustainedTraitResearch.c");
    addSpecification("expire message", "This is an expire message.");
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}

