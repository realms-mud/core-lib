//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "role");
    addSpecification("name", "Weasel Lord");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "nerd");
    addSpecification("opposing root", "jock");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    addSpecification("cost", 1);
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}
