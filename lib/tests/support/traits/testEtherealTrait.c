//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "Inconsequential Boy");
    addSpecification("description", "blah blah blah");
    addSpecification("bonus energy attack", 15);
    addSpecification("root", "ethereal");
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}
