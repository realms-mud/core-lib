//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "Jerk");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "mean");
    addSpecification("opposing root", "nice");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
    addSpecification("cost", 1);
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}
