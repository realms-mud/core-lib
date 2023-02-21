//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "Duelist");
    addSpecification("description", "blah blah blah");
    addSpecification("bonus long sword", 1);
    addSpecification("bonus weapon attack", 1);
    addSpecification("root", "jock");
    addSpecification("opposing root", "nerd");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    addSpecification("cost", 1);
    addSpecification("research tree", 
        "/lib/tests/support/research/testResearchTreeNoPrerequisites.c");
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}
