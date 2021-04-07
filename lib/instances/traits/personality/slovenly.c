//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "slovenly");
    addSpecification("description", "You are rather unrefined and "
        "tend to not care too much about your unkempt appearance.");
    addSpecification("root", "crude");
    addSpecification("opposing root", "refined");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
}
